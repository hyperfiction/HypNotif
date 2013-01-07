package fr.hyperfiction.events;

import nme.events.Event;

/**
* 
* @author LouisBL
*/

class HypFoxMessageEvent extends Event {

	public static inline var PRIVATE_MESSAGE : String = "PRIVATE_MESSAGE";
	
	public var message	: String;
	public var sender	: Int;

	// -------o constructor

		public function new( type : String, msg : String, id : Int ) : Void {
			super( type );
			message = msg;
			sender = id;
		}


	// -------o public

		override public function toString( ) : String {
			return '[ '+type+' message : '+message+' from : '+sender+' ]';
		}


	// -------o protected


	// -------o misc

}