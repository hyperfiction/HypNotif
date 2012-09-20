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

		private var hyplocation_create		: Dynamic;
		private var hyplocation_start		: Dynamic;
		private var hyplocation_stop		: Dynamic;
		private var hyplocation_instance	: Dynamic;
	#end

	#if mobile
		private static var hyp_cb_on_location_changed	= Lib.load( "hyperlocation", "hyp_cb_on_location_changed", 1 );
		private static var hyp_cb_on_provider_disabled	= Lib.load( "hyperlocation", "hyp_cb_on_provider_disabled", 1 );
		private static var hyp_cb_on_provider_enabled	= Lib.load( "hyperlocation", "hyp_cb_on_provider_enabled", 1 );
		private static var hyp_cb_on_status_changed		= Lib.load( "hyperlocation", "hyp_cb_on_status_changed", 1 );
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
				hyp_cb_on_location_changed( _onLocationChanged );
				hyp_cb_on_provider_enabled( _onProviderEnabled );
				hyp_cb_on_provider_disabled( _onProviderDisabled );
				hyp_cb_on_status_changed( _onStatusChanged );

				if( hyplocation_create == null )
					hyplocation_create = JNI.createStaticMethod( ANDROID_CLASS , 'createInstance' , "()Lfr/hyperfiction/HyperLocation;" );
					
				hyplocation_instance = hyplocation_create( );
			#end
		}


	// -------o public

		public function startLocation( minTime : Float = 0, minDistance : Float = 0 ) : Void {
			#if android
				if( hyplocation_start == null )
					hyplocation_start = JNI.createMemberMethod( ANDROID_CLASS , 'beginLocationUpdates' , "(JF)V" );
				
				hyplocation_start( hyplocation_instance, minTime, minDistance );
			#end
		}

		public function stopLocation( ) : Void {
			#if android
				if( hyplocation_stop == null )
					hyplocation_stop = JNI.createMemberMethod( ANDROID_CLASS , 'stopLocationUpdates' , "()V" );
				
				hyplocation_stop( hyplocation_instance );
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