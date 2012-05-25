package ;

import nme.display.Bitmap;
import nme.display.Sprite;
import nme.events.MouseEvent;
import nme.Lib;
import fr.hyperfiction.Facebook;

/**
 * ...
 * @author shoe[box]
 */

class TestFacebook extends Sprite{

	private static var hyp_fb_connect : Dynamic;
	private static var hyp_fb_init : Dynamic;

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

			var fb = Facebook.getInstance( );
				fb.init('397904743584044');
				fb.onConnect.connect( _on_fb_connected );
				fb.connect( );
			trace( fb );
			
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _on_fb_connected( sToken : String ) : Void{
			trace('_on_fb_connected ::: '+sToken);
			//Facebook.getInstance( ).appRequest('Hello','World','100');
			Facebook.getInstance( ).feed( 'Hello World title' , 'hello world caption' , 'description de test' , 'http://www.hyperfiction.fr','http://hyperfiction.fr/LogoHyperfiction.png');
		}

	// -------o misc
		
		public static function main () {
			Lib.current.addChild ( new TestFacebook() );		
		}
}