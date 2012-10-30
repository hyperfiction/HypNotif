package fr.hyperfiction;

import android.util.Log;
import android.provider.Settings.Secure;

import com.google.android.vending.licensing.AESObfuscator;
import com.google.android.vending.licensing.LicenseChecker;
import com.google.android.vending.licensing.LicenseCheckerCallback;
import com.google.android.vending.licensing.Policy;
import com.google.android.vending.licensing.ServerManagedPolicy;

import org.haxe.nme.GameActivity;
import org.haxe.nme.HaxeObject;

/**
 * ...
 * @author shoe[box]
 */
public class HypLicensing implements LicenseCheckerCallback{

	private LicenseChecker mChecker;
	private HaxeObject mCallback;

	private static String TAG = "HypLicensing";
	private static final byte[] SALT = new byte[] {
        -46, 65, 30, -128, -103, -57, 74, -64, 51, 88, -95, -45, 77, -117, -36, -113, -11, 32, -64,
        89
    };

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		private void HypLicensing() {
			Log.i( TAG, " constructor" );
		}
	
	// -------o public				

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void run( final String sPublicKey , final HaxeObject cb ) {
			Log.i( TAG, "run ::: " );

			//
				String deviceId = Secure.getString(GameActivity.getContext().getContentResolver(), Secure.ANDROID_ID);
				Log.i( TAG, "deviceId ::: "+deviceId );
				Log.i( TAG, "package  ::: "+GameActivity.getContext().getPackageName() );
				AESObfuscator aes = new AESObfuscator( SALT, GameActivity.getContext().getPackageName(), deviceId );
				ServerManagedPolicy pol = new ServerManagedPolicy( GameActivity.getContext(), aes );

			//
	        	mCallback = cb;

	        //
				mChecker = new LicenseChecker( GameActivity.getContext(), pol ,sPublicKey );
		        mChecker.checkAccess( this );

		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void allow(int policyReason) {
			mCallback.call1("allow",policyReason);
			Log.i( TAG, "allow ::: "+policyReason );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void dontAllow(int policyReason) {
			mCallback.call1("dontAllow",policyReason);
			Log.i( TAG, "dontAllow ::: "+policyReason );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void applicationError(int errorCode) {
			mCallback.call1("applicationError",errorCode);		
			Log.i( TAG, "applicationError ::: "+errorCode );
		}

	// -------o protected
	
	// -------o misc
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public HypLicensing getInstance( ){
			if( __instance == null )
				__instance = new HypLicensing( );

			return __instance;
		}

		private static HypLicensing __instance = null;
}