package fr.hyperfiction;

#if android
import nme.JNI;
#end

#if cpp
import cpp.Lib;
#elseif neko
import neko.Lib;
#end

import fr.hyperfiction.events.GesturePanEvent;
import fr.hyperfiction.events.GesturePinchEvent;
import fr.hyperfiction.events.GestureRotationEvent;
import fr.hyperfiction.events.GestureSwipeEvent;
import fr.hyperfiction.events.GestureTapEvent;
import nme.Lib;
import nme.Memory;
import nme.display.Stage;
import nme.errors.Error;
import nme.events.EventDispatcher;
import org.shoebox.geom.FPoint;

/**
 * ...
 * @author shoe[box]
 */

class HyperTouch extends EventDispatcher{

	public var allowDoubleTap( default , _setAllowDoubleTap ) : Bool;
	public var allowPinch( default , _setAllowPinch )  : Bool;
	public var allowRotation( default , _setAllowRot ) : Bool;
	public var allowTap( default , _setAllowTap ) : Bool;
	public var allowTwoFingersTap( default , _setAllowTwixTap ) : Bool;
	
	public static inline var SWIPE_DIRECTION_RIGHT : Int = 1;
	public static inline var SWIPE_DIRECTION_LEFT  : Int = 2;
	public static inline var SWIPE_DIRECTION_UP    : Int = 4;
	public static inline var SWIPE_DIRECTION_DOWN  : Int = 8;

	#if mobile
	private static var hyp_touch_callback_pan      = Lib.load ( "hypertouch" , "hyp_touch_callback_pan", 1);
	private static var hyp_touch_callback_pinch    = Lib.load ( "hypertouch" , "hyp_touch_callback_pinch", 1);
	private static var hyp_touch_callback_rotation = Lib.load ( "hypertouch" , "hyp_touch_callback_rotation", 1);
	private static var hyp_touch_callback_swipe    = Lib.load ( "hypertouch" , "hyp_touch_callback_swipe", 1);
	private static var hyp_touch_callback_tap      = Lib.load ( "hypertouch" , "hyp_touch_callback_tap", 1);
	#end

	#if iphone
	static var hypTouch_init             = nme.Loader.load( "hyp_touch_init" , 0 );
	static var hyp_touch_add_pan         = nme.Loader.load( "hyp_touch_add_pan" , 2 );
	static var hyp_touch_add_pinch       = nme.Loader.load( "hyp_touch_add_pinch" , 0 );	
	static var hyp_touch_add_rot         = nme.Loader.load( "hyp_touch_add_rot" , 0 );
	static var hyp_touch_add_swipe       = nme.Loader.load( "HypTouch_addSwipe" , 2 );
	static var hyp_touch_add_tap         = nme.Loader.load( "HypTouch_addTap" , 2 );
	static var hyp_touch_get_orientation = nme.Loader.load( "HypTouch_get_orientation" , 0 );
	static var hyp_touch_rem_pan         = nme.Loader.load( "hyp_touch_remove_pan" , 2 );
	static var hyp_touch_rem_pinch       = nme.Loader.load( "hyp_touch_remove_pinch" , 0 );
	static var hyp_touch_rem_rot         = nme.Loader.load( "hyp_touch_remove_rot" , 0 );
	static var hyp_touch_rem_swipe       = nme.Loader.load( "HypTouch_removeSwipe" , 2 );
	static var hyp_touch_rem_tap         = nme.Loader.load( "HypTouch_removeTap" , 2 );
	#end

	#if android
	//static private var hypfb_request : Dynamic;
	public static inline var ANDROID_CLASS : String = 'fr.hyperfiction.HyperTouch';

	static private var hyp_touch_init : Dynamic;
	#end

	public static inline var PAN      : String = 'PAN';
	public static inline var PINCH    : String = 'PINCH';
	public static inline var ROTATION : String = 'ROTATION';
	public static inline var SWIPE    : String = 'SWIPE';
	public static inline var TAP      : String = 'TAP';

