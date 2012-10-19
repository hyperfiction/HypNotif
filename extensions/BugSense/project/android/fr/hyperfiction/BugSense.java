package fr.hyperfiction;

import android.util.Log;
import org.haxe.nme.GameActivity;
import com.bugsense.trace.BugSenseHandler; 


/**
 * ...
 * @author shoe[box]
 */
public class BugSense{

	private static String TAG = "trace";

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		private void BugSense() {
			Log.i( TAG, " constructor" );
		}
	
	// -------o public				

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void run( final String sApiKey ) {
			Log.i( TAG, "run ::: "+sApiKey );
			GameActivity.getInstance( ).runOnUiThread(
				new Runnable(){
	                @Override
	                public void run() {
	                	BugSenseHandler.initAndStartSession( GameActivity.getContext( ) , sApiKey );
	                }                   
		        }
            );			
			
		}

	// -------o protected
	
	// -------o misc
		
}