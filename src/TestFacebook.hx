package ;

import fr.hyperfiction.HypFacebook;
import nme.Lib;
import nme.display.Sprite;

/**
 * ...
 * @author shoe[box]
 */

class TestFacebook extends Sprite{
	
	private var _fb : HypFacebook;


	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new() {
			super( );
			trace('constructor');
			_fb = new HypFacebook( '397904743584044' );
			_run( );
		}
	
	// -------o public
				
				

	// -------o protected
		
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _run( ) : Void{
			//HypFacebook.trace_hash( );
			_fb.addEventListener( HypFacebookEvent.OPENED , _onConn_opened , false );
			
			var bRes = _fb.connect( );
			trace('run :::: '+bRes);
			if( bRes  ){
				trace('session valide');
			}else{
				trace('session non valide, authorize');
				_authorize( );				
			}
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _authorize( ) : Void{
			trace('_authorize');
			#if android
			_fb.authorize( ["basic_info"] );
			#end

			#if iphone
			_fb.authorize( ["user_about_me"] );
			#end
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onConn_opened( e : HypFacebookEvent ) : Void{
			trace('_onConn_opened');

			//Test Request dialog
				/*
				var h = new Hash<String>( );
					h.set("message","toto");

				_fb.request_dialog( h );
				*/

			//Test Feed Dialog
				/*
				var h = new Hash<String>( );
					h.set("name", "Facebook SDK for Android");
				    h.set("caption", "Build great social apps and get more installs.");
				    h.set("description", "The Facebook SDK for Android makes it easier and faster to develop Facebook integrated Android apps.");
				    h.set("link", "https://developers.facebook.com/android");
				    h.set("picture", "https://raw.github.com/fbsamples/ios-3.x-howtos/master/Images/iossdk_logo.png");


				_fb.feed_dialog( h );
				*/
		
			//Test Graph			
				_fb.addEventListener( HypFacebookRequestEvent.GRAPH_REQUEST_ERROR , _onGraphRequest_results );
				_fb.addEventListener( HypFacebookRequestEvent.GRAPH_REQUEST_RESULTS , _onGraphRequest_results );
				_fb.graph_request( 'me/feed' );

		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onGraphRequest_results( e : HypFacebookRequestEvent ) : Void{
			trace('_onGraphRequest_results ::: '+e.sResult);
		}

	// -------o misc
		
		public static function main () {
			Lib.current.addChild ( new TestFacebook() );		
		}
}