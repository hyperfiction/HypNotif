package fr.hyperfiction;

import	::APP_PACKAGE::.R;

import android.app.AlertDialog;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.net.ConnectivityManager;
import android.os.Build.VERSION_CODES;
import android.os.Build;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup.LayoutParams;
import android.view.Window;
import android.widget.ProgressBar;

import java.util.Locale;

import org.haxe.nme.GameActivity;


/**
 * ...
 * @author shoe[box]
 */

class HypSystem{

	private static String TAG = "HypSystem";

	private static LoadingDialog dialog_progress;

	public static final int TABLET_MIN_DP_WEIGHT = 450;

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		private void HypSystem() {
			Log.i( TAG, " constructor" );
		}
	
	// -------o public
				
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public boolean isConnectedtoInternet() {

			trace("activity ::: "+GameActivity.getInstance( ));
			ConnectivityManager conMgr = (ConnectivityManager) GameActivity.getContext( ).getSystemService(Context.CONNECTIVITY_SERVICE);
		    Boolean res = false;
		    if (conMgr.getActiveNetworkInfo() != null
		            && conMgr.getActiveNetworkInfo().isAvailable()
		            && conMgr.getActiveNetworkInfo().isConnected()) {
		        trace("Internet Connection  Present");
		        res=true;
		    } else {
		        trace("Internet Connection Not Present");
		        res= false;
		    }
		    trace("isConnectedtoInternet ::: "+res);
		    return res;

		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public boolean is_a_phone( ){
			
		    DisplayMetrics metrics = new DisplayMetrics();
		    GameActivity.getInstance( ).getWindowManager().getDefaultDisplay().getMetrics(metrics);

		    int dpi = 0;
		    if (metrics.widthPixels < metrics.heightPixels){
		        dpi = (int) (metrics.widthPixels / metrics.density);
		    }else{
		        dpi = (int) (metrics.heightPixels / metrics.density);
		    }

		   return dpi < TABLET_MIN_DP_WEIGHT;
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public String get_screen_bucket( ){
			DisplayMetrics dm = new DisplayMetrics();
			GameActivity.getInstance( ).getWindowManager().getDefaultDisplay().getMetrics(dm);	
			trace("bucket : "+dm.densityDpi);

			String sRes = "mdpi";

			switch( dm.densityDpi ){

				case DisplayMetrics.DENSITY_LOW :
					sRes = "ldpi";
					break;

				/*
				case DisplayMetrics.DENSITY_DEFAULT:
					sRes = "mdpi";
					break;
				*/

				case DisplayMetrics.DENSITY_MEDIUM:
					sRes = "mdpi";
					break;

				case DisplayMetrics.DENSITY_HIGH:
					sRes = "hdpi";
					break;

				case DisplayMetrics.DENSITY_XHIGH :
					sRes = "xhdpi";
					break;

				/*
				case DisplayMetrics.DENSITY_XXHIGH :
					sRes = "xxhdpi";
					break;
				*/
			}

			return sRes;	
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void show_loading( ){
			GameActivity.getInstance( ).runOnUiThread(
				new Runnable(){
	                @Override
	                public void run() {
	                	if( dialog_progress == null )
	                    	dialog_progress = new LoadingDialog( GameActivity.getContext( ) );
							dialog_progress.show( );
	                }                   
		        }
            );			
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void hide_loading( ){
			trace("hide_loading");
			GameActivity.getInstance( ).runOnUiThread(
				new Runnable(){
	                @Override
	                public void run() {
	                	if( dialog_progress != null )
	                    	dialog_progress.hide( );
	                }                   
		        }
            );			
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void dismiss_loading( ){
			trace("dismiss_loading");
			GameActivity.getInstance( ).runOnUiThread(
				new Runnable(){
	                @Override
	                public void run() {
	                	if( dialog_progress != null )
	                    	dialog_progress.dismiss( );
	                    	dialog_progress = null;
	                }                   
		        }
            );			
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void show_error_dialog( String error_msg ){
			trace("show_error_dialog ::: "+error_msg);
			AlertDialog.Builder builder = new AlertDialog.Builder( GameActivity.getContext( ) );  
           						builder.setMessage( error_msg );  
           						builder.setNegativeButton("OK", new DialogInterface.OnClickListener() {  
                @Override  
                public void onClick(DialogInterface dialog, int which) {  
                     dialog.cancel();  
                }  
           });  
           AlertDialog 	alert = builder.create();  
          				alert.show();  
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public String get_system_language( ){
			return Locale.getDefault().getLanguage();
		}


	// -------o protected
	
		

	// -------o misc
		
		public static void trace( String s ){
			Log.i( TAG, s );
		}

	static class LoadingDialog extends Dialog{

		ProgressBar pb;

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public LoadingDialog( final Context context ){
			super( context , R.style.CustomDialogTheme );

			addContentView( pb = new ProgressBar( GameActivity.getContext( ) ) ,  new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT));

			//getWindow().setBackgroundDrawableResource(R.color.bg_tran);
		}
	}
}