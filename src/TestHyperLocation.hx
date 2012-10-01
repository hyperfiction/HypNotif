package ;

import nme.Assets;
import nme.display.Sprite;
import nme.Lib;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.events.MouseEvent;
import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.events.Event;

#if mobile
import fr.hyperfiction.HyperLocation;
import fr.hyperfiction.events.LocationProviderEvent;
import fr.hyperfiction.events.LocationChangedEvent;
#end
/**
* 
* @author LouisBL
*/

class TestHyperLocation extends Sprite {

	public var topLat		: Float = 45.908749;
	public var bottomLat	: Float = 45.902821;
	
	public var leftLng		: Float = 6.121636;
	public var rightLng		: Float = 6.134521;
	
	public var coeffLat		: Float;
	public var coeffLng		: Float;

	var _screenWidth : Int;
	var _screenHeight : Int;

	var _spUser : Sprite;

	var _btnStart		: Sprite;
	var _btnStop		: Sprite;
	#if mobile
		var _hypLocation	: HyperLocation;
	#end
	var _map : BitmapData;
	var _containerMap : Bitmap;
	

	// -------o constructor

		/**
		* Constructor
		*
		* @public
		* @return	void
		*/
		public function new() : Void {
			super();
			
			Lib.current.stage.scaleMode	= StageScaleMode.NO_SCALE;
			Lib.current.stage.align		= StageAlign.TOP_LEFT;
			
			_screenWidth  = Lib.current.stage.stageWidth;
			_screenHeight = Lib.current.stage.stageHeight;

			trace( "width ::: "+_screenWidth );
			trace( "height ::: "+_screenHeight );

			_initMap();
			_initUser();

			#if mobile
				_initHypLocation();
				//addEventListener( MouseEvent.CLICK, _onStartClick );
			#end

			Lib.current.addEventListener( Event.DEACTIVATE, _onDeActivate);
			Lib.current.addEventListener( Event.ACTIVATE, _onActivate);

		}


	// -------o public

	// -------o protected

	function _onActivate( event : Event ) : Void {
		#if mobile
			trace( event );
			_hypLocation.startLocation(0,0);
		#end
	}

	function _onDeActivate( event : Event ) : Void {
		#if mobile
			trace( event );
			_hypLocation.pauseLocation();
		#end
	}

	function _move( latitude : Float, longitude : Float ) : Void {
		_containerMap.x = -Math.round( ( longitude - leftLng ) / coeffLng );
		_containerMap.y = -Math.round( ( latitude - topLat ) / coeffLat );

		trace( "x : "+_containerMap.x );
		trace( "y : "+_containerMap.y );

		_containerMap.x += _screenWidth/2;
		_containerMap.y += _screenHeight/2;

		//_checkBounds();

		trace( "x : "+_containerMap.x );
		trace( "y : "+_containerMap.y );
	}

	function _initUser( ) : Void {
		_spUser = new Sprite( );
		_spUser.graphics.beginFill( 0x00FF00 );
		_spUser.graphics.drawRect( 0 , 0 , 10 , 10 );
		_spUser.graphics.endFill( );
		_spUser.x = _screenWidth / 2;
		_spUser.y = _screenHeight / 2;
		addChild( _spUser );
	}

	function _initMap( ) : Void {
		_map = Assets.getBitmapData( "assets/map.jpg" );
		_containerMap = new Bitmap( _map );

		addChild( _containerMap );

		coeffLng = ( rightLng - leftLng ) / 1200;
		coeffLat = ( bottomLat - topLat ) / 800;
	}

	function _checkBounds( ) : Void {
		if (_containerMap.x < -(_map.width - _screenWidth)) {
			_containerMap.x = -(_map.width - _screenWidth);
		}
		if (_containerMap.y < -(_map.height - _screenHeight)) {
			_containerMap.y = -(_map.height - _screenHeight);
		}
		if (_containerMap.x >= 0) {
			_containerMap.x = 0;
		}
		if (_containerMap.y >= 0) {
			_containerMap.y = 0;
		}
	}

	#if mobile
		function _initHypLocation( ) : Void {

			trace( "init HypLocation ::: " );

			_hypLocation = new HyperLocation( );

			_hypLocation.setTestIfBetter( true );
			_hypLocation.setTimeAccuracy( 10000.0 );

			_hypLocation.addEventListener( LocationChangedEvent.LOCATION_CHANGED, _onLocationChanged );
			_hypLocation.addEventListener( LocationProviderEvent.PROVIDER_ENABLED, _onProviderEnabled );
			_hypLocation.addEventListener( LocationProviderEvent.PROVIDER_DISABLED, _onProviderDisabled );
			_hypLocation.addEventListener( LocationProviderEvent.STATUS_CHANGED, _onStatusChanged );
			
			_hypLocation.startLocation( 0, 0 );
		}

		function _onStartClick( event : MouseEvent ) : Void {
			trace( "on start click" );
			removeEventListener( MouseEvent.CLICK, _onStartClick );
			addEventListener( MouseEvent.CLICK, _onStopClick );
		}

		function _onStopClick( event : MouseEvent ) : Void {
			trace( "on stop click" );
			removeEventListener( MouseEvent.CLICK, _onStopClick );
			_hypLocation.stopLocation();
			addEventListener( MouseEvent.CLICK, _onStartClick );
		}

		function _onLocationChanged( event : LocationChangedEvent ) : Void {
			trace( event );
			_move( event.latitude, event.longitude );
		}

		function _onProviderEnabled( event : LocationProviderEvent ) : Void {
			trace( event );
		}

		function _onProviderDisabled( event : LocationProviderEvent ) : Void {
			trace( event );
		}

		function _onStatusChanged( event : LocationProviderEvent ) : Void {
			trace( event );
		}

	#end
	// -------o misc

}