package fr.hyperfiction;

import nme.events.Event;
import nme.events.EventDispatcher;

/**
 * ...
 * @author shoe[box]
 */
@:build(org.shoebox.utils.NativeMirror.build( )) class HypFacebook extends EventDispatcher{

	private var _sApp_id : String;

	#if android
	private var _JNI_instance : Dynamic;
	#end

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new( sAppId : String ) {
			super( );
			trace('constructor ::: '+sAppId);
			_sApp_id = sAppId;
			_init( );
		}
	
	// -------o public
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function connect( ) : Bool {
			trace("connect");

			var bSessionValid = false;	
			#if android
			bSessionValid = jni_connect( _JNI_instance );
			#end

			trace('bSessionValid ::: '+bSessionValid);
			return bSessionValid;
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function authorize( a : Array<String> ) : Void {
			trace('authorize ::: '+a);

			#if android
			jni_authorize( _JNI_instance , a.join('&') );				
			#end

		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function logout( ) : Void {
						
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function request_dialog( h : Hash<String> ) : Void {
			
			trace('request_dialog ::: '+h);
			#if android
				//call_request_dialog( _JNI_instance , "toto" );
				//req_dialog( "toto" , "tata" );

				var aKeys : Array<String> = [ ];
				var aVals : Array<String> = [ ];

				for( key in h.keys( ) ){
					aKeys.push( key );
					aVals.push( h.get( key ) );
				}

				req_dialog( aKeys.join("&") , aVals.join("&") );
			#end

		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function feed_dialog( h : Hash<String> ) : Void {
			trace('feed_dialog');
			#if android
				//call_request_dialog( _JNI_instance , "toto" );
				//req_dialog( "toto" , "tata" );

				var aKeys : Array<String> = [ ];
				var aVals : Array<String> = [ ];

				for( key in h.keys( ) ){
					aKeys.push( key );
					aVals.push( h.get( key ) );
				}

				call_feed_dialog( aKeys.join("&") , aVals.join("&") );
			#end

		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function graph_request( sRequest : String ) : Void {
			#if android
			jni_graph_request( sRequest );
			#end
		}

	// -------o protected
	
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _init( ) : Void{
			trace('_init');
			
			#if cpp
			trace('set_callback');
			HypFB_set_event_callback( _onEvent );
			#end

			#if android
				
				#if debug
				trace_hash( );
				#end

				_JNI_instance = create( _sApp_id );

			#end

		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _onEvent( sEventType : String , sArg1 : String , sArg2 : String ) : Void{
			//trace('_onEvent ::: '+sEventType+' - '+sArg1+' - '+sArg2);
			
			var e = Type.createEnum( EventTypes , sEventType );
			var ev : HypFacebookEvent = null;
			switch( e ){

				case OPENED:
					ev = new HypFacebookEvent( sEventType );
					ev.sFacebook_token = sArg1;

				case FEEDDIALOG_CANCELED:	
					ev = _dispatch_feeddialog_event( sEventType , sArg2 , sArg1 );
							
				case FEEDDIALOG_ERROR:
					ev = _dispatch_feeddialog_event( sEventType );
					
				case FEEDDIALOG_SENT:
					ev = _dispatch_feeddialog_event( sEventType );

				case REQUESTDIALOG_CANCELED:
					ev = _dispatch_requestdialog_event( sEventType );

				case REQUESTDIALOG_ERROR:
					ev = _dispatch_requestdialog_event( sEventType , null , sArg1 );

				case REQUESTDIALOG_SENT:
					ev = _dispatch_requestdialog_event( sEventType , sArg1 , null );

				case GRAPH_REQUEST_ERROR:
					ev = _dispatch_request_event( sEventType , sArg1 , null , sArg2 );

				case GRAPH_REQUEST_RESULTS:
					ev = _dispatch_request_event( sEventType , sArg1 , sArg2 );

				default:
					

			}

			if( ev != null ){
				trace('dispatch ::: '+ev.type);
				ev.eTypes = e;
				dispatchEvent( ev );
			}else
				trace( sEventType +'??' );
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _dispatch_feeddialog_event( 
														sType	: String , 
														sPostID	: String = null , 
														sError	: String = null 
													) : HypFacebookEvent{

			var ev = new HypFacebookFeedDialogEvent( sType );	
				ev.sPostID	= sPostID;
				ev.sError	= sError;
			return ev;
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _dispatch_requestdialog_event( 
															sType		: String , 
															sRequestID	: String = null , 
															sError		: String = null 
														) : HypFacebookEvent{

			var ev = new HypFacebookRequestDialogEvent( sType );
				ev.sRequestID	= sRequestID;
				ev.sError		= sError;
			return ev;
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _dispatch_request_event( 
													sType		: String , 
													sResult		: String,
													sGraphPath	: String,
													sError		: String = null 
												 ) : HypFacebookRequestEvent{

			var ev = new HypFacebookRequestEvent( sType );
				ev.sResult		= sResult;
				ev.sGraphPath	= sGraphPath;
				ev.sError		= sError;
				
			return ev;
		}

	// -------o misc
		
	
	// -------o CPP

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@CPP("HypFacebook")
		public function HypFB_set_event_callback( fCallBack : Dynamic) : Void {
						
		}

	// -------o JNI

		#if android

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@JNI
		static public function create( sAppId : String ) : HypFacebook {
						
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@JNI
		static public function req_dialog( sKeys : String , sVals : String ) : Void {
						
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@JNI("fr.hyperfiction.HypFacebook","feed_dialog")
		static public function call_feed_dialog( sKeys : String , sVals : String ) : Void {
						
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@JNI
		static public function trace_hash( ) : Void {
						
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@JNI("fr.hyperfiction.HypFacebook","connect")
		public function jni_connect( instance : Dynamic ) : Bool {
						
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@JNI("fr.hyperfiction.HypFacebook","authorize")
		public function jni_authorize( instance : Dynamic , sPerms : String ) : Void {
						
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		@JNI
		static public function jni_graph_request( sGraphPath : String ) : Void{
						
		}


		#end

}

/**
 * ...
 * @author shoe[box]
 */

class HypFacebookEvent extends Event{


	public var eTypes			: EventTypes;
	public var sFacebook_token	: String;
	public var sError			: String;

	public static inline var OPENED : String = 'OPENED';
	
	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new( s : String ) {
			super( s );
		}
	
	// -------o public
	
	// -------o protected
	
	// -------o misc
	
}

/**
 * ...
 * @author shoe[box]
 */

class HypFacebookFeedDialogEvent extends HypFacebookEvent{

	public static inline var FEEDDIALOG_CANCELED	= "FEEDDIALOG_CANCELED";
	public static inline var FEEDDIALOG_ERROR		= "FEEDDIALOG_ERROR";
	public static inline var FEEDDIALOG_SENT		= "FEEDDIALOG_SENT";

	public var sPostID	: String;
		
	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new( sType : String ) {
			super( sType );
		}
	
	// -------o public
		
	// -------o protected
	
	// -------o misc
	
}

/**
 * ...
 * @author shoe[box]
 */

class HypFacebookRequestDialogEvent extends HypFacebookEvent{

	public static inline var REQUESTDIALOG_CANCELE	= "REQUESTDIALOG_CANCELED";
	public static inline var REQUESTDIALOG_ERROR	= "REQUESTDIALOG_ERROR";
	public static inline var REQUESTDIALOG_SEN		= "REQUESTDIALOG_SENT";

	public var sRequestID	: String;

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new( sType : String ) {
			super( sType );
		}
	
	// -------o public
		
	// -------o protected
	
	// -------o misc
	
}

/**
 * ...
 * @author shoe[box]
 */

class HypFacebookRequestEvent extends HypFacebookEvent{

	public static inline var GRAPH_REQUEST_ERROR	= "GRAPH_REQUEST_ERROR";
	public static inline var GRAPH_REQUEST_RESULTS	= "GRAPH_REQUEST_RESULTS";

	public var sResult : String;
	public var sGraphPath : String;

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new( sType : String ) {
			super( sType );
		}
	
	// -------o public
			

	// -------o protected
			

	// -------o misc
	
}

enum EventTypes{
	OPENED;
	FEEDDIALOG_CANCELED;
	FEEDDIALOG_ERROR;	
	FEEDDIALOG_SENT;
	REQUESTDIALOG_CANCELED;
	REQUESTDIALOG_ERROR;	
	REQUESTDIALOG_SENT;
	GRAPH_REQUEST_ERROR;
	GRAPH_REQUEST_RESULTS;
}