	private var _fTmp : FPoint;

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		private function new( ) {
			trace('constructor');
			super( );

			#if iphone
			hypTouch_init( );
			#end

			#if mobile
			hyp_touch_callback_pan( _onPanCallback );
			hyp_touch_callback_pinch( _onPinchCallback );
			hyp_touch_callback_rotation( _onRotCallback );
			hyp_touch_callback_swipe( _onSwipeCallback );
			hyp_touch_callback_tap( _onTapCallback );
			#end

			#if android
			
			//Initialize
				if( hyp_touch_init == null )
					hyp_touch_init = JNI.createStaticMethod( 'fr.hyperfiction.HyperTouch' , 'HyperTouch_init' , "()V" );
				nme.Lib.postUICallback( 
										function() { 
											trace('postUICallback 1');
											hyp_touch_init( );	
										});
			
				
			
			#end

			_fTmp = { x : 0.0 , y : 0.0 };
		}
	
	// -------o public

		#if iphone

		/**
		* Add a Tap listener
		* 
		* @public
		* @param 	iFingers : Fingers Count 	( int )
		* @param 	iTaps    : Taps Count 		( int )
		* @return	boolean
		*/
		public function addCustomTapListener( iFingers : Int , iTaps : Int ) : Bool {
			return hyp_touch_add_tap( iFingers , iTaps );
		}

		/**
		* Remove a Tap Listener
		* 
		* @public
		* @param 	fingersCount 	: Simultaneous fingers needed 	( int )
		* @param 	tapsCount 		: Taps count needed 			( int )
		* @return	boolean
		*/
		public function removeTapListener( fingersCount : Int , tapsCount : Int ) : Bool {
			return hyp_touch_rem_tap( fingersCount , tapsCount );
		}

		/**
		* Add a Swipe Listener witht the specififed FingersCount / Direction
		* 
		* @public
		* @param 	fingersCount 	: Simultaneous fingers needed ( int )
		* @param 	direction : Direction of the Swipe ( int )
		* @return	boolean;
		*/
		public function addSwipeListener( fingersCount : Int , direction : Int ) : Bool {
			return hyp_touch_add_swipe( fingersCount , direction );
		}

		/**
		* Remove a Swipe Listener with the specified FingersCount / Direction
		* 
		* @public
		* @param 	fingersCount 	: Simultaneous fingers needed ( int )
		* @param 	direction : Direction of the Swipe ( int )
		* @return	boolean;
		*/
		public function removeSwipeListener( fingersCount : Int , direction : Int ) : Bool {
			return hyp_touch_rem_swipe( fingersCount , direction );
		}

		/**
		* Add a pna Listener with a min / max finger count
		* 
		* @public
		* @param 	minTouch : Min finger( s ) count ( Int )
		* @param 	maxTouch : Max finger( s ) count ( Int )
		* @return	boolean
		*/
		public function addPanListener( minTouch : Int , maxTouch : Int ) : Bool {
			trace('addPanListener ::: '+minTouch+' - '+maxTouch);
			return hyp_touch_add_pan( minTouch , maxTouch );
		}

		/**
		* Remove a PAN Listener with a min / max finger count
		* 
		* @public
		* @param 	minTouch : Min finger( s ) count ( Int )
		* @param 	maxTouch : Max finger( s ) count ( Int )
		* @return	boolean
		*/
		public function removePanListener( minTouch : Int , maxTouch : Int ) : Bool {
			return hyp_touch_rem_pan( minTouch , maxTouch );
		}

		#end

	// -------o protected
		
		/**
		* Setter of the rotation mode
		* 
		* @private
		* @param	b : Rotation ON / OFF ( Bool )
		* @return	bool
		*/
		private function _setAllowRot( b : Bool ) : Bool{
			if( this.allowRotation == b )
				return b;

			#if iphone
				if( b )
					hyp_touch_add_rot( );
				else
					hyp_touch_rem_rot( );
			#end

			return this.allowRotation = b;
		}

		/**
		* Setter of the Pinch Mode
		* 
		* @private
		* @param 	b : Pinch ON / OFF ( bool )
		* @return	bool
		*/
		private function _setAllowPinch( b : Bool ) : Bool{
			if( this.allowPinch == b )
				return b;

			#if iphone
				if( b )
					hyp_touch_add_pinch( );
				else
					hyp_touch_rem_pinch( );
			#end

			return this.allowPinch = b;
		}

