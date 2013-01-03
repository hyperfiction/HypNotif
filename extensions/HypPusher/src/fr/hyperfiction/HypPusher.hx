package fr.hyperfiction;

#if android
import nme.JNI;
#end

#if cpp
import cpp.Lib;
#end

import nme.Lib;
import nme.events.EventDispatcher;
import nme.events.Event;

import org.shoebox.utils.system.Signal;
import org.shoebox.utils.system.Signal1;
import org.shoebox.utils.system.Signal3;


/**
* 
* @author LouisBL
*/

class HypPusher extends EventDispatcher {
	
	#if android	
		public static inline var ANDROID_CLASS : String = 'fr/hyperfiction/HypPusher';
		
		private var _hyp_connect				: Dynamic;
		private var _hyp_disconnect				: Dynamic;
		private var _hyp_subscribe_public_chan	: Dynamic;
		private var _hyp_send_on_chan			: Dynamic;
		private var _hyp_bind_on_chan			: Dynamic;
	#end

	#if android
		private static var hyp_cb_connect				= Lib.load( "hyppusher","hyp_cb_connect", 1 );
		private static var hyp_cb_disconnect			= Lib.load( "hyppusher","hyp_cb_disconnect", 1 );
		private static var hyp_cb_message				= Lib.load( "hyppusher","hyp_cb_message", 1 );
	#end
	
	public var onConnect			: Signal1<String>;
	public var onDisconnect			: Signal;
	public var onMessage			: Signal3<String, String, Dynamic>;

	public var authEndPoint			: String;

	private var _socketId 			: String;
	private var _channelName		: String;
	private var _auth 				: String;

	// -------o constructor

		/**
		* Constructor
		*
		* @public
		* @return	void
		*/
		public function new() : Void {

			trace( "HypPusher constructor ::: " );

			authEndPoint = "/pusher/auth";

			super();
			
			onConnect				= new Signal1<String>();
			onDisconnect			= new Signal();
			onMessage				= new Signal3<String, String, Dynamic>();

			#if android
				hyp_cb_connect( _onConnect );
				hyp_cb_disconnect( _onDisconnect );
				hyp_cb_message( _onMessage );
			#end
		}


	// -------o public

		public function connectToServer(  ) : Void {
			#if android	
				if( _hyp_connect == null )
					_hyp_connect = JNI.createStaticMethod( ANDROID_CLASS, 'connect', "()V");
					_hyp_connect( );
			#end
		}

		public function subscribeToPrivateChannel( chan : String ) : Void {
			trace('subscribe to private channel ::: '+chan);

			var auth : String;
			var pusherAuth : HypPusherAuth;

			_channelName = chan;

			pusherAuth = new HypPusherAuth();
			pusherAuth.sgAuthSuccessful.connect( _on_auth_success );
			pusherAuth.sgAuthFailed.connect( _on_auth_failed );
			pusherAuth.sgAuthError.connect( _on_auth_error );

			pusherAuth.authenticate( _socketId, authEndPoint, _channelName );
		}

		function _on_auth_success( auth : String ) : Void {
			trace( "on auth success ::: " );

			_auth = auth;

			#if android
				if( _hyp_subscribe_public_chan == null )
					_hyp_subscribe_public_chan = JNI.createStaticMethod( ANDROID_CLASS, 'subscribeToPrivateChannel', "(Ljava/lang/String;Ljava/lang/String;)V" );
					_hyp_subscribe_public_chan( _channelName, auth );
			#end
		}

		function _on_auth_error( ) : Void {
			trace( "on auth error ::: " );
		}

		function _on_auth_failed( ) : Void {
			trace( "on auth failed ::: " );
		}

		public function subscribeToPublicChannel( chan : String ) : Void {
			trace('subscribe to public channel ::: '+chan);
			#if android
				if( _hyp_subscribe_public_chan == null )
					_hyp_subscribe_public_chan = JNI.createStaticMethod( ANDROID_CLASS, 'subscribeToPublicChannel', "(Ljava/lang/String;)V" );
					_hyp_subscribe_public_chan( chan );
			#end
		}

		public function sendEventOnChannel( event : String, chan : String, data : Dynamic ) : Void {
			trace('send event :::'+event+' on channel ::: '+chan+' with data ::: '+data);
			if( data == null )
				data = {};
			data.auth = _auth;
			
			try{
				data = haxe.Json.stringify( data );
			}catch( e  : Dynamic ){
				trace( "malformed Json data ::: "+data );
			}
			#if android
				if( _hyp_send_on_chan == null )
					_hyp_send_on_chan = JNI.createStaticMethod( ANDROID_CLASS, 'sendEventOnChannel', "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V" );
					_hyp_send_on_chan( event, chan, data );
			#end
		}

		public function bindToEventOnChannel( event : String, chan : String ) : Void {
			trace('bind to event ::: '+event+' on channel ::: '+chan);
			#if android
				if( _hyp_bind_on_chan == null )
					_hyp_bind_on_chan = JNI.createStaticMethod( ANDROID_CLASS, 'bindToEventOnChannel', "(Ljava/lang/String;Ljava/lang/String;)V" );
					_hyp_bind_on_chan( event, chan );
			#end
		}

		public function disconnect() : Void {
			trace( "disconnect ::: " );
			#if android
				if( _hyp_disconnect == null )
					_hyp_disconnect = JNI.createStaticMethod( ANDROID_CLASS, 'disconnect', "()V" );
					_hyp_disconnect( );
			#end
		}

	// -------o protected

		function _onConnect( socketId : String ) : Void {
			trace( "_onConnect" );
			_socketId = socketId;
			onConnect.emit( socketId );
		}

		function _onDisconnect( ) : Void {
			trace( "_onDisconnect" );
			onDisconnect.emit();
		}

		function _onMessage( message : String ) : Void {
			trace( "_onMessage ::: "+message );
			
			var msg 	: Dynamic;
			var data 	: Dynamic;
			var event 	: String;
			var channel : String;
				
			try{
				msg = haxe.Json.parse( message );
				if( msg != null ){	
					data = haxe.Json.parse( msg.data );
					event = msg.event;
					channel = msg.channel;
					trace( "channel ::: "+channel+" event ::: "+event+" with data ::: "+data );
					onMessage.emit( event, channel, data );
				}
			}catch( e : Dynamic ) {
				trace( "[Pusher] Error ::: "+ e + " parsing Json message ::: "+message );
			}

		}

	// -------o misc

}