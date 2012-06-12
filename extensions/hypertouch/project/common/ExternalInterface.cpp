#ifndef IPHONE
#define IMPLEMENT_API
#endif

#if defined(HX_WINDOWS) || defined(HX_MACOS) || defined(HX_LINUX)
#define NEKO_COMPATIBLE
#endif


#include <hx/CFFI.h>
#include "HyperTouch.h"
#include <stdio.h>

#ifdef ANDROID
#include <jni.h>
#endif

using namespace Hyperfiction;

AutoGCRoot *eval_callback_pan = 0;
AutoGCRoot *eval_callback_pinch = 0;
AutoGCRoot *eval_callback_rotation = 0;
AutoGCRoot *eval_callback_swipe = 0;
AutoGCRoot *eval_callback_tap = 0;

extern "C"{

	void nme_extensions_main(){
		printf("HyperTouch_extension_main()\n");
	}
	//DEFINE_ENTRY_POINT(nme_extensions_main);
	
	int hypertouch_register_prims(){
		printf("HyperTouch: register_prims()\n");
		//nme_extensions_main( );
		return 0;
	}

	void callbackTap( int touches , int taps , float fx , float fy ){
		value args = alloc_array( 4 );
		val_array_set_i( args , 0 , alloc_int( touches ) );
		val_array_set_i( args , 1 , alloc_int( taps ) );
		val_array_set_i( args , 2 , alloc_float( fx ) );
		val_array_set_i( args , 3 , alloc_float( fy ) );
   		val_call1( eval_callback_tap -> get( ) , args ); 
   	}

	void callbackSwipe( int direction ){
		val_call1( eval_callback_swipe -> get( ) , alloc_int( direction ) ); 
	}

	void callbackRotation( float rotation , float velocity ){
		val_call2( eval_callback_rotation -> get( ) , alloc_float( rotation )  , alloc_float( velocity ) ); 
	}

	void callbackPinch( float scale , float velocity ){
		val_call2( eval_callback_pinch -> get( ) , alloc_float( scale )  , alloc_float( velocity ) ); 
	}

	void callbackPan( float fx , float fy , float vx , float vy ){
		value args = alloc_array( 4 );
		val_array_set_i( args , 0 , alloc_float( fx ) );
		val_array_set_i( args , 1 , alloc_float( fy ) );
		val_array_set_i( args , 2 , alloc_float( vx ) );
		val_array_set_i( args , 3 , alloc_float( vy ) );
   		val_call1( eval_callback_pan -> get( ) , args ); 
   	}


	#ifdef ANDROID

	   	JNIEXPORT void JNICALL Java_fr_hyperfiction_HyperTouch_onTap(JNIEnv * env, jobject  obj , jint touches , jint taps , jfloat fx , jfloat fy ){

	   		value args = alloc_array( 4 );
			val_array_set_i( args , 0 , alloc_float( touches ) );
			val_array_set_i( args , 1 , alloc_float( taps ) );
			val_array_set_i( args , 2 , alloc_float( fx ) );
			val_array_set_i( args , 3 , alloc_float( fy ) );
	   		val_call1( eval_callback_tap -> get( ) , args ); 
		}

		JNIEXPORT void JNICALL Java_fr_hyperfiction_HyperTouch_onSwipe( JNIEnv * env, jobject  obj , jint dir ){
	   		val_call1( eval_callback_swipe -> get( ) , alloc_int( dir ) ); 
		}

		JNIEXPORT void JNICALL Java_fr_hyperfiction_HyperTouch_onScale( JNIEnv * env, jobject  obj , jfloat scale , jfloat velocity ){
	   		val_call2( eval_callback_pinch -> get( ) , alloc_float( scale )  , alloc_float( velocity ) ); 
		}

		JNIEXPORT void JNICALL Java_fr_hyperfiction_HyperTouch_onPan( JNIEnv * env, jobject  obj , jfloat fx , jfloat fy , jfloat vx , jfloat vy ){
	   		value args = alloc_array( 4 );
			val_array_set_i( args , 0 , alloc_float( fx ) );
			val_array_set_i( args , 1 , alloc_float( fy ) );
			val_array_set_i( args , 2 , alloc_float( vx ) );
			val_array_set_i( args , 3 , alloc_float( vy ) );
	   		val_call1( eval_callback_pan -> get( ) , args ); 
		}

	#endif
}

