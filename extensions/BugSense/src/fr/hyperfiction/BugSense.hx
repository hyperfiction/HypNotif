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

class BugSense{

	#if android
	static private var _bs_func_run : Dynamic;

	private static inline var ANDROID_CLASS : String = 'fr/hyperfiction/BugSense';
	#end

	#if iphone
	private static var bugsense_run_bugtracker = Lib.load( "BugSense" , "BugSense_run_bugtracker" , 1 );
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
		static public function run( sCode : String ) : Void {
			trace('run ::: '+sCode);
			#if android
			if( _bs_func_run == null )
				_bs_func_run = JNI.createStaticMethod( ANDROID_CLASS , 'run' , '(Ljava/lang/String;)V' );
				_bs_func_run( sCode );		
			#end

			#if iphone
			bugsense_run_bugtracker( sCode );
			#end
		}		

	// -------o protected
	
		

	// -------o misc
	
}