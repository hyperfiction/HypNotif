package fr.hyperfiction;

import android.util.Log;

import org.haxe.nme.GameActivity;

import android.opengl.GLSurfaceView;
import com.smartfoxserver.v2.exceptions.SFSException;
import sfs2x.client.SmartFox;
import sfs2x.client.core.BaseEvent;
import sfs2x.client.core.IEventListener;
import sfs2x.client.core.SFSEvent;
import sfs2x.client.entities.match.MatchExpression;
import sfs2x.client.entities.match.NumberMatch;
import sfs2x.client.requests.FindUsersRequest;
import sfs2x.client.requests.PrivateMessageRequest;
import sfs2x.client.requests.JoinRoomRequest;
import sfs2x.client.requests.LoginRequest;
import sfs2x.client.entities.User;
// import sfs2x.client.entities.Interface.Room;
// import sfs2x.client.entities.Interface.User;

import java.io.File;
import java.util.ArrayList;

public class HypFox implements IEventListener {
	
	private SmartFox _sfs_client;
	private String _zone	= "";
	private String _lobby	= "";

	static public native void onConnection( boolean sucess );
	static public native void onConnectionLost();
	static public native void onLogin();
	static public native void onRoomJoin();
	static public native void onPrivateMessage( String msg, int id );
	static public native void onUserFound( int id );

	public static GLSurfaceView mSurface;

	static {
		System.loadLibrary( "hypfox" );
		System.setProperty("java.net.preferIPv6Addresses", "false");
	}

	public static String TAG = "HypFox";

	public HypFox( ){
		Log.i( TAG , "constructor" );
		initSmartFox( );
	}

	public void initSmartFox() {
		mSurface = ( GLSurfaceView ) GameActivity.getInstance( ).getCurrentFocus( );	
		Log.i( TAG , "initSmartFox" );
		_sfs_client = new SmartFox( true );
		//_sfs_client.loadConfig("sfs-config.xml", true);
		_sfs_client.addEventListener(SFSEvent.CONNECTION, this);
		_sfs_client.addEventListener(SFSEvent.CONNECTION_LOST, this);
		_sfs_client.addEventListener(SFSEvent.LOGIN, this);
		_sfs_client.addEventListener(SFSEvent.ROOM_JOIN, this);
		_sfs_client.addEventListener(SFSEvent.PRIVATE_MESSAGE, this);
		_sfs_client.addEventListener(SFSEvent.USER_FIND_RESULT, this);		
		_sfs_client.loadConfig();
	}

	public void handleEvent(final SFSEvent event){
		Log.i( TAG , "handleEvent :::"+event );
	}

	/**
	* 
	* 
	* @public
	* @return	void
	*/
	public SmartFox getClient( ){
		return _sfs_client;	
	}

	/**
	 * Connects to SmartFoxServer instance.
	 * 
	 * @param ip the server IP. 
	 */
	static public void sf_connectToServer(final String ip){
		Log.i( TAG , "connectToServer ::: "+ip );
		/*
		//connect() method is called in separate thread
        //so it does not blocks the UI
		final SmartFox sfs = _sfs_client;
		GameActivity.getInstance().mHandler.post(
			new Runnable() {
				@Override
				public void run() {
					_sfs_client.connect(ip);
				}
			}
		);
		*/

		GameActivity.getInstance().mHandler.post(
			new Runnable() {
				@Override
				public void run() {
					getInstance( ).getClient( ).connect( ip );
				}
			}
		);

		
	}

	/**
	 * Connects to SmartFoxServer instance.
	 * 
	 * @param ip the server IP.
	 * @param port the server port. 
	 */
	static public void sf_connectToServer( final String ip , final int port ){
		Log.i( TAG , "connectToServer ::: "+ip+" port : "+port );
		//connect() method is called in separate thread
        //so it does not blocks the UI
        getInstance( ).getClient( ).connect( ip , port );
        /*
        final HypFox instance = 
		Log.i( TAG , "instance ::: "+instance );
		GameActivity.getInstance().mHandler.post(
			new Runnable() {
				@Override
				public void run() {
					
				}
			}
		);
		*/
	} 

	static public void sf_setZone( final String zone ) {		
		getInstance( ).setZone( zone );		
	}

	static public void sf_setLobby( final String s ){
		getInstance( ).setLobby( s );
	}

	static public void sf_sendPrivateMessage( final String s , final int id ){
		getInstance( ).sendPrivateMessage( s , id );
	}

	static public void sf_findUserByCode( final int code ){
		getInstance( ).findUserByCode( code );
	}

	static public int sf_findUserByName( String room_name , String username ){
		return getInstance( ).getRoomUserID( room_name , username );
	}

	static public void sf_deco( ){
		Log.d( TAG, "sf_deco" );
		getInstance( ).getClient( ).disconnect( );
	}

