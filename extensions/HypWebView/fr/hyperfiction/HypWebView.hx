package fr.hyperfiction;

#if android
import nme.JNI;
#end

#if cpp
import cpp.Lib;
#elseif neko
import neko.Lib;
#end


/**
 * ...
 * @author shoe[box]
 */

class HypWebView{

	#if android
		static private var _func_open	: Dynamic;
		static private var _func_close	: Dynamic;
		static private var _instance	: Dynamic;

		private static inline var ANDROID_CLASS : String = 'fr.hyperfiction.HypWebView';
	#end

	#if iphone
		private static var hyp_webview_open		= Lib.load( "HypWebView" , "HypWebView_open" , 5 );
		private static var hyp_webview_close	= Lib.load( "HypWebView" , "HypWebView_close" , 0 );
	#end

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new() {
			
		}
	
	// -------o public
				
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function open( sUrl : String , iPosX : Int , iPosY : Int , iWidth : Int , iHeight : Int ) : Void {
			trace('open ::: '+sUrl+' - '+iPosX+' - '+iPosY+' - '+iWidth+' - '+iHeight );
			_open( sUrl , iPosX , iPosY , iWidth , iHeight );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function close( ) : Void {
			_close( );		
		}

	// -------o protected
		
		#if iphone
		
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		static private function _open( sUrl : String , iPosX : Int , iPosY : Int , iWidth : Int , iHeight : Int ) : Void{
			hyp_webview_open( sUrl , iPosX , iPosY , iWidth , iHeight );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		static private function _close( ) : Void{
			hyp_webview_close( );
		}

		#end

		#if android

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		static private function _open( sUrl : String , iPosX : Int , iPosY : Int , iWidth : Int , iHeight : Int ) : Void{
			if( _func_open == null )
				_func_open = JNI.createMemberMethod( ANDROID_CLASS ,'open', '(Ljava/lang/String;IIII)V');
				nme.Lib.postUICallback( function( ){
					_func_open( _get_android_instance( ) , sUrl , iPosX , iPosY , iWidth , iHeight );
				});
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		static private function _close( ) : Void{
			if( _func_close == null )
				_func_close = JNI.createMemberMethod( ANDROID_CLASS ,'close', '()V)');
				nme.Lib.postUICallback( function( ){
					_func_close( _get_android_instance( ) );
				});
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		static private function _get_android_instance( ) : Dynamic{

			if( _instance == null ){
				var method = JNI.createStaticMethod( ANDROID_CLASS ,'getInstance', '()Lfr/hyperfiction/HypWebView;');
				_instance = method( );
			}
			return _instance;
		}

		#end

	// -------o misc
	
}