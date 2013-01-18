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

	public static String TAG = "trace";

	public static native void onConnect( String socketId );
	public static native void onDisconnect();
	public static native void onMessage(String event, String data, String channel);
	public static native void onSubscribed(String channel);

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
			public void onMessage(JSONObject message)
			{
				Log.i(TAG, "Received message from Pusher: " + message.toString() );
				
				String event;
				String data;
				String channel;
				
				event	= message.optString("event");
				data	= message.optString("data");
				channel	= message.optString("channel");

				final String msgEvent	= event;
				final String msgData	= data;
				final String msgChannel	= channel;

				mSurface.queueEvent(new Runnable( )
				{
					@Override
					public void run()
					{
						HypPusher.onMessage(msgEvent, msgData, msgChannel);
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
		if( subscribe( channelName ) != null ){
			HypPusher.onSubscribed(channelName);
		}
	}
	
	public void subscribeToPrivate( String channelName, String authToken )
	{
		Log.i(TAG, "[Pusher] subscribeToPrivate ::: " + channelName);
		if( subscribe( channelName, authToken ) != null ){
			HypPusher.onSubscribed(channelName);
		}
	}

	public void sendEvent( String eventName, String data, String channelName )
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

	public void bindToEvent( final String eventName, final String channelName)
	{
		Channel channel = channel(channelName);
		if (channel != null) {
			channel.bind(eventName, new ChannelListener()
			{
				@Override
				public void onMessage(JSONObject message)
				{
					String event;
					String data;
					
					event	= message.optString("event");
					data	= message.optString("data");

					final String msgEvent	= event;
					final String msgData	= data;

					Log.i(TAG, "[Pusher] receive message ::: " + message.toString());
					mSurface.queueEvent(new Runnable( )
					{
						@Override
						public void run()
						{
							HypPusher.onMessage( msgEvent, msgData, channelName );
						}
					});
				}
			});
		}
	}

	public void unbindEvent( final String eventName, final String channelName)
	{
		Channel channel = channel(channelName);
		if (channel != null) {
			channel.unbind(eventName);
		}
	}
}
