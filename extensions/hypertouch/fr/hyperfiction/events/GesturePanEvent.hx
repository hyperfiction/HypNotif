package fr.hyperfiction.events;

import nme.events.Event;

/**
 * ...
 * @author shoe[box]
 */

class GesturePanEvent extends Event{

	public var x         : Float;
	public var y         : Float;
	public var velocityX : Float;
	public var velocityY : Float;

	public static inline var PAN : String = 'GesturePanEvent_PAN';

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new( fx : Float , fy : Float , vx : Float , vy : Float ) {
			super( PAN );
			this.x = fx;
			this.y = fy;
			this.velocityX = vx;
			this.velocityY = vy;
		}
	
	// -------o public
				
	// -------o protected
	
	// -------o misc
	
}