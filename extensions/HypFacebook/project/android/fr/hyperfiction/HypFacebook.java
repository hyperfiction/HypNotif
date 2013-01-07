package fr.hyperfiction;

import com.facebook.*;
import com.facebook.model.GraphUser;
import com.facebook.widget.*;
import com.facebook.internal.SessionAuthorizationType;
import com.facebook.internal.SessionTracker;
import com.facebook.internal.Utility;

import android.app.Activity;
import android.content.SharedPreferences.Editor;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.util.Log;

<<<<<<< HEAD
import fr.hyperfiction.Base64;

import java.io.IOException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
=======
import com.facebook.android.*;
import com.facebook.android.Facebook.*;

import java.io.IOException;
>>>>>>> e8d2e589e80680aaccdd98e8e1bcbb7aa7d0bdfc
import java.util.Arrays;

import org.haxe.nme.GameActivity;
import org.haxe.nme.HaxeObject;
import org.haxe.nme.NME;

/**
 * ...
 * @author shoe[box]
 */
<<<<<<< HEAD

public class HypFacebook implements Session.StatusCallback{

	static public native void onFBEvent( String jsEvName , String javaArg1 , String javaArg2 );
	static{
		System.loadLibrary( "HypFacebook" );
	}

	private String _sAppID;
	private Session _session;
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

	private static String TAG				= "trace";//HypFacebook";
	private static String ARGS_SEPARATOR	= "-";	
	private static HypFacebook __instance	= null;

	private static String OPENED					= "OPENED";
	private static String FEEDDIALOG_CANCELED		= "FEEDDIALOG_CANCELED";
	private static String FEEDDIALOG_ERROR			= "FEEDDIALOG_ERROR";
	private static String FEEDDIALOG_SENT			= "FEEDDIALOG_SENT";
	private static String REQUESTDIALOG_CANCELED	= "REQUESTDIALOG_CANCELED";
	private static String REQUESTDIALOG_ERROR		= "REQUESTDIALOG_ERROR";
	private static String REQUESTDIALOG_SENT		= "REQUESTDIALOG_SENT";
	private static String GRAPH_REQUEST_ERROR		= "GRAPH_REQUEST_ERROR";
	private static String GRAPH_REQUEST_RESULTS		= "GRAPH_REQUEST_RESULTS";

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public HypFacebook( String sAppID ){
			trace("constructor ::: "+sAppID);
			_sAppID = sAppID;
		}
=======

public class HypFacebook extends Facebook implements DialogListener{

	static public native void onFBEvent( String jsEvName , String jsArgs );
	static{
		System.loadLibrary( "fb" );
	}

	private SharedPreferences _oPrefs;
	
	private static String TAG				= "trace";//HypFacebook";
	private static String ARGS_SEPARATOR	= "-";
	
	private static HypFacebook __instance	= null;


	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public HypFacebook( String sAppID ){
			super( sAppID );
			trace("constructor ::: "+sAppID);
			_oPrefs	= GameActivity.getInstance( ).getPreferences( Activity.MODE_PRIVATE );
		}
>>>>>>> e8d2e589e80680aaccdd98e8e1bcbb7aa7d0bdfc
	
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
<<<<<<< HEAD

			boolean bRes = true;

			_session = Session.getActiveSession( );
			if( _session == null || !_session.isOpened() || _session.isClosed() )
				bRes = false;

			return bRes;
=======
			String sAccess_Token	= _oPrefs.getString( "access_token" , null );
			long lExpire			= _oPrefs.getLong( "access_expires" , 0 );	

			trace( "connect" );
			trace( "sAccess_Token 	:::"+sAccess_Token );
			trace( "lExpire 		:::"+lExpire );

			if( sAccess_Token != null )
				setAccessToken( sAccess_Token );

			 if( lExpire != 0 )
	            setAccessExpires( lExpire );

