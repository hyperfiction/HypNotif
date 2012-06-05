package fr.hyperfiction.events;

import nme.events.Event;

/**
 * ...
 * @author shoe[box]
 */

class GestureTapEvent extends Event{

	public var x : Float;
	public var y : Float;

	public static inline var DOUBLE_TAP      : String = 'GestureTapEvent_DOUBLE_TAP';
	public static inline var TAP             : String = 'GestureTapEvent_TAP';
	public static inline var TWO_FINGERS_TAP : String = 'GestureTapEvent_TWO_FINGERS_TAP';

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new( type : String , fx : Float , fy : Float ) {
			super( type );
			this.x = fx;
			this.y = fy;
		}
	
	// -------o public
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		override public function toString( ) : String {
			return '[ '+type+' at position x : '+x+' y : '+y+']';
		}

	// -------o protected
	
	// -------o misc
	
}