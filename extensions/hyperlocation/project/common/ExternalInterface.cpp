#ifndef IPHONE
#define IMPLEMENT_API
#endif

#include <hx/CFFI.h>
#include <hx/Macros.h>
#include <stdio.h>
#include <hxcpp.h>
#include "HyperLocation.h"

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

AutoGCRoot *_on_location_changed	= 0;
AutoGCRoot *_on_provider_enabled	= 0;
AutoGCRoot *_on_provider_disabled	= 0;
AutoGCRoot *_on_status_changed		= 0;

extern "C" {
	
	int hyperlocation_register_prims( ) {
		printf("HyperLocation ::: register_prims() \n");
		return 0;
	}

	#ifdef ANDROID
		JNIEXPORT void JNICALL Java_fr_hyperfiction_HyperLocation_onHypLocationChanged(JNIEnv * env, jobject  obj , jlong locTime, jdouble lat , jdouble lgt, jdouble alt ){
	        value args = alloc_array( 4 );
			val_array_set_i( args , 0 , alloc_float( locTime ) );
			val_array_set_i( args , 1 , alloc_float( lat ) );
			val_array_set_i( args , 2 , alloc_float( lgt ) );
			val_array_set_i( args , 3 , alloc_float( alt ) );
	        val_call1( _on_location_changed -> get( ), args );
	    }

	    JNIEXPORT void JNICALL Java_fr_hyperfiction_HyperLocation_onHypProviderDisabled(JNIEnv * env, jobject  obj , jstring provider ){
	        const char *providerString = env->GetStringUTFChars(provider, 0);
	        val_call1( _on_provider_disabled -> get( ), alloc_string( providerString ) );
	        env->ReleaseStringUTFChars(provider, providerString);
	    }

	    JNIEXPORT void JNICALL Java_fr_hyperfiction_HyperLocation_onHypProviderEnabled(JNIEnv * env, jobject  obj , jstring provider ){
	        const char *providerString = env->GetStringUTFChars(provider, 0);
	        val_call1( _on_provider_enabled -> get( ), alloc_string( providerString ) );
	        env->ReleaseStringUTFChars(provider, providerString);
	    }

	    JNIEXPORT void JNICALL Java_fr_hyperfiction_HyperLocation_onHypStatusChanged(JNIEnv * env, jobject  obj , jstring provider, jint status, jint satellites ){
	        const char *providerString = env->GetStringUTFChars(provider, 0);
	        val_call3( _on_status_changed -> get( ), alloc_string( providerString ), alloc_int( status ), alloc_int( satellites ) );
	        env->ReleaseStringUTFChars(provider, providerString);
	    }
	#endif
}

static value hyp_cb_location_changed( value onCall ) {
	printf("Set Location changed callback");
	_on_location_changed = new AutoGCRoot( onCall );
    return alloc_bool(true);
}
DEFINE_PRIM(hyp_cb_location_changed,1);

static value hyp_cb_provider_enabled( value onCall ) {
	printf("Set provider enabled callback");
	_on_provider_enabled = new AutoGCRoot( onCall );
    return alloc_bool(true);
}
DEFINE_PRIM(hyp_cb_provider_enabled,1);

static value hyp_cb_provider_disabled( value onCall ) {
	printf("Set provider disabled callback");
	_on_provider_disabled = new AutoGCRoot( onCall );
    return alloc_bool(true);
}
DEFINE_PRIM(hyp_cb_provider_disabled,1);

static value hyp_cb_status_changed( value onCall ) {
	printf("Set status changed callback");
	_on_status_changed = new AutoGCRoot( onCall );
    return alloc_bool(true);
}
DEFINE_PRIM(hyp_cb_status_changed,1);