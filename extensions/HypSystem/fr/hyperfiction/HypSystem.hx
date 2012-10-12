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
	private static var _fisConnectedtoInternet : Dynamic;

	private static inline var ANDROID_CLASS : String = 'fr/hyperfiction/HypSystem';
	#end


	#if iphone
	private static var isconnected	= Lib.load( "HypSystem" , "HypSystem_isConnectedtoInternet" , 1 );
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