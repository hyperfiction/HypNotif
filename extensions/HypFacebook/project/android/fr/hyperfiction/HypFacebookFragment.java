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

import android.util.Log;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.TextView;
import android.view.ViewGroup;

import fr.hyperfiction.HypFacebookView;

import org.haxe.nme.GameActivity;

/**
 * ...
 * @author shoe[box]
 */

public class HypFacebookFragment extends Fragment{

	public HypFacebookView view;

	private UiLifecycleHelper uiHelper;

	private static String TAG = "trace";//HypFacebook";

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public HypFacebookFragment() {
			trace("constructor");			
		}
	
	// -------o public
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void onCreate(Bundle savedInstanceState) {
			trace("onCreate");
			__instance = this;
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
	        super.onDestroy();
	        uiHelper.onDestroy();
   		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@Override
    	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
			trace("onCreateView");

			Settings.addLoggingBehavior(LoggingBehavior.INCLUDE_ACCESS_TOKENS);

	        Session session = Session.getActiveSession();
	        if (session == null) {
	            if (savedInstanceState != null) {
	                session = Session.restoreSession(getActivity(), null, callback, savedInstanceState);
	            }
	            if (session == null) {
	                session = new Session(getActivity());
	            }
	            Session.setActiveSession(session);
	            if (session.getState().equals(SessionState.CREATED_TOKEN_LOADED)) {
	                session.openForRead(new Session.OpenRequest(this).setCallback( callback ));
	            }
	        }

			return view = new HypFacebookView( );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void authorize( ){
			trace("authorize");
			Session session = Session.getActiveSession();
	        if (!session.isOpened() && !session.isClosed() ) {
	            session.openForRead( new Session.OpenRequest(this).setCallback( callback ) );
	        } else {
	            Session.openActiveSession( getActivity( ), this , true , callback );
	        }
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

	// -------o misc
		
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		public static void trace( String s ){
			Log.w( TAG, "HypFacebookFragment ::: "+s );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public static HypFacebookFragment getInstance( ){
			trace("getInstance ::: "+__instance);
			return __instance;
		}
		private static HypFacebookFragment __instance = null;
}