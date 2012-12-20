package fr.hyperfiction;

import org.json.JSONException;
import org.json.JSONObject;

import org.haxe.nme.GameActivity;

import android.opengl.GLSurfaceView;
import android.util.Log;

import com.justinschultz.pusherclient.ChannelListener;
import com.justinschultz.pusherclient.Pusher;
import com.justinschultz.pusherclient.Pusher.Channel;
import com.justinschultz.pusherclient.PusherListener;

public class HypPusher {

	public static String API = "c2216b7ec96e9eb9a409";
	public static String TAG = "HypPusher";

	public static native void onConnect();

	public static native void onDisconnect();

	public static native void onMessage(String message);

	private PusherListener _eventListener;
	private Pusher _pusher;

	public static GLSurfaceView mSurface;

	static {
		System.loadLibrary("hyppusher");
		System.setProperty("java.net.preferIPv6Addresses", "false");
	}

	public HypPusher() {
		Log.i( TAG, "new HypPusher ::: ");
		
		mSurface = (GLSurfaceView) GameActivity.getInstance().getCurrentFocus();
		
		_eventListener = new PusherListener() {
			@Override
			public void onConnect(String socketId) {
				Log.i(TAG, "Pusher connected. Socket Id is: " + socketId);
				mSurface.queueEvent(new Runnable(){
					@Override
					public void run() {
						HypPusher.onConnect( );
					}
				});
			}

			@Override
			public void onMessage(final String message) {
				Log.i(TAG, "Received message from Pusher: " + message);
				mSurface.queueEvent(new Runnable( ){
					@Override
					public void run() {
						HypPusher.onMessage(message);
					}
				});

			}

			@Override
			public void onDisconnect() {
				Log.i(TAG, "Pusher disconnected.");
				mSurface.queueEvent(new Runnable( ){
					@Override
					public void run() {
						HypPusher.onDisconnect();
					}
				});
			}
		};

		Log.i( TAG, "event listener constructed, keep going...");

		_pusher = new Pusher(API);
		_pusher.setPusherListener(_eventListener);
	}

	public Pusher getPusher() {
		return _pusher;
	}

	public static void disconnect() {
		getInstance().getPusher().disconnect();
	}

	public static void connect() {
		getInstance().getPusher().connect();
		Log.i(TAG, "[Pusher] trying to connect to pusher...");
	}

	public static void subscribeToPublicChannel(String channelName) {
		getInstance().getPusher().subscribe(channelName);
		Log.i(TAG, "[Pusher] subscribed to public channel ::: " + channelName);
	}

	public static void sendEventOnChannel(String eventName, String channelName,
			String data) {
		Channel channel = getInstance().getPusher().channel(channelName);
		if (channel != null) {
			try {
				channel.send(eventName, new JSONObject(data));
			} catch (JSONException e) {
				e.printStackTrace();
			}
		}
	}

	public static void bindToEventOnChannel(final String eventName, final String channelName) {
		Channel channel = getInstance().getPusher().channel(channelName);
		if (channel != null) {
			channel.bind(eventName, new ChannelListener() {
				@Override
				public void onMessage(final String message) {
					Log.i(TAG, "[Pusher] receive message ::: " + message);
					mSurface.queueEvent(new Runnable( ){
						@Override
						public void run() {
							HypPusher.onMessageFromChannel(channelName, eventName, message);
						}
					});
				}
			});
		}
	}

	public static HypPusher getInstance() {
		if (__instance == null)
			__instance = new HypPusher();

		return __instance;
	}

	private static HypPusher __instance = null;
}
