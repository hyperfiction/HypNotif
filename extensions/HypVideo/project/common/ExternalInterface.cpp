#ifndef IPHONE
#define IMPLEMENT_API
#endif

#include <hx/CFFI.h>
#include <hx/Macros.h>
#include <stdio.h>
#include <hxcpp.h>
#include "HypVideo.h"

#ifdef ANDROID
#include <jni.h>
#endif
using namespace Hyperfiction;

#ifdef ANDROID
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
	   jniDouble,
	};
	#define  LOG_TAG    "trace"
	#define  ALOG(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

#endif

AutoGCRoot *eval_onConnect = 0;
AutoGCRoot *eval_onEvent = 0;

extern "C"{

	int HypVideo_register_prims(){
		printf("HypVideo : register_prims()\n");
		return 0;
	}

	void dispatch_event( const char *sType , const char *sArg1 , const char *sArg2 ){
		val_call3( 
					eval_onEvent->get( ) , 
					alloc_string( sType ) ,
					alloc_string( sArg1 ) ,
					alloc_string( sArg2 ) 
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
		
		/*
		JNIEXPORT void JNICALL Java_fr_hyperfiction_HypVideo_onConnectionOK( JNIEnv * env ){		
			val_call0( eval_onConnect->get( ) );	
		}
		*/

	#endif
}

// Callbacks ------------------------------------------------------------------------------------------------------
	
	/*
	static value HypFB_set_event_callback( value onCall ){
		ALOG("HypFB_set_event_callback %d", __LINE__ );
		eval_onEvent = new AutoGCRoot( onCall );
		return alloc_bool( true );
	}
	DEFINE_PRIM( HypFB_set_event_callback , 1 );
	*/

// iPhone ---------------------------------------------------------------------------------------------------------

	#ifdef IPHONE

	//Play Video remote
		value HypVideo_play_remote_video( value sVideoURL ){
			playRemove_video( val_string( sVideoURL ) );
			return alloc_null( );
		}
		DEFINE_PRIM( HypVideo_play_remote_video , 1 );
	
	#endif

