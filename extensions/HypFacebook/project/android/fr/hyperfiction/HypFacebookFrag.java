package fr.hyperfiction;

import ::APP_PACKAGE::.R;

import com.facebook.*;
import com.facebook.model.GraphObject;
import com.facebook.model.GraphPlace;
import com.facebook.model.GraphUser;
import com.facebook.widget.*;
import com.facebook.LoggingBehavior;
import com.facebook.Session;
// import com.facebook.Session.SessionStatusCallback;
import com.facebook.SessionState;
import com.facebook.Settings;

import android.content.Intent;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import java.util.List;

import fr.hyperfiction.HypFacebookView;

import org.haxe.nme.GameActivity;

/**
 * ...
 * @author shoe[box]
 */

public class HypFacebookFrag extends Fragment{

	private UiLifecycleHelper uiHelper;
	private List<String> aPermissions;

	private static String TAG = "trace";//HypFacebook";

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public HypFacebookFrag() {
			trace("constructor");			
		}
	
	// -------o public
		
		public void setPermissions( List<String> perms ) {
			trace("setPermissions");
            this.aPermissions = perms;
        }

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void onCreate(Bundle savedInstanceState) {
			trace("onCreate");
			super.onCreate(savedInstanceState);
			uiHelper = new UiLifecycleHelper( GameActivity.getInstance( ) , callback);
        	uiHelper.onCreate(savedInstanceState);
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@Override
	    public void onStart() {
	        super.onStart( );
	    	trace("onStart");
	    	if( Session.getActiveSession( ).isOpened( ) )
	    		return;
	       _authorize( );
	    }

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@Override
	    public void onPause() {
	    	trace("onPause");
	        super.onPause();
	        uiHelper.onPause();
	    }

	    /**
		* 
		* 
		* @public
		* @return	void
		*/
	    @Override
	    public void onDestroy() {
	    	trace("onDestroy");
	        super.onDestroy();
	        uiHelper.onDestroy();
   		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void authorize( ){
			Session session = Session.getActiveSession();
	        if (!session.isOpened() && !session.isClosed() ) {
	            session.openForRead( new Session.OpenRequest(this).setCallback( callback ) );
	        } else {
	            Session.openActiveSession( getActivity( ), this , true , callback );
	        }
		}

		@Override
    	public void onActivityResult(int requestCode, int resultCode, Intent data) {
    		trace("onActivityResult");
    		super.onActivityResult(requestCode, resultCode, data);
    		Session.getActiveSession().onActivityResult( getActivity( ) , requestCode , resultCode , data );
    	}

	// -------o protected
	
		private Session.StatusCallback callback = new Session.StatusCallback() {
	        @Override
	        public void call(Session session, SessionState state, Exception exception) {
	        	trace("call ::: "+session);
	            onSessionStateChange(session, state, exception);
	        }
	    };

	    /**
	    * 
	    * 
	    * @private
	    * @return	void
	    */
	    private void onSessionStateChange(Session session, SessionState state, Exception exception) {
	    	trace("onSessionStateChange");
	    }

	    /**
	    * 
	    * 
	    * @private
	    * @return	void
	    */
	    private void _authorize( ){
	    	trace("_authorize");

	    	final Session.OpenRequest 	req = new Session.OpenRequest( this );
										req.setPermissions( aPermissions );
			Session.getActiveSession( ).openForRead( req );
	    }

	// -------o misc
		
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		public static void trace( String s ){
			Log.w( TAG, "HypFacebookFrag ::: "+s );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public static HypFacebookFrag getInstance( ){
			trace("getInstance ::: "+__instance);

			if( __instance == null )
				__instance = new HypFacebookFrag( );

			return __instance;
		}
		private static HypFacebookFrag __instance = null;
}