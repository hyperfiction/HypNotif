package fr.hyperfiction;

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
		public function init( app_id : String ) : Void {
			_init( app_id );	
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function connect( ) : Void {

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
		}

	// -------o protected
	
		

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _init( sAppId : String ) : Void{
			
			_sAppID = sAppId;

			//
				#if iphone
				hyp_fb_init( _sAppID );
				#end
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _connect( ) : Void{

			//
				#if iphone
				hypfb_set_callback( _onCallback );
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
			var type = Type.createEnum( FbCallback , sType );
			switch( Type.createEnum( FbCallback , sType ) ){
				
				case ON_LOGIN:
					session_token = arg;
					_bConnected = true;
					onConnect.emit( session_token );
					trace('onLogin ::: token : '+session_token );

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
}