package fr.hyperfiction;

import android.util.Log;
import com.google.android.apps.analytics.GoogleAnalyticsTracker;
import org.haxe.nme.GameActivity;

/**
 * ...
 * @author shoe[box]
 */
public class HypGA{

	GoogleAnalyticsTracker tracker;

	private static String TAG = "HyperLocation";

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		private void HypGA() {
			Log.i( TAG, " constructor" );
		}
	
	// -------o public				

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void set_dispatch_period( int iPeriod ) {
			Log.i( TAG, " set_dispatch_period : "+iPeriod );
			tracker = GoogleAnalyticsTracker.getInstance( );
			tracker.setDispatchPeriod( iPeriod );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void startNewSession( String sUA_code ){
			Log.i( TAG, " startNewSession : "+sUA_code );
			tracker = GoogleAnalyticsTracker.getInstance( );
			tracker.startNewSession( sUA_code , GameActivity.getInstance( ) );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void trackEvent( String sCat , String sAction , String sLabel , int val ){
			Log.i( TAG, "trackEvent : cat "+sCat+" || action : "+sAction+" || label : "+sLabel+" || val : "+val );
			tracker = GoogleAnalyticsTracker.getInstance( );
			tracker.trackEvent( sCat , sAction , sLabel , val );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void trackPageView( String sPage ){
			Log.i( TAG, "trackPageView : "+sPage );
			tracker = GoogleAnalyticsTracker.getInstance( );
			tracker.trackPageView( sPage );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void stopSession( ){
			Log.i( TAG, "stopSession");
			tracker = GoogleAnalyticsTracker.getInstance( );
			tracker.stopSession( );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void setCustomVar( int iSlot , String sName , String sValue ){
			tracker = GoogleAnalyticsTracker.getInstance( );
			tracker.setCustomVar( iSlot , sName , sValue );
		}

	// -------o protected
	
	// -------o misc
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public HypGA getInstance( ){		
			if( __instance == null )
				__instance = new HypGA( );

			return __instance;
		}

		static private HypGA __instance = null;
}