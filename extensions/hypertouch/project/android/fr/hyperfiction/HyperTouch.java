package fr.hyperfiction;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.util.Log;
import android.view.GestureDetector.OnDoubleTapListener;
import android.view.GestureDetector.OnGestureListener;
import android.view.GestureDetector.SimpleOnGestureListener;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Toast;
import fr.hyperfiction.SimpleGestureFilter;
import org.haxe.nme.GameActivity;
import org.haxe.nme.HaxeObject;

public class HyperTouch extends GestureDetector.SimpleOnGestureListener implements View.OnTouchListener{
	
	//Singleton instance of the Class
	static private HyperTouch __instance = null;
	
	//Gestures codes for Haxe Callback
	final static String GESTURE_SWIPE = "onSwipe";
	final static String GESTURE_PAN   = "onPan";
	final static String GESTURE_TAP   = "onTap";

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
	private HaxeObject _mCallBack;
	private View mViewNME;
	
	// -------o constructor

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void HyperTouch( ){
			//Log.i( TAG , "constructor" );
		}

	// -------o public

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void setCallback( HaxeObject cb ){
			Log.i( TAG , "setCallback ::: "+cb);
			_mCallBack = cb;
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void init(  ) {
			
			mViewNME = GameActivity.getInstance( ).getCurrentFocus( );
			mViewNME.setOnTouchListener( this );
			mGestureDetector = new GestureDetector( GameActivity.getInstance( ) , this );			

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
			Log.i( TAG , "onSingleTapUp ::: "+ev.getPointerCount( ));
			Number[] 	args = new Number[4];
						args[0] = ev.getX( );
						args[1] = ev.getY( );
						args[2] = ev.getPointerCount( );
			_mCallBack.call( GESTURE_TAP , args );
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
			//Log.i( TAG , "onScroll : "+e1+" - "+e2+" - "+distanceX+" - "+distanceY);  
			//_mCallBack.call( GESTURE_PAN , e2.getX( ) , e2.getY( ) , distanceX , distanceY )
			_mCallBack.callD2( GESTURE_PAN , e2.getX( ) , e2.getY( ) );
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
			
			Float fx = e1.getX() - e2.getX();
			Float fy = e1.getY() - e2.getY() ;
			
			//Horizontal Swipe ?
			if( Math.abs( fy ) < SWIPE_MAX_OFF_PATH && Math.abs( fx ) > SWIPE_MIN_DISTANCE && Math.abs( velocityX ) > SWIPE_THRESHOLD_VELOCITY ){
				
				if( velocityX < 0 )
					_mCallBack.callD1( GESTURE_SWIPE , SWIPE_DIRECTION_LEFT );
				else
					_mCallBack.callD1( GESTURE_SWIPE , SWIPE_DIRECTION_RIGHT );
					//Toast.makeText(GameActivity.getInstance( ), "Right Swipe", Toast.LENGTH_SHORT).show( );

			}else if( Math.abs( fx ) < SWIPE_MAX_OFF_PATH && Math.abs( fy ) > SWIPE_MIN_DISTANCE && Math.abs( velocityY ) > SWIPE_THRESHOLD_VELOCITY ){
				
				if( velocityY > 0 )
					_mCallBack.callD1( GESTURE_SWIPE , SWIPE_DIRECTION_DOWN );
				else
					_mCallBack.callD1( GESTURE_SWIPE , SWIPE_DIRECTION_UP );

			}
            return false;
		}  

	// -------o private

	// -------o misc

		public static void HyperTouch_init( HaxeObject cb ){
			//Log.i( TAG , "HyperTouch_init");
			getInstance( ).setCallback( cb );			
		}

		public static void HyperTouch_run( ){
			getInstance( ).init( );
		}

		public static HyperTouch getInstance( ){
			if( __instance == null ){
				//Log.i( TAG , "HyperTouch Create Instance" );
				__instance = new HyperTouch( );
			}
			return __instance;
		}

}