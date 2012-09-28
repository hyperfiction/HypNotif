package ;

import nme.display.Bitmap;
import nme.display.Sprite;
import nme.events.MouseEvent;
import nme.Lib;
import fr.hyperfiction.HypGA;

/**
 * ...
 * @author shoe[box]
 */
class TestGA extends Sprite{
	
	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new() {
			trace('constructor');	
			super( );
			_run( );
		}
	
	// -------o public
		
	// -------o protected
	
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _run( ) : Void{
			trace('run');
			var hypGA = HypGA.getInstance( );
				hypGA.startNewSession('UA-35145689-1' , 1);
				hypGA.trackPageView('/test/tototest');
				hypGA.trackEvent( "j'ai" , 'mangé' , 'une pomme' , 0 );
				hypGA.setCustomVariable( 1 , 'hello' , 'world' );
				
			haxe.Timer.delay( function(){
				hypGA.stopSession( );
			}  , 10000 );
		}

	// -------o misc
		
		public static function main () {
			Lib.current.addChild ( new TestGA() );		
		}
}