package fr.hyperfiction.events;

import nme.events.Event;

/**
* 
* @author LouisBL
*/

class LocationProviderEvent extends Event {
	public static inline var PROVIDER_DISABLED	: String = "PROVIDER_DISABLED";
	public static inline var PROVIDER_ENABLED	: String = "PROVIDER_ENABLED";
	public static inline var STATUS_CHANGED		: String = "STATUS_CHANGED";
	
	public var provider		: String;
	public var status		: Int;
	public var satellites	: Int;


	// -------o constructor

		public function new( type : String, provider : String, ?status : Int, ?satellites : Int ) {
			super( type );
			this.provider	= provider;
			this.status		= status;
			this.satellites	= satellites;
		}


	// -------o public

	override public function toString( ) : String {
		return '[ '+type+' provider : '+provider+' status : '+status+' satellites : '+satellites+' ]';
	}


	// -------o protected


	// -------o misc
	
}