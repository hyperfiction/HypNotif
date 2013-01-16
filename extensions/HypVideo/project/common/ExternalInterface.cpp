

#ifndef IPHONE
#define IMPLEMENT_API
#endif

#include <hx/CFFI.h>
#include "HypVideo.h"
#include <stdio.h>

using namespace hyperfiction;

AutoGCRoot *eval_onEvent = 0;

extern "C"{
	
	int HypVideo_register_prims(){
		printf("HypVideo: register_prims()\n");
		return 0;
	}

	void dispatch_event( const char *sEvent , const char *sArg ){
		printf("dispatch_event\n");
		val_call2( 
					eval_onEvent->get( ) , 
					alloc_string( sEvent ) ,
					alloc_string( sArg )
				);
		
	}
}

#ifdef IPHONE

	static value HypVideo_play_remote( value sUrl ){
		printf("HypVideo_play_remote");
		play_remote( val_string( sUrl ) );
		return alloc_null( );
	}
	DEFINE_PRIM( HypVideo_play_remote , 1 );

	static value HypVideo_dispose( ){
		printf("HypVideo_dispose");
		dispose( );
		return alloc_null( );
	}
	DEFINE_PRIM( HypVideo_dispose , 0 );

#endif

// Callbacks ------------------------------------------------------------------------------------------------------
	
	static value HypVideo_set_event_callback( value onCall ){
		printf("HypVideo_set_event_callback");
		eval_onEvent = new AutoGCRoot( onCall );
		return alloc_bool( true );
	}
	DEFINE_PRIM( HypVideo_set_event_callback , 1 );
