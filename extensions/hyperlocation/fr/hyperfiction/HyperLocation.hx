package fr.hyperfiction;

#if android
import nme.JNI;
#end

#if cpp
import cpp.Lib;
#end

import nme.Lib;
import nme.events.EventDispatcher;
import fr.hyperfiction.events.LocationProviderEvent;
import fr.hyperfiction.events.LocationChangedEvent;

/**
* 
* @author LouisBL
*/

class HyperLocation extends EventDispatcher {
	
	#if android	
		public static inline var ANDROID_CLASS : String = 'fr.hyperfiction.HyperLocation';

		private var _hyp_create				: Dynamic;
		private var _hyp_start				: Dynamic;
		private var _hyp_stop				: Dynamic;
		private var _hyp_instance			: Dynamic;
		private var _hyp_set_time_accuracy	: Dynamic;
		private var _hyp_set_test_better		: Dynamic;
	#end

	#if mobile
		private static var hyp_cb_location_changed	= Lib.load( "hyperlocation", "hyp_cb_location_changed", 1 );
		private static var hyp_cb_provider_disabled	= Lib.load( "hyperlocation", "hyp_cb_provider_disabled", 1 );
		private static var hyp_cb_provider_enabled	= Lib.load( "hyperlocation", "hyp_cb_provider_enabled", 1 );
		private static var hyp_cb_status_changed		= Lib.load( "hyperlocation", "hyp_cb_status_changed", 1 );
	#end

	// -------o constructor

		/**
		* Constructor
		*
		* @public
		* @return	void
		*/
		public function new() : Void {
			super();

			#if android
				hyp_cb_location_changed( _onLocationChanged );
				hyp_cb_provider_enabled( _onProviderEnabled );
				hyp_cb_provider_disabled( _onProviderDisabled );
				hyp_cb_status_changed( _onStatusChanged );

				if( _hyp_create == null )
					_hyp_create = JNI.createStaticMethod( ANDROID_CLASS , 'createInstance' , "()Lfr/hyperfiction/HyperLocation;" );
					
				_hyp_instance = _hyp_create( );
			#end
		}


	// -------o public

		public function setTimeAccuracy( time : Float ) : Void {
			#if android
				if( _hyp_set_time_accuracy == null )
					_hyp_set_time_accuracy = JNI.createMemberMethod( ANDROID_CLASS, 'setTimeAccuracy', "(F)V" );
				
				_hyp_set_time_accuracy( _hyp_instance, time );
			#end
		}

		public function setTestIfBetter( test : Bool ) : Void {
			#if android
				if( _hyp_set_test_better == null )
					_hyp_set_test_better = JNI.createMemberMethod( ANDROID_CLASS, 'setTestIfBetter', "(Z)V" );

				_hyp_set_test_better( _hyp_instance, test );
			#end
		}

		public function startLocation( minTime : Float = 0, minDistance : Float = 0 ) : Void {
			#if android
				if( _hyp_start == null )
					_hyp_start = JNI.createMemberMethod( ANDROID_CLASS , 'beginLocationUpdates' , "(JF)V" );
				
				_hyp_start( _hyp_instance, minTime, minDistance );
			#end
		}

		public function stopLocation( ) : Void {
			#if android
				if( _hyp_stop == null )
					_hyp_stop = JNI.createMemberMethod( ANDROID_CLASS , 'stopLocationUpdates' , "()V" );
				
				_hyp_stop( _hyp_instance );
			#end
		}

	// -------o protected

		function _onLocationChanged( args : Array<Float> ) : Void {
			Reflect.callMethod( this , _disaptchLocationChanged , args );
		}

		function _disaptchLocationChanged( locTime : Float, lat : Float, lgt : Float, alt : Float ) : Void {
			dispatchEvent( new LocationChangedEvent( LocationChangedEvent.LOCATION_CHANGED, locTime, lat, lgt, alt ) ); 
		}

		function _onProviderEnabled( provider : String ) : Void {
			dispatchEvent( new LocationProviderEvent( LocationProviderEvent.PROVIDER_ENABLED, provider ) );
		}

		function _onProviderDisabled( provider : String ) : Void {
			dispatchEvent( new LocationProviderEvent( LocationProviderEvent.PROVIDER_DISABLED, provider ) );
		}

		function _onStatusChanged( provider : String, status : Int, satellites : Int ) : Void {
			dispatchEvent( new LocationProviderEvent( LocationProviderEvent.STATUS_CHANGED, provider, status, satellites ) );
		}

	// -------o misc

}