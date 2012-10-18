package fr.hyperfiction;

import android.os.Build;
import android.os.Build.VERSION_CODES;
import android.content.Context;
import android.net.ConnectivityManager;
import android.util.Log;
import android.view.View;
import org.haxe.nme.GameActivity;

/**
 * ...
 * @author shoe[box]
 */

class HypSystem{

	private static String TAG = "HypSystem";

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		private void HypSystem() {
			Log.i( TAG, " constructor" );
		}
	
	// -------o public
				
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public boolean isConnectedtoInternet() {

			trace("activity ::: "+GameActivity.getInstance( ));
			ConnectivityManager conMgr = (ConnectivityManager) GameActivity.getContext( ).getSystemService(Context.CONNECTIVITY_SERVICE);
		    Boolean res = false;
		    if (conMgr.getActiveNetworkInfo() != null
		            && conMgr.getActiveNetworkInfo().isAvailable()
		            && conMgr.getActiveNetworkInfo().isConnected()) {
		        trace("Internet Connection  Present");
		        res=true;
		    } else {
		        trace("Internet Connection Not Present");
		        res= false;
		    }
		    trace("isConnectedtoInternet ::: "+res);
		    return res;

		}


	// -------o protected
	
		

	// -------o misc
		
		public static void trace( String s ){
			Log.i( TAG, s );
		}
}