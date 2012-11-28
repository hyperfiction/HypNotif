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

import com.facebook.android.*;
import com.facebook.android.AsyncFacebookRunner;
import com.facebook.android.AsyncFacebookRunner.RequestListener;
import com.facebook.android.Facebook.*;

import fr.hyperfiction.Base64;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.MalformedURLException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import org.haxe.nme.GameActivity;
import org.haxe.nme.HaxeObject;
import org.haxe.nme.NME;

public class HypFacebook implements DialogListener{
	
	static public native void onConnect( );
	static {
		System.loadLibrary( "fb" );
	}

	static private Facebook 			_mFacebook;
	static private HaxeObject 			_mCallBack;
	static private SharedPreferences 	_mPrefs;
	static private String[ ] 			_aPerms;

	private static String TAG = "HypFB";

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
		static public Facebook get_fb_instance( ){
			return _mFacebook;
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public String get_token( ) {
			return _mFacebook.getAccessToken( );		
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void init( String appId , HaxeObject oCallback , String sPerms ){
			Log.i( TAG , "Init : "+appId+" callback : "+oCallback );
			_aPerms		= sPerms.split("|");
			_mCallBack	= oCallback;
			_mFacebook	= new Facebook( appId );
			_mPrefs		= GameActivity.getInstance( ).getPreferences( Activity.MODE_PRIVATE );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public String request( final String graphpath ){

			Log.i( TAG , "request : "+graphpath );

			String res = null;
			try {
				res = _mFacebook.request( graphpath );
				Log.i( TAG , "response : "+res );
			} catch (IOException e) {
				e.printStackTrace();
			}
			return res;
			
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void connect( ){

			String sAccess_Token	= _mPrefs.getString( "access_token" , null );
			long lExpire			= _mPrefs.getLong( "access_expires" , 0 );	

			Log.i( TAG , "connect" );
			Log.i( TAG , "sAccess_Token 	:::"+sAccess_Token );
			Log.i( TAG , "lExpire 			:::"+lExpire );

        	if( sAccess_Token != null) 
	            _mFacebook.setAccessToken( sAccess_Token );
	        
	        if( lExpire != 0 )
	            _mFacebook.setAccessExpires( lExpire );
	        
        	Log.i("trace","session valid : "+_mFacebook.isSessionValid());
			if(!_mFacebook.isSessionValid()){
	         	_createSession( );
	        }else{
	        	Log.i( TAG , "Sessions is valid :::"+sAccess_Token );

	        	SharedPreferences.Editor editor = _mPrefs.edit();
                    editor.putString("access_token", sAccess_Token );
                    editor.putLong("access_expires", lExpire );
                    editor.commit( );
	        	onConnect( );
	        }
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
 			//_mCallBack.call2( "_onCallback" , "ON_LOGIN" , _mFacebook.getAccessToken() );

			_on_connected( );
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
	   static private void _createSession( ){
	    	Log.i( TAG ,"_createSession" );
			_mFacebook.authorize( 
									GameActivity.getInstance( ) , 
									_aPerms , 
									getInstance( ) 
								);
	    }

	    private void _on_connected( ){
	    	Log.i( TAG , "_on_connected ::: "+_mFacebook.getAccessToken());
	    	onConnect( );
	    }

	    /**
	    * 
	    * 
	    * @private
	    * @return	void
	    */
	    private void _onSessionValid( ){
	    	Log.i( TAG ,"_onSessionValid");
	    	//_mCallBack.call2( "_onCallback" , "ON_LOGIN" , _mFacebook.getAccessToken() );
	    	_on_connected( );
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
	    public static HypFacebook getInstance( ){
	    	
	    	if( __instance == null )
	    		__instance = new HypFacebook( );

	    	return __instance;
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