package fr.hyperfiction;

import ::APP_PACKAGE::.R;

import android.widget.ProgressBar;
import android.content.Context;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.content.pm.ActivityInfo;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.media.MediaPlayer.OnPreparedListener;
import android.media.MediaPlayer;
import android.net.Uri;
import android.os.Bundle;
import android.support.v4.app.DialogFragment;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.FrameLayout.LayoutParams;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.MediaController;
import android.widget.TextView;
import android.widget.VideoView;

import fr.hyperfiction.HypVideo;

import org.haxe.nme.GameActivity;

/**
 * ...
 * @author shoe[box]
 */

public class HypVideoFrag extends DialogFragment{

	private MediaController mc;
	private VideoView mVideoView;
	private View view;
	private String _sUrl;
	private int _iPrev;
	private static LoadingDialog progressDialog;
	private static ProgressBar progressBar;

	private static String TAG = "trace";//HypFacebook";

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public HypVideoFrag( String sUrl ) {
			super( );
			trace("constructor");			
			_sUrl = sUrl;
		}
	
	// -------o public

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@Override public void onDetach() {
			super.onDetach();
			trace("onDetach");
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@Override public View onCreateView( LayoutInflater inflater, ViewGroup container, Bundle bundle ) {
			trace("onCreateView ::: "+container);
			
				_iPrev = getActivity( ).getRequestedOrientation( );
				getActivity( ).setRequestedOrientation( ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE );
			
			//
				View view = inflater.inflate( R.layout.hypvideo , container , false );

			//
				progressDialog = new LoadingDialog( GameActivity.getContext( ) );
				progressDialog.show( );
				
			//
				mVideoView = (VideoView) view.findViewById( R.id.myvideoview );
				mVideoView.setZOrderOnTop( true );

			//
				MediaController mediaController = new MediaController(this.getActivity());
	            				mediaController.setAnchorView( mVideoView );
			
			//
	            Uri video = Uri.parse( _sUrl );
	            mVideoView.setOnPreparedListener(new MediaPlayer.OnPreparedListener() {

				    public void onPrepared(MediaPlayer arg0) {
				        progressDialog.dismiss();
				        mVideoView.start();
				    }
				});

	            mVideoView.setVideoURI(video);           
	            mVideoView.setMediaController(mediaController);
	            mVideoView.requestFocus();
	            mVideoView.start( );


			return view;

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
			Log.w( TAG, "HypVideoFrag ::: "+s );
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