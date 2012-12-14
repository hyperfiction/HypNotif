package ;

import nme.display.Bitmap;
import nme.display.Sprite;
import nme.events.Event;
import nme.events.MouseEvent;
import nme.Lib;
import fr.hyperfiction.HypFacebook;

/**
 * ...
 * @author shoe[box]
 */
class TestFacebook extends Sprite{

	private var _fb : HypFacebook;

	private static var hyp_fb_connect : Dynamic;
	private static var hyp_fb_init : Dynamic;

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new() {
			trace('constructor');	
			super( );
			Lib.current.stage.addEventListener( nme.events.MouseEvent.CLICK , _run , false );
		}
	
	// -------o public
		
	// -------o protected
	
		/**
		* 
		*  
		* @private
		* @return	void
		*/
		private function _run( _ ) : Void{

			_fb = new HypFacebook( '397904743584044' );
			_fb.addEventListener( HypFacebookEvent.CONNECTION_OK , _on_fb_connected );
			_fb.connect( [ 'publish_stream' ] );
						
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _on_fb_connected( e : HypFacebookEvent ) : Void{
			trace('_on_fb_connected ::: '+e);
			//_fb.appRequest( 'Hello' , 'World' , 100 );
			//Facebook.getInstance( ).appRequest('Hello','World','100');
			//Facebook.getInstance( ).feed( 'Hello World title' , 'hello world caption' , 'description de test' , 'http://www.hyperfiction.fr','http://hyperfiction.fr/LogoHyperfiction.png');
			_fb.addEventListener( HypFacebookEvent.ON_REQUEST_COMPLETE , _on_me );
			_fb.request('me');			
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _on_me( e : HypFacebookEvent ) : Void{
			trace('_on_me ::: '+e.args2);

			_fb.dialog( "feed" , ["message"] , ["Test API facebook depuis Haxe"] );

			haxe.Timer.delay( function( ){
					_fb.dialog( "feed" , 
									[
										"name",
										"caption",
										"description",
										"link",
									], 
									[
										"toto",
										"Tartine",
										"Confiture",
										"http://www.hyperfiction.fr"
									] 
								);
				},10000);
		}

	// -------o misc
		
		public static function main () {
			Lib.current.addChild ( new TestFacebook() );		
		}
}