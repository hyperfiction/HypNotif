package fr.hyperfiction.events;

import nme.events.Event;

/**
* 
* @author LouisBL
*/

class HypFoxEvent extends Event {

	public static inline var CONNECTION : String = "CONNECTION";
	public static inline var CONNECTION_LOST : String = "CONNECTION_LOST";
	public static inline var LOGIN : String = "LOGIN";
	public static inline var ROOM_JOIN : String = "ROOM_JOIN";

	public var success	: Bool;


	// -------o constructor

		public function new( type : String, suc : Bool ) : Void {
			super( type );
			this.success = suc;
		}


	// -------o public

		override public function toString( ) : String {
			return '[ '+type+' success : '+success+' ]';
		}


	// -------o protected


	// -------o misc

}