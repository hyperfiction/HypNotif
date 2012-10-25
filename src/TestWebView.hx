package ;

import nme.display.Bitmap;
import nme.display.Sprite;
import nme.events.KeyboardEvent;
import nme.events.MouseEvent;
import nme.Lib;
import fr.hyperfiction.HypWebView;
import fr.hyperfiction.HypSystem;

/**
 * ...
 * @author shoe[box]
 */
class TestWebView extends Sprite{
	
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
			haxe.Timer.delay( _run , 500 );
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
			Lib.current.stage.scaleMode = nme.display.StageScaleMode.NO_SCALE;
			Lib.current.stage.align     = nme.display.StageAlign.TOP_LEFT;
			#if mobile
			#if !flash
            nme.display.Stage.shouldRotateInterface = function( inOrientation : Int ) : Bool{
                return true;//( inOrientation == nme.display.Stage.OrientationPortrait );
            };
            #end
        	#end

        	//Lib.current.stage.addEventListener( nme.events.Event.ENTER_FRAME , _onFrame , false);
			Lib.current.stage.addEventListener( KeyboardEvent.KEY_DOWN , _onKey , false );

			HypWebView.open('http://www.hyperfiction.fr/arkeon/rules' , 10 , 10 , 10 , 100 );
		
			
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onFrame( _ ) : Void{
			trace('_onFrame');
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onKey( e : KeyboardEvent ) : Void{
			trace('_onKey ::: '+e.keyCode);
		}

	// -------o misc
		
		public static function main () {
			Lib.current.addChild ( new TestWebView() );		
		}
}