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
	public var onSubscribed			: Signal1<String>;
	public var onMessage			: Signal3<String, String, Dynamic>;

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
		* Constructor, instantiate apusher client. No auto connect.
		* @see connectToServer to connect to the pusher server
		*
		* @public
		* @param apiKey Pusher api Key
		* @param authEndPoint url used to authenticate private channel
		* @param token a token used to authenticate against the authendPoint
		* @return	void
		*/
		public function new( apiKey : String, ?authEndPoint : String, ?token : String ) : Void
		{

			trace( "HypPusher constructor ::: " );
			
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
		* @return	void
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
		* @return	void
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
		* @return	void
		*/
		public function setChannel( channelName : String ) : Void
		{
			var chanIsPrivate : Bool;
			chanIsPrivate = false;

			if( StringTools.startsWith( channelName, "private-" ) ){
				if( _authEndPoint == null || _token == null ){
					throw "authEndPoint or token not set before subscribing to private channel";
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
		* @return	void
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
		* @return	void
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
		* @return	void
		*/
		public function send( event : String, ?data : Dynamic ) : Void
		{
			if( !_subscribed ){
				throw "cannot send event without subscribing to a channel";
				return;
			}

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
		* @return	void
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
			trace( "on auth success ::: " );

			_auth = auth;

			#if android
				subscribeToPrivate( _instance, _channelName, _auth );
			#end
		}

		function _on_auth_error( ) : Void
		{
			trace( "on auth error ::: " );
		}

		function _on_auth_failed( ) : Void
		{
			trace( "on auth failed ::: " );
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
			trace( "_onConnect" );

			_socketId = socketId;
			onConnect.emit( socketId );
		}

		function _onDisconnect( ) : Void
		{
			trace( "_onDisconnect" );

			onDisconnect.emit();
		}

		function _onMessage( event : String, data : String, channel : String ) : Void
		{
			trace( "_onMessage ::: "+event );
			
			var dataObj : Dynamic;
			dataObj = {};
				
			try{
				dataObj	= haxe.Json.parse( data );
				
				trace( "channel ::: "+channel+" event ::: "+event+" with data ::: "+data );
			
			} catch( e : Dynamic ) {
			
				trace( "[Pusher] Error ::: "+ e + " parsing Json data ::: "+data );
			}

			onMessage.emit( event, channel, dataObj );

		}

		function _onSubscribed( channel : String ) : Void
		{
			trace( "_onSubscribed ::: "+channel );

			_subscribed = true;
			onSubscribed.emit( channel );
		}
}