package fr.hyperfiction;

#if android
import nme.JNI;
#end

#if cpp
import cpp.Lib;
#end

import nme.events.Event;
import nme.events.EventDispatcher;

/**
 * ...
 * @author shoe[box]
 */

class HypFacebook extends EventDispatcher{

	public var token( default , default ) : String;
	public var app_id( default , default ) : String;

	#if mobile
		static var f_set_callback		= cpp.Lib.load( "HypFacebook" , "hyp_fb_set_callback" , 1 );
		static var f_set_event_callback	= cpp.Lib.load( "HypFacebook" , "hyp_fb_set_event_callback" , 1 );
	#end

	#if ios
		private static inline var CPP_FB_CLASS : String = "HypFacebook";
		private var _fCCP_authorize		: String->Bool;
		private var _fCCP_disconnect	: Void->Void;
		private var _fCPP_connect		: String->Bool;
		private var _fCPP_dialog		: String->String->String->Void;
		private var _fCPP_request		: String->String;
	#end

	#if android		
		private var _HypFB_java_instance	: Dynamic;
		private var _fJNI_authorize			: JNIFunc<Dynamic->String->Void>;
		private var _fJNI_connect			: JNIFunc<Dynamic->Bool>; 
		private var _fJNI_disconnect		: JNIFunc<Dynamic->String>;
		private var _fJNI_request			: JNIFunc<Dynamic->String->String>;
		private var _fJNI_dialog			: JNIFunc<Dynamic->String->String->String->Void>;

		private static inline var ANDROID_CLASS : String = 'fr/hyperfiction/HypFacebook';
	#end
	
	private static inline var ARGS_SEPARATOR : String = '|';

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new( sAppID : String ) {
			
			super( );
			this.app_id = sAppID;
			trace('constructor ::: '+sAppID );

			//iOS
				#if ios
					_fCCP_authorize		= Lib.load( CPP_FB_CLASS , "CPP_FB_authorize" , 1 );
					_fCCP_disconnect	= Lib.load( CPP_FB_CLASS , "CPP_FB_Disconnect" , 0 );
					_fCPP_connect		= Lib.load( CPP_FB_CLASS , "CPP_FB_Connect" , 1 );
					_fCPP_dialog		= Lib.load( CPP_FB_CLASS , "CPP_FB_dialog" , 3 );
					_fCPP_request		= Lib.load( CPP_FB_CLASS , "CPP_FB_request" , 1 );
				#end

			//CPP
				#if cpp
					f_set_event_callback( _on_event );
				#end

			//Android
				#if android
					_fJNI_authorize		= new JNIFunc<Dynamic->String->Void>( false ,ANDROID_CLASS , 'authorize' , [String] , Void );
					_fJNI_connect		= new JNIFunc<Dynamic->Bool>( false ,ANDROID_CLASS , 'connect' , [ ] , Bool );
					_fJNI_dialog		= new JNIFunc<Dynamic->String->String->String->Void>( false ,ANDROID_CLASS , 'dialog' , [ String , String , String ] , Void );
					_fJNI_disconnect	= new JNIFunc<Dynamic->String>( false ,ANDROID_CLASS , 'logout' , null , String );
					_fJNI_request		= new JNIFunc<Dynamic->String->String>( false , ANDROID_CLASS , 'graph_request' , [String] , String );

					var fCreate = new JNIFunc<String->Void>( true , ANDROID_CLASS , 'create' , [String] , HypFacebook );
						fCreate.call( [ sAppID ] );
					_HypFB_java_instance = fCreate.call( [ sAppID ] );
				#end
		}
	
