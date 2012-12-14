package fr.hyperfiction;

import android.app.Activity;
import android.content.SharedPreferences.Editor;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.util.Log;

import com.facebook.android.*;
import com.facebook.android.Facebook.*;

import java.io.IOException;
import java.util.Arrays;

import org.haxe.nme.GameActivity;
import org.haxe.nme.HaxeObject;
import org.haxe.nme.NME;

/**
 * ...
 * @author shoe[box]
 */

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
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public String logout( ){

			String res = null;

			try {
	           	res = logout(GameActivity.getContext( ) );
	        } catch (Exception e) {
	            Log.e("LogoutException",""+e.getMessage());
	        }

	        return res;
		}		

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void authorize( String sPerms ) {
			trace("authorize");
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
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
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
			
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
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
		}

		//Dialog listeners

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		 @Override
        public void onComplete(Bundle values) {
        	    
        }


		/**
		* 
		* 
		* @public
		* @return	void
		*/
        @Override
        public void onFacebookError(FacebookError error) {
	          
        }


		/**
		* 
		* 
		* @public
		* @return	void
		*/
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
	
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private void _onSessionValid( ){
			trace( "_onSessionValid" );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private void _on_event( String sType , String sConcatArgs ){
			trace("_on_event ::: "+sType+" = "+sConcatArgs);
			onFBEvent( sType , sConcatArgs );
		}

	// -------o misc
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public static void trace( String s ){
			Log.w( TAG, s );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public static HypFacebook create( String sAppId ){
			Log.i( TAG, "create ::: "+sAppId );			
			return __instance = new HypFacebook( sAppId );
		}

	//JNI
		static public native void onConnect( );
		static {
			System.loadLibrary( "fb" );
		}
}