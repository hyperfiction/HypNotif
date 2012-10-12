package fr.hyperfiction;

import android.util.Log;
import org.haxe.nme.GameActivity;
import org.acra.*;
import org.acra.sender.*;
import org.acra.annotation.*;

/**
 * ...
 * @author shoe[box]
 */
public class HypAcra{

	private static String TAG = "debug";

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
		static public void run_acra( String sCode ) {
			Log.i( TAG, "run ::: "+sCode );
			//ACRAConfiguration.setFormKey( sCode );
			ACRA.init( GameActivity.getInstance( ).getApplication( ) );
			ACRA.getConfig( ).setFormKey( sCode );
			//https://docs.google.com/spreadsheet/viewform?formkey=dFA4VjFJc0FjcXp3aWR6eW9wSWxqeFE6MQ
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