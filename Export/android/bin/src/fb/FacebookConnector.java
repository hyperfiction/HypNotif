package fb;

import android.app.Activity;
import android.content.SharedPreferences.Editor;
import android.content.SharedPreferences;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import com.facebook.android.AsyncFacebookRunner;
import com.facebook.android.AsyncFacebookRunner.RequestListener;
import com.facebook.android.DialogError;
import com.facebook.android.Facebook.DialogListener;
import com.facebook.android.Facebook;
import com.facebook.android.FacebookError;
import com.facebook.android.SessionEvents.AuthListener;
import com.facebook.android.SessionEvents.LogoutListener;
import com.facebook.android.SessionStore;
import org.haxe.nme.GameActivity;
import 	android.content.pm.Signature;
import 	android.content.pm.PackageManager;
import 	android.content.pm.Signature;
import 	android.content.pm.PackageInfo;
import org.haxe.nme.NME;
import org.haxe.nme.HaxeObject;
import 	java.security.MessageDigest;
import fb.Base64;
import 	android.content.pm.PackageManager.NameNotFoundException;
import 		java.security.NoSuchAlgorithmException;
import com.facebook.android.Facebook.DialogListener;

public class FacebookConnector extends Activity implements DialogListener{
	
	private Facebook mFacebook;
	private SharedPreferences mPrefs;
	private HaxeObject mCallBack;
	
	// -------o public

		public FacebookConnector( HaxeObject cb ) {
			Log.i("trace","constructor");
			
			mCallBack = cb;
			mFacebook = new Facebook( "143901891377" );
			//import fr.hyperfiction.Tests.R;
			mPrefs =  GameActivity.getInstance( ).getPreferences(Activity.MODE_PRIVATE);
		}
	
		public void connect( ){

			try {
			   //PackageInfo info = GameActivity.getInstance( ).getPackageManager().getPackageInfo("**YOURPACKAGENAME**", PackageManager.GET_SIGNATURES);
			   PackageInfo info = GameActivity.getInstance( ).getPackageManager().getPackageInfo("fr.hyperfiction.Tests", PackageManager.GET_SIGNATURES);
			   for (Signature signature : info.signatures) {
			        MessageDigest md = MessageDigest.getInstance("SHA");
			        md.update(signature.toByteArray());
			        Log.i("trace", "PXR : "+Base64.encodeBytes(md.digest()));
			   }
			}
			catch (NameNotFoundException e) {
				Log.i("trace","NameNotFoundException : "+e);
			}
			catch (NoSuchAlgorithmException e) {
				Log.i("trace","NoSuchAlgorithmException : "+e);
			}
			
			String access_token = mPrefs.getString("access_token", null);
        	long expires = mPrefs.getLong("access_expires", 0);	

        	if(access_token != null) {
	            mFacebook.setAccessToken(access_token);
	        }
	        if(expires != 0) {
	            mFacebook.setAccessExpires(expires);
	        }

        	Log.i("trace","session valid : "+mFacebook.isSessionValid());
			if(!mFacebook.isSessionValid())
	         	_createSession( );
	        else
	        	_onSessionValid( );
	        	
		}

		@Override
	    public void onComplete( Bundle values ) {
	        Log.i("trace","onConnexion complete : "+mFacebook.getAccessToken());
	        SharedPreferences.Editor    editor = GameActivity.getInstance( ).getPreferences(Activity.MODE_PRIVATE).edit();
	                                    editor.putString("access_token", mFacebook.getAccessToken());
	                                    editor.putLong("access_expires", mFacebook.getAccessExpires());
	                                    editor.commit();     
 			mCallBack.call1( "onToken" , mFacebook.getAccessToken() );
 		}

	    @Override
	    public void onFacebookError( FacebookError error ) {
	        Log.i("trace","onConnexion error"+error);
	        
	    }

	    @Override
	    public void onError(DialogError e) {
	        Log.i("trace","onDialog Error"+e);
	    }

	    @Override
	    public void onCancel() {
	        Log.i("trace","onCancel");
	    }

  	// -------o protected

		private void _createSession( ){
			Log.i("trace","_createSession" );
			String[] mPermissions = new String[ ] { "publish_stream" };
			mFacebook.authorize( GameActivity.getInstance( ) , mPermissions , this );
		}

		private void _onSessionValid( ){
			mCallBack.call1( "onToken" , mFacebook.getAccessToken() );
			 mFacebook.dialog(GameActivity.getInstance( ), "feed",
                        new SampleDialogListener());
		}

	// -------o misc

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public static int nmeCreate( HaxeObject cb ){
			Log.i("trace","nmeCreate FacebookConnector ::: "+cb);
			mFb = new FacebookConnector( cb );
			mFb.connect( );
			return 0;
		}

		static private FacebookConnector mFb;
	


 class SampleDialogListener extends BaseDialogListener {

        public void onComplete(Bundle values) {
            final String postId = values.getString("post_id");
            if (postId != null) {
                Log.d("Facebook-Example", "Dialog Success! post_id=" + postId);
            } else {
                Log.d("Facebook-Example", "No wall post made");
            }
        }
    }

    public abstract class BaseDialogListener implements DialogListener {

    public void onFacebookError(FacebookError e) {
        e.printStackTrace();
    }

    public void onError(DialogError e) {
        e.printStackTrace();        
    }

    public void onCancel() {        
    }
    
}
}
