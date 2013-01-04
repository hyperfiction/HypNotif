package fr.hyperfiction;

#if android
import nme.JNI;
#end

import nme.Lib;
import nme.events.Event;

import org.shoebox.utils.system.Signal;
import org.shoebox.utils.system.Signal1;
import org.shoebox.utils.system.Signal3;


/**
* 
* @author LouisBL
*/

@:build( org.shoebox.utils.NativeMirror.build() )class HypPusher
{

	public var onConnect			: Signal1<String>;
	public var onDisconnect			: Signal;
	public var onMessage			: Signal3<String, String, Dynamic>;

	private var _socketId 			: String;
	private var _channelName		: String;
	private var _auth 				: String;

	private var _instance 			: Dynamic;
	private var _authEndPoint 		: String;

	// -------o constructor

		/**
		* Constructor
		*
		* @public
		* @return	void
		*/
		public function new( apiKey : String, ?authEndPoint : String ) : Void
		{

			trace( "HypPusher constructor ::: " );
			
			onConnect		= new Signal1<String>();
			onDisconnect	= new Signal();
			onMessage		= new Signal3<String, String, Dynamic>();

			#if ( android || ios )

				_authEndPoint = authEndPoint;
				_instance = create( apiKey );

				hyp_cb_connect( _onConnect );
				hyp_cb_disconnect( _onDisconnect );
				hyp_cb_message( _onMessage );
			#end
		}


	// -------o public

		public function connectToServer( ) : Void
		{
			connect( _instance );
		}

		public function disconnectFromServer( ) : Void
		{
			disconnect( _instance );
		}

		public function setChannel( channelName : String ) : Void
		{
			if( StringTools.startsWith( channelName, "private-" ) ){
				authenticate( channelName, _authEndPoint );
			} else {
				subscribeToPublic( _instance, channelName );
			}
		}

		public function bind( event : String ) : Void
		{
			bindToEventOnChannel( _instance, event, _channelName );
		}

		public function sendEvent( event : String, ?data : Dynamic ) : Void
		{
			trace('send event :::'+event+' on channel ::: '+_channelName+' with data ::: '+data);
			
			if( data == null ) {
				data = {};
			}

			data.auth = _auth;
			
			try{
				data = haxe.Json.stringify( data );
			} catch ( e  : Dynamic ){
				trace( "malformed Json data ::: "+data );
			}

			sendEventOnChannel( _instance, event, _channelName, data );
		}

		public function authenticate( chan : String, authEndPoint : String ) : Void
		{
			trace('subscribe to private channel ::: '+chan);

			var auth		: String;
			var pusherAuth	: HypPusherAuth;

			_channelName	= chan;
			pusherAuth		= new HypPusherAuth();

			pusherAuth.sgAuthSuccessful.connect( _on_auth_success );
			pusherAuth.sgAuthFailed.connect( _on_auth_failed );
			pusherAuth.sgAuthError.connect( _on_auth_error );

			pusherAuth.authenticate( _socketId, authEndPoint, _channelName );
		}

		function _on_auth_success( auth : String ) : Void
		{
			trace( "on auth success ::: " );

			_auth = auth;

			subscribeToPrivate( _instance, _channelName, _auth );
		}

		function _on_auth_error( ) : Void
		{
			trace( "on auth error ::: " );
		}

		function _on_auth_failed( ) : Void
		{
			trace( "on auth failed ::: " );
		}


		@JNI
		public static function create( apiKey : String ) : HypPusher
		{
		}

		@JNI
		public function connect( instance : Dynamic ) : Void
		{
		}

		@JNI
		public function subscribeToPublic( instance : Dynamic, chan : String ) : Void
		{
		}
		
		@JNI
		public function subscribeToPrivate( instance : Dynamic, chan : String, auth : String ) : Void
		{
		}

		@JNI
		public function bindToEventOnChannel( instance : Dynamic, event : String, chan : String ) : Void
		{
		}

		@JNI
		public function sendEventOnChannel( instance : Dynamic, event : String, chan : String, data : String ) : Void
		{
		}

		@JNI
		public function disconnect( instance : Dynamic ) : Void
		{
		}

		@CPP("hyppusher")
		public function hyp_cb_connect( cb : Dynamic ) : Void
		{
		}

		@CPP("hyppusher")
		public function hyp_cb_disconnect( cb : Dynamic ) : Void
		{
		}

		@CPP("hyppusher")
		public function hyp_cb_message( cb : Dynamic ) : Void
		{
		}

	// -------o protected

		function _onConnect( socketId : String ) : Void
		{
			trace( "_onConnect" );

			_socketId = socketId;
			onConnect.emit( socketId );
		}

		function _onDisconnect( ) : Void
		{
			trace( "_onDisconnect" );

			onDisconnect.emit();
		}

		function _onMessage( message : String ) : Void
		{
			trace( "_onMessage ::: "+message );
			
			var msg 	: Dynamic;
			var data 	: Dynamic;
			var event 	: String;
			var channel : String;
				
			try{
				msg = haxe.Json.parse( message );
				
				if( msg != null ){	
					data	= haxe.Json.parse( msg.data );
					event	= msg.event;
					channel	= msg.channel;
					
					trace( "channel ::: "+channel+" event ::: "+event+" with data ::: "+data );
					
					onMessage.emit( event, channel, data );
				}
			} catch( e : Dynamic ) {
				trace( "[Pusher] Error ::: "+ e + " parsing Json message ::: "+message );
			}

		}

	// -------o misc

}