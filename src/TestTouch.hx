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
#end

/**
 * ...
 * @author shoe[box]
 */

class TestTouch extends Sprite{

	private var _spB    : Sprite;
	private var _spDemo : Sprite;
	private var _spL    : Sprite;
	private var _spR    : Sprite;
	private var _spT    : Sprite;
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

			_spL = new Sprite( );
			_spL.visible = false;
			_spL.graphics.beginFill( 0x5ab6f3 );
			_spL.graphics.drawRect( 0 , 0 , 30 , Lib.current.stage.stageHeight );
			_spL.graphics.endFill( );
			addChild( _spL );
			
			_spR = new Sprite( );
			_spR.visible = false;
			_spR.x = Lib.current.stage.stageWidth - 30;
			_spR.graphics.beginFill( 0x5ab6f3 );
			_spR.graphics.drawRect( 0 , 0 , 30 , Lib.current.stage.stageHeight );
			_spR.graphics.endFill( );
			addChild( _spR );

			_spT = new Sprite( );
			_spT.visible = false;
			_spT.graphics.beginFill( 0x5ab6f3 );
			_spT.graphics.drawRect( 0 , 0 , Lib.current.stage.stageWidth , 30 );
			_spT.graphics.endFill( );
			addChild( _spT );

			_spB = new Sprite( );
			_spB.visible = false;
			_spB.graphics.beginFill( 0x5ab6f3 );
			_spB.graphics.drawRect( 0 , 0 , Lib.current.stage.stageWidth , 30 );
			_spB.graphics.endFill( );
			_spB.y = Lib.current.stage.stageHeight - 30;
			addChild( _spB );
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
				hyp.onSwipe.connect( _onSwipe );
				/*
				hyp.onPan.connect( _onPan );
				hyp.onTap.connect( _onTap );
				hyp.onPinch.connect( _onPinch );
				hyp.onDoubleTap.connect( _onDoubleTap );
				hyp.onTwoFingersTap.connect( _onTap2Fingers );
				hyp.onRotation.connect( _onRotation );
				
				hyp.allowRotation      = true;
				hyp.allowPinch         = true;
				hyp.allowTap           = true;
				hyp.allowTwoFingersTap = true;

				hyp.addSwipeListener( 1 , HyperTouch.SWIPE_DIRECTION_LEFT );
				hyp.addSwipeListener( 1 , HyperTouch.SWIPE_DIRECTION_RIGHT );
				hyp.addSwipeListener( 1 , HyperTouch.SWIPE_DIRECTION_UP );
				hyp.addSwipeListener( 1 , HyperTouch.SWIPE_DIRECTION_DOWN );
				hyp.addPanListener( 2 , 2 );
				*/
				
			#end
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
			
			#if mobile
			
			switch ( direction ) {

				case HyperTouch.SWIPE_DIRECTION_LEFT:
					_resetTimer( _timerL);
					_spL.visible = true;
					_timerL = haxe.Timer.delay( function( ){
						_spL.visible = false;
					} , 200 );

				case HyperTouch.SWIPE_DIRECTION_RIGHT:
					_resetTimer( _timerR);					
					_spR.visible = true;
					_timerR = haxe.Timer.delay( function( ){
						_spR.visible = false;
					} , 200 );

				case HyperTouch.SWIPE_DIRECTION_DOWN:
					_resetTimer( _timerB );
					_spB.visible = true;
					_timerB = haxe.Timer.delay( function( ){
						_spB.visible = false;
					} , 200 );

				case HyperTouch.SWIPE_DIRECTION_UP:
					_resetTimer( _timerT );
					_spT.visible = true;
					_timerT = haxe.Timer.delay( function( ){
						_spT.visible = false;
					} , 200 );
			}
			#end
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

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onTap( fx : Float , fy : Float ) : Void{
			trace('onTap ::: '+fx+' - '+fy );
			_spTap.graphics.clear( );
			_spTap.graphics.lineStyle( 4 , 0 );
			_spTap.graphics.drawCircle( fx , fy , 40 );
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
		private function _onRotation( fRotation : Float , fVelocity : Float ) : Void{
			_spDemo.rotation = fRotation * org.shoebox.core.BoxMath.RAD_TO_DEG;
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onPinch( fScale : Float , fVelocity : Float ) : Void{
			_spDemo.scaleX = fScale;
			_spDemo.scaleY = fScale;
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onPan( fx : Float , fy : Float , fVelocityX : Float , fVelocityY : Float ) : Void{
			_spDemo.x = fx;
			_spDemo.y = fy;
		}		

	// -------o misc
		
		public static function main () {
			Lib.current.addChild ( new TestTouch() );		
		}
}