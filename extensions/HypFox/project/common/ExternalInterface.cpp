#ifndef IPHONE
#define IMPLEMENT_API
#endif

#include <hx/CFFI.h>
#include <hx/Macros.h>
#include <stdio.h>
#include <hxcpp.h>
#include "HypFox.h"

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

AutoGCRoot *_on_connection		= 0;
AutoGCRoot *_on_connection_lost	= 0;
AutoGCRoot *_on_login			= 0;
AutoGCRoot *_on_room_join		= 0;
AutoGCRoot *_on_private_message	= 0;
AutoGCRoot *_on_user_found		= 0;

extern "C" {
	
	int hypfox_register_prims( ) {
		printf("HypFox ::: register_prims() \n");
		return 0;
	}

	#ifdef ANDROID

		JNIEXPORT void JNICALL Java_fr_hyperfiction_HypFox_onConnection(JNIEnv * env, jobject  obj, jboolean success ){
	        val_call1( _on_connection -> get( ), alloc_bool( success ) );
	    }
		JNIEXPORT void JNICALL Java_fr_hyperfiction_HypFox_onConnectionLost(JNIEnv * env, jobject  obj ){
	        val_call0( _on_connection_lost -> get( ) );
	    }
		JNIEXPORT void JNICALL Java_fr_hyperfiction_HypFox_onLogin(JNIEnv * env, jobject  obj ){
	        val_call0( _on_login -> get( ) );
	    }
		JNIEXPORT void JNICALL Java_fr_hyperfiction_HypFox_onRoomJoin(JNIEnv * env, jobject  obj ){
	        val_call0( _on_room_join -> get( ) );
	    }
		JNIEXPORT void JNICALL Java_fr_hyperfiction_HypFox_onPrivateMessage(JNIEnv * env, jobject  obj, jstring msg, jint id ){
			 const char *messageString = env->GetStringUTFChars(msg, 0);
			 val_call2( _on_private_message -> get( ), alloc_string( messageString ), alloc_int( id ) );
			 env->ReleaseStringUTFChars( msg, messageString );
	    }
		JNIEXPORT void JNICALL Java_fr_hyperfiction_HypFox_onUserFound(JNIEnv * env, jobject  obj, jint id ){
	        val_call1( _on_user_found-> get( ), alloc_int( id ) );
	    }

	#endif
}

static value hyp_cb_connection( value onCall ) {
	printf("on connection");
	_on_connection = new AutoGCRoot( onCall );
    return alloc_bool(true);
}
DEFINE_PRIM(hyp_cb_connection,1);

static value hyp_cb_connection_lost( value onCall ) {
	printf("on connection lost");
	_on_connection_lost = new AutoGCRoot( onCall );
    return alloc_bool(true);
}
DEFINE_PRIM(hyp_cb_connection_lost,1);

static value hyp_cb_login( value onCall ) {
	printf("on login");
	_on_login = new AutoGCRoot( onCall );
    return alloc_bool(true);
}
DEFINE_PRIM(hyp_cb_login,1);

static value hyp_cb_room_join( value onCall ) {
	printf("on room join");
	_on_room_join = new AutoGCRoot( onCall );
    return alloc_bool(true);
}
DEFINE_PRIM(hyp_cb_room_join,1);

static value hyp_cb_private_message( value onCall ) {
	printf("on private message");
	_on_private_message = new AutoGCRoot( onCall );
	return alloc_bool( true );
}
DEFINE_PRIM(hyp_cb_private_message,1);

static value hyp_cb_user_found( value onCall ) {
	printf("on user found");
	_on_user_found = new AutoGCRoot( onCall );
	return alloc_bool( true );
}
DEFINE_PRIM(hyp_cb_user_found,1);