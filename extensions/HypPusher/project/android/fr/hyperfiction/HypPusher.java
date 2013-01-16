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

public class HypPusher extends Pusher
{

	public static String TAG = "HypPusher";

	public static native void onConnect( String socketId );
	public static native void onDisconnect();
	public static native void onMessage(String message);

	public static GLSurfaceView mSurface;

	private PusherListener _eventListener;

	static {
		System.loadLibrary("hyppusher");
		System.setProperty("java.net.preferIPv6Addresses", "false");
	}

	public HypPusher( String apiKey )
	{
		super( apiKey );

		Log.i( TAG, "new HypPusher ::: ");

		
		mSurface = (GLSurfaceView) GameActivity.getInstance().getCurrentFocus();
		
		_eventListener = new PusherListener()
		{
			@Override
			public void onConnect(final String socketId)
			{
				Log.i(TAG, "Pusher connected. Socket Id is: " + socketId);
				mSurface.queueEvent(new Runnable()
				{                    
					@Override
					public void run()
					{
						HypPusher.onConnect( socketId );
					}
				});
			}

			@Override
			public void onMessage(final String message)
			{
				Log.i(TAG, "Received message from Pusher: " + message);
				mSurface.queueEvent(new Runnable( )
				{
					@Override
					public void run()
					{
						HypPusher.onMessage(message);
					}
				});

			}

			@Override
			public void onDisconnect()
			{
				Log.i(TAG, "Pusher disconnected.");
				mSurface.queueEvent(new Runnable( )
				{
					@Override
					public void run()
					{
						HypPusher.onDisconnect();
					}
				});
			}
		};

		setPusherListener(_eventListener);
	}

	public static HypPusher create( String apiKey )
	{
		return new HypPusher( apiKey );
	}

	public void subscribeToPublic( String channelName )
	{
		subscribe( channelName );
	}
	
	public void subscribeToPrivate( String channelName, String authToken )
	{
		subscribe( channelName, authToken );
	}

	public void sendEventOnChannel( String eventName, String data, String channelName )
	{
		Channel channel = channel(channelName);
		JSONObject obj;
		
		obj = new JSONObject();
		
		if (channel != null) {

			try {
				obj = new JSONObject(data);
			} catch (JSONException e) {
				e.printStackTrace();
			}
			channel.send(eventName, obj);
		}
	}

	public void bindToEventOnChannel( final String eventName, final String channelName)
	 {
		Channel channel = channel(channelName);
		if (channel != null) {
			channel.bind(eventName, new ChannelListener()
			{
				@Override
				public void onMessage(final String message)
				{
					Log.i(TAG, "[Pusher] receive message ::: " + message);
					mSurface.queueEvent(new Runnable( )
					{
						@Override
						public void run()
						{
							HypPusher.onMessage( message );
						}
					});
				}
			});
		}
	}
}
