package fr.hyperfiction;

import nme.JNI;
#if cpp
import cpp.Lib;
#elseif neko
import neko.Lib;
#end
/**
 * ...
 * @author shoe[box]
 */

class HypSystem{

	#if android
	private static var _f_dismiss_loading		: Dynamic;
	private static var _f_hide_loading			: Dynamic;
	private static var _f_hide_system_bar		: Dynamic;
	private static var _f_is_iphone				: Dynamic;
	private static var _f_show_dialog			: Dynamic;
	private static var _f_show_loading			: Dynamic;
	private static var _fisConnectedtoInternet	: Dynamic;
	private static var _f_screen_bucket			: Dynamic;
	private static var _f_lights_out			: Dynamic;

	private static inline var ANDROID_CLASS : String = 'fr/hyperfiction/HypSystem';
	#end


	#if iphone
	private static var isconnected			= Lib.load( "HypSystem" , "HypSystem_isConnectedtoInternet" , 1 );
	private static var isiphone				= Lib.load( "HypSystem" , "HypSystem_is_iphone" , 0 );
	private static var hyp_webview_screen_w	= Lib.load( "HypSystem" , "HypSystem_screen_width"  , 0 );
	private static var hyp_webview_screen_h	= Lib.load( "HypSystem" , "HypSystem_screen_height" , 0 );
	private static var hyp_system_lang		= Lib.load( "HypSystem" , "HypSystem_get_system_lang" , 0 );
	#end

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		private function new() {
			
		}
	
	// -------o public
			
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function isConnected( ) : Bool {
			
			#if iphone
			return _isConnected( );
			#end	

			#if android
			return _isConnected( );
			#end	

			return true;
		}	

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function show_error_dialog( sText : String ) : Void {
			#if android
			_show_error_dialog( sText );
			#end		
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function get_system_language( ) : String {

			var s = 'unknow';
			#if android
			s = _get_system_language( );
			#end

			#if iphone
			s = hyp_system_lang( );			
			#end

			return s;

		}
		
		

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function isSmartPhone( ) : Bool {
			#if iphone
			return isiphone( );	
			#end

			#if android
			return JNI.createStaticMethod( ANDROID_CLASS , 'is_a_phone' , '()Z' )( );
			#end
		}
		
		#if iphone

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function get_screen_width( ) : Int {
			return hyp_webview_screen_w( );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function get_screen_height( ) : Int {
			return hyp_webview_screen_h( );
		}

		#end

		#if android

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function get_screen_bucket( ) : String {
			if( _f_screen_bucket == null )
				_f_screen_bucket = JNI.createStaticMethod( ANDROID_CLASS , 'get_screen_bucket' , '()Ljava/lang/String;' );
			return _f_screen_bucket( );	
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function show_loading( ) : Void {
			trace("show_loading");

			#if android
			if( _f_show_loading == null )
				_f_show_loading = JNI.createStaticMethod( ANDROID_CLASS , 'show_loading' , '()V' );
				_f_show_loading();
			#end
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function hide_loading( ) : Void {
			trace("hide_loading");
			#if android
			if( _f_hide_loading == null )
				_f_hide_loading = JNI.createStaticMethod( ANDROID_CLASS , 'hide_loading' , '()V' );
				_f_hide_loading();
			#end
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function dismiss_loading( ) : Void {
			trace("dismiss_loading");
			#if android
			if( _f_dismiss_loading == null )
				_f_dismiss_loading = JNI.createStaticMethod( ANDROID_CLASS , 'dismiss_loading' , '()V' );
				_f_dismiss_loading();		
			#end
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		static private function _show_error_dialog( sText : String ) : Void{
			trace('_show_error_dialog ::: '+sText);
			#if android
			if( _f_show_dialog == null )
				_f_show_dialog = JNI.createStaticMethod( ANDROID_CLASS , 'show_error_dialog' , '(Ljava/lang/String;)V' );
				_f_show_dialog( sText );		
			#end
		}

		#end

	// -------o protected
		
		#if android

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		static private function _isConnected( ) : Bool{
			trace('isConnectedtoInternet');
			if( _fisConnectedtoInternet == null )
				_fisConnectedtoInternet = JNI.createStaticMethod( ANDROID_CLASS , 'isConnectedtoInternet' , '()Z' );

			return _fisConnectedtoInternet();
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		static private function _get_system_language( ) : String{
			return JNI.createStaticMethod( ANDROID_CLASS , 'get_system_language' , '()Ljava/lang/String;' )();
		}

		#end

		#if iphone
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		static private function _isConnected( ) : Bool{
			trace('_isConnected ::: ');
			return isconnected( 'http://www.hyperfiction.fr');
		}
		#end

	// -------o misc
	
}