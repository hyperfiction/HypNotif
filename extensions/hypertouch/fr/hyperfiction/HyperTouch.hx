package fr.hyperfiction;

import nme.display.Stage;
#if android
import nme.JNI;
#end
import nme.errors.Error;
import nme.Lib;
import org.shoebox.utils.system.Signal1;
import org.shoebox.utils.system.Signal2;
import org.shoebox.utils.system.Signal4;
import org.shoebox.geom.FPoint;

/**
 * ...
 * @author shoe[box]
 */

class HyperTouch{

	public var onCustomTap     : Signal4<Int,Int,Float,Float>;
	public var onDoubleTap     : Signal2<Float,Float>;
	public var onPan           : Signal4<Float,Float,Float,Float>;
	public var onPinch         : Signal2<Float,Float>;
	public var onRotation      : Signal2<Float,Float>;
	public var onSwipe         : Signal1<Int>;
	public var onTap           : Signal2<Float,Float>;
	public var onTwoFingersTap : Signal2<Float,Float>;

	#if mobile
	public var allowPinch( default , _setAllowPinch )  : Bool;
	public var allowRotation( default , _setAllowRot ) : Bool;
	public var allowTap( default , _setAllowTap ) : Bool;
	public var allowDoubleTap( default , _setAllowDoubleTap ) : Bool;
	public var allowTwoFingersTap( default , _setAllowTwixTap ) : Bool;
	#end
	
	public static inline var SWIPE_DIRECTION_T : Int = 0;
	public static inline var SWIPE_DIRECTION_B : Int = 1;
	public static inline var SWIPE_DIRECTION_L : Int = 2;
	public static inline var SWIPE_DIRECTION_R : Int = 3;

	#if iphone
	
	static var hyp_touch_callback_pan      = nme.Loader.load( "hyp_touch_callback_pan" , 1 );
	static var hyp_touch_callback_pinch    = nme.Loader.load( "hyp_touch_callback_pinch" , 1 );
	static var hyp_touch_callback_rotation = nme.Loader.load( "hyp_touch_callback_rotation" , 1 );
	static var hyp_touch_callback_swipe    = nme.Loader.load( "hyp_touch_callback_swipe" , 1 );
	static var hyp_touch_callback_tap      = nme.Loader.load( "hyp_touch_callback_tap" , 1 );

	static var hypTouch_init       = nme.Loader.load( "hyp_touch_init" , 0 );
	static var hyp_touch_add_pan   = nme.Loader.load( "hyp_touch_add_pan" , 2 );
	static var hyp_touch_add_pinch = nme.Loader.load( "hyp_touch_add_pinch" , 0 );	
	static var hyp_touch_add_rot   = nme.Loader.load( "hyp_touch_add_rot" , 0 );
	static var hyp_touch_add_swipe = nme.Loader.load( "HypTouch_addSwipe" , 2 );
	static var hyp_touch_add_tap   = nme.Loader.load( "HypTouch_addTap" , 2 );
	static var hyp_touch_rem_pan   = nme.Loader.load( "hyp_touch_remove_pan" , 2 );
	static var hyp_touch_rem_pinch = nme.Loader.load( "hyp_touch_remove_pinch" , 0 );
	static var hyp_touch_rem_rot   = nme.Loader.load( "hyp_touch_remove_rot" , 0 );
	static var hyp_touch_rem_swipe = nme.Loader.load( "HypTouch_removeSwipe" , 2 );
	static var hyp_touch_rem_tap   = nme.Loader.load( "HypTouch_removeTap" , 2 );
	#end

	#if android
	//static private var hypfb_request : Dynamic;
	//public static inline var ANDROID_CLASS : String = 'fr.hyperfiction.HypFacebook';
	#end

	public static inline var PAN      : String = 'PAN';
	public static inline var PINCH    : String = 'PINCH';
	public static inline var ROTATION : String = 'ROTATION';
	public static inline var SWIPE    : String = 'SWIPE';
	public static inline var TAP      : String = 'TAP';

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		private function new( ) {
			#if iphone
			hypTouch_init( );
			hyp_touch_callback_pan( _onPanCallback );
			hyp_touch_callback_pinch( _onPinchCallback );
			hyp_touch_callback_rotation( _onRotCallback );
			hyp_touch_callback_swipe( _onSwipeCallback );
			hyp_touch_callback_tap( _onTapCallback );
			#end

			onCustomTap     = new Signal4<Int,Int,Float,Float>();
			onDoubleTap     = new Signal2<Float,Float>();
			onPan           = new Signal4<Float,Float,Float,Float>();
			onPinch         = new Signal2<Float,Float>();
			onRotation      = new Signal2<Float,Float>();
			onSwipe         = new Signal1<Int>();
			onTap           = new Signal2<Float,Float>();
			onTwoFingersTap = new Signal2<Float,Float>();
		}
	
