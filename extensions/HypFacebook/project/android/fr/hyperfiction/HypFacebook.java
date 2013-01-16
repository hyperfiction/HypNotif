package fr.hyperfiction;

import com.facebook.*;
import com.facebook.model.GraphUser;
import com.facebook.widget.*;
import com.facebook.internal.SessionAuthorizationType;
import com.facebook.internal.SessionTracker;
import com.facebook.internal.Utility;

import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentActivity;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;

import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.Signature;
import android.app.Activity;
import android.content.SharedPreferences.Editor;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.content.pm.PackageManager.NameNotFoundException;
import android.util.Log;
import android.widget.FrameLayout;

import fr.hyperfiction.Base64;

import java.io.IOException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import java.util.Arrays;

import org.haxe.nme.GameActivity;
import org.haxe.nme.HaxeObject;
import org.haxe.nme.NME;

import ::APP_PACKAGE::.R;

/**
 * ...
 * @author shoe[box]
 */
public class HypFacebook implements Session.StatusCallback{

	static public native void onFBEvent( String jsEvName , String javaArg1 , String javaArg2 );
	static{
		System.loadLibrary( "HypFacebook" );
	}

	private String _sAppID;
	private HypFacebookFrag _oFrag;

	private static HypFacebook __instance			= null;
	private static String ARGS_SEPARATOR			= "-";	
	private static String FEEDDIALOG_CANCELED		= "FEEDDIALOG_CANCELED";
	private static String FEEDDIALOG_ERROR			= "FEEDDIALOG_ERROR";
	private static String FEEDDIALOG_SENT			= "FEEDDIALOG_SENT";
	private static String GRAPH_REQUEST_ERROR		= "GRAPH_REQUEST_ERROR";
	private static String GRAPH_REQUEST_RESULTS		= "GRAPH_REQUEST_RESULTS";
	private static String OPENED					= "OPENED";
	private static String REQUESTDIALOG_CANCELED	= "REQUESTDIALOG_CANCELED";
	private static String REQUESTDIALOG_ERROR		= "REQUESTDIALOG_ERROR";
	private static String REQUESTDIALOG_SENT		= "REQUESTDIALOG_SENT";
	private static String TAG						= "trace";//HypFacebook";

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public HypFacebook( String sAppID ){
			trace("constructor ::: "+sAppID);
			_oFrag = HypFacebookFrag.getInstance( );
			_sAppID = sAppID;
		}

