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
#include <android/log.h>
#endif

using namespace hyperfiction;

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

AutoGCRoot *_on_connect					= 0;
AutoGCRoot *_on_disconnect				= 0;
AutoGCRoot *_on_message					= 0;
AutoGCRoot *_on_subscribed				= 0;

extern "C"
{
	
	int hyppusher_register_prims( )
	{
		printf("HypPusher ::: register_prims() \n");
		return 0;
	}
	
// Android -------------------------------------------------------------------------------------------------------------

	#ifdef ANDROID

		JNIEXPORT void JNICALL Java_fr_hyperfiction_HypPusher_onConnect(JNIEnv * env, jobject  obj, jstring socketId )
		{
			const char *socketIdString = env->GetStringUTFChars(socketId, 0);
	        val_call1( _on_connect -> get( ), alloc_string( socketIdString )  );
			env->ReleaseStringUTFChars( socketId, socketIdString );
	    }
	    
	    JNIEXPORT void JNICALL Java_fr_hyperfiction_HypPusher_onDisconnect(JNIEnv * env, jobject  obj )
	    {
	        val_call0( _on_disconnect -> get( ) );
	    }
		
		JNIEXPORT void JNICALL Java_fr_hyperfiction_HypPusher_onMessage(
		                                                                JNIEnv * env, 
		                                                                jobject  obj, 
		                                                                jstring event,
		                                                                jstring data, 
		                                                                jstring channel
		                                                                )
		{
			 const char *eventString = env->GetStringUTFChars(event, 0);
			 const char *dataString = env->GetStringUTFChars(data, 0);
			 const char *channelString = env->GetStringUTFChars(channel, 0);
			 
			 val_call3( _on_message -> get( ), 
			           alloc_string( eventString ), 
			           alloc_string( dataString ), 
			           alloc_string( channelString ) 
			           );
			 
			 env->ReleaseStringUTFChars( event, eventString );
			 env->ReleaseStringUTFChars( data, dataString );
			 env->ReleaseStringUTFChars( channel, channelString );
	    }

	    JNIEXPORT void JNICALL Java_fr_hyperfiction_HypPusher_onSubscribed( 
	                                                                       JNIEnv * env, 
	                                                                       jobject obj, 
	                                                                       jstring channel 
	                                                                       )
	    {
			const char *channelString = env->GetStringUTFChars(channel, 0);
	        val_call1( _on_subscribed -> get( ), alloc_string( channelString )  );
			env->ReleaseStringUTFChars( channel, channelString );
	    }
	#endif

// iOS -----------------------------------------------------------------------------------------------------------------
	
	#ifdef IPHONE
		
		void hyp_on_connect( const char *socketId )
		{
			val_call1( _on_connect -> get( ), alloc_string( socketId ) );
		}

		void hyp_on_subscribed( const char *channel )
		{
			val_call1( _on_subscribed-> get( ), alloc_string( channel ) );
		}

		void hyp_on_disconnect( )
		{
			val_call0( _on_disconnect -> get( ) );
		}

		void hyp_on_message( const char *event, const char *data, const char *channel )
		{
			val_call3( _on_message -> get( ), alloc_string( event ), alloc_string( data ), alloc_string( channel ) );
		}

	#endif
}

// iOS -----------------------------------------------------------------------------------------------------------------

	#ifdef IPHONE

		void hyp_bind_event( value event )
		{
			bindEvent( val_string(event) );
		}
		DEFINE_PRIM( hyp_bind_event, 1);

		void hyp_unbind_event( value event )
		{
			unbindEvent( val_string(event) );
		}
		DEFINE_PRIM( hyp_unbind_event, 1);

		void hyp_send_event( value event, value data, value channel )
		{
			sendEvent( val_string(event), val_string(data), val_string(channel) );
		}
		DEFINE_PRIM( hyp_send_event, 3);

		void hyp_create( value apiKey )
		{
			createClient( val_string( apiKey ) );
		}
		DEFINE_PRIM( hyp_create, 1 );

		void hyp_set_authurl( value url, value token )
		{
			setAuthEndPoint( val_string( url ), val_string( token ) );
		}
		DEFINE_PRIM( hyp_set_authurl, 2 );

		void hyp_subscribe( value channel )
		{
			subscribe( val_string( channel ) );
		}
		DEFINE_PRIM( hyp_subscribe, 1 );

		void hyp_connect( )
		{
			connect( );
		}
		DEFINE_PRIM( hyp_connect, 0 );

		void hyp_disconnect( )
		{
			disconnect( );
		}
		DEFINE_PRIM( hyp_disconnect, 0 );

	#endif




// Callbacks -----------------------------------------------------------------------------------------------------------

	static value hyp_cb_connect( value onCall ) {
		_on_connect = new AutoGCRoot( onCall );
	    return alloc_bool(true);
	}
	DEFINE_PRIM(hyp_cb_connect,1);
	
	static value hyp_cb_disconnect( value onCall ) {
		_on_disconnect = new AutoGCRoot( onCall );
	    return alloc_bool(true);
	}
	DEFINE_PRIM(hyp_cb_disconnect,1);
	
	static value hyp_cb_message( value onCall ) {
		_on_message = new AutoGCRoot( onCall );
	    return alloc_bool(true);
	}
	DEFINE_PRIM(hyp_cb_message,1);

	static value hyp_cb_subscribed( value onCall ) {
		_on_subscribed = new AutoGCRoot( onCall );
	    return alloc_bool(true);
	}
	DEFINE_PRIM(hyp_cb_subscribed,1);