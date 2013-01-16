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
	private var _authEndPoint 		: String;

	#if android
	private var _instance 			: Dynamic;
	#end

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

				hyp_cb_connect( _onConnect );
				hyp_cb_disconnect( _onDisconnect );
				hyp_cb_message( _onMessage );
			#end

			#if android
				_instance = create( apiKey );
			#end
			
			#if ios
				hyp_create( apiKey );
				if( _authEndPoint != null )
					hyp_set_authurl( _authEndPoint );
			#end
		}


	// -------o public

		public function connectToServer( ) : Void
		{
			#if android
				connect( _instance );
			#end
			#if ios
				hyp_connect( );
			#end
		}

		public function disconnectFromServer( ) : Void
		{
			#if android
				disconnect( _instance );
			#end
			#if ios
				hyp_disconnect( );
			#end
		}

		public function setChannel( channelName : String ) : Void
		{
			_channelName = channelName;

			#if ios
				hyp_subscribe( channelName );
			#end

			#if android
				if( StringTools.startsWith( channelName, "private-" ) ){
					authenticate( channelName, _authEndPoint );
				} else {
					subscribeToPublic( _instance, channelName );
				}
			#end
		}

		public function bind( event : String ) : Void
		{
			#if android
				bindToEventOnChannel( _instance, event, _channelName );
			#end
			#if ios
				hyp_bind_event( event );
			#end
		}

		public function unbind( event : String ) : Void
		{
			#if android
			#end
			#if ios
				hyp_unbind_event( event );
			#end
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

			#if android
				sendEventOnChannel( _instance, event, data, _channelName );
			#end
			#if ios
				hyp_send_event( event, data, _channelName );
			#end
		}


	// -------o protected

		function authenticate( authEndPoint : String ) : Void
		{
			var auth		: String;
			var pusherAuth	: HypPusherAuth;

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

			#if android
				subscribeToPrivate( _instance, _channelName, _auth );
			#end
			#if ios
				
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
			function subscribeToPublic( instance : Dynamic, chan : String ) : Void
			{
			}
			
			@JNI
			function subscribeToPrivate( instance : Dynamic, chan : String, auth : String ) : Void
			{
			}

			@JNI
			function bindToEventOnChannel( instance : Dynamic, event : String, chan : String ) : Void
			{
			}

			@JNI
			function sendEventOnChannel( instance : Dynamic, event : String, data : String, chan : String ) : Void
			{
			}

			@JNI
			function disconnect( instance : Dynamic ) : Void
			{
			}
		
		#end

		#if cpp

			@CPP("hyppusher")
			function hyp_connect( ) : Void 
			{
			}

			@CPP("hyppusher")
			function hyp_disconnect( ) : Void 
			{
			}

			@CPP("hyppusher")
			function hyp_create( apiKey : String ) : Void 
			{
			}

			@CPP("hyppusher")
			function hyp_set_authurl( url : String ) : Void 
			{
			}

			@CPP("hyppusher")
			function hyp_subscribe( channel : String ) : Void 
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
			function hyp_send_event( event : String, data : String, chan : String ) : Void
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
}