	// -------o public
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public static HypFacebook getInstance( ){
			return __instance;
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public boolean connect( ){
			trace("connect");
			boolean bRes = true;

			//Session
				Session session = Session.getActiveSession( );						
				if( session == null || !session.isOpened() || session.isClosed() ){
					session = new Session.Builder( GameActivity.getContext( ) ).setApplicationId( _sAppID ).build( );
					Session.setActiveSession( session );
					bRes = false;
				}

				session.addCallback( this );

			return false;
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void call_callback( final String s , final String sArg1 , final String sArg2 ){
			onFBEvent( s , sArg1 , sArg2 );	
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void logout( ){

		}		

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void authorize( final String sPerms ) {
			trace("authorize");
			
			//
				GameActivity.getInstance( ).runOnUiThread(
					new Runnable(){
		                @Override
		                public void run() {
		                	
	            			_oFrag.setPermissions(Arrays.asList( sPerms.split("&") ));

	            			FragmentTransaction ft = GameActivity.getInstance( ).getSupportFragmentManager( ).beginTransaction( );
	            								ft.add( android.R.id.content , _oFrag ).commit( );
	            								
		                }
		            });

		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void requestDialog( String sKeys , String sVals ){
			
			trace("sKeys ::: "+sKeys);
			trace("sVals ::: "+sVals);

			String[] aKeys = sKeys.split("&");
			String[] aVals = sVals.split("&");

			//Parameters bundle
				Bundle params = new Bundle( );

				for( int i = 0 ; i < aKeys.length ; i++ ){
					params.putString( aKeys[ i ] , aVals[ i ] );
				}

			//
				WebDialog 	requestsDialog = new WebDialog.RequestsDialogBuilder( GameActivity.getInstance() , Session.getActiveSession() , params).build();
							requestsDialog.setOnCompleteListener( listener_request_dialog );
							requestsDialog.show( );
		     
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void feedDialog( String sKeys , String sVals ){
			
			trace("sKeys ::: "+sKeys);
			trace("sVals ::: "+sVals);

			String[] aKeys = sKeys.split("&");
			String[] aVals = sVals.split("&");

			//Parameters bundle
				Bundle params = new Bundle( );

				for( int i = 0 ; i < aKeys.length ; i++ ){
					trace("---"+i);
					params.putString( aKeys[ i ] , aVals[ i ] );
				}
				
			//
				WebDialog 	requestsDialog = new WebDialog.FeedDialogBuilder( GameActivity.getInstance() , Session.getActiveSession() , params).build();
							requestsDialog.setOnCompleteListener( listener_feed_dialog );
							requestsDialog.show( );
		   
		}

		//Dialog listeners

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void dialog( String sAction , String sParamsNames , String sParamsValues ){
			
			
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void graph_request( String sGraphRequest ){
			
			trace("request ::: "+sGraphRequest);
			Request req = new Request( Session.getActiveSession( ) , sGraphRequest , null , null , listener_request );
					req.executeAsync( );
			
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void call(Session session, SessionState state, Exception exception){
			trace("call ::: "+session);
			final String s = session.getState( ).toString( );
			if( s == OPENED )
				onFBEvent( s , session.getAccessToken( ) , "" );
			else
				onFBEvent( s , "" , "" );
		}

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

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		public static HypFacebook create( String sAppId ){
			Log.i( TAG, "HypFacebook :: create ::: "+sAppId );			
			return __instance = new HypFacebook( sAppId );
		}

	// -------o misc

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static void req_dialog( String sKeys , String sVals ){
			__instance.requestDialog( sKeys , sVals );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static void feed_dialog( String sKeys , String sVals ){
			__instance.feedDialog( sKeys , sVals );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static void jni_graph_request( String sGraphPath ){
			__instance.graph_request( sGraphPath );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static void jni_logout( ){
			__instance.logout( );
		}

		public static void trace_hash( ){
			trace("trace_hash");
	    	
	    	
	    	Log.i("trace", "nme_key_hash : +::APP_PACKAGE:: ");
	    	try {
			   PackageInfo info = GameActivity.getInstance( ).getPackageManager( ).getPackageInfo( "::APP_PACKAGE::" , PackageManager.GET_SIGNATURES );
			   for (Signature signature : info.signatures) {
			        MessageDigest 	md = MessageDigest.getInstance("SHA");
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


		private WebDialog.OnCompleteListener listener_feed_dialog = new WebDialog.OnCompleteListener( ){
						
						@Override
		            	public void onComplete(Bundle values, FacebookException error) {
		            		trace("onComplete");
		            		if( error != null ){
		            			onFBEvent( FEEDDIALOG_ERROR , error.toString( ) , "" );
		            		}else{
		            			final String postId = values.getString("post_id");
		            			if ( postId != null )
		            				onFBEvent( FEEDDIALOG_SENT , postId , "" );
		            			else
		            				onFBEvent( FEEDDIALOG_CANCELED , "" , "" );
		            		}
		            	}
					};

		private WebDialog.OnCompleteListener listener_request_dialog = new WebDialog.OnCompleteListener( ){
						
						@Override
		            	public void onComplete(Bundle values, FacebookException error) {
		            		trace("onComplete");
		            		if( error != null ){
		            			onFBEvent( REQUESTDIALOG_ERROR , error.toString( ) , "" );
		            		}else{
		            			final String requestId = values.getString("request");
		            			if (requestId != null)
		            				onFBEvent( REQUESTDIALOG_SENT , requestId , "" );
		            			else
		            				onFBEvent( REQUESTDIALOG_CANCELED , "" , "" );
		            		}
		            	}
					};

		private Request.Callback listener_request = new Request.Callback( ){

			@Override
		    public void onCompleted(Response response) {
				
		    	String sGraphPath = response.getRequest( ).getGraphPath( );

				FacebookRequestError error = response.getError( );
				if( error != null ){
					trace( "error : "+error );
					onFBEvent( REQUESTDIALOG_ERROR , sGraphPath , error.toString( ) );
				}else{
					onFBEvent( GRAPH_REQUEST_RESULTS , sGraphPath , response.getGraphObject( ).getInnerJSONObject().toString() );
				}

			}

		};

		private class SessionStatusCallback implements Session.StatusCallback {
		        
		    @Override
		    public void call( final Session session , SessionState state, Exception exception) {
		    	call_callback( session.getState( ).toString( ) , "" , "" );
		    }

		}
		private Session.StatusCallback statusCallback = new SessionStatusCallback( );

}