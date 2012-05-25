package test;

import android.app.Activity;
import android.os.Bundle;
import android.app.ListActivity;
import android.view.GestureDetector;
import android.util.Log;
import android.view.GestureDetector.SimpleOnGestureListener;
import android.view.GestureDetector.OnDoubleTapListener;
import android.view.GestureDetector.OnGestureListener;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.ViewGroup.LayoutParams;
import android.view.View;
import android.widget.Button;
import android.os.Handler;
import org.haxe.nme.GameActivity;

public class Test extends Activity implements OnGestureListener{


	private GestureDetector gestureScanner;
		
	public Test( ){
		Log.i("trace","constructor");
		gestureScanner = new GestureDetector( GameActivity.getInstance( ) , this );
		GameActivity ga = GameActivity.getInstance();
Button b = new Button(ga); b.setText("toto");
ga.addContentView(b, new LayoutParams(LayoutParams.WRAP_CONTENT,
LayoutParams.WRAP_CONTENT)); 
	}

	@Override
	public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY) {
		Log.i("trace","onFling");
		return true;
	}

	@Override
	public void onLongPress(MotionEvent e){
		Log.i("trace","onLongPress");
	}

	@Override
	public boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX, float distanceY){
		Log.i("trace","onScroll");
		return true;
	}

	@Override
	public boolean onDown(MotionEvent e) {
		Log.i("trace","onDown");
		return true;
	}

	@Override
	public boolean onSingleTapUp(MotionEvent e) {
		Log.i("trace","onSingleTapUp");
		return true;
	}

	@Override
	public void onShowPress(MotionEvent e){
		Log.i("trace","onShowPress");		
	}





	public static int nmeCreate( ){
		Log.i("trace","nmeCreate");
		mTest = new Test( );
		
		return 0;
	}
	static private Test mTest;

	static public int twoPlusTwo( ) {
		
		return 2 + 2;
	}

}

class MyGestureDetector extends SimpleOnGestureListener {
        @Override
        public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY) {
        	 Log.i("trace", "onFling");
            return false;
        }

    }


