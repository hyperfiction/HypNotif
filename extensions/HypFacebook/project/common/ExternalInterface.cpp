#ifndef IPHONE
#define IMPLEMENT_API
#endif

#import "Events.h"
#include "HypFacebook.h"
#include <hx/CFFI.h>
#include <hx/Macros.h>
#include <hxcpp.h>
#include <stdio.h>

using namespace Hyperfiction;

#ifdef ANDROID
	#include <jni.h>
	#include <stdio.h>
	#include <string.h>
	#include <android/log.h>
	extern JNIEnv *GetEnv();
	enum JNIType{
		jniUnknown,
		jniVoid,
		jniObjectString,
		jniObjectArray,
		jniObject,
		jniBoolean,
		jniByte,
		jniChar,
		jniShort,
		jniInt,
		jniLong,
		jniFloat,
		jniDouble
	};
#endif

AutoGCRoot *eval_onConnect = 0;
AutoGCRoot *eval_onEvent = 0;

extern "C"{

	void nme_extensions_main(){
		printf("fb_extensions_main()\n");
	}
	//DEFINE_ENTRY_POINT(nme_extensions_main);
		
	int HypFacebook_register_prims(){
		printf("HypFacebook : register_prims()\n");
		//nme_extensions_main( );
		return 0;
	}

	void dispatch_event( EventType eType , const char *sType , const char *sArgs ){
		val_call3( 
					eval_onEvent->get( ) , 
					alloc_string( EnumToString( eType ) ) , 
					alloc_string( sType ) ,
					alloc_string( sArgs ) 
				);
	}

	#ifdef IPHONE

		void callback( const char* cbType , const char* data ){
			val_call2( eval_onConnect->get( ), alloc_string( cbType ) , alloc_string( data ) );
		}
				

	#endif

// Common ------------------------------------------------------------------------------------------------------

	

// Android ----------------------------------------------------------------------------------------------------------

	#ifdef ANDROID
	
		JNIEXPORT void JNICALL Java_fr_hyperfiction_HypFacebook_onConnectionOK( JNIEnv * env ){		
			val_call0( eval_onConnect->get( ) );	
		}

		JNIEXPORT void JNICALL Java_fr_hyperfiction_HypFacebook_onFBEvent( 
																			JNIEnv * env , 
																			jobject obj , 
																			jstring jsEvName , 
																			jstring jsArgs 
																		){
			//Convert jstring to char*
			__android_log_write(ANDROID_LOG_ERROR, "Tag", "onFBEvent" );

			const char *sEvName	= env->GetStringUTFChars( jsEvName , false );
			__android_log_print(ANDROID_LOG_ERROR, "Tag", "EventName : %s" , sEvName );
			value valEvName = alloc_string(sEvName);
			env->ReleaseStringUTFChars( jsEvName , sEvName );

			const char *sArgs = env->GetStringUTFChars( jsArgs , false );
			__android_log_print(ANDROID_LOG_ERROR, "Tag", "Args : %s" , sArgs );
			value valArgs = alloc_string(sArgs);
			env->ReleaseStringUTFChars( jsArgs , sArgs );

			//Call
			val_call2( eval_onEvent->get( ) , valEvName , valArgs );

		}

	#endif
}

// Callbacks ------------------------------------------------------------------------------------------------------
	
	static value hyp_fb_set_callback( value onCall ){
		eval_onConnect = new AutoGCRoot( onCall );
	    return alloc_bool( true );
	}
	DEFINE_PRIM( hyp_fb_set_callback , 1 );

	static value hyp_fb_set_event_callback( value onCall ){
		eval_onEvent = new AutoGCRoot( onCall );
	    return alloc_bool( true );
	}
	DEFINE_PRIM( hyp_fb_set_event_callback , 1 );

// iPhone ---------------------------------------------------------------------------------------------------------

	#ifdef IPHONE

	value CPP_FB_Connect( value app_id ){
		return alloc_bool(connect( val_string( app_id)));
	}
	DEFINE_PRIM( CPP_FB_Connect , 1 );

	value CPP_FB_Disconnect( ){
		disconnect( );
		return alloc_null( );
	}
	DEFINE_PRIM( CPP_FB_Disconnect , 0 );

	value CPP_FB_authorize( value sPerms ){
		return alloc_bool(authorize( val_string( sPerms )));
	}
	DEFINE_PRIM( CPP_FB_authorize , 1 );

	value CPP_FB_request( value sGraphRequest ){		
		return alloc_string(request( val_string( sGraphRequest )));
	}
	DEFINE_PRIM( CPP_FB_request , 1 );

	value CPP_FB_dialog( value sAction , value sParamsName , value sParamsValues ){		
		dialog( 
			val_string( sAction ) , 
			val_string( sParamsName ) , 
			val_string( sParamsValues )
		);
		return alloc_null( );
	}
	DEFINE_PRIM( CPP_FB_dialog , 3 );

	/*
	value hyp_fb_connect(){
		fbConnect( );
		return alloc_null( );
	}
	DEFINE_PRIM( hyp_fb_connect , 0 );

	value hyp_fb_apprequest( value title , value message ){
		fbAppRequest( val_string( title ) , val_string( message ) );
		return alloc_null( );
	}
	DEFINE_PRIM( hyp_fb_apprequest , 2 );

	value hyp_fb_apprequest_to_user( value title , value message , value friendId ){
		fbAppRequestToUser( val_string( title ) , val_string( message ) , val_string( friendId ) );
		return alloc_null( );
	}
	DEFINE_PRIM( hyp_fb_apprequest_to_user , 3 );



	static value hypfb_feed( 
									value title,
									value caption,
									value description,
									value link,
									value pictureUrl
								){
		fbFeed( 
				val_string( title ) , 
				val_string( caption ) ,
				val_string( description ) ,
				val_string( link ) ,
				val_string( pictureUrl ) 
			);

		return alloc_null( );
	}
	DEFINE_PRIM( hypfb_feed , 5 );
	*/
	
	#endif

