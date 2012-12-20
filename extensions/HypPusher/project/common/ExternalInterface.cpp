#ifndef IPHONE
#define IMPLEMENT_API
#endif

#include <hx/CFFI.h>
#include <hx/Macros.h>
#include <stdio.h>
#include <hxcpp.h>
#include "HypPusher.h"

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
#endif

AutoGCRoot *_on_connect					= 0;
AutoGCRoot *_on_disconnect				= 0;
AutoGCRoot *_on_message					= 0;
AutoGCRoot *_on_message_from_channel	= 0;

extern "C" {
	
	int hyppusher_register_prims( ) {
		printf("HypPusher ::: register_prims() \n");
		return 0;
	}

	#ifdef ANDROID
		JNIEXPORT void JNICALL Java_fr_hyperfiction_HypPusher_onConnect(JNIEnv * env, jobject  obj ){
	        val_call0( _on_connect -> get( ) );
	    }
	    JNIEXPORT void JNICALL Java_fr_hyperfiction_HypPusher_onDisconnect(JNIEnv * env, jobject  obj ){
	        val_call0( _on_disconnect -> get( ) );
	    }
		JNIEXPORT void JNICALL Java_fr_hyperfiction_HypPusher_onMessage(JNIEnv * env, jobject  obj, jstring msg ){
			 const char *messageString = env->GetStringUTFChars(msg, 0);
			 val_call1( _on_message -> get( ), alloc_string( messageString ) );
			 env->ReleaseStringUTFChars( msg, messageString );
	    }
	    JNIEXPORT void JNICALL Java_fr_hyperfiction_HypPusher_onMessageFromChannel(JNIEnv * env, jobject  obj, jstring chan, jstring evt, jstring msg ){
			 const char *messageString = env->GetStringUTFChars(msg, 0);
			 const char *eventString = env->GetStringUTFChars(evt, 0);
			 const char *channelString = env->GetStringUTFChars(chan, 0);
			 
			 val_call3( _on_message -> get( ), alloc_string( channelString ), alloc_string( eventString ), alloc_string( messageString ) );
			 
			 env->ReleaseStringUTFChars( msg, messageString );
			 env->ReleaseStringUTFChars( evt, eventString );
			 env->ReleaseStringUTFChars( chan, channelString );
	    }
	#endif
}

static value hyp_cb_connect( value onCall ) {
	printf("on connect");
	_on_connect = new AutoGCRoot( onCall );
    return alloc_bool(true);
}
DEFINE_PRIM(hyp_cb_connect,1);

static value hyp_cb_disconnect( value onCall ) {
	printf("on disconnect");
	_on_disconnect = new AutoGCRoot( onCall );
    return alloc_bool(true);
}
DEFINE_PRIM(hyp_cb_disconnect,1);

static value hyp_cb_message( value onCall ) {
	printf("on message");
	_on_message = new AutoGCRoot( onCall );
    return alloc_bool(true);
}
DEFINE_PRIM(hyp_cb_message,1);

static value hyp_cb_message_from_channel( value onCall ) {
	printf("on message from channel");
	_on_message_from_channel = new AutoGCRoot( onCall );
    return alloc_bool(true);
}
DEFINE_PRIM(hyp_cb_message_from_channel,1);