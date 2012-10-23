package fr.hyperfiction;

import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.Window;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.FrameLayout;
import android.widget.RelativeLayout;
import android.widget.LinearLayout;
import android.view.ViewGroup.LayoutParams;
import android.view.WindowManager;
import android.view.Gravity;
import org.haxe.nme.GameActivity;
import android.graphics.PixelFormat;
import android.app.Dialog;
import android.app.AlertDialog;

/**
 * ...
 * @author shoe[box]
 */

class HypWebView{

	private static String TAG = "trace";

	static public WebView mWebView;
	static public Dialog dialog;

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public HypWebView( ){
			trace("constructor");
		}
	
	// -------o public
				
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void open( String sURL , int iPosX , int iPosY , int iWidth , int iHeight ){
			trace("open ::: "+sURL+" || x : "+iPosX+" || y : "+iPosY+" || w : "+iWidth+" || h : "+iHeight);
			
			//
				LinearLayout.LayoutParams llp = new LinearLayout.LayoutParams( iWidth , iHeight );
				LinearLayout 	mLinearLayout = new LinearLayout( GameActivity.getContext() );
								mLinearLayout.setLayoutParams(llp);

			//
				dialog = new Dialog( GameActivity.getContext() );// , android.R.style.Theme_Translucent_NoTitleBar );
				dialog.requestWindowFeature(Window.FEATURE_NO_TITLE);
				dialog.getWindow().setLayout( iWidth , iHeight );
				//dialog.getWindow().setGravity( 0x00000035 );
				dialog.setContentView(mLinearLayout);
			
			//
				WindowManager.LayoutParams 	WMLP 		= dialog.getWindow().getAttributes();
											WMLP.x		= iPosX;
											WMLP.y		= iPosY;
											WMLP.width	= iWidth;
											WMLP.height	= iHeight;

			//
				mWebView = new WebView( GameActivity.getInstance( ) );
				mWebView.getSettings().setJavaScriptEnabled(true);
				mWebView.loadUrl( sURL );
				mWebView.setWebViewClient(new NMEWebViewClient());
				mLinearLayout.addView(mWebView);

			//
				WebSettings webSettings = mWebView.getSettings();
							webSettings.setJavaScriptEnabled(true);

			//
				dialog.getWindow().setAttributes( WMLP );
				//dialog.setContentView(mLinearLayout);
				dialog.show();

		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void close( ){
			dialog.cancel( );	
			mWebView = null;
			dialog = null;	
		}	

	// -------o protected
	
	// -------o misc
		
		public static void trace( String s ){
			Log.i( TAG, s );
		}

		static private class NMEWebViewClient extends WebViewClient {
			@Override
			public boolean shouldOverrideUrlLoading(WebView view, String url) {
				Log.e("NMEWebView","shouldOverrideUrlLoading " + url);
				view.loadUrl(url);
				return true;
			}
		}
	}