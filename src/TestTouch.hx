package ;

import nme.display.Bitmap;
import nme.display.Sprite;
import nme.display.Stage;
import nme.events.MouseEvent;
import nme.events.Event;
import nme.installer.Assets;
import nme.Lib;
import org.shoebox.utils.Perf;
#if mobile
import fr.hyperfiction.HyperTouch;
#end

/**
 * ...
 * @author shoe[box]
 */

class TestTouch extends Sprite{

	private var _spDemo : Sprite;

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
			_spDemo = new Sprite( );
			addChild( _spDemo );
			Lib.current.stage.addEventListener( Event.RESIZE , _onResize , false );
		}
	
	// -------o public
		
	// -------o protected
		
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onResize( _ ) : Void{
			trace('_onResize');
			haxe.Timer.delay( _run , 1000 );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _run( ) : Void{
		
			var bmp = new Sprite( );
				bmp.addChild( new Bitmap( Assets.getBitmapData('assets/logo.png') ));
				bmp.mouseEnabled = true;
				bmp.width = Lib.current.stage.stageWidth;
				bmp.height = Lib.current.stage.stageHeight;
			addChild( bmp );

			#if mobile
			trace('run ::: '+Stage.getOrientation( ));
			var hyp = HyperTouch.getInstance( );
				
				hyp.onSwipe.connect( _onSwipe );
				hyp.onPan.connect( _onPan );
				hyp.onTap.connect( _onTap );
				hyp.onDoubleTap.connect( _onDoubleTap );
				hyp.onTwoFingersTap.connect( _onTap2Fingers );
				
				hyp.allowRotation      = true;
				hyp.allowPinch         = true;
				hyp.allowTap           = true;
				hyp.allowTwoFingersTap = true;

				hyp.addSwipeListener( 1 , HyperTouch.SWIPE_DIRECTION_L );
				hyp.addSwipeListener( 1 , HyperTouch.SWIPE_DIRECTION_R );
				
			#end
			//Lib.current.stage.addEventListener( Event.ENTER_FRAME , _onFrame , false);
			addChild( new Perf( ) );

		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onFrame( _ ) : Void{
			trace( Lib.current.stage.width +' - '+Lib.current.stage.height);
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onSwipe( direction : Int ) : Void{
			trace('onSwipe ::: '+direction);
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onTap( fx : Float , fy : Float ) : Void{
			trace('onTap ::: '+fx+' - '+fy );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onDoubleTap( fx : Float , fy : Float ) : Void{
			trace('_onDoubleTap ::: '+fx+' - '+fy );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onTap2Fingers( fx : Float , fy : Float ) : Void{
			trace('_onTap2Fingers ::: at position'+fx+' - '+fy );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function onRotation( fRotation : Float , fVelocity : Float ) : Void{
			trace('onRotation ::: '+fRotation+' - '+fVelocity );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onPan( fx : Float , fy : Float , fVelocityX : Float , fVelocityY : Float ) : Void{
			trace('onPan ::: '+fx+' - '+fy+' - '+fVelocityX+' - '+fVelocityY );
		}		

	// -------o misc
		
		public static function main () {
			Lib.current.addChild ( new TestTouch() );		
		}
}