package fr.hyperfiction;

#if android
import nme.JNI;
#end

import nme.errors.Error;
import org.shoebox.utils.system.Signal1;

/**
 * ...
 * @author shoe[box]
 */

class Facebook{

	public var session_token( default , default ) : String;
	public var app_id( default , default ) : String;

	public var onConnect : Signal1<String>;

	private var _sAppID            : String;
	private var _bConnected        : Bool;
	private var _sFb_session_token : String;

	#if iphone
	static var hyp_fb_init               = nme.Loader.load( "hyp_fb_init" , 1 );
	static var hypfb_connect             = nme.Loader.load( "hyp_fb_connect" , 0 );
	static var hypfb_set_callback        = nme.Loader.load( "hypfb_set_callback" , 1 );
	static var hyp_fb_apprequest         = nme.Loader.load( "hyp_fb_apprequest" , 2 );
	static var hyp_fb_apprequest_to_user = nme.Loader.load( "hyp_fb_apprequest_to_user" , 3 );
	static var hyp_fb_feed 				 = nme.Loader.load( "hypfb_feed" , 5 );
	#end

	#if android
	static private var hyp_fb_init   : Dynamic;
	static private var hypfb_connect : Dynamic;
	static private var hypfb_feed    : Dynamic;
	static private var hypfb_request : Dynamic;
	
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
			onConnect = new Signal1<String>( );
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
		public function appRequest( sTitle : String , sMessage , toUser : String = null ) : Void {
			#if iphone
				if( toUser != null )
					hyp_fb_apprequest( sTitle , sMessage );
				else
					hyp_fb_apprequest_to_user( sTitle , sMessage , toUser);
			#else
				if( hypfb_request == null )
					hypfb_request = JNI.createStaticMethod( 'fr.hyperfiction.HypFacebook' , 'hypfb_apprequest' , "(Ljava/lang/String;Ljava/lang/String;)V" );
					hypfb_request( sTitle , sMessage );
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
			#else
				if( hypfb_feed == null )
					hypfb_feed = JNI.createStaticMethod( 'fr.hyperfiction.HypFacebook' , 'hypfb_feed' , "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V" );
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
			/*
			trace('generateKeyHash ::: '+sPackageName);
			var hyp_key : Dynamic = JNI.createStaticMethod( 'fr.hyperfiction.HypFacebook' , 'hypfb_key_hash' , "(Ljava/lang/String;)V" );
				hyp_key( sPackageName );
			*/
		}
		
		#end

	// -------o protected
	
		

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
			#else

				if( hyp_fb_init == null )
					hyp_fb_init = JNI.createStaticMethod( 'fr.hyperfiction.HypFacebook' , 'hypfb_init' , "(Ljava/lang/String;Lorg/haxe/nme/HaxeObject;Ljava/lang/String;)V" );
					nme.Lib.postUICallback( 
											function() { 
												hyp_fb_init( _sAppID , this , aPerms.join('|') );
											});
				
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
			#if iphone
				hypfb_set_callback( _onCallback );
				hypfb_connect( );
			#else

				if( hypfb_connect == null )
					hypfb_connect = JNI.createStaticMethod( 'fr.hyperfiction.HypFacebook' , 'hypfb_connect' , "()V" );
					nme.Lib.postUICallback( function() { 
						hypfb_connect( );
					});
				
			#end
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onCallback( sType : String , arg = null ) : Void{
			trace('_onCallback ::: '+sType+' - '+arg);
			var type = Type.createEnum( FbCallback , sType );
			switch( Type.createEnum( FbCallback , sType ) ){
				
				case ON_LOGIN:
					session_token = arg;
					_bConnected = true;
					onConnect.emit( session_token );
				
				case ON_ERROR:
					trace('ON_ERROR ::: '+arg );

				case ON_FACEBOOK_ERROR:
					trace('ON_FACEBOOK_ERROR ::: '+arg );

				case ON_CANCEL:
					trace('ON_CANCEL ::: '+arg );
			}
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