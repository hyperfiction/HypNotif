package ;

import nme.display.Bitmap;
import nme.display.Sprite;
import nme.events.MouseEvent;
import nme.Lib;
import fr.hyperfiction.HypLicensing;

/**
 * ...
 * @author shoe[box]
 */
class TestLicensing extends Sprite{
	
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
			HypLicensing.run( 'MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAhysJ6fmhH/zqbFujSpHazNlpJP38nOKqjdtXj3RwTWK9lZJ9V//eLDmu2dA2x7CXgaNUGEGX2DcELcWH7L9ysoTZHvmrtQ2V3etsPLTQqjI03XevLdAT5qAs1NDB2AnW6Lh1f1V6Rr2wWUbKk/JyUJlVYReero1MV4E2zyM3EpYlbZgnDoyf1ileU+jWYN0QrDO3ETE86eb6kZSN1dEMl1bc/d0IS5+SjWUfEEhc1A44VHoehdc2BO9IjjsA7xE29WZNUirMhv8wUWEBTrONwU+B9L15Xu3tXFnoXDtjeN7ahb1wjiq5X+WN6TweVEg+QgxGZbTc0j/VmPhStuaWVQIDAQAB' );
		}

	// -------o misc
		
		public static function main () {
			Lib.current.addChild ( new TestLicensing() );		
		}
}