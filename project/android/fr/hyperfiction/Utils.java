/*
Copyright (c) 2013, Hyperfiction
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
package fr.hyperfiction;

import com.google.android.gcm.GCMRegistrar;

import android.content.Context;
import android.util.Log;
import android.os.AsyncTask;

import java.io.IOException;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Random;
import java.util.Locale;

public final class Utils
{
	 /**
     * Base URL of the Demo Server (such as http://my_host:8080/gcm-demo)
     */
    public static String SERVER_URL = null;
    public static String REGISTER_URL = null;
    public static String UNREGISTER_URL = null;

    public static String USER_ID = null;

    /**
     * Google API project id registered to use GCM.
     */
    public static String SENDER_ID = null;

	private static final int MAX_ATTEMPTS			= 5;
	private static final int BACKOFF_MILLI_SECONDS	= 2000;
	private static final Random random				= new Random();

    private static final String TAG = "trace";

    private static AsyncTask<Void,Void,Void> registerTask;

    /**
     * Register this account/device pair within the server.
     *
     * @return whether the registration succeeded or not.
     */
    public static void register(final Context context, final String regId)
    {

        registerTask = new AsyncTask<Void, Void, Void>() {

            @Override
            protected Void doInBackground(Void... params) {
                registerOnServer(context, regId);
                return null;
            }

            @Override
            protected void onPostExecute(Void result) {
                registerTask = null;
            }

        };
        registerTask.execute(null, null, null);
    }

    public static void dispose( ) {
        if( registerTask != null ) {
            registerTask.cancel( true );
        }
    }

    protected static boolean registerOnServer( final Context context, final String regId ) {
        // Log.i(TAG, "registering device (regId = " + regId + ")");
        Log.i(TAG, "registering device");

        String serverUrl  = SERVER_URL + REGISTER_URL;
        // Log.i(TAG,serverUrl);

        Map<String, String> params  = new HashMap<String, String>();

        params.put("os", "and");
        params.put("lang", Locale.getDefault().getLanguage());
        params.put("appname", "::APP_PACKAGE::");
        params.put("appversion", "::APP_VERSION::");
        params.put("deviceuid", regId);
        params.put("userid", USER_ID);
        params.put("devicename", android.os.Build.PRODUCT);
        params.put("devicemodel", android.os.Build.MODEL);
        params.put("deviceversion", android.os.Build.VERSION.RELEASE);

        // Log.i(TAG,params.toString());

        long backoff = BACKOFF_MILLI_SECONDS + random.nextInt(1000);

        // Once GCM returns a registration id, we need to register it in the
        // demo server. As the server might be down, we will retry it a couple
        // times.
        for (int i = 1; i <= MAX_ATTEMPTS; i++) {

            Log.i(TAG, "Attempt #" + i + " to register");

            try {

                post(serverUrl, params);
                GCMRegistrar.setRegisteredOnServer(context, true);

                return true;

            } catch (IOException e) {

                Log.e(TAG, "Failed to register on attempt " + i, e);
                if (i == MAX_ATTEMPTS) {
                    break;
                } try {

                    Log.i(TAG, "Sleeping for " + backoff + " ms before retry");

                    Thread.sleep(backoff);

                } catch (InterruptedException e1) {
                    // Activity finished before we complete - exit.

                    Log.i(TAG, "Thread interrupted: abort remaining retries!");

                    Thread.currentThread().interrupt();

                    return false;

                }
                // increase backoff exponentially
                backoff *= 2;
            }
        }
        return false;
    }

    /**
     * Unregister this account/device pair within the server.
     */
    public static void unregister(final Context context, final String regId)
    {

        Log.i(TAG, "unregistering device (regId = " + regId + ")");

		String serverUrl  = SERVER_URL + UNREGISTER_URL;
		Map<String, String> params	= new HashMap<String, String>();

        params.put("os", "and");
        params.put("appname", "::APP_PACKAGE::");
        params.put("appversion", "::APP_VERSION::");
        params.put("deviceuid", regId);
        params.put("userid", USER_ID);

        try {

            post(serverUrl, params);

            GCMRegistrar.setRegisteredOnServer(context, false);

        } catch (IOException e) {
            // At this point the device is unregistered from GCM, but still
            // registered in the server.
            // We could try to unregister again, but it is not necessary:
            // if the server tries to send a message to the device, it will get
            // a "NotRegistered" error message and should unregister the device.
        }
    }

    /**
     * Issue a POST request to the server.
     *
     * @param endpoint POST address.
     * @param params request parameters.
     *
     * @throws IOException propagated from POST.
     */
    private static void post(String endpoint, Map<String, String> params) throws IOException
    {
        URL url;

        try {
            url = new URL(endpoint);
        } catch (MalformedURLException e) {
            throw new IllegalArgumentException("invalid url: " + endpoint);
        }

		StringBuilder bodyBuilder					= new StringBuilder();
		Iterator<Entry<String, String>> iterator	= params.entrySet().iterator();

        // constructs the POST body using the parameters
        while (iterator.hasNext()) {
            Entry<String, String> param = iterator.next();

            bodyBuilder.append(param.getKey()).append('=')
                    .append(param.getValue());

            if (iterator.hasNext()) {
                bodyBuilder.append('&');
            }
        }

        String body = bodyBuilder.toString();

        Log.v(TAG, "Posting '" + body + "' to " + url);

		byte[] bytes			= body.getBytes();
		HttpURLConnection conn	= null;

        try {
            conn = (HttpURLConnection) url.openConnection();
            conn.setDoOutput(true);
            conn.setUseCaches(false);
            conn.setFixedLengthStreamingMode(bytes.length);
            conn.setRequestMethod("POST");
            conn.setRequestProperty("Content-Type",
                    "application/x-www-form-urlencoded;charset=UTF-8");
            // post the request
            OutputStream out = conn.getOutputStream();
            out.write(bytes);
            out.close();
            // handle the response
            int status = conn.getResponseCode();
            if (status != 200) {
              throw new IOException("Post failed with error code " + status);
            }
        } finally {
            if (conn != null) {
                conn.disconnect();
            }
        }
      }
}