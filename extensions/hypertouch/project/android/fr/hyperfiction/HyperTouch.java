package fr.hyperfiction;
import android.util.Log;
import android.view.GestureDetector.SimpleOnGestureListener;
import android.view.MotionEvent;
import android.view.View;
import org.haxe.nme.GameActivity;
import android.view.GestureDetector.OnDoubleTapListener;
import android.view.GestureDetector.OnGestureListener;
import android.view.GestureDetector.SimpleOnGestureListener;
import android.view.ScaleGestureDetector;
import android.view.ScaleGestureDetector.SimpleOnScaleGestureListener;
import android.view.GestureDetector;
import org.haxe.nme.HaxeObject;

public class HyperTouch extends GestureDetector.SimpleOnGestureListener implements View.OnTouchListener{

	static private HyperTouch __instance = null;

	public static String TAG = "HyperTouch";

	private View mViewNME;
	
	static public HaxeObject mCallBack;
	public static GestureDetector mGestureDetector;
	public static ScaleGestureDetector mScaleDetector;

	public SimpleOnScaleGestureListener mListener = new ScaleGestureDetector.SimpleOnScaleGestureListener( ) {
		
		

		@Override
		public boolean onScale( ScaleGestureDetector detector) {

			if( !_bAllowPinch )
				return false;

			float time = detector.getEventTime( );
			if( ( time - _fPrevZoom ) < 30 )
				return false;

			_fPrevZoom = time;
			//mScaleFactor = detector.getScaleFactor();
			float scaleFactor = detector.getScaleFactor( );
			if( Math.abs( scaleFactor ) > 0.01 && detector.getTimeDelta( ) > 10 ){
           		new Thread( new ScaleRunnable( scaleFactor ) ).start( );
				return true;
			}else
				return false;
		};
	};

	private boolean _bAllowPan = false;
	private boolean _bAllowPinch = false;
	private float _fPrevZoom = 0;
	private float _fPrevScroll = 0;

	//Directions codes for Haxe Callback
	final static int SWIPE_DIRECTION_RIGHT = 1;
	final static int SWIPE_DIRECTION_LEFT  = 2;
	final static int SWIPE_DIRECTION_UP    = 4;
	final static int SWIPE_DIRECTION_DOWN  = 8;

	//Perhaps not the better way to detect a Swipe in Android
	private static final int SWIPE_MIN_DISTANCE = 120;
    private static final int SWIPE_MAX_OFF_PATH = 250;
    private static final int SWIPE_THRESHOLD_VELOCITY = 200;

	// -------o constructor

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void HyperTouch( ){
			Log.i( TAG , "constructor" );			
		}

	// -------o public

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void setAllowPan( boolean b ){
			Log.i( TAG , "setAllowPan ::: "+b );
			_bAllowPan = b;
		}

