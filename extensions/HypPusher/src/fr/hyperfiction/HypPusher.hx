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

	#if mobile
		private static var hyp_cb_connect				= Lib.load( "hyppusher","hyp_cb_connect", 1 );
		private static var hyp_cb_disconnect			= Lib.load( "hyppusher","hyp_cb_disconnect", 1 );
		private static var hyp_cb_message				= Lib.load( "hyppusher","hyp_cb_message", 1 );
		private static var hyp_cb_message_from_channel	= Lib.load( "hyppusher","hyp_cb_message_from_channel", 1 );
	#end
	
	public var onConnect			: Signal;
	public var onDisconnect			: Signal;
	public var onMessage			: Signal1<String>;
	public var onMessageFromChannel	: Signal3<String,String,String>;

	// -------o constructor

		/**
		* Constructor
		*
		* @public
		* @return	void
		*/
		public function new() : Void {
			super();
			
			onConnect				= new Signal();
			onDisconnect			= new Signal();
			onMessage				= new Signal1<String>();
			onMessageFromChannel	= new Signal3<String,String,String>();

			#if mobile
				hyp_cb_connect( _onConnect );
				hyp_cb_disconnect( _onDisconnect );
				hyp_cb_message( _onMessage );
				hyp_cb_message_from_channel( _onMessageFromChannel );
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

		public function subscribeToPublicChannel( chan : String ) : Void {
			trace('subscribe to channel ::: '+chan);
			#if android
				if( _hyp_subscribe_public_chan == null )
					_hyp_subscribe_public_chan = JNI.createStaticMethod( ANDROID_CLASS, 'subscribeToPublicChannel', "(Ljava/lang/String;)V" );
					_hyp_subscribe_public_chan( chan );
			#end
		}

		public function sendEventOnChannel( event : String, chan : String, data : Dynamic = "" ) : Void {
			trace('send event :::'+event+' on channel ::: '+chan+' with data ::: '+data);
			data = haxe.Json.stringify( data );
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

		function _onConnect( ) : Void {
			trace( "_onConnect" );
			onConnect.emit();
		}

		function _onDisconnect( ) : Void {
			trace( "_onDisconnect" );
			onDisconnect.emit();
		}

		function _onMessage( message : String ) : Void {
			trace( "_onMessage ::: "+message );
			onMessage.emit( message );
		}

		function _onMessageFromChannel( chan : String, evt : String, msg : String ) : Void {
			trace( "_onMessageFromChannel ::: "+chan+" on event ::: "+evt+" ::: "+msg );
			onMessageFromChannel.emit( chan, evt, msg );
		}

	// -------o misc

}