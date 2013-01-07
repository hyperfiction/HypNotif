package fr.hyperfiction;


#if android
import nme.JNI;
#end

#if cpp
import cpp.Lib;
#end

import nme.events.EventDispatcher;
import nme.errors.Error;
import nme.events.Event;
import org.shoebox.utils.system.Signal1;

/**
 * ...
 * @author shoe[box]
 */

class Facebook extends EventDispatcher{

	public var session_token	( default , default ) : String;
	public var app_id			( default , default ) : String;

	public var onConnect : Signal1<String>;

	private var _sAppID            : String;
	private var _bConnected        : Bool;
	private var _sFb_session_token : String;

	#if mobile
	static var hypfb_set_callback = Lib.load( "fb" , "hyp_fb_set_callback" , 1 );
	#end

	#if iphone
	static var hyp_fb_init               = nme.Loader.load( "hyp_fb_init" , 1 );
	static var hypfb_connect             = nme.Loader.load( "hyp_fb_connect" , 0 );
	static var hyp_fb_apprequest         = nme.Loader.load( "hyp_fb_apprequest" , 2 );
	static var hyp_fb_apprequest_to_user = nme.Loader.load( "hyp_fb_apprequest_to_user" , 3 );
	static var hyp_fb_feed 				 = nme.Loader.load( "hypfb_feed" , 5 );
	#end

	#if android
	static private var hypfb_app_request	: Dynamic;
	static private var hypfb_request		: Dynamic;
	static private var hypfb_connect		: Dynamic;
	static private var hypfb_feed			: Dynamic;
	static private var hypfb_get_instance	: Dynamic;
	static private var hypfb_init			: Dynamic;
	static private var hypfb_token			: Dynamic;

	static private var __java_instance : Dynamic;
	
	public static inline var ANDROID_CLASS : String = 'fr.hyperfiction.HypFacebook';
	#end


	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		private function new( ) {
			trace('constructor');
			super( );
		}
	
	// -------o public
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function init( app_id : String , aPerms : Array<String> = null ) : Void {

			if( aPerms == null )
				aPerms = [ ];

			#if android
			__java_instance = _get_java_instance( );
			#end

			_init( app_id , aPerms );	
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function connect( ) : Void {
			trace('connect');
			if( _sAppID == null )
				throw new Error( "Facebook App ID is not defined" );

			#if mobile
			_connect(  );
			#end
		}	

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function request( sGraphPath : String ) : String {

			var sRes : String = null;
			#if android
				if( hypfb_request == null )
					hypfb_request = JNI.createStaticMethod( ANDROID_CLASS , 'request' , "(Ljava/lang/String;)Ljava/lang/String;" );
					sRes = hypfb_request( sGraphPath );
				
			#end
			
			return sRes;

		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function appRequest( sTitle : String , sMessage , toUser : String = null ) : Void {

			#if iphone
				if( toUser != null )
					hyp_fb_apprequest( sTitle , sMessage );
				else
					hyp_fb_apprequest_to_user( sTitle , sMessage , toUser);
			#end

			#if android
				if( hypfb_app_request == null )
					hypfb_app_request = JNI.createMemberMethod( ANDROID_CLASS , 'fbAppRequest' , "(Ljava/lang/String;Ljava/lang/String;)V" );
					hypfb_app_request( __java_instance , sTitle , sMessage );
			#end
			
		}	

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function feed( 
								sTitle       : String , 
								sCaption     : String , 
								sDescription : String , 
								sLink        : String , 
								sPictureUrl  : String 
							) : Void {
			#if iphone
				hyp_fb_feed( sTitle , sCaption , sDescription , sLink , sPictureUrl );
			#end

			#if android
				if( hypfb_feed == null )
					hypfb_feed = JNI.createStaticMethod( ANDROID_CLASS , 'hypfb_feed' , "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V" );
					hypfb_feed( sTitle , sCaption , sDescription , sLink , sPictureUrl );
											
			#end
		}

		#if android

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function generateKeyHash( sPackageName : String ) : Void {
			
			var hyp_key : Dynamic = JNI.createStaticMethod( ANDROID_CLASS , 'hypfb_key_hash' , "(Ljava/lang/String;)V" );
				hyp_key( sPackageName );
			
		}
		
		#end

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function get_token( ) : String {
			
			var sRes : String = null;

			#if android
				if( hypfb_token == null )
					hypfb_token = JNI.createStaticMethod( ANDROID_CLASS , 'get_token' , "()Ljava/lang/String;" );
				
				sRes = hypfb_token( );
			#end

			return sRes;

		}

	// -------o protected
		
		#if android
		
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _get_java_instance( ) : Dynamic{
			trace('_get_java_instance');
			if( __java_instance != null )
				return __java_instance;

			if( hypfb_get_instance == null )
				hypfb_get_instance = JNI.createStaticMethod( 
																ANDROID_CLASS , 
																'getInstance' , 
																"()Lfr/hyperfiction/HypFacebook;" 
															);
			
			return hypfb_get_instance( );
			
		}

		#end

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _init( sAppId : String , aPerms : Array<String> ) : Void{
			trace( 'init ::: ' + sAppId );
			_sAppID = sAppId;

			#if iphone
				hyp_fb_init( _sAppID );
			#end

			#if android
				
				if( hypfb_init == null )
					hypfb_init = JNI.createStaticMethod( 
															ANDROID_CLASS , 
															'init' , 
															"(Ljava/lang/String;Lorg/haxe/nme/HaxeObject;Ljava/lang/String;)V" 
														);
					hypfb_init( _sAppID , this , aPerms.join('|') );
				
			#end
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _connect( ) : Void{
			trace('connect');
			//

			#if mobile
				hypfb_set_callback( _on_connected );
				trace('hypfb_set_callback ::: '+hypfb_set_callback);
			#end

			#if iphone
				hypfb_connect( );
			#end

			#if android
				if( hypfb_connect == null )
					hypfb_connect = JNI.createStaticMethod( ANDROID_CLASS , 'connect' , "()V" );
					hypfb_connect( );
				
				
			#end
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onCallback( sType : String , arg = null ) : Void{
			trace('_onCallback ::: '+sType+' - '+arg );
			var type = Type.createEnum( FbCallback , sType );
			switch( Type.createEnum( FbCallback , sType ) ){
				
				case ON_LOGIN:
					trace('ON_LOGIN');
					session_token = arg;
					_bConnected = true;
					trace('emit');
					//onConnect.emit( session_token );
					dispatchEvent( new Event( Event.CONNECT ) );
				
				case ON_ERROR:
					trace('ON_ERROR ::: '+arg );

				case ON_FACEBOOK_ERROR:
					trace('ON_FACEBOOK_ERROR ::: '+arg );

				case ON_CANCEL:
					trace('ON_CANCEL ::: '+arg );
			}
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _on_connected( ) : Void{
			trace('_on_connected ');
			dispatchEvent( new Event( Event.CONNECT ) );
		}

	// -------o misc
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function getInstance( ) : Facebook {
			if( __instance == null )
				__instance = new Facebook( );

			return __instance;
		}

		private static var __instance : Facebook = null;
}

enum FbCallback{
	ON_LOGIN;
	ON_ERROR;
	ON_CANCEL;
	ON_FACEBOOK_ERROR;
}