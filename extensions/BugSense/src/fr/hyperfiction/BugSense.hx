package fr.hyperfiction;

import nme.JNI;

/**
 * ...
 * @author shoe[box]
 */

class BugSense{

	#if android
	static private var _bs_func_run : Dynamic;

	private static inline var ANDROID_CLASS : String = 'fr.hyperfiction.BugSense';
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
			if( _bs_func_run == null )
				_bs_func_run = JNI.createStaticMethod( ANDROID_CLASS , 'run' , '(Ljava/lang/String;)V' );
				_bs_func_run( sCode );		
		}		

	// -------o protected
	
		

	// -------o misc
	
}