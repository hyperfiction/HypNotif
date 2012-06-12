package fr.hyperfiction;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.util.Log;
import android.view.ScaleGestureDetector;
import android.view.ScaleGestureDetector.SimpleOnScaleGestureListener;
import android.view.GestureDetector.OnDoubleTapListener;
import android.view.GestureDetector.OnGestureListener;
import android.view.GestureDetector.SimpleOnGestureListener;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Toast;
//import fr.hyperfiction.SimpleGestureFilter;
import org.haxe.nme.GameActivity;
import org.haxe.nme.HaxeObject;

public class HyperTouch extends GestureDetector.SimpleOnGestureListener implements View.OnTouchListener{
	
	static public native void onTap( int touches , int taps , float fx , float fy );
	static public native void onSwipe( int direction );
	static public native void onScale( float scale , float velocity );
	static public native void onPan( float fx , float fy , float vx , float vy );

	//Singleton instance of the Class
	static private HyperTouch __instance = null;
	
	//Directions codes for Haxe Callback
	final static int SWIPE_DIRECTION_RIGHT = 1;
	final static int SWIPE_DIRECTION_LEFT  = 2;
	final static int SWIPE_DIRECTION_UP    = 4;
	final static int SWIPE_DIRECTION_DOWN  = 8;

	//Perhaps not the better way to detect a Swipe in Android
	private static final int SWIPE_MIN_DISTANCE = 120;
    private static final int SWIPE_MAX_OFF_PATH = 250;
    private static final int SWIPE_THRESHOLD_VELOCITY = 200;

    //Log Trace code
	private static final String TAG = "trace";

	private GestureDetector mGestureDetector;
	private ScaleGestureDetector mScaleDetector;
	private float mScaleFactor = 1.f;
	private View mViewNME;
	private GLSurfaceView mSurface;
	
	private SimpleOnScaleGestureListener _mListener = new ScaleGestureDetector.SimpleOnScaleGestureListener( ) {
		
		@Override
		public boolean onScale(ScaleGestureDetector detector) {
			//mScaleFactor = detector.getScaleFactor();
           	mSurface.queueEvent(
				new ScaleRunnable( detector.getScaleFactor() )
            );
			return true;
		};

	};

	static{ 
		System.loadLibrary( "hypertouch"); 
	}

	
	
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
		public void init( ) {
			Log.i( TAG , "init" );
			mViewNME = GameActivity.getInstance( ).getCurrentFocus( );
			mViewNME.setOnTouchListener( this );
			mSurface = ( (GLSurfaceView ) mViewNME );
			
			mGestureDetector = new GestureDetector( GameActivity.getInstance( ) , this );		
			mScaleDetector   = new ScaleGestureDetector( GameActivity.getInstance( ) , _mListener );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public boolean onTouch(View v, MotionEvent ev) {
			
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
		public void onScaled( ) {			
			
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public boolean onSingleTapUp(MotionEvent ev) { 
			Log.i( TAG , "onSingleTapUp : "+mSurface); 
			if( mSurface == null )
				return true;
			mSurface.queueEvent(
				new TapRunnable( ev.getPointerCount( ) , 1 , ev.getX( ) , ev.getY( ) )
            );
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
			mSurface.queueEvent(
				new PanRunnable( e2.getX( ) , e2.getY( ) , 0.f , 0.f )
            );
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
			mSurface.queueEvent(
				/*
				new Runnable() {
	                public void run() {
	                	onSwipe( direction );
	                }
             	}
             	*/
             	new SwipeRunnable( direction )
            );
		}

	// -------o misc

		public static void HyperTouch_init(){
			//Log.i( TAG , "HyperTouch_init");
			getInstance( ).init( );			
		}

		public static HyperTouch getInstance( ){
			if( __instance == null ){
				//Log.i( TAG , "HyperTouch Create Instance" );
				__instance = new HyperTouch( );
			}
			return __instance;
		}

	class SwipeRunnable implements Runnable{
		int direction;
		
		SwipeRunnable( int d ) { 
			direction = d; 
		}

		public void run( ){
			HyperTouch.onSwipe( direction );
		}

	}

	class TapRunnable implements Runnable{
			
		int fingers;
		int taps;
		float fx;
		float fy;	

		TapRunnable( int f , int t , float x , float y ){
			fingers = f;
			taps = t;
			fx = x;
			fy = y;
		}

		public void run( ){
			HyperTouch.onTap( fingers , taps , fx , fy );
		}

	}

	class ScaleRunnable implements Runnable{
		float value;
		
		ScaleRunnable( float v ) { 
			value = v;
		}

		public void run( ){
			HyperTouch.onScale( value , 0.f );
		}

	}

	class PanRunnable implements Runnable{
			
		float fx;
		float fy;	
		float vx;	
		float vy;	

		PanRunnable( float x , float y , float vx , float vy ){
			this.fx = x;
			this.fy = y;
			this.vx = vx;
			this.vy = vy;
		}

		public void run( ){
			HyperTouch.onPan( fx , fy , vx , vy );
		}

	}
}
