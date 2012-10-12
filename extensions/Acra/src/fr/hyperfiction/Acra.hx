package fr.hyperfiction;

import nme.JNI;

/**
 * ...
 * @author shoe[box]
 */

class Acra{

	#if android
	static private var _acra_func_run : Dynamic;

	private static inline var ANDROID_CLASS : String = 'fr.hyperfiction.HypAcra';
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
			if( _acra_func_run == null )
				_acra_func_run = JNI.createStaticMethod( ANDROID_CLASS , 'run_acra' , '(Ljava/lang/String;)V' );
				_acra_func_run( sCode );		
		}		

	// -------o protected
	
		

	// -------o misc
	
}