#ifdef ANDROID

	//
		static value test_two_plus_two () {	
			return alloc_int ( TwoPlusTwo () );	
		}
		DEFINE_PRIM (test_two_plus_two, 0);

	//
		static value hyp_touch_callback_pan( value onCall ){
			eval_callback_pan = new AutoGCRoot( onCall );
		    return alloc_bool( true );
		}
		DEFINE_PRIM( hyp_touch_callback_pan , 1 );

		static value hyp_touch_callback_pinch( value onCall ){
			eval_callback_pinch = new AutoGCRoot( onCall );
		    return alloc_bool( true );
		}
		DEFINE_PRIM( hyp_touch_callback_pinch , 1 );

		static value hyp_touch_callback_rotation( value onCall ){
			eval_callback_rotation = new AutoGCRoot( onCall );
		    return alloc_bool( true );
		}
		DEFINE_PRIM( hyp_touch_callback_rotation , 1 );

		static value hyp_touch_callback_swipe( value onCall ){
			eval_callback_swipe = new AutoGCRoot( onCall );
		    return alloc_bool( true );
		}
		DEFINE_PRIM( hyp_touch_callback_swipe , 1 );

		static value hyp_touch_callback_tap( value onCall ){
			eval_callback_tap = new AutoGCRoot( onCall );
		    return alloc_bool( true );
		}
		DEFINE_PRIM( hyp_touch_callback_tap , 1 );

#endif


/* Device
**************************************************/

#ifdef IPHONE
	
	//
		static value hyp_touch_init( ){
			init_hyp_touch( );
			return alloc_null( );
		}
		DEFINE_PRIM( hyp_touch_init , 0 );
	
	//
		static value hyp_touch_callback_pan( value onCall ){
			eval_callback_pan = new AutoGCRoot( onCall );
		    return alloc_bool( true );
		}
		DEFINE_PRIM( hyp_touch_callback_pan , 1 );

		static value hyp_touch_callback_pinch( value onCall ){
			eval_callback_pinch = new AutoGCRoot( onCall );
		    return alloc_bool( true );
		}
		DEFINE_PRIM( hyp_touch_callback_pinch , 1 );

		static value hyp_touch_callback_rotation( value onCall ){
			eval_callback_rotation = new AutoGCRoot( onCall );
		    return alloc_bool( true );
		}
		DEFINE_PRIM( hyp_touch_callback_rotation , 1 );

		static value hyp_touch_callback_swipe( value onCall ){
			eval_callback_swipe = new AutoGCRoot( onCall );
		    return alloc_bool( true );
		}
		DEFINE_PRIM( hyp_touch_callback_swipe , 1 );

		static value hyp_touch_callback_tap( value onCall ){
			eval_callback_tap = new AutoGCRoot( onCall );
		    return alloc_bool( true );
		}
		DEFINE_PRIM( hyp_touch_callback_tap , 1 );

	//---------------------------------------------------------------------------------------------------
	
		static value HypTouch_addTap( value fingers , value taps ){
			return alloc_bool( addTapRecognizer( val_int( fingers ) , val_int( taps ) ) );
		}
		DEFINE_PRIM( HypTouch_addTap , 2 );

		static value HypTouch_removeTap( value fingers , value taps ){
			return alloc_bool( removeTapRecognizer( val_int( fingers ) , val_int( taps ) ) );
		}
		DEFINE_PRIM( HypTouch_removeTap , 2 );

	//---------------------------------------------------------------------------------------------------
	
		static value HypTouch_addSwipe( value fingers , value direction ){
			return alloc_bool( addSwipeRecognizer( val_int( fingers ) , val_int( direction ) ) );
		}
		DEFINE_PRIM( HypTouch_addSwipe , 2 );

		static value HypTouch_removeSwipe( value fingers , value direction ){
			return alloc_bool( removeSwipeRecognizer( val_int( fingers ) , val_int( direction ) ) );
		}
		DEFINE_PRIM( HypTouch_removeSwipe , 2 );

	//---------------------------------------------------------------------------------------------------
	
		static value hyp_touch_add_rot( value fingers , value direction ){
			return alloc_bool( addRotationRecognizer( ) );
		}
		DEFINE_PRIM( hyp_touch_add_rot , 0 );

		static value hyp_touch_remove_rot( value fingers , value direction ){
			return alloc_bool( removeRotationRecognizer( ) );
		}
		DEFINE_PRIM( hyp_touch_remove_rot , 0 );

	//---------------------------------------------------------------------------------------------------
	
		static value hyp_touch_add_pan( value min_touch , value max_touch ){
			return alloc_bool( addPanRecognizer( val_int( min_touch ) , val_int( max_touch ) ));
		}
		DEFINE_PRIM( hyp_touch_add_pan , 2 );

		static value hyp_touch_remove_pan( value min_touch , value max_touch ){
			return alloc_bool( removePanRecognizer( val_int( min_touch ) , val_int( max_touch ) ));
		}
		DEFINE_PRIM( hyp_touch_remove_pan , 2 );

	//---------------------------------------------------------------------------------------------------
	
		static value hyp_touch_add_pinch( ){
			return alloc_bool( addPinchRecognize( ) );
		}
		DEFINE_PRIM( hyp_touch_add_pinch , 0 );

		static value hyp_touch_remove_pinch( ){
			return alloc_bool( removePinchRecognize( ) );
		}
		DEFINE_PRIM( hyp_touch_remove_pinch , 0 );

		static value HypTouch_get_orientation( ){
			return alloc_int( getOrientation( ) );
		}
		DEFINE_PRIM( HypTouch_get_orientation , 0 );
		

#endif

