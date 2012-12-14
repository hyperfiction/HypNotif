package fr.hyperfiction.events;

import nme.events.Event;

/**
* 
* @author LouisBL
*/

class HypFoxUserEvent extends Event {

	public static inline var USER_FOUND : String = "USER_FOUND";
	
	public var id	: Int;

	// -------o constructor

		public function new( type : String, user_id : Int ) : Void {
			super( type );
			id = user_id;
		}


	// -------o public

		override public function toString( ) : String {
			return '[ '+type+' id : '+id+' ]';
		}


	// -------o protected


	// -------o misc

}