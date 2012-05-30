package fr.hyperfiction;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences.Editor;
import android.content.SharedPreferences;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager.NameNotFoundException;
import android.content.pm.PackageManager;
import android.content.pm.Signature;
import android.content.pm.Signature;
import android.os.Bundle;
import android.util.Log;
import com.facebook.android.AsyncFacebookRunner.RequestListener;
import com.facebook.android.AsyncFacebookRunner;
import com.facebook.android.DialogError;
import com.facebook.android.Facebook.DialogListener;
import com.facebook.android.Facebook.DialogListener;
import com.facebook.android.Facebook;
import com.facebook.android.FacebookError;
import com.facebook.android.SessionEvents.AuthListener;
import com.facebook.android.SessionEvents.LogoutListener;
import com.facebook.android.SessionStore;
import fr.hyperfiction.Base64;
import java.io.FileNotFoundException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import org.haxe.nme.GameActivity;
import org.haxe.nme.HaxeObject;
import org.haxe.nme.NME;
  import com.facebook.android.Facebook.DialogListener;

public class HypFacebook implements DialogListener{
	
	private HaxeObject 			_mCallBack;
	private Facebook 			_mFacebook;
	private SharedPreferences 	_mPrefs;

	private static String TAG = "trace";

	// -------o constructor

		public void HypFacebook( ){
			Log.i( TAG , "constructor" );
		}