	       	boolean bSessionValid = isSessionValid( );
	       	if( bSessionValid ){
	       		trace("session valide");
	       		SharedPreferences.Editor 	editor = _oPrefs.edit();
						                    editor.putString("access_token", sAccess_Token );
						                    editor.putLong("access_expires", lExpire );
						                    editor.commit( );
	       	}

	       	return bSessionValid;
>>>>>>> e8d2e589e80680aaccdd98e8e1bcbb7aa7d0bdfc
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
<<<<<<< HEAD
		public void logout( ){
			
=======
		public String logout( ){

			String res = null;

			try {
	           	res = logout(GameActivity.getContext( ) );
	        } catch (Exception e) {
	            Log.e("LogoutException",""+e.getMessage());
	        }

	        return res;
>>>>>>> e8d2e589e80680aaccdd98e8e1bcbb7aa7d0bdfc
		}		

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void authorize( String sPerms ) {
			trace("authorize");
<<<<<<< HEAD

			_session = new Session.Builder( GameActivity.getContext( ) ).setApplicationId( _sAppID ).build();
			Session.setActiveSession( _session );

			Session.OpenRequest req = new Session.OpenRequest( GameActivity.getInstance( ) );
								req.setPermissions(Arrays.asList( sPerms.split("&") ));
			_session.addCallback( this );
			_session.openForRead( req );
=======
			String[ ] a_permissions = sPerms.split("|");
			trace("a_permissions ::: "+a_permissions);

			DialogListener listener = new DialogListener( ){

				@Override
				public void onComplete( Bundle values ){
					trace("onComplete ::: "+values);
					_on_event( "authorize_onComplete" , values.get("access_token")+"" );
				}

				@Override
				public void onFacebookError( FacebookError e ){
					trace("onFacebookError ::: "+e);
					_on_event( "authorize_onComplete" , e.getErrorCode( ) + ARGS_SEPARATOR + e.getErrorType( ) );
				}

				@Override
				public void onError( DialogError e ){
					trace("onError ::: "+e);
					_on_event( "authorize_dialog_error" , e.getErrorCode( ) + ARGS_SEPARATOR + e.getFailingUrl( ) );
				}

				@Override
				public void onCancel( ){
					trace("onCancel ::: ");
					_on_event( "authorize_dialog_cancel" , "" );
				}

			};

			trace("authorize");
			authorize( GameActivity.getInstance( ) , a_permissions , listener );
			trace("ok");
>>>>>>> e8d2e589e80680aaccdd98e8e1bcbb7aa7d0bdfc
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
<<<<<<< HEAD
		public void requestDialog( String sKeys , String sVals ){
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
				WebDialog 	requestsDialog = new WebDialog.RequestsDialogBuilder( GameActivity.getInstance() , Session.getActiveSession() , params).build();
							requestsDialog.setOnCompleteListener( listener_request_dialog );
							requestsDialog.show( );
		        
=======
		public void dialog( String sAction , String sParamsNames , String sParamsValues ){
			trace("dialog ::: "+sAction+" - "+sParamsNames+" - "+sParamsValues);	

			//Split to array
				String[ ] aParams = sParamsNames.split( ARGS_SEPARATOR );	
				String[ ] aValues = sParamsValues.split( ARGS_SEPARATOR );	
				trace("aParams ::: "+aParams.length);
				
			//Bundle
				int l = aParams.length;
				trace("l ::: "+l);
				Bundle params = new Bundle( );
				for( int i = 0 ; i<l ; i++ ){
					trace("i ::: "+i+"|"+aParams[i]+" = "+aValues[i]);
					params.putString( aParams[ i ] , aValues[ i ] );
				}
				trace("params ::: "+params);

			//	
				DialogListener listener = new DialogListener( ){

					@Override
					public void onComplete( Bundle values ){
						trace("onComplete ::: "+values);
					}

					@Override
					public void onFacebookError( FacebookError e ){
						trace("onFacebookError ::: "+e);
					}

					@Override
					public void onError( DialogError e ){
						trace("onError ::: "+e);
					}

					@Override
					public void onCancel( ){
						trace("onCancel ::: ");
					}

				};
				dialog( GameActivity.getContext( ) , sAction , params , listener );
			
>>>>>>> e8d2e589e80680aaccdd98e8e1bcbb7aa7d0bdfc
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
<<<<<<< HEAD
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
		        
=======
		public String graph_request( String sGraphRequest ){
			trace("graph_request ::: "+sGraphRequest);
			String res = null;
			try {
				res = request( sGraphRequest );
			} catch (IOException e) {
				trace("graph_request exception ::: "+e);
				e.printStackTrace();
			}
			return res;			
>>>>>>> e8d2e589e80680aaccdd98e8e1bcbb7aa7d0bdfc
		}

		//Dialog listeners

		/**
		* 
		* 
		* @public
		* @return	void
		*/
<<<<<<< HEAD
		public void dialog( String sAction , String sParamsNames , String sParamsValues ){
			
			
		}
=======
		 @Override
        public void onComplete(Bundle values) {
        	    
        }

>>>>>>> e8d2e589e80680aaccdd98e8e1bcbb7aa7d0bdfc

		/**
		* 
		* 
		* @public
		* @return	void
		*/
<<<<<<< HEAD
		public void graph_request( String sGraphRequest ){
			trace("request ::: "+sGraphRequest);
			Request req = new Request( Session.getActiveSession( ) , sGraphRequest , null , null , listener_request );
					req.executeAsync( );

		}
=======
        @Override
        public void onFacebookError(FacebookError error) {
	          
        }

>>>>>>> e8d2e589e80680aaccdd98e8e1bcbb7aa7d0bdfc

		/**
		* 
		* 
		* @public
		* @return	void
		*/
<<<<<<< HEAD
		public void call(Session session, SessionState state, Exception exception){
			
			final String s = session.getState( ).toString( );
			if( s == OPENED )
				onFBEvent( s , session.getAccessToken( ) , "" );
			else
				onFBEvent( s , "" , "" );

		}

	// -------o protected
	
	// -------o misc
		
=======
        @Override
        public void onCancel() {

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
	    }

	// -------o protected
	
>>>>>>> e8d2e589e80680aaccdd98e8e1bcbb7aa7d0bdfc
		/**
		* 
		* 
		* @private
		* @return	void
		*/
<<<<<<< HEAD
		public static void trace( String s ){
			Log.w( TAG, s );
=======
		private void _onSessionValid( ){
			trace( "_onSessionValid" );
>>>>>>> e8d2e589e80680aaccdd98e8e1bcbb7aa7d0bdfc
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
<<<<<<< HEAD
		public static HypFacebook create( String sAppId ){
			Log.i( TAG, "create ::: "+sAppId );			
			return __instance = new HypFacebook( sAppId );
		}

=======
		private void _on_event( String sType , String sConcatArgs ){
			trace("_on_event ::: "+sType+" = "+sConcatArgs);
			onFBEvent( sType , sConcatArgs );
		}

	// -------o misc
		
>>>>>>> e8d2e589e80680aaccdd98e8e1bcbb7aa7d0bdfc
		/**
		* 
		* 
		* @public
		* @return	void
		*/
<<<<<<< HEAD
		static void req_dialog( String sKeys , String sVals ){
			__instance.requestDialog( sKeys , sVals );
=======
		public static void trace( String s ){
			Log.w( TAG, s );
>>>>>>> e8d2e589e80680aaccdd98e8e1bcbb7aa7d0bdfc
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
<<<<<<< HEAD
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
			   //PackageInfo info = GameActivity.getInstance( ).getPackageManager().getPackageInfo("**YOURPACKAGENAME**", PackageManager.GET_SIGNATURES);
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
	
=======
		public static HypFacebook create( String sAppId ){
			Log.i( TAG, "create ::: "+sAppId );			
			return __instance = new HypFacebook( sAppId );
		}

	//JNI
		static public native void onConnect( );
		static {
			System.loadLibrary( "fb" );
		}
>>>>>>> e8d2e589e80680aaccdd98e8e1bcbb7aa7d0bdfc
}