package fr.hyperfiction;

#if android
import nme.errors.Error;
import nme.JNI;
import org.shoebox.utils.system.Signal1;
#end

/**
 * ...
 * @author shoe[box]
 */

class HypLicensing extends Signal1<Bool>{

	 /**
     * LICENSED means that the server returned back a valid license response
     */
    public static inline var LICENSED : Int = 0x0100;
    /**
     * NOT_LICENSED means that the server returned back a valid license response
     * that indicated that the user definitively is not licensed
     */
    public static inline var NOT_LICENSED : Int = 0x0231;
    /**
     * RETRY means that the license response was unable to be determined ---
     * perhaps as a result of faulty networking
     */
    public static inline var RETRY : Int = 0x0123;


	#if android
	private var _hyp_licensing_instance	: Dynamic;
	private var _hyp_licensing_run		: Dynamic;
	private var _i_retry_count			: Int;
	private var _s_public_key			: String;

	static private inline var ANDROID_CLASS : String = 'fr.hyperfiction.HypLicensing';
	#end

	// -------o constructor
		
		/**
		* constructor
		*
		* @param	
		* @return	void
		*/
		private function new() {
			super( );
			trace('constructor');
			_i_retry_count = 0;
		}
	
	// -------o public
				
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function run( sPublicKey : String ) : Void {
			#if android
				_s_public_key = sPublicKey;
				trace('run ::: ');
				trace("Dont forget permission : com.android.vending.CHECK_LICENSE");

				if( _hyp_licensing_instance == null ){
					var method = JNI.createStaticMethod( ANDROID_CLASS ,'getInstance', '()Lfr/hyperfiction/HypLicensing;');
					_hyp_licensing_instance = method( );
				}

				if( _hyp_licensing_run == null )
					_hyp_licensing_run = JNI.createMemberMethod( ANDROID_CLASS , 'run' , '(Ljava/lang/String;Lorg/haxe/nme/HaxeObject;)V' );
					_hyp_licensing_run( _hyp_licensing_instance , sPublicKey , this );	

				//

			#else
				trace('Android only !!! ');
				throw new Error('This extension is android only');
			#end
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function allow( res : Int ) : Void {
			trace('allow ::: '+res);	
			if( res != RETRY )
				emit( true );
			else{
				if( _i_retry_count++ < 3 )
					run( _s_public_key );		
				else{
					fr.hyperfiction.HypSystem.show_error_dialog( 'Cannot connect to the Google Android Licensing server. Please try again later.');
					emit( false );
				}
			}
		}		

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function dontAllow( res : Int ) : Void {
			trace('dontAllow ::: '+res);	
			fr.hyperfiction.HypSystem.show_error_dialog( "Your google account is not authorized to use that app. (error : "+res+")" );
			emit( false );	
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		public function applicationError( errorCode : Int ) : Void {
			trace('applicationError ::: '+errorCode);
			fr.hyperfiction.HypSystem.show_error_dialog( "An error occured when validating your google account. ( error : "+errorCode+" )" );
			emit( false );
		}

	// -------o protected
	
		

	// -------o misc
		
		/**
		* 
		* 
		* @public
		* @return	void
		*/
		static public function getInstance( ) : HypLicensing {
			
			if( __instance == null )
				__instance = new HypLicensing( );

			return __instance;
		}

		private static var __instance : HypLicensing;
}