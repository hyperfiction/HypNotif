package fr.hyperfiction;

import android.util.Log;
import com.google.android.apps.analytics.GoogleAnalyticsTracker;
import org.haxe.nme.GameActivity;

/**
 * ...
 * @author shoe[box]
 */
public class HypGA{

	private static String TAG = "HypGA";

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
		static public void set_dispatch_period( int iPeriod ) {
			Log.i( TAG, " set_dispatch_period : "+iPeriod );
			GoogleAnalyticsTracker.getInstance( ).setDispatchPeriod( iPeriod );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void startNewSession( String sUA_code ){
			Log.i( TAG, " startNewSession : "+sUA_code );
			GoogleAnalyticsTracker.getInstance( ).startNewSession( sUA_code , GameActivity.getInstance( ) );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void trackEvent( String sCat , String sAction , String sLabel , int val ){
			Log.i( TAG, "trackEvent : cat "+sCat+" || action : "+sAction+" || label : "+sLabel+" || val : "+val );
			GoogleAnalyticsTracker.getInstance( ).trackEvent( sCat , sAction , sLabel , val );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void trackPageView( String sPage ){
			Log.i( TAG, "trackPageView : "+sPage );
			GoogleAnalyticsTracker.getInstance( ).trackPageView( sPage );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void stopSession( ){
			Log.i( TAG, "stopSession");
			GoogleAnalyticsTracker.getInstance( ).stopSession( );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void setCustomVar( int iSlot , String sName , String sValue ){
			GoogleAnalyticsTracker.getInstance( ).setCustomVar( iSlot , sName , sValue );
		}

	// -------o protected
	
	// -------o misc
		
		
}