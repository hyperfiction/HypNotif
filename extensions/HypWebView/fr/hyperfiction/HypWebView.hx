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

		private static inline var ANDROID_CLASS : String = 'fr/hyperfiction/HypWebView';
	#end

	#if iphone
		private static var hyp_webview_open			= Lib.load( "hypwebview" , "hypwebview_open" 		 , 5 );
		private static var hyp_webview_open_local	= Lib.load( "hypwebview" , "hypwebview_loc" 		 , 5 );
		private static var hyp_webview_close		= Lib.load( "hypwebview" , "hypwebview_close" 		 , 0 );
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
		#if android	
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function open( 
										sUrl	: String , 
										iPosX	: Int , 
										iPosY	: Int , 
										iWidth	: Int , 
										iHeight	: Int 
									) : Void {


			trace("open ::: "+sUrl+" - "+iPosX+" - "+iPosY+" - "+iWidth+" - "+iHeight );

			_open( sUrl , iPosX , iPosY , iWidth , iHeight );
			

		}

		#end

		#if iphone

		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function open( sUrl : String , iMarginL : Int , iMarginT : Int , iMarginR : Int , iMarginB : Int ) : Void {
			trace(Std.format('open url : $sUrl l : $iMarginL t : $iMarginT , r : $iMarginR , b : $iMarginB'));
			hyp_webview_open( sUrl , iMarginL , iMarginT , iMarginR , iMarginB );
		}
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function open_local( 
											sUrl		: String , 
											sExtension	: String , 
											iMarginL	: Int , 
											iMarginT	: Int , 
											iMarginR	: Int , 
											iMarginB	: Int
										):Void{
			
			trace(Std.format('open_local url : $sUrl l : $iMarginL t : $iMarginT , r : $iMarginR , b : $iMarginB'));
			hyp_webview_open_local( sUrl , iMarginL , iMarginT , iMarginR , iMarginB );
		
		}
		#end

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function close( ) : Void {
			
			#if android
			_close( );		
			#end

			#if iphone
			_close( );		
			#end

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
			trace('_open ::: '+Std.format( 'url  : $sUrl x : $iPosX y : $iPosY w : $iWidth h : $iHeight' ) );
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
			_func_open = JNI.createStaticMethod( ANDROID_CLASS ,'open', '(Ljava/lang/String;IIII)V');
			nme.Lib.postUICallback( function( ){
				_func_open( sUrl , iPosX , iPosY , iWidth , iHeight );
			});
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		static private function _close( ) : Void{
			_func_close = JNI.createStaticMethod( ANDROID_CLASS ,'close', '()V)');
			nme.Lib.postUICallback( function( ){
				_func_close( );
			});
		}


		#end

	// -------o misc
	
}