		/**
		* Setter of the Tap Mode
		* 
		* @private
		* @param 	b : Tap ON / OFF ( bool )
		* @return	bool
		*/
		private function _setAllowTap( b : Bool ) : Bool{ 
			
			if( this.allowTap == b )
				return b;

			#if iphone
				if( b )
					hyp_touch_add_tap( 1 , 1 );
				else
					hyp_touch_rem_tap( 1 , 1 );
			#end

			return this.allowTap = b;
		}

		/**
		* Setter of the Double Tap Mode
		* 
		* @private
		* @param 	b : Double Tap ON / OFF ( bool )
		* @return	bool
		*/
		public function _setAllowDoubleTap( b : Bool ) : Bool{ 

			if( this.allowDoubleTap == b )
				return b;

			#if iphone
				if( b )
					hyp_touch_add_tap( 1 , 2 );
				else
					hyp_touch_rem_tap( 1 , 2 );	
			#end

			return this.allowDoubleTap = b;
		}

		/**
		* Setter of the Double Finger Tap Mode
		* 
		* @private
		* @param 	b : Twix ON / OFF ( bool )
		* @return	bool
		*/
		public function _setAllowTwixTap( b : Bool ) : Bool{ 

			if( this.allowTwoFingersTap == b )
				return b;
			
			#if iphone
				if( b )
					hyp_touch_add_tap( 2 , 1 );
				else
					hyp_touch_rem_tap( 2 , 1 );	
			#end

			return this.allowTwoFingersTap = b;
		}

		#if mobile

		/**
		* Callback of the Pan
		* 
		* @private
		* @param 	args : Callback arguments coordinates ( Array<Float> )
		* @return	void
		*/
		private function _onPanCallback( args : Array<Float> ) : Void{
			_onDispatchPan( args[ 0 ] , args[ 1 ] , args[ 2 ] , args[ 3 ] );
		}

		/**
		* Callback of the Pinch Listener
		* 
		* @private
		* @param 	fScale    : Pinch Scale Value ( Float )
		* @param 	fVelocity : Velocity of the pinch ( Float )
		* @return	void
		*/
		private function _onPinchCallback( fScale : Float , fVelocity : Float ) : Void{
			_onDispatchPinch( fScale , fVelocity );
		}

		/**
		* Callback of the rotation listener
		* 
		* @private
		* @param	fRotation : Rotation value ( Float )
		* @param	fVelocity : Velocity of the rotation gesture ( Float )
		* @return	void
		*/
		private function _onRotCallback( fRotation : Float , fVelocity : Float ) : Void{
			_onDispatchRotation( fRotation , fVelocity );
		}

		/**
		* Callback of the swipe gesture
		* 
		* @private
		* @param	direction : Direction of gesture ( Int )
		* @return	void
		*/
		private function _onSwipeCallback( direction : Int ) : Void{
			trace('_onSwipeCallback ::: '+direction);
			_onDispatchSwipe( direction );
		}		

		/**
		* Callback of the Tap gesture
		* 
		* @private
		* @param 	args : Callback arguments coordinates ( Array<Float> )
		* @return	void
		*/
		private function _onTapCallback( args : Array<Float> ) : Void{
			trace('_onTapCallback ::: '+args);

			var touches = Std.int( args[ 0 ] );
			var taps    = Std.int( args[ 1 ] );

			#if iphone
			var res = _convertToGl( args[ 2 ] , args[ 3 ] );
			_onDispatchTap( res.x , res.y , touches , taps );
			#end

			#if android
			_onDispatchTap( args[ 2 ] , args[ 3 ] , touches , taps );
			#end
		}

		#end

		#if iphone

		/**
		* Convert the coordinates for openGL stage coordinates
		* Warning : Seems buggy
		*
		* @private
		* @param 	f : Position to convert ( float )
		* @return	res ( FPoint )
		*/
		private function _convertToGl( fx : Float , fy : Float ) : FPoint{
			
			_fTmp.x = fx;
			_fTmp.y = fy;
			
			switch ( hyp_touch_get_orientation( ) ) {
				
				case Stage.OrientationPortrait:
					_fTmp.x = nme.Lib.current.stage.stageWidth - fy;
					_fTmp.y = fx;

				case Stage.OrientationPortraitUpsideDown:
					_fTmp.x = fy;
					_fTmp.y = nme.Lib.current.stage.stageHeight - fx;

				case Stage.OrientationLandscapeLeft:
					_fTmp.x = nme.Lib.current.stage.stageWidth - fy;
					_fTmp.y = fx;

				case Stage.OrientationLandscapeRight:
					_fTmp.x = fy;
					_fTmp.y = nme.Lib.current.stage.stageHeight - fx;
				
				case Stage.OrientationFaceDown:
					_fTmp.x = nme.Lib.current.stage.stageWidth - fy;
					_fTmp.y = fx;

				case Stage.OrientationFaceUp:
					_fTmp.x = nme.Lib.current.stage.stageWidth - fy;
					_fTmp.y = fx;
					
			}
			//trace('convert ::: '+fx+' - '+fy+'------------'+hyp_touch_get_orientation( )+' / '+Stage.getOrientation( )+' === '+_fTmp.x+' | '+_fTmp.y);
			return _fTmp;
		}

