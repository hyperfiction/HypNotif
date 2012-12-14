package fr.hyperfiction;

import nme.JNI;

/**
 * ...
 * @author shoe[box]
 */

class HypVideo{

	#if android
		
		private static inline var ANDROID_CLASS		: String = 'fr.hyperfiction.HypVideo';
		
		private static var _f_play_local_video	: String->Void;
		private static var _f_play_remote_video	: String->Void;

	#end

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new() {
			trace('constructor');
		}
	
	// -------o public
				
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function play( sUrl : String , bRemote : Bool = false ) : Void {
			trace('play_video ::: '+sUrl+' remote ? : '+bRemote);

			if( bRemote )
				_play_remote_video( sUrl );
			else
				_play_local_video( sUrl );

		}

	// -------o protected

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		static private function _play_local_video( sUrl : String ) : Void{
			trace('_play_local_video ::: '+sUrl);
			#if android
				if( _f_play_local_video == null )
					_f_play_local_video = JNI.createStaticMethod( ANDROID_CLASS , 'play_local_video' , '(Ljava/lang/String;)V' );
					_f_play_local_video( sUrl );

			#end
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		static private function _play_remote_video( sUrl : String ) : Void{
			trace('_play_remote_video ::: '+sUrl);

			#if android
				if( _f_play_remote_video == null )
					_f_play_remote_video = JNI.createStaticMethod( ANDROID_CLASS , 'play_remote_video' , '(Ljava/lang/String;)V' );
					_f_play_remote_video( sUrl );

			#end
		}

	// -------o misc
	
}