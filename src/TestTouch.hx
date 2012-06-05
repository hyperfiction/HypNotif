package ;

import haxe.Timer;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.display.Stage;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.events.MouseEvent;
import nme.events.Event;
import nme.installer.Assets;
import nme.Lib;
import org.shoebox.utils.Perf;

#if mobile
import fr.hyperfiction.HyperTouch;
import fr.hyperfiction.events.GesturePanEvent;
import fr.hyperfiction.events.GesturePinchEvent;
import fr.hyperfiction.events.GestureRotationEvent;
import fr.hyperfiction.events.GestureSwipeEvent;
import fr.hyperfiction.events.GestureTapEvent;
#end

/**
 * ...
 * @author shoe[box]
 */

class TestTouch extends Sprite{

	private var _spDemo : Sprite;
	private var _spTap  : Sprite;

	private var _timerL : Timer;
	private var _timerR : Timer;
	private var _timerT : Timer;
	private var _timerB : Timer;

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

			Lib.current.stage.scaleMode = StageScaleMode.NO_SCALE;
			Lib.current.stage.align = StageAlign.TOP_LEFT;
			#if iphone
			Lib.current.stage.addEventListener( Event.RESIZE , _onResize , false );
			#else
			_onResize( );
			#end
		}
	
	// -------o public
		
	// -------o protected
		
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onResize( e : Event = null ) : Void{
			trace('_onResize');
			
			#if mobile
			Stage.shouldRotateInterface = function( inOrientation : Int ) : Bool{
				return ( inOrientation == Stage.OrientationLandscapeRight || inOrientation == Stage.OrientationLandscapeLeft );
			};
			#end

			Lib.current.stage.removeEventListener( Event.RESIZE , _onResize , false );
			haxe.Timer.delay( _run , 1000 );

			var size = Math.min( Lib.current.stage.stageWidth , Lib.current.stage.stageHeight );
				size *= 0.3;

			_spDemo = new Sprite( );
			_spDemo.graphics.beginFill( 0xFF6600 );
			_spDemo.graphics.drawRect( -size , -size , size * 2 , size * 2 );
			_spDemo.graphics.endFill( );
			_spDemo.x = Lib.current.stage.stageWidth / 2;
			_spDemo.y = Lib.current.stage.stageHeight / 2;
			addChild( _spDemo );

			_spTap = new Sprite( );
			addChild( _spTap );

		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _run( ) : Void{
			
			Lib.current.stage.addEventListener( MouseEvent.CLICK , function( _ ) {trace('onClick');} , false );

			#if mobile
			var hyp = HyperTouch.getInstance( );
				hyp.addEventListener( GesturePanEvent.PAN , _onPan , false );
				hyp.addEventListener( GesturePinchEvent.PINCH , _onPinch , false );
				hyp.addEventListener( GestureRotationEvent.ROTATE , _onRotation , false );
				hyp.addEventListener( GestureSwipeEvent.SWIPE , _onSwipe , false );
				hyp.addEventListener( GestureTapEvent.TAP , _onTap , false );
				hyp.addEventListener( GestureTapEvent.TWO_FINGERS_TAP , _onTwoFingers , false );
				hyp.addEventListener( GestureTapEvent.DOUBLE_TAP , _onDoubleTap , false );

				hyp.allowRotation      = true;
				hyp.allowPinch         = true;
				hyp.allowTap           = true;
				hyp.allowTwoFingersTap = true;

				#if iphone
				hyp.addSwipeListener( 1 , HyperTouch.SWIPE_DIRECTION_LEFT );
				hyp.addSwipeListener( 1 , HyperTouch.SWIPE_DIRECTION_RIGHT );
				hyp.addSwipeListener( 1 , HyperTouch.SWIPE_DIRECTION_UP );
				hyp.addSwipeListener( 1 , HyperTouch.SWIPE_DIRECTION_DOWN );
				hyp.addPanListener( 2 , 2 );
				#end
			#end
			//addChild( new Perf( ) );
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
		private function _resetTimer( t : Timer ) : Void{
			if( t == null )
				return;
			t.stop( );
		}

		#if mobile

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onPan( e : GesturePanEvent ) : Void{
			trace('onPan ::: '+e);
			_spDemo.x = e.x;
			_spDemo.y = e.y;
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onPinch( e : GesturePinchEvent ) : Void{
			trace('onPinch ::: '+e);
			_spDemo.scaleY = _spDemo.scaleX = e.scale;
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onRotation( e : GestureRotationEvent ) : Void{
			_spDemo.rotation = e.rotation * org.shoebox.core.BoxMath.RAD_TO_DEG;
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onSwipe( e : GestureSwipeEvent ) : Void{
			trace('onSwipe ::: '+e);
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onTap( e : GestureTapEvent ) : Void{
			trace('onTap ::: '+e);
			_spTap.graphics.clear( );
			_spTap.graphics.lineStyle( 4 , 0 );
			_spTap.graphics.drawCircle( e.x , e.y , 40 );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onTwoFingers( e : GestureTapEvent ) : Void{
			_spDemo.rotation = 0;
			_spDemo.scaleX = _spDemo.scaleY = 1;
			_spDemo.x = Lib.current.stage.stageWidth / 2;
			_spDemo.y = Lib.current.stage.stageHeight / 2;
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onDoubleTap( e : GestureTapEvent ) : Void{
			trace('onDoubleTap ::: '+e);
		}

		#end

	// -------o misc
		
		public static function main () {
			Lib.current.addChild ( new TestTouch() );		
		}
}