		#end

		/**
		* Dispatch an Tap Event at the specified position, fingers and taps count
		* 
		* @private
		* @param	fx      : Position X of the Tap Event ( Float )
		* @param	fy      : Position Y of the Tap Event ( Float )
		* @param	fingers : Tap fingers count ( Int )
		* @param	taps    : Taps count ( Int )
		* @return	void
		*/
		private function _onDispatchTap( fx : Float , fy : Float , fingers : Int , taps : Int = 1 ) : Void{
			trace('_onDispatchTap ::: '+fx+' - '+fy+' - '+fingers+' - '+taps);
			trace('allowTap ::: '+allowTap);
			trace('allowTap ::: '+allowDoubleTap);
			if( fingers == 1 ){
				if( taps == 2 && allowDoubleTap ){
					if( hasEventListener( GestureTapEvent.DOUBLE_TAP ) )
						dispatchEvent( new GestureTapEvent( GestureTapEvent.DOUBLE_TAP , fx , fy ) );
				}else if( taps == 1 && allowTap ){
					trace('allowTap --- '+'GestureTapEvent.TAP');
					if( hasEventListener( GestureTapEvent.TAP ) )
						dispatchEvent( new GestureTapEvent( GestureTapEvent.TAP , fx , fy ) );
				}
			}else if( taps == 1 && fingers == 2 ){
				if( hasEventListener( GestureTapEvent.TWO_FINGERS_TAP ) )
					dispatchEvent( new GestureTapEvent( GestureTapEvent.TWO_FINGERS_TAP , fx , fy ) );
			}

		}

		/**
		* Dispatch an Swipe Event for the specified direction
		* 
		* @private
		* @param	direction : Direction of the swipe ( Int )
		* @return	void
		*/
		private function _onDispatchSwipe( direction : Int ) : Void{
			dispatchEvent( new GestureSwipeEvent( direction ) );
		}

		/**
		* Dispatch an Rotation Event
		* 
		* @private
		* @param	fRotation : Rotation gesture ( Float )
		* @param	fVelocity : Rotation velocity ( Float )
		* @return	void
		*/
		private function _onDispatchRotation( fRotation : Float , fVelocity : Float ) : Void{
			dispatchEvent( new GestureRotationEvent( fRotation , fVelocity ) );
		}

		/**
		* Dispatch an Pan Event
		* 
		* @private
		* @param	fx : X offset 	( Float )
		* @param	fy : Y offset 	( Float )
		* @param	vx : X velocity ( Float )
		* @param	vy : Y velocity ( Float )
		* @return	void
		*/
		private function _onDispatchPan( fx : Float , fy : Float , vx : Float , vy : Float ) : Void{
			dispatchEvent( new GesturePanEvent( fx , fy , vx , vy ) );
		}

		/**
		* Dispatch an Pinch Event
		* 
		* @private
		* @param 	fScale    : Pinch Scale Value ( Float )
		* @param 	fVelocity : Velocity of the pinch ( Float )
		* @return	void
		*/
		private function _onDispatchPinch( fScale : Float , fVelocity : Float ) : Void{
			dispatchEvent( new GesturePinchEvent( fScale , fVelocity ) );
		}

	// -------o misc
		
		/**
		* Singleton instance of the HyperTouch 
		* 
		* @public
		* @return	singleton instance of the Class
		*/
		static public function getInstance( ) : HyperTouch {
			if( __instance == null )
				__instance = new HyperTouch( );

			return __instance;
		}

		private static var __instance : HyperTouch = null;
}
