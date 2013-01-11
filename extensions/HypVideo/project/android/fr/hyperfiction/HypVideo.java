package fr.hyperfiction;

import ::APP_PACKAGE::.R;

import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentActivity;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.content.pm.ActivityInfo;
import fr.hyperfiction.HypVideoFrag;

import android.net.Uri;
import android.util.Log;
import android.widget.VideoView;
import android.media.MediaPlayer;
import android.media.MediaPlayer.OnPreparedListener;

import org.haxe.nme.GameActivity;

/**
 * ...
 * @author shoe[box]
 */

public class HypVideo{

	private static String TAG = "HypVideo";

	private static VideoView _video_view_instance = null;

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public void HypVideo() {
			trace("constructor");
		}
	
	// -------o public
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void play_local_video( String sUrl ) {
			trace( "play_local_video ::: " + sUrl );		
			/*
			
			VideoView vp = new VideoView( GameActivity.getContext( ) );
			trace( "vp ::: " + vp );

			if( bRemote ){
				Uri uri = Uri.parse( sUrl );
				vp.setVideoURI( uri );
			}

			vp.start( );
			*/
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public void play_remote_video( final String sUrl ) {
			trace( "play_remote_video ::: " + sUrl );	
			
			GameActivity.getInstance( ).runOnUiThread(
				new Runnable(){
	                @Override
	                public void run() {
	                	
						
						HypVideoFrag newFragment = new HypVideoFrag( sUrl );
						FragmentActivity fa = (FragmentActivity) GameActivity.getInstance( );
						trace("fa ::: "+fa);
						//FragmentManager fm = fa.getFragmentManager( );
						//trace("fm ::: "+fm);

						FragmentTransaction ft = GameActivity.getInstance( ).getSupportFragmentManager( ).beginTransaction( );
            								ft.add( android.R.id.content , newFragment );
            								ft.addToBackStack( null );
            								ft.commit( );
            			trace("test");
                    }                   
		        }
            );			
			
		}

	// -------o protected
		
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		static private VideoView _get_video_view( ){
			if( _video_view_instance == null )
				_video_view_instance = new VideoView( GameActivity.getContext( ) );

			return _video_view_instance;
		}

	// -------o misc
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public HypVideo getInstance( ){

			if( __instance == null )
				__instance = new HypVideo( );

			return __instance;
		}	

		private static HypVideo __instance = null;

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public static void trace( String s ){
			Log.i( TAG, s );
		}
}	