	// -------o public

		#if iphone

		/**
		* Add a Tap listener
		* 
		* @public
		* @param 	fingersCount 	: Simultaneous fingers needed ( int )
		* @param 	tapsCount 		: Taps count needed ( int )
		* @return	boolean
		*/
		public function addCustomTapListener( fingersCount : Int , tapsCount : Int ) : Bool {
			return hyp_touch_add_tap( fingersCount , tapsCount );
		}

		/**
		* Remove a Tap Listener
		* 
		* @public
		* @param 	fingersCount 	: Simultaneous fingers needed ( int )
		* @param 	tapsCount 		: Taps count needed ( int )
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
		
		#if iphone

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

			if( b )
				hyp_touch_add_rot( );
			else
				hyp_touch_rem_rot( );
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

			if( b )
				hyp_touch_add_pinch( );
			else
				hyp_touch_rem_pinch( );
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

			if( b )
				hyp_touch_add_tap( 1 , 1 );
			else
				hyp_touch_rem_tap( 1 , 1 );

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

			if( b )
				hyp_touch_add_tap( 1 , 2 );
			else
				hyp_touch_rem_tap( 1 , 2 );	

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

			if( b )
				hyp_touch_add_tap( 1 , 2 );
			else
				hyp_touch_rem_tap( 1 , 2 );	

			return this.allowTwoFingersTap = b;
		}

		/**
		* Callback of the Swipe
		* 
		* @private
		* @param 	direction : Direction of the Swipe ( mode )
		* @return	void
		*/
		private function _onSwipe( direction : Int ) : Void{
			//TODO : Convert in to the current orientation mode
			onSwipe.emit( direction );
		}

		/**
		* Callback of the Pan
		* 
		* @private
		* @param 	args : Callback arguments coordinates ( Array<Float> )
		* @return	void
		*/
		private function _onPanCallback( args : Array<Float> ) : Void{
			//TODO : Convert in to the current orientation mode
			onPan.emit( args[ 0 ] , args[ 1 ] , args[ 2 ] , args[ 3 ] );
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
			onPinch.emit( fScale , fVelocity );
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
			onRotation.emit( fRotation , fVelocity );
		}

		/**
		* Callback of the swipe gesture
		* 
		* @private
		* @param	direction : Direction of gesture ( Int )
		* @return	void
		*/
		private function _onSwipeCallback( direction : Int ) : Void{
			onSwipe.emit( direction );
		}

		/**
		* Callback of the Tap gesture
		* 
		* @private
		* @param 	args : Callback arguments coordinates ( Array<Float> )
		* @return	void
		*/
		private function _onTapCallback( args : Array<Float> ) : Void{
			
			var touches : Int = Std.int( args[ 0 ] );
			var fingers : Int = Std.int( args[ 1 ] );

			var res = _convert( args[ 2 ] , args[ 3 ] );
			
			if( fingers == 1 ){
				if( touches == 1 && allowTap )
					onTap.emit( res.x , res.y );
				else if( touches == 2 && allowDoubleTap )
					onDoubleTap.emit( res.x , res.y );
			}else if( fingers == 2 && touches == 1 ){
				onTwoFingersTap.emit( res.x , res.y );
			}else{
				onCustomTap.emit( touches , fingers , res.x , res.y );
			}

		}

		/**
		* Convert the coordinates for the current Stage orientation
		* Warning : Seems buggy
		*
		* @private
		* @param 	f : Position to convert ( float )
		* @return	res ( FPoint )
		*/
		private function _convert( fx : Float , fy : Float ) : FPoint{
			var res = { x : fx , y : fy };
			var oppX : Float = Lib.current.stage.stageWidth - fx;
			var oppY : Float = Lib.current.stage.stageHeight - fy;

			switch ( Stage.getOrientation( ) ) {

				case Stage.OrientationPortrait:
					res.x = fy;//Lib.current.stage.stageWidth - fy;
					res.y = Lib.current.stage.stageHeight - fx;

				case Stage.OrientationPortraitUpsideDown:
					res.x = fy;//Lib.current.stage.stageWidth - fy;
					res.y = Lib.current.stage.stageHeight - fx;

				case Stage.OrientationLandscapeRight:
					res.x = fy;
					res.y = Lib.current.stage.stageHeight - fx;
					
				case Stage.OrientationLandscapeLeft:
					res.x = Lib.current.stage.stageWidth - fy;
					res.y = fx;

				case Stage.OrientationFaceUp:
					res.x = fy;
					res.y = Lib.current.stage.stageHeight - fx;

				case Stage.OrientationFaceDown:
					res.x = fx;
					res.y = oppY;

			}
			
			return res;
		}

		#end

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
