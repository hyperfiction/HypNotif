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

import fr.hyperfiction.events.HypFoxEvent;
import fr.hyperfiction.events.HypFoxMessageEvent;
import fr.hyperfiction.events.HypFoxUserEvent;

import org.shoebox.utils.system.Signal1;
import org.shoebox.utils.system.Signal2;


/**
* 
* @author LouisBL
*/

class HypFox extends EventDispatcher {
	
	#if android	
		public static inline var ANDROID_CLASS : String = 'fr/hyperfiction/HypFox';
		
		private var _hyp_create		: Dynamic;
		private var _hyp_instance	: Dynamic;
		
		private var _hyp_connect				: Dynamic;
		private var _hyp_connect_port			: Dynamic;
		private var _hyp_set_zone				: Dynamic;
		private var _hyp_set_lobby				: Dynamic;
		private var _hyp_send_private_message	: Dynamic;
		private var _hyp_find_user				: Dynamic;
		private var _hyp_find_user2				: Dynamic;
	#end

	#if mobile
		private static var hyp_cb_connection		= Lib.load( "hypfox", "hyp_cb_connection", 1 );
		private static var hyp_cb_connection_lost	= Lib.load( "hypfox", "hyp_cb_connection_lost", 1 );
		private static var hyp_cb_login				= Lib.load( "hypfox", "hyp_cb_login", 1 );
		private static var hyp_cb_room_join			= Lib.load( "hypfox", "hyp_cb_room_join", 1 );
		private static var hyp_cb_private_message	= Lib.load( "hypfox", "hyp_cb_private_message", 1 );
		private static var hyp_cb_user_found		= Lib.load( "hypfox", "hyp_cb_user_found", 1 );
	#end

	public var onUserFound : Signal1<Int>;
	public var onPm : Signal2<String,Int>;

	// -------o constructor

		/**
		* Constructor
		*
		* @public
		* @return	void
		*/
		public function new() : Void {
			super();
			onUserFound = new Signal1<Int>( );
			onPm = new Signal2<String,Int>( );

			#if android
				hyp_cb_connection( _onConnection );
				hyp_cb_connection_lost( _onConnectionLost );
				hyp_cb_login( _onLogin );
				hyp_cb_room_join( _onRoomJoin );
				hyp_cb_private_message( _onPrivateMessage );
				hyp_cb_user_found( _onUserFound );

				/*
				if( _hyp_create == null )
					_hyp_create = JNI.createStaticMethod( ANDROID_CLASS , 'createInstance' , "()Lfr/hyperfiction/HypFox;" );
					
				_hyp_instance = _hyp_create( );
				*/
			#end
		}


	// -------o public

		public function connectToServer( ip : String ) : Void {
			#if android
				if( _hyp_connect == null )
					_hyp_connect = JNI.createStaticMethod( ANDROID_CLASS, 'sf_connectToServer', "(Ljava/lang/String;)V");
					_hyp_connect( ip );
			#end
		}

		public function connectToServerWithPort( ip : String, port : Int ) : Void {
			#if android
				if( _hyp_connect_port == null )
					_hyp_connect_port = JNI.createStaticMethod( ANDROID_CLASS, 'sf_connectToServer', "(Ljava/lang/String;I)V");
					_hyp_connect_port( ip, port );
			#end
		}

		public function setZone( zone : String ) : Void {
			#if android
				if( _hyp_set_zone == null )
					_hyp_set_zone = JNI.createStaticMethod( ANDROID_CLASS, 'sf_setZone', "(Ljava/lang/String;)V" );
					_hyp_set_zone( zone );
			#end
		}

		public function setLobby( lobby : String ) : Void {
			#if android
				if( _hyp_set_lobby == null )
					_hyp_set_lobby = JNI.createStaticMethod( ANDROID_CLASS, 'sf_setLobby', "(Ljava/lang/String;)V" );
					_hyp_set_lobby( lobby );
			#end
		}

		public function sendPrivateMessage( msg : String, id : Int ) : Void {
			trace('sendPrivateMessage ::: '+msg+' to user id : '+id);
			#if android
				if( _hyp_send_private_message == null )
					_hyp_send_private_message = JNI.createStaticMethod( ANDROID_CLASS, 'sf_sendPrivateMessage', "(Ljava/lang/String;I)V" );
					_hyp_send_private_message( msg, id );
			#end
		}
		
		public function findUserByCode( code : Int ) : Void {
			#if android
				if( _hyp_find_user == null )
					_hyp_find_user = JNI.createStaticMethod( ANDROID_CLASS, 'sf_findUserByCode', "(I)V" );
					_hyp_find_user( code );
			#end
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function get_userid_from_name( sRoom : String , s : String ) : Int {
			var res = -1;
			#if android
				if( _hyp_find_user2 == null )
					_hyp_find_user2 = JNI.createStaticMethod( ANDROID_CLASS, 'sf_findUserByName', "(Ljava/lang/String;Ljava/lang/String;)I" );
				res = _hyp_find_user2( sRoom , s );
			#end

			return res;
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function disconnect( ) : Void {
			#if android
			var fDeco = JNI.createStaticMethod( ANDROID_CLASS, 'sf_deco', "()V" );		
				fDeco( );
			#end
		}
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		override public function dispatchEvent( e : Event ) : Bool {
			trace('dispatchEvent ::: '+e);
			return super.dispatchEvent( e );		
		}

	// -------o protected

		function _onConnection( success : Bool ) : Void {
			trace( "on connection ::: "+success);
			dispatchEvent( new HypFoxEvent( HypFoxEvent.CONNECTION, success ) ); 
		}

		function _onConnectionLost() : Void {
			trace( "on connection lost" );
			dispatchEvent( new HypFoxEvent( HypFoxEvent.CONNECTION_LOST, true ) ); 
		}

		function _onLogin() : Void {
			trace( "on login" );
			dispatchEvent( new HypFoxEvent( HypFoxEvent.LOGIN, true ) ); 
		}

		function _onRoomJoin() : Void {
			trace( "on room join" );
			dispatchEvent( new HypFoxEvent( HypFoxEvent.ROOM_JOIN, true ) ); 
		}

		function _onPrivateMessage( msg : String, id : Int ) : Void {
			trace( "private message ::: "+msg+" from ::: "+id );
			trace('onPm ::: '+onPm);
			//dispatchEvent( new HypFoxMessageEvent( HypFoxMessageEvent.PRIVATE_MESSAGE, msg, id) ); 
			onPm.emit( msg , id );
		}

		function _onUserFound( id : Int ) : Void {
			trace( "user found ::: "+id );
			//dispatchEvent( new HypFoxUserEvent( HypFoxUserEvent.USER_FOUND, id) ); 
			onUserFound.emit( id );
		}

	// -------o misc

}