		public void setAllowPinch( boolean b ){
			Log.i( TAG , "setAllowZoom ::: "+b );
			_bAllowPinch = b;
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void setCallback( HaxeObject cb ) {
			Log.i( TAG , "setCallback" );
			mCallBack = cb;
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void init(  ) {
			Log.i( TAG , "init ::: " );
			
			mViewNME  = GameActivity.getInstance( ).getCurrentFocus( );
			mViewNME.setOnTouchListener( this );

			GameActivity.getInstance( ).mHandler.post(
					new Runnable(){
						@Override public void run(){
							HyperTouch.mGestureDetector = new GestureDetector( GameActivity.getInstance( ) , HyperTouch.getInstance( ) );		
						}
					});

			GameActivity.getInstance( ).mHandler.post(
				new Runnable(){
						@Override public void run(){
							HyperTouch.mScaleDetector = new ScaleGestureDetector( GameActivity.getInstance( ) , HyperTouch.getInstance( ).mListener );		
						}
					});

			//mScaleDetector   = new ScaleGestureDetector( GameActivity.getInstance( ) , _mListener );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public boolean onTouch( View v , final MotionEvent ev) {
			//Log.i( TAG , "onTouch" );
			//
				mGestureDetector.onTouchEvent( ev );
				mScaleDetector.onTouchEvent( ev );

			//Restoring the NME touchevent
				mViewNME.onTouchEvent( ev );

			return true;	
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public boolean onSingleTapUp(MotionEvent ev) { 
			Log.i( TAG , "onSingleTapUp : "); 
			//mCallBack.callD2( "onTap" , ev.getX( ) , ev.getY( ) );
			//GameActivity.getInstance( ).mHandler.post( new TapRunnable( ev.getX( ) , ev.getY( ) ) );
			new Thread( new TapRunnable( ev.getX( ) , ev.getY( ) ) ).start( );
			
			return true;  
		}  
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void onShowPress(MotionEvent ev) {  
			//Log.i( TAG , "onShowPress : "+ev.toString());  
		}  
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void onLongPress(MotionEvent ev) {  
			//Log.i( TAG , "onLongPress : "+ev.toString());  
		}  
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX, float distanceY) {  
			// TODO : Velocity calculations
			/*
			mSurface.queueEvent(
				new PanRunnable( e2.getX( ) , e2.getY( ) , 0.f , 0.f )
            );
            */
			if( !_bAllowPan )
				return false;

			float time = e2.getEventTime( );
			if( ( time - _fPrevScroll ) < 30 )
				return false;

			Log.i( TAG , "onScroll : ");  
			_fPrevScroll = time;
			//Log.i( TAG , "onScroll : "+e2.getEventTime( ) );
			if( Math.abs( distanceX ) > 2 || Math.abs( distanceY ) > 2 ){
				new Thread( new PanRunnable( distanceX , distanceY ) ).start( );
				return true;  
			}

			return false;
		}  
		
		public boolean onDown(MotionEvent ev) {  
			//Log.i( TAG , "onDownd : "+ev);  
			return true;  
		}  
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY) {  
			
			//Log.i( TAG , "onFling : "+velocityX+" || "+velocityY);  
			Float fx = e1.getX() - e2.getX();
			Float fy = e1.getY() - e2.getY() ;
			try {
				if( Math.abs( fy ) < SWIPE_MAX_OFF_PATH && Math.abs( fx ) > SWIPE_MIN_DISTANCE && Math.abs( velocityX ) > SWIPE_THRESHOLD_VELOCITY ){
					
					if( velocityX < 0 )
						_swipe( SWIPE_DIRECTION_LEFT );
					else
						_swipe( SWIPE_DIRECTION_RIGHT );

					return true;

				}else if( Math.abs( fx ) < SWIPE_MAX_OFF_PATH && Math.abs( fy ) > SWIPE_MIN_DISTANCE && Math.abs( velocityY ) > SWIPE_THRESHOLD_VELOCITY ){

					if( velocityY > 0 )
						_swipe( SWIPE_DIRECTION_DOWN );
					else
						_swipe( SWIPE_DIRECTION_UP );
					
					return true;
				}
			} catch (Exception e) {
	        	Log.i( TAG , "Exception : "+e);  
	        }

	        return false;
		}  

	// -------o private

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private void _swipe( final int direction ){
			//mCallBack.callD1( "onSwipe" , direction );
			new Thread( new SwipeRunnable( direction ) ).start( );
		}

	// -------o misc

		public static void HyperTouch_init( HaxeObject cb ){
			Log.i( TAG , "HyperTouch_init ::: "+cb);
			__instance = new HyperTouch( );
			__instance.setCallback( cb );
			__instance.init( );	
		}

		public static void HyperTouch_run( ){
			Log.i( TAG , "HyperTouch_run");		
		}

		public static HyperTouch getInstance( ){
			return __instance;
		}

		public static void HyperTouch_allowPan( boolean value ){
			//Log.i( TAG , "HyperTouch_allowPan ::: "+value);
			__instance.setAllowPan( value );
		}

		public static void HyperTouch_allowPinch( boolean value ){
			__instance.setAllowPinch( value );	
		}

	}

	class TapRunnable implements Runnable{
		
		float fx;
		float fy;
		TapRunnable( float x , float y ){
			fx = x;
			fy = y;
		}

		public void run( ){
			HyperTouch.mCallBack.callD2( "onTap" , fx , fy );
		}

	}

	class PanRunnable implements Runnable{
		
		float fx;
		float fy;
		PanRunnable( float x , float y ){
			fx = x;
			fy = y;
		}

		public void run( ){
			HyperTouch.mCallBack.callD2( "onPan" , fx , fy );
		}

	}

	class SwipeRunnable implements Runnable{
		
		int direction;
		SwipeRunnable( int dir ){
			direction = dir;
		}

		public void run( ){
			HyperTouch.mCallBack.callD1( "onSwipe" , direction );
		}
	}

	class ScaleRunnable implements Runnable{
		
		float scale;
		ScaleRunnable( float scl ){
			scale = scl;
		}

		public void run( ){
			HyperTouch.mCallBack.callD2( "onScale" , scale , 0.f );
		}
	}
