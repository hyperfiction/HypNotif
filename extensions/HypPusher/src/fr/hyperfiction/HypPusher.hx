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
*	HypPusher, NME native extension for pusher service.
*	See <a href="http://pusher.com/docs">pusher documentation</a>
*	
*	Use <a href="https://github.com/jmschultz/JavaPusherClient">JavaPusherClient</a> for Android
*	Use <a href="https://github.com/lukeredpath/libPusher">LibPusher</a> for iOS
*
* 	Default is to use wss://, on port 443 as it works better on mobile connection
*
* 	In order to use private channel, you need to provide an end point url to authenticate
*
* 	Limitations : only one channel at a time for now, no presence channel
* 	TODO : better handling of connection / reconnection
* 
* @author LouisBL
*/

@:build( org.shoebox.utils.NativeMirror.build() )class HypPusher
{
	// Emit the socketID once connected to pusher
	public var onConnect			: Signal1<String>;

	// Emit once disconnected
	public var onDisconnect			: Signal;
	
	// Emit the channel name once subscribed
	public var onSubscribed			: Signal1<String>;
	
	// Emit message with the event name, a JSON object for data, the channel name
	public var onMessage			: Signal3<String, Dynamic, String >;

	var _socketId 			: String;
	var _channelName		: String;
	var _auth 				: String;
	var _authEndPoint 		: String;
	var _token 				: String;
	var _subscribed			: Bool;

	#if android
		var _instance 			: Dynamic;
	#end

	// -------o constructor

		/**
		 * Constructor, instantiate a pusher client, wihtout autoconnect.
		 * @see connectToServer to connect to the pusher server
		 * 
		 * @param apiKey        : String Pusher API Key
		 * @param ?authEndPoint : String url used to authenticate private/presence channel
		 * @param ?token        : String a token used to authenticate with the authEndPoint
		 * @return Void
		 */
		public function new( apiKey : String, ?authEndPoint : String, ?token : String ) : Void
		{
			onConnect		= new Signal1<String>();
			onDisconnect	= new Signal();
			onSubscribed 	= new Signal1<String>();
			onMessage		= new Signal3<String, String, Dynamic>();

			#if ( android || ios )

				_authEndPoint 	= authEndPoint;
				_token 			= token;

				hyp_cb_connect( _onConnect );
				hyp_cb_disconnect( _onDisconnect );
				hyp_cb_message( _onMessage );
				hyp_cb_subscribed( _onSubscribed );
			#end

			#if android
				_instance = create( apiKey );
			#end
			
			#if ios
				hyp_create( apiKey );
				if( _authEndPoint != null && _token != null )
					hyp_set_authurl( _authEndPoint, _token );
			#end
		}


	// -------o public


	/**
		* connectToServer try to connect to the pusher server
		* default uses secure connection over 443 port.
		* 
		* @public
		* @return	Void
		*/
		public function connectToServer( ) : Void
		{
			#if android
				connect( _instance );
			#end
			#if ios
				hyp_connect( );
			#end
		}

		/**
		* disconnectFromServer
		* 
		* @public
		* @return	Void
		*/
		public function disconnectFromServer( ) : Void
		{
			#if android
				disconnect( _instance );
			#end
			#if ios
				hyp_disconnect( );
			#end
		}

		/**
		* setChannel subscribe to a channel. if the name
		* start with "private-", subscribe to a private channel.
		* otherwise a public one.
		* No presence channel for now.
		* Only one channel at a time for now.
		* 
		* @public
		* @param channelName the name of the channel to subscribe to.
		* @return	Void
		*/
		public function setChannel( channelName : String ) : Void
		{
			var chanIsPrivate : Bool;
			chanIsPrivate = false;

			if( StringTools.startsWith( channelName, "private-" ) ){
				if( _authEndPoint == null || _token == null ){
					throw "[HypPusher] Error ::: authEndPoint or token not set before subscribing to private channel";
					return;
				}else{
					chanIsPrivate = true;
				}
			}

			_channelName = channelName;

			#if ios
				hyp_subscribe( channelName );
			#end

			#if android
				if( chanIsPrivate ){
					_authenticate( );
				} else {
					subscribeToPublic( _instance, channelName );
				}
			#end
		}

		/**
		* bind bind to an event. All notif are received
		* through onMessage signal.
		* 
		* @public
		* @param event name of the event
		* @return	Void
		*/
		public function bind( event : String ) : Void
		{
			#if android
				bindToEvent( _instance, event, _channelName );
			#end
			#if ios
				hyp_bind_event( event );
			#end
		}

		/**
		* unbind unbind from a previously subscribed event
		* 
		* @public
		* @param event the name of the event
		* @return	Void
		*/
		public function unbind( event : String ) : Void
		{
			#if android
				unbindEvent( _instance, event, _channelName );
			#end
			#if ios
				hyp_unbind_event( event );
			#end
		}

		/**
		* sendEvent send a client event to Pusher, with optional json data.
		* only allowed when subscribed to a private channel.
		* 
		* @public
		* @param event the name of the event
		* @param data optional data, json object
		* @return	Void
		*/
		public function send( event : String, ?data : Dynamic ) : Void
		{
			if( !_subscribed ){
				throw "[HypPusher] Error ::: cannot send event without subscribing to a channel";
				return;
			}

			if( data == null ) {
				data = {};
			}

			data.auth = _auth;
			
			try{
				data = haxe.Json.stringify( data );
			} catch ( e  : Dynamic ){
				throw "[HypPusher] Error ::: malformed Json data ::: "+data;
			}

			#if android
				sendEvent( _instance, event, data, _channelName );
			#end
			#if ios
				hyp_send_event( event, data, _channelName );
			#end
		}


	// -------o protected


		/**
		* _authenticate request an auth token to the authEndPoint.
		* Only used for android. LibPusher for iOS already provide
		* the auth mechanism.
		* 
		* @private
		* @return	Void
		*/
		function _authenticate( ) : Void
		{
			var auth		: String;
			var pusherAuth	: HypPusherAuth;

			pusherAuth		= new HypPusherAuth();

			pusherAuth.sgAuthSuccessful.connect( _on_auth_success );
			pusherAuth.sgAuthFailed.connect( _on_auth_failed );
			pusherAuth.sgAuthError.connect( _on_auth_error );

			pusherAuth.authenticate( _socketId, _authEndPoint, _channelName, _token );
		}

		function _on_auth_success( auth : String ) : Void
		{
			_auth = auth;

			#if android
				subscribeToPrivate( _instance, _channelName, _auth );
			#end
		}

		function _on_auth_error( ) : Void
		{
			throw "[HypPusher] Error ::: auth error ::: ";
		}

		function _on_auth_failed( ) : Void
		{
			throw "[HypPusher] Error ::: auth failed ::: ";
		}


	// -------o native

		#if android
			
			@JNI
			static function create( apiKey : String ) : HypPusher
			{
			}

			@JNI
			function connect( instance : Dynamic ) : Void
			{
			}

			@JNI
			function disconnect( instance : Dynamic ) : Void
			{
			}

			@JNI
			function subscribeToPublic( instance : Dynamic, chan : String ) : Void
			{
			}
			
			@JNI
			function subscribeToPrivate( instance : Dynamic, chan : String, auth : String ) : Void
			{
			}

			@JNI
			function bindToEvent( instance : Dynamic, event : String, chan : String ) : Void
			{
			}

			@JNI
			function unbindEvent( instance : Dynamic, event : String, chan : String ) : Void
			{
			}

			@JNI
			function sendEvent( instance : Dynamic, event : String, data : String, chan : String ) : Void
			{
			}
		
		#end

		#if cpp

			@CPP("hyppusher")
			function hyp_create( apiKey : String ) : Void 
			{
			}

			@CPP("hyppusher")
			function hyp_set_authurl( url : String, token : String ) : Void 
			{
			}

			@CPP("hyppusher")
			function hyp_connect( ) : Void 
			{
			}

			@CPP("hyppusher")
			function hyp_disconnect( ) : Void 
			{
			}

			@CPP("hyppusher")
			function hyp_subscribe( channel : String ) : Void 
			{
			}

			@CPP("hyppusher")
			function hyp_bind_event( event : String ) : Void
			{
			}

			@CPP("hyppusher")
			function hyp_unbind_event( event : String ) : Void
			{
			}

			@CPP("hyppusher")
			function hyp_send_event( event : String, data : String, chan : String ) : Void
			{
			}

			// CPP Callbacks

			@CPP("hyppusher")
			function hyp_cb_connect( cb : Dynamic ) : Dynamic
			{
			}

			@CPP("hyppusher")
			function hyp_cb_disconnect( cb : Dynamic ) : Dynamic
			{
			}

			@CPP("hyppusher")
			function hyp_cb_message( cb : Dynamic ) : Dynamic
			{
			}

			@CPP("hyppusher")
			function hyp_cb_subscribed( cb : Dynamic ) : Dynamic
			{
			}
		
		#end


	// -------o misc

		function _onConnect( socketId : String ) : Void
		{
			_socketId = socketId;
			onConnect.emit( socketId );
		}

		function _onDisconnect( ) : Void
		{
			onDisconnect.emit();
		}

		function _onMessage( event : String, data : String, channel : String ) : Void
		{
			var dataObj : Dynamic;
			dataObj = {};
				
			try{
				dataObj	= haxe.Json.parse( data );
			} catch( e : Dynamic ) {
				throw "[HypPusher] Error ::: "+ e + " parsing Json data ::: "+data;
			}

			onMessage.emit( event, dataObj, channel );

		}

		function _onSubscribed( channel : String ) : Void
		{
			_subscribed = true;
			onSubscribed.emit( channel );
		}
}