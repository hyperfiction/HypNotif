package fr.hyperfiction;

import android.util.Log;
import android.view.View;
import org.haxe.nme.GameActivity;

/**
 * ...
 * @author shoe[box]
 */

public class HypFacebookView extends View{

	private static String TAG = "trace";//HypFacebook";

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public HypFacebookView() {
			super( GameActivity.getContext( ) );
		}
	
	// -------o public
				
				

	// -------o protected
	
		

	// -------o misc
		
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		public static void trace( String s ){
			Log.w( TAG, s );
		}
}