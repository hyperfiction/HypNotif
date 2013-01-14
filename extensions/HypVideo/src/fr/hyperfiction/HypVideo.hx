package fr.hyperfiction;

import nme.JNI;

/**
 * ...
 * @author shoe[box]
 */

@:build(org.shoebox.utils.NativeMirror.build( )) class HypVideo{

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new() {
			trace('constructor');

			#if( ios || android )
			trace("ios ou android HypVideo_set_event_callback( )");
			HypVideo_set_event_callback( _onCallBack );
			#end

		}
	
	// -------o public
				
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function play( sUrl : String , bRemote : Bool = false ) : Void {
			trace('play_video ::: '+sUrl+' remote ? : '+bRemote);

			if( bRemote )
				_play_remote_video( sUrl );
			else
				_play_local_video( sUrl );

		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function dispose( ) : Void {
			
			#if ios
				HypVideo_dispose( );
			#end

		}

	// -------o protected

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onCallBack( sEvent : String , sArg : String ) : Void{
			trace("_onCallBack ::: ev : "+sEvent+' arg : '+sArg);
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		static private function _play_local_video( sURL : String ) : Void{
			
			#if android
				play_local_video( sURL );
			#end
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		static private function _play_remote_video( sURL : String ) : Void{
			
			#if android
				play_remote_video( sURL );
			#end

			#if ios
				HypVideo_play_remote( sURL );
			#end
			
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@JNI
		static public function play_remote_video( sURL : String ) : Void {
						
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@JNI
		static public function play_local_video( sURL : String ) : Void {
						
		}

		#if( ios )

		/**
		* 
		* 
		* @public
		* @return	void
		*/		
		@CPP("HypVideo")
		static public function HypVideo_play_remote( sURL : String ) : Void {
						
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/		
		@CPP("HypVideo")
		static public function HypVideo_dispose( ) : Void {
						
		}

		#end

		#if( ios || android )

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@CPP("HypVideo")
		public function HypVideo_set_event_callback( f : String->String->Void ) : Void {
						
		}

		#end

	// -------o misc
	
}