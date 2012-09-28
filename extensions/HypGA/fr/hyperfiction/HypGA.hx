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

		private static inline var ANDROID_CLASS : String = 'fr.hyperfiction.HypGA';
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
			_startSession( sUA , iPeriod );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function stopSession( ) : Void {
			_stop_session( );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function trackPageView( s_path : String ) : Void {
			_track_page_view( s_path );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function trackEvent( sCat : String , sAction : String , sLabel : String , value : Int ) : Void {
			_track_event( sCat , sAction , sLabel , value );
		}
		#if android

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function setDispatchPeriod( i : Int ) : Void {
			_set_dispatch_period( i );
		}

		#end

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function setCustomVariable( iSlot : Int , sName : String , sValue : String ) : Void {
			_set_custom_variable( iSlot , sName , sValue );	
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
					_func_new_session = JNI.createMemberMethod( ANDROID_CLASS , 'startNewSession' , '(Ljava/lang/String;)V' );
		
			//
				_func_new_session( _get_android_instance( ) , sUA );

			//
				_set_dispatch_period( iPeriod );
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function _set_custom_variable( iSlot : Int , sName : String , sValue : String ) : Void {
			if( _func_set_user_var == null )
				_func_set_user_var = JNI.createMemberMethod( ANDROID_CLASS , 'setCustomVar' , '(ILjava/lang/String;Ljava/lang/String;)V' );
				_func_set_user_var( _get_android_instance( ) );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _stop_session( ) : Void{
			if( _func_stop_session == null )
				_func_stop_session = JNI.createMemberMethod( ANDROID_CLASS , 'stopSession' , '()V' );
				_func_stop_session( _get_android_instance( ) );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _track_page_view( s_path : String ) : Void{
			if( _func_track_page == null )
				_func_track_page = JNI.createMemberMethod( ANDROID_CLASS , 'trackPageView' , '(Ljava/lang/String;)V' );
				_func_track_page( _get_android_instance( ) , s_path );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _track_event( sCat : String , sAction : String , sLabel : String , value : Int ) : Void{

			if( _func_track_event == null )
				_func_track_event = JNI.createMemberMethod( ANDROID_CLASS , 'trackEvent' , '(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V' );
				_func_track_event( _get_android_instance( ) , sCat , sAction , sLabel , value );

		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _get_android_instance( ) : Dynamic{

			if( _instance == null ){
				var method = JNI.createStaticMethod( ANDROID_CLASS ,'getInstance', '()Lfr/hyperfiction/HypGA;');
				_instance = method( );
			}
			return _instance;
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _set_dispatch_period( i : Int ) : Void{
			if( _func_set_period == null )
				_func_set_period = JNI.createMemberMethod( ANDROID_CLASS , 'set_dispatch_period' , '(I)V' );
				_func_set_period( _get_android_instance( ) , i );
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