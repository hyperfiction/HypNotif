package ;

import nme.display.Sprite;
import nme.Lib;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.events.MouseEvent;

import fr.hyperfiction.HyperLocation;
import fr.hyperfiction.events.LocationProviderEvent;
import fr.hyperfiction.events.LocationChangedEvent;
/**
* 
* @author LouisBL
*/

class TestHyperLocation extends Sprite {

	var _btnStart		: Sprite;
	var _btnStop		: Sprite;
	var _hypLocation	: HyperLocation;
	

	// -------o constructor

		/**
		* Constructor
		*
		* @public
		* @return	void
		*/
		public function new() : Void {
			super();

			_hypLocation = new HyperLocation( );

			_hypLocation.addEventListener( LocationChangedEvent.LOCATION_CHANGED, _onLocationChanged );
			_hypLocation.addEventListener( LocationProviderEvent.PROVIDER_ENABLED, _onProviderEnabled );
			_hypLocation.addEventListener( LocationProviderEvent.PROVIDER_DISABLED, _onProviderDisabled );
			_hypLocation.addEventListener( LocationProviderEvent.STATUS_CHANGED, _onStatusChanged );

			Lib.current.stage.scaleMode = StageScaleMode.NO_SCALE;
			Lib.current.stage.align = StageAlign.TOP_LEFT;

			_btnStart = new Sprite( );
			_btnStart.graphics.beginFill( 0x00FF00 );
			_btnStart.graphics.drawRect( 0 , 0 , 100 , 100 );
			_btnStart.graphics.endFill( );
			_btnStart.x = 100;
			_btnStart.y = 100;
			addChild( _btnStart );

			_btnStop = new Sprite( );
			_btnStop.graphics.beginFill( 0xFF0000 );
			_btnStop.graphics.drawRect( 0 , 0 , 100 , 100 );
			_btnStop.graphics.endFill( );
			_btnStop.x = 300;
			_btnStop.y = 100;
			addChild( _btnStop );

			_btnStart.addEventListener( MouseEvent.CLICK, _onStartClick );
			_btnStop.addEventListener( MouseEvent.CLICK, _onStopClick );

		}


	// -------o public

	// -------o protected

	function _onStartClick( event : MouseEvent ) : Void {
		_hypLocation.startLocation( 0, 0 );
	}

	function _onStopClick( event : MouseEvent ) : Void {
		_hypLocation.stopLocation();
	}

	function _onLocationChanged( event : LocationChangedEvent ) : Void {
		trace( event );
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

	// -------o misc

}