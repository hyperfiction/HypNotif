package ;

import nme.Lib;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import org.shoebox.utils.system.Signal1;

/**
 * ...
 * @author shoe[box]
 */

class TestFacebookAndroid extends Sprite{

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new() {
			super( );
			Lib.current.stage.scaleMode = StageScaleMode.NO_SCALE;
			Lib.current.stage.align     = StageAlign.TOP_LEFT;
			_run( );
		}
	
	// -------o public
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function onCallback( ) : Void {
						
		}

	// -------o protected
		
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _run( ) : Void{

			trace('run');
			var bmp = nme.installer.Assets.getBitmapData('assets/logo.png');
			addChild( new Bitmap( bmp ) );
			//var test = nme.JNI.createMemberMethod('test.Test' , "twoPlusTwo", "()I");
			//trace( 'test : '+test( ) );
			#if android
			//var launch:Dynamic = nme.JNI.createStaticMethod("test.Test", "nmeCreate", "()I");
			//nme.Lib.postUICallback( function() { launch( ); });

			var cb = new TestCB( );
				cb.onCallBack.connect( _onConnect );

			var launch2:Dynamic = nme.JNI.createStaticMethod("fb.FacebookConnector", "nmeCreate", "(Lorg/haxe/nme/HaxeObject;)I");
			nme.Lib.postUICallback( function() { 
												launch2( cb ); 
											}
									);
			#end
			/*
			var launch:Dynamic = nme.JNI.createStaticMethod("nme.NMEWebView", "nmeCreate", "(Ljava/lang/String;)Landroid/view/View;");
				if (launch!=null)
         	nme.Lib.postUICallback( function() { launch('http://www.google.fr'); } );
         	*/

         	Lib.current.stage.addEventListener( nme.events.MouseEvent.CLICK , _onClick , false );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _test( ) : Void{
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onConnect( sToken : String ) : Void{
			trace('onConnect ::: '+sToken);
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onClick( _ ) : Void{
			trace('onClick');
		}

	// -------o misc
		
		public static function main () {
			Lib.current.addChild ( new TestNativeGestures() );		
		}
}

/**
 * ...
 * @author shoe[box]
 */

class TestCB{

	public var onCallBack : Signal1<String>;

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new() {
			onCallBack = new Signal1<String>( );
		}
	
	// -------o public
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function onToken( sToken : String ) : Void {
			trace('onCallBack ::: '+sToken );
			onCallBack.emit( sToken );
		}
				

	// -------o protected
	
		

	// -------o misc
	
}