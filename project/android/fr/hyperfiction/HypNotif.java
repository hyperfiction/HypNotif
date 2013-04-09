/*
Copyright (c) 2013, Hyperfiction
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
package fr.hyperfiction;

import android.util.Log;

import com.google.android.gcm.GCMRegistrar;

import fr.hyperfiction.Utils;

import org.haxe.nme.GameActivity;

import ::APP_PACKAGE::.R;

public class HypNotif
{
    private static final String TAG = "trace";

	static{
		System.loadLibrary( "hypnotif" );
	}

	public HypNotif( String server_url, boolean debug_check ){
		if( debug_check ) {
			GCMRegistrar.checkDevice( GameActivity.getInstance() );
			GCMRegistrar.checkManifest( GameActivity.getInstance());
		}
		final String regId = GCMRegistrar.getRegistrationId(GameActivity.getInstance());
		if (regId.equals("")) {
		  GCMRegistrar.register(GameActivity.getInstance(), GameActivity.getContext().getString(R.string.senderid) );
		} else {
		  if( !GCMRegistrar.isRegisteredOnServer( GameActivity.getInstance() ) ){
			Utils.register( GameActivity.getInstance(), regId );
		  }
		}

	}

	public void removeNotif( ) {
		GCMRegistrar.unregister( GameActivity.getInstance() );
	}

	public static HypNotif init( String server_url, String register_url, String unregister_url, String user_id, boolean debug_check ) {
		Utils.SERVER_URL    	= server_url;
		Utils.REGISTER_URL  	= register_url;
		Utils.UNREGISTER_URL	= unregister_url;
		Utils.USER_ID       	= user_id;

		return new HypNotif( server_url, debug_check );
	}

}