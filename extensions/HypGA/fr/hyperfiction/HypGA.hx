package fr.hyperfiction;

#if android
import nme.JNI;
#end

#if cpp
import cpp.Lib;
#elseif neko
import neko.Lib;
#end


/**
 * ...
 * @author shoe[box]
 */

class HypGA{

	#if android
		private var _func_new_session	: Dynamic;
		private var _func_stop_session	: Dynamic;
		private var _func_set_period	: Dynamic;
		private var _func_set_user_var	: Dynamic;
		private var _func_track_event	: Dynamic;
		private var _func_track_page	: Dynamic;
		private var _instance			: Dynamic;

		private static inline var ANDROID_CLASS : String = 'fr/hyperfiction/HypGA';
	#end

	#if iphone
		private static var hyp_ga_startSession	= Lib.load( "hyp-ga" , "HypGA_startNewSession" , 2 );
		private static var hyp_ga_trackPageView	= Lib.load( "hyp-ga" , "HypGA_trackPageView" , 1 );
		private static var hyp_ga_trackEvent	= Lib.load( "hyp-ga" , "HypGA_trackEvent" , 4 );
		private static var hyp_ga_setCustomVar	= Lib.load( "hyp-ga" , "HypGA_setCustomVar" , 3 );
		private static var hyp_ga_stopSession	= Lib.load( "hyp-ga" , "HypGA_stopSession" , 0 );
	#end

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		private function new() {
			
		}
	
	// -------o public
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function startNewSession( sUA : String , iPeriod : Int = 5 ) : Void {
			trace('startNewSession ::: '+sUA+' - '+iPeriod);
			#if android
			_startSession( sUA , iPeriod );
			#end

			#if iphone
			_startSession( sUA , iPeriod );
			#end
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function stopSession( ) : Void {
			#if iphone
			_stop_session( );
			#end

			#if android
			_stop_session( );
			#end
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function trackPageView( s_path : String ) : Void {
			trace('trackPageView ::: '+s_path);
			#if iphone
			_track_page_view( s_path );
			#end

			#if android
			_track_page_view( s_path );
			#end
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function trackEvent( sCat : String , sAction : String , sLabel : String , value : Int ) : Void {
			trace('trackEvent ::: '+sCat+' - '+sAction+' - '+sLabel+' - '+value);
			#if iphone
			_track_event( sCat , sAction , sLabel , value );
			#end

			#if android
			_track_event( sCat , sAction , sLabel , value );
			#end
		}

		#if android

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function setDispatchPeriod( i : Int ) : Void {
			#if android
			_set_dispatch_period( i );
			#end
		}

		#end

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function setCustomVariable( iSlot : Int , sName : String , sValue : String ) : Void {
			
			#if android
			_set_custom_variable( iSlot , sName , sValue );	
			#end

			#if iphone
			_set_custom_variable( iSlot , sName , sValue );	
			#end

		}

	// -------o protected
		
		#if iphone

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _startSession( sUA : String , iPeriod : Int ) : Void{
			hyp_ga_startSession( sUA , iPeriod );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function _set_custom_variable( iSlot : Int , sName : String , sValue : String ) : Void {
			hyp_ga_setCustomVar( iSlot , sName , sValue );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _stop_session( ) : Void{
			hyp_ga_stopSession( );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _track_page_view( s_path : String ) : Void{
			hyp_ga_trackPageView( s_path );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _track_event( sCat : String , sAction : String , sLabel : String , value : Int = -1 ) : Void{
			hyp_ga_trackEvent( sCat , sAction , sLabel , value );
		}

		#end

		#if android

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _startSession( sUA : String , iPeriod : Int ) : Void{
			//
				if( _func_new_session == null )
					_func_new_session = JNI.createStaticMethod( ANDROID_CLASS , 'startNewSession' , '(Ljava/lang/String;)V' );
		
			//
				trace('call _startSession');
				_func_new_session( sUA );

			//
				_set_dispatch_period( iPeriod );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		private function _set_custom_variable( iSlot : Int , sName : String , sValue : String ) : Void {
			trace('_set_custom_variable::::');
			if( _func_set_user_var == null )
				_func_set_user_var = JNI.createStaticMethod( ANDROID_CLASS , 'setCustomVar' , '(ILjava/lang/String;Ljava/lang/String;)V' );
				_func_set_user_var( iSlot , sName , sValue );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _stop_session( ) : Void{
			if( _func_stop_session == null )
				_func_stop_session = JNI.createStaticMethod( ANDROID_CLASS , 'stopSession' , '()V' );
				_func_stop_session( );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _track_page_view( s_path : String ) : Void{
			if( _func_track_page == null )
				_func_track_page = JNI.createStaticMethod( ANDROID_CLASS , 'trackPageView' , '(Ljava/lang/String;)V' );
				_func_track_page( s_path );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _track_event( sCat : String , sAction : String , sLabel : String , value : Int ) : Void{
			trace('_track_event ::: '+sCat+' - '+sAction+' - '+sLabel+' - '+value);
			if( _func_track_event == null )
				_func_track_event = JNI.createStaticMethod( ANDROID_CLASS , 'trackEvent' , '(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V' );
				_func_track_event( sCat , sAction , sLabel , value );

		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _set_dispatch_period( i : Int ) : Void{
			if( _func_set_period == null )
				_func_set_period = JNI.createStaticMethod( ANDROID_CLASS , 'set_dispatch_period' , '(I)V' );
			trace('call _func_set_period');
				_func_set_period( i );
		}

		#end

	// -------o misc
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function getInstance( ) : HypGA {
			
			if( __instance == null )
				__instance = new HypGA( );
			return __instance;

		}

		private static var __instance : HypGA = null;

}