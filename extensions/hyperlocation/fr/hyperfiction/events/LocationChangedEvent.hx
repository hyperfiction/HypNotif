package fr.hyperfiction.events;

import nme.events.Event;

/**
* 
* @author LouisBL
*/

class LocationChangedEvent extends Event {

	public static inline var LOCATION_CHANGED : String = "LOCATION_CHANGED";

	public var time			: Float;
	public var latitude		: Float;
	public var longitude	: Float;
	public var altitude		: Float;


	// -------o constructor

		public function new( type : String, time : Float, latitude : Float, longitude : Float, altitude : Float ) : Void {
			super( type );
			this.time		= time;
			this.latitude	= latitude;
			this.longitude	= longitude;
			this.altitude	= altitude;
		}


	// -------o public

		override public function toString( ) : String {
			return '[ '+type+' time : '+time+' latitude : '+latitude+' longitude : '+longitude+' altitude : '+altitude+' ]';
		}


	// -------o protected


	// -------o misc

}