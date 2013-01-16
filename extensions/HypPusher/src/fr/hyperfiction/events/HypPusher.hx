package fr.hyperfiction.events;

import nme.events.Event;

/**
* 
* @author LouisBL
*/

class HypPusher extends Event {

	public static inline var CONNECT : String = "CONNECT";
	public static inline var DISCONNECT : String = "DISCONNECT";

	// -------o constructor

		public function new( type : String ) : Void {
			super( type );
		}


	// -------o public

		override public function toString( ) : String {
			return '[ '+type+' ]';
		}


	// -------o protected


	// -------o misc

}