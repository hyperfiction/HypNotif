package fr.hyperfiction;

import nme.display.Stage;
#if android
import nme.JNI;
#end
import nme.errors.Error;
import nme.Lib;
import nme.Memory;
import org.shoebox.utils.system.Signal1;
import org.shoebox.utils.system.Signal2;
import org.shoebox.utils.system.Signal4;
import org.shoebox.geom.FPoint;

/**
 * ...
 * @author shoe[box]
 */

class HyperTouch{

	#if iphone
	public var onCustomTap     : Signal4<Int,Int,Float,Float>;
	#end

	public var onDoubleTap     : Signal2<Float,Float>;
	public var onPan           : Signal4<Float,Float,Float,Float>;
	public var onPinch         : Signal2<Float,Float>;
	public var onRotation      : Signal2<Float,Float>;
	public var onSwipe         : Signal1<Int>;
	public var onTap           : Signal2<Float,Float>;
	public var onTwoFingersTap : Signal2<Float,Float>;

	public var allowDoubleTap( default , _setAllowDoubleTap ) : Bool;
	public var allowPinch( default , _setAllowPinch )  : Bool;
	public var allowRotation( default , _setAllowRot ) : Bool;
	public var allowTap( default , _setAllowTap ) : Bool;
	public var allowTwoFingersTap( default , _setAllowTwixTap ) : Bool;
	
	public static inline var SWIPE_DIRECTION_RIGHT : Int = 1;
	public static inline var SWIPE_DIRECTION_LEFT  : Int = 2;
	public static inline var SWIPE_DIRECTION_UP    : Int = 4;
	public static inline var SWIPE_DIRECTION_DOWN  : Int = 8;

	#if iphone
	static var hyp_touch_callback_pan      = nme.Loader.load( "hyp_touch_callback_pan" , 1 );
	static var hyp_touch_callback_pinch    = nme.Loader.load( "hyp_touch_callback_pinch" , 1 );
	static var hyp_touch_callback_rotation = nme.Loader.load( "hyp_touch_callback_rotation" , 1 );
	static var hyp_touch_callback_swipe    = nme.Loader.load( "hyp_touch_callback_swipe" , 1 );
	static var hyp_touch_callback_tap      = nme.Loader.load( "hyp_touch_callback_tap" , 1 );

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
	static private var hyp_touch_run  : Dynamic;

	private var _oListener : AndroidCallback;
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

			#if iphone
			hypTouch_init( );
			hyp_touch_callback_pan( _onPanCallback );
			hyp_touch_callback_pinch( _onPinchCallback );
			hyp_touch_callback_rotation( _onRotCallback );
			hyp_touch_callback_swipe( _onSwipeCallback );
			hyp_touch_callback_tap( _onTapCallback );
			#end

			#if android
			
			//Initialize
				if( hyp_touch_init == null )
					hyp_touch_init = JNI.createStaticMethod( ANDROID_CLASS , 'HyperTouch_init' , "(Lorg/haxe/nme/HaxeObject;)V" );
					hyp_touch_init( _oListener = new AndroidCallback( this ) );
			
			//Run 
				hyp_touch_run = nme.JNI.createStaticMethod( ANDROID_CLASS , "HyperTouch_run" , "()V" );
					nme.Lib.postUICallback( 
											function() { 
												trace('createStaticMethod');
												hyp_touch_run( );
											});
			#end

			_fTmp = { x : 0.0 , y : 0.0 };

			#if iPhone
			onCustomTap     = new Signal4<Int,Int,Float,Float>();
			#end

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

		#if iphone

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

			var touches = Std.int( args[ 0 ] );
			var taps    = Std.int( args[ 1 ] );

			var res = _convertToGl( args[ 2 ] , args[ 3 ] );
			
			if( touches == 1 ){

				if( taps == 2 && allowDoubleTap )
					onDoubleTap.emit( res.x , res.y );
				else if( taps == 1 && allowTap )
					onTap.emit( res.x , res.y );

			}else if( touches == 2 && taps == 1 ){
				onTwoFingersTap.emit( res.x , res.y );
			}else{
				onCustomTap.emit( touches , taps , res.x , res.y );
			}

		}

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
					_fTmp.x = Lib.current.stage.stageWidth - fy;
					_fTmp.y = fx;

				case Stage.OrientationPortraitUpsideDown:
					_fTmp.x = fy;
					_fTmp.y = Lib.current.stage.stageHeight - fx;

				case Stage.OrientationLandscapeLeft:
					_fTmp.x = Lib.current.stage.stageWidth - fy;
					_fTmp.y = fx;

				case Stage.OrientationLandscapeRight:
					_fTmp.x = fy;
					_fTmp.y = Lib.current.stage.stageHeight - fx;
				
				case Stage.OrientationFaceDown:
					_fTmp.x = Lib.current.stage.stageWidth - fy;
					_fTmp.y = fx;

				case Stage.OrientationFaceUp:
					_fTmp.x = Lib.current.stage.stageWidth - fy;
					_fTmp.y = fx;
					
			}
			//trace('convert ::: '+fx+' - '+fy+'------------'+hyp_touch_get_orientation( )+' / '+Stage.getOrientation( )+' === '+_fTmp.x+' | '+_fTmp.y);
			return _fTmp;
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

#if android

/**
 * ...
 * @author shoe[box]
 */
class AndroidCallback{

	public var _instance : HyperTouch;

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new( from : HyperTouch ) {
			_instance = from;
		}
	
	// -------o public
		
		/**
		* Callback of the Swipe
		* 
		* @private
		* @param 	direction : Direction of the Swipe ( mode )
		* @return	void
		*/
		public function onSwipe( direction : Int ) : Void {
			_instance.onSwipe.emit( direction );
		}

		/**
		* Callback of the Swipe
		* 
		* @public
		* @param 	fx : X position in to the current view space ( Float )
		* @param 	fy : Y position in to the current view space ( Float )
		* @param 	fingers : Finger count ( Int )
		* @return	void
		*/
		public function onTap( fx : Float , fy : Float , fingers : Int = 1 ) : Void {
			trace('onTap ::: '+fx+' | '+fy+' === '+fingers);
			return;

			if( fingers == 2 && _instance.allowDoubleTap )
				_instance.onTwoFingersTap.emit( fx , fy );
			else
				_instance.onTap.emit( fx , fy );
				
		}

		/**
		* Callback of the pan gesture
		* 
		* @public
		* @return	void
		*/
		public function onPan( fx , fy ) : Void {
			trace('onPan ::: '+fx+' - '+fy);
			//_instance.onPan.emit( Std.parseFloat( fx ) , Std.parseFloat( fy ) , 0.0 , 0.0 ); //NO VELOCITY FOR PAN WITH ANDROID
		}

	// -------o protected
	
	// -------o misc
	
}
#end