package fr.hyperfiction;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.view.View;
import android.view.KeyEvent;
import org.haxe.nme.GameActivity;
import android.content.Context;
import android.widget.RelativeLayout;

/**
 * ...
 * @author shoe[box]
 */
class HypWebView extends WebView{

	private static String TAG = "HypWebView";

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public HypWebView( ) {
			
			super( GameActivity.getContext( ) );
			Log.i( TAG, " constructor" );
			WebSettings webSettings = getSettings();
					    webSettings.setSavePassword(false);
					    webSettings.setSaveFormData(false);
					    webSettings.setJavaScriptEnabled(true);
					    webSettings.setSupportZoom(false);

			setWebViewClient(new NMEWebViewClient());
			RelativeLayout.LayoutParams p = new RelativeLayout.LayoutParams(LayoutParams.FILL_PARENT, 416);
			setLayoutParams(p);
		}
	
	// -------o public				

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void open( String sURL , int iPosX , int iPosY , int iWidth , int iHeight ){
			Log.i( TAG, " open ::: "+sURL );
			setMinimumWidth( iWidth );
			setMinimumHeight( iHeight );
			loadUrl( sURL );
			GameActivity.pushView( this );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public void close(){
			GameActivity.popView( );	
		}

	// -------o protected
	
	// -------o misc
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public HypWebView getInstance( ){		
			if( __instance == null )
				__instance = new HypWebView( );

			return __instance;
		}

		static private HypWebView __instance = null;


		private class NMEWebViewClient extends WebViewClient {
			@Override
			public boolean shouldOverrideUrlLoading(WebView view, String url) {
				Log.e("NMEWebView","shouldOverrideUrlLoading " + url);
				view.loadUrl(url);
				return true;
			}
		}
}