	// -------o public
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function connect( a_permissions : Array<String> = null ) : Void {
			trace('connect');

			var bRes : Bool = false;

			//Android
				#if android
					bRes = _fJNI_connect.call( [ _HypFB_java_instance ] );					
				#end

			//iOS
				#if ios
					bRes = _fCPP_connect( app_id );
				#end	

			//
				trace('bRes :::: '+bRes);
				if( !bRes )
					authorize( a_permissions );
				
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function disconnect( ) : Void {
			
			//Android
				#if android
					_fJNI_disconnect.call( [ _HypFB_java_instance ] );
				#end

			//iOS
				#if ios
					_fCCP_disconnect( );
				#end

		}	

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function authorize( a_permissions : Array<String> = null ) : Void {
			trace('authorize ::: '+a_permissions);

			//
				if( a_permissions == null )
					a_permissions = [ ];
				var sPerms = a_permissions.join('|');

			//Android
				#if android		
					_fJNI_authorize.call( [ _HypFB_java_instance , sPerms ] );										
				#end

			//iOS
				#if ios
					_fCCP_authorize( sPerms );
				#end
		}	

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function request( sRequest : String ) : String {
			trace('request ::: '+sRequest);

			var res : String = null;

			//Android
				#if android
				res = _fJNI_request.call( [ _HypFB_java_instance , sRequest ] , false );
				#end

			//iPhone
				#if iphone
				res = _fCPP_request( sRequest );
				#end

			return res;
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function dialog( sAction	: String , paramsNames : Array<String> , paramsValues : Array<String> ) : Void {

			trace('dialog ::: '+sAction+' :: params : '+paramsNames+' :: values : '+paramsValues );

			//Android
				#if android
					_fJNI_dialog.call( 
										[ 
											_HypFB_java_instance , 
											sAction , 
											paramsNames.join( ARGS_SEPARATOR ) , 
											paramsValues.join( ARGS_SEPARATOR ) 
										] , false );					
				#end

			//iOS
				#if iphone
					_fCPP_dialog( 
									sAction , 
									paramsNames.join( ARGS_SEPARATOR ) , 
									paramsValues.join( ARGS_SEPARATOR ) 
								);
				#end
		}

	// -------o protected
	
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		private function _on_event( sEventType : String , args1 : String , args2 : String ) : Void{
			dispatchEvent( new HypFacebookEvent( sEventType , args1 , args2 ) );
		}

	// -------o misc
		
}

/**
 * ...
 * @author shoe[box]
 */

class HypFacebookEvent extends Event{

	public static inline var CONNECTION_OK			: String = 'CONNECTION_OK';
	public static inline var ON_REQUEST_COMPLETE	: String = 'ON_REQUEST_COMPLETE';
	public static inline var ON_REQUEST_FAILED		: String = 'ON_REQUEST_FAILED';	
	public static inline var ON_DIALOG_SUCCESS		: String = 'ON_DIALOG_SUCCESS';	

	public var args2		: String;
	public var args1		: String;

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new( s : String , args1 : String = null , args2 : String = null ) {
			super( s );
			this.args1	= args1;
			this.args2		= args2;
		}
	
	// -------o public
				
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		override public function toString( ) : String {
			return Std.format( '[HypFacebookEvent type : $type args1 : $args1 args2 : $args2]' );
		}

	// -------o protected
	
		

	// -------o misc
	
}

#if android

/**
 * ...
 * @author shoe[box]
 */

class JNIFunc<T>{

	public var bStaticMethod	: Bool;
	public var func				: T;
	public var sClassName		: String;
	public var sFuncName		: String;
	public var signature		: String;

	private var _func : T;

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		public function new( 
								bStatic		: Bool,
								sClassName	: String , 
								sFuncName	: String , 
								args_types	: Array<Dynamic> = null , 
								return_type	: Dynamic = null
							) {

			trace('constructur ::: '+sClassName+' sFuncName :: '+sFuncName+' return : '+return_type);

			//
				this.signature		= '('+( args_types != null ? _translate_types( args_types ) : '')+')'+_translate_type( return_type );
				this.sClassName		= sClassName;
				this.sFuncName		= sFuncName;
				this.bStaticMethod	= bStatic;
				
		}
	
	// -------o public
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function call( args : Array<Dynamic> , bOnUiThread : Bool = true ) : Dynamic {
			
			if( _func == null ){
				trace('call ::: '+sClassName+' ||| '+sFuncName+' ||| '+signature);
				try{					
					if( bStaticMethod )
						_func = JNI.createStaticMethod( sClassName , sFuncName , signature );
					else
						_func = JNI.createMemberMethod( sClassName , sFuncName , signature );
					
				}catch( e : nme.errors.Error ){
					trace('JNIFunc error : '+e);
				}
			}

			if( _func == null )
				throw new nme.errors.Error( );

			var res;
			if( bOnUiThread )
				nme.Lib.postUICallback( 
					function( ){
						res = Reflect.callMethod( JNIFunc , _func , args );						
					}
				);
			else
				res = Reflect.callMethod( JNIFunc , _func , args );						

			return res;
		}

	// -------o protected
		
		/**
		* 
		* 
		* @private
		* @return	void
		*/
		inline private function _translate_types( a : Array<Dynamic> ) : String{

			var sRes = '';
			for( t in a )
				sRes += _translate_type( t );
			
			return sRes;
		}

		/**
		* 
		* 
		* @private
		* @return	void
		*/
		inline private function _translate_type( type : Dynamic ) : String{

			var sRes : String = null;
			switch( type ){

				case Bool:
					sRes = 'Z';

				case String:
					sRes = 'Ljava/lang/String;';

				case Void:
					sRes = 'V';

				default:
					sRes = 'L'+Type.getClassName( type ).split('.').join('/')+';';
			}

			return sRes;
		}

	// -------o misc
	
}

#end