	/**
	* 
	* 
	* @public
	* @return	void
	*/
	public void setZone( String zone ) {
		_zone = zone;		
	}


	public void dispatch( final BaseEvent event ) throws SFSException {
		Log.d( TAG, "dispatch :::"+event.getType() );
		/*
		mSurface.queueEvent(new Runnable(){
			@Override
			public void run() {
		*/
				if( event.getType().equalsIgnoreCase(SFSEvent.CONNECTION) ) {

					if(event.getArguments().get("success").equals(true)) {
						Log.d( TAG, " success true " );

						mSurface.queueEvent(new Runnable(){
							@Override
							public void run() {
								HypFox.onConnection( true );
							}
						});

					   	_sfs_client.send(new LoginRequest("", "", _zone));

					} else {
						Log.d( TAG, " success false " );
							
						mSurface.queueEvent(new Runnable(){
							@Override
							public void run() {
								HypFox.onConnection( false );
							}
						});
						
				    }

				} else if( event.getType().equalsIgnoreCase(SFSEvent.CONNECTION_LOST) ) {
					HypFox.onConnectionLost();
					mSurface.queueEvent(new Runnable(){
						@Override
						public void run() {
							HypFox.onConnectionLost( );
						}
					});
					destroySmartFox();

				} else if( event.getType().equalsIgnoreCase(SFSEvent.LOGIN) ) {
					Log.d( TAG, " on login " );
					mSurface.queueEvent(new Runnable(){
						@Override
						public void run() {
							HypFox.onLogin( );
						}
					});
					_sfs_client.send(new JoinRoomRequest(_lobby));

				} else if( event.getType().equalsIgnoreCase(SFSEvent.ROOM_JOIN) ) {
					
					mSurface.queueEvent(new Runnable(){
						@Override
						public void run() {
							HypFox.onRoomJoin( );
						}
					});

				} else if( event.getType().equalsIgnoreCase(SFSEvent.PRIVATE_MESSAGE) ) {
					Log.d( TAG, "----> "+event.toString() );
					final User sender = (User)event.getArguments().get("sender"); 
					Log.d( TAG, "sender ----> "+sender );
					if ( !sender.isItMe( ) ){
						mSurface.queueEvent(new Runnable(){
							@Override
							public void run() {
								HypFox.onPrivateMessage( event.getArguments().get("message").toString(), sender.getId() );
							}
						});

					}
						//System.out.println("User " + sender.getName() + " sent me this PM: " + event.getArguments().get("message"));
					/*
					if (sender != _sfs_client.getMySelf()) {
						HypFox.onPrivateMessage( event.getArguments().get("message").toString(), sender.getId() );
					}
					*/
				} else if( event.getType().equalsIgnoreCase(SFSEvent.USER_FIND_RESULT) ) {
					
					Log.d(TAG,"--"+event.getArguments().get("users").toString());
					ArrayList<User> users = (ArrayList<User>)event.getArguments().get("users");
					Log.d(TAG,">>>>"+users.toString());
					
					if( users.size() > 0 ){
						final User found = (User) users.get(0);
						mSurface.queueEvent(new Runnable(){
							@Override
							public void run() {
								HypFox.onUserFound( found.getId() );
							}
						});
						
					} else {
						mSurface.queueEvent(new Runnable(){
							@Override
							public void run() {
								HypFox.onUserFound( -1 );
							}
						});
					}
				}
		/*
			}
		});
		*/
	}

	

	public void setLobby( String lobby ) {
		_lobby = lobby;
	}

	public void sendPrivateMessage( final String msg, final int id ) {
		final SmartFox sfs = _sfs_client;
		GameActivity.getInstance().mHandler.post(
			new Runnable() {
				@Override
				public void run() {
					sfs.send( new PrivateMessageRequest( msg, id ) );
				}
			}
		);
	}

	public void findUserByCode( int code ) {
		MatchExpression exp = new MatchExpression("code", NumberMatch.EQUALS, code );
		_sfs_client.send( new FindUsersRequest( exp ) );
	}
	
	public int getRoomUserID( String roomname , String username ){

		if( _sfs_client.getRoomByName(roomname).getUserByName( username ) == null )
			return -1;

		return _sfs_client.getRoomByName(roomname).getUserByName( username ).getId( );
	}

	public void destroySmartFox() {
		Log.d( TAG, "destroy smartfox connection ");
		if(_sfs_client != null)
		{
			_sfs_client.removeAllEventListeners();
	    	
			_sfs_client.disconnect();
			
		}	
	}
	
	/**
	* 
	* 
	* @public
	* @return	void
	*/
	static public HypFox getInstance( ){
		
		if( __instance == null )
			__instance = new HypFox( );

		return __instance;
	}

	private static HypFox __instance = null;
}