	// -------o public

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void init( String appId , HaxeObject oCallback ){
			Log.i( TAG , "Init : "+appId+" callback : "+oCallback );
			_mCallBack = oCallback;
			_mFacebook = new Facebook( appId );
			_mPrefs    = GameActivity.getInstance( ).getPreferences( Activity.MODE_PRIVATE );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void connect( ){
			Log.i( TAG , "connect" );
			String sAccess_Token = _mPrefs.getString( "access_token" , null );
			long lExpire         = _mPrefs.getLong( "access_expires" , 0 );	

        	if( sAccess_Token != null) 
	            _mFacebook.setAccessToken( sAccess_Token );
	        
	        if( lExpire != 0 )
	            _mFacebook.setAccessExpires( lExpire );
	        
        	Log.i("trace","session valid : "+_mFacebook.isSessionValid());
			if(!_mFacebook.isSessionValid())
	         	_createSession( );
	        else
	        	_onSessionValid( );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void setCallBack( HaxeObject callbackFunc ) {
			//_fCallBack = fCallBack;
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void fbAppRequest( String sTitle , String sMessage ){
			
			Bundle 	params = new Bundle();
					params.putString("title"		, sTitle );
					params.putString("message"		, sMessage );
			
			try{
				_mFacebook.dialog( GameActivity.getInstance( ) , "apprequests", params , new Dialog_listener( ) );
			}
			catch( Throwable e ){
				_onError( e.toString( ) );
			}

		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void fbAppRequestToUser( String sTitle , String sMessage , String sUserId ){
			
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void fbFeed( 
								String sTitle,
								String sMessage,
								String sDescription,
								String sLink,
								String sPictureUrl
							){
			
			Bundle 	params = new Bundle();
					params.putString("caption"		, sTitle );
					params.putString("message"		, sMessage );
					params.putString("link"			, sLink );
					params.putString("description"	, sDescription);
					params.putString("picture"		, sPictureUrl );

			try{
				_mFacebook.dialog( GameActivity.getInstance( ) , "feed", params , new Dialog_listener( ) );
			}
			catch( Throwable e ){
				_onError( e.toString( ) );
			}
			
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@Override
	    public void onComplete( Bundle values ) {
	        Log.i("trace","onConnexion complete : "+_mFacebook.getAccessToken());
	       
	        SharedPreferences.Editor    editor = GameActivity.getInstance( ).getPreferences(Activity.MODE_PRIVATE).edit();
	                                    editor.putString("access_token", _mFacebook.getAccessToken());
	                                    editor.putLong("access_expires", _mFacebook.getAccessExpires());
	                                    editor.commit();     
 			_mCallBack.call2( "_onCallback" , "ON_LOGIN" , _mFacebook.getAccessToken() );
 		}

 		/**
		* 
		* 
		* @public
		* @return	void
		*/
	    @Override
	    public void onFacebookError( FacebookError e ) {
	        Log.i("trace","onConnexion error"+e);
	        _mCallBack.call2( "_onCallback" , "ON_FACEBOOK_ERROR" , e );
	        
	    }

	    /**
		* 
		* 
		* @public
		* @return	void
		*/
	    @Override
	    public void onError( DialogError e ) {
	        Log.i("trace","onDialog Error"+e);
	        _onError( e.toString( ) );
	    }

	    /**
		* 
		* 
		* @public
		* @return	void
		*/
	    @Override
	    public void onCancel( ) {
	        Log.i("trace","onCancel");
	        _mCallBack.call2( "_onCallback" , "ON_CANCEL" , null );
	    }

	// -------o private

	    /**
	    * 
	    * 
	    * @private
	    * @return	void
	    */
	    private void _createSession( ){
	    	Log.i( TAG ,"_createSession" );
			String[ ] mPermissions = new String[ ] { "publish_stream" };
			_mFacebook.authorize( 
									GameActivity.getInstance( ) , 
									mPermissions , 
									this 
								);
	    }

	    /**
	    * 
	    * 
	    * @private
	    * @return	void
	    */
	    private void _onSessionValid( ){
	    	Log.i( TAG ,"_onSessionValid");
	    	_mCallBack.call2( "_onCallback" , "ON_LOGIN" , _mFacebook.getAccessToken() );
	    }

	    /**
	    * 
	    * 
	    * @private
	    * @return	void
	    */
	    private void _onError( String sError ){
	    	_mCallBack.call2( "_onCallback" , "ON_ERROR" , sError );
	    }

	// -------o misc

	    /**
	    * 
	    * 
	    * @public
	    * @return	void
	    */
	    public static void hypfb_init( String appId , HaxeObject cb ){
	    	Log.i( TAG , "nme_init appId: "+appId +" and callback object ::: "+cb);
	    	__instance = new HypFacebook( );
	    	__instance.init( appId , cb );
	    }

	     /**
	    * 
	    * 
	    * @public
	    * @return	void
	    */
	    public static void hypfb_connect( ){
	    	Log.i( TAG , "hypfb_connect" );
	    	__instance.connect( );
	    }

	     /**
	    * 
	    * 
	    * @public
	    * @return	void
	    */
	    public static void hypfb_key_hash( String sName ){
	    	Log.i("trace", "nme_key_hash : "+sName );
	    	try {
			   //PackageInfo info = GameActivity.getInstance( ).getPackageManager().getPackageInfo("**YOURPACKAGENAME**", PackageManager.GET_SIGNATURES);
			   PackageInfo info = GameActivity.getInstance( ).getPackageManager( ).getPackageInfo( sName , PackageManager.GET_SIGNATURES );
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
	    }

	    /**
	    * 
	    * 
	    * @public
	    * @return	void
	    */
	    public static void hypfb_feed( 
	    								String sTitle,
										String sMessage,
										String sDescription,
										String sLink,
										String sPictureUrl 
									) {
	    	__instance.fbFeed( sTitle , sMessage , sDescription , sLink , sPictureUrl );
	    }

	    /**
	    * 
	    * 
	    * @public
	    * @return	void
	    */
	    public static void hypfb_apprequest( 
	    								String sTitle,
										String sMessage
	    								)  {
	    	__instance.fbAppRequest( sTitle , sMessage );
	    }

	    static private HypFacebook __instance;

	  	 /*
	     * callback for the feed dialog which updates the profile status
	     */
	    public class Dialog_listener extends BaseDialogListener {

	        @Override
	        public void onComplete(Bundle values) {
	            
	        }

	        @Override
	        public void onFacebookError(FacebookError error) {
		          
	        }

	        @Override
	        public void onCancel() {

	        }
	    }

		public abstract class BaseDialogListener implements DialogListener {

		    @Override
		    public void onFacebookError(FacebookError e) {
		        e.printStackTrace();
		    }

		    @Override
		    public void onError(DialogError e) {
		        e.printStackTrace();
		    }

		    @Override
		    public void onCancel() {

		    }

		}

}