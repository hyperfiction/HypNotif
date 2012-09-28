

#ifndef IPHONE
#define IMPLEMENT_API
#endif

#include <hx/CFFI.h>
#include "HypGA.h"
#include <stdio.h>

using namespace hyperfiction;
extern "C"{
	
	int HypGA_register_prims(){
		printf("HypGA: register_prims()\n");
		return 0;
	}
}
#ifdef IPHONE

	static value HypGA_startNewSession( value sUA_code , value iPeriod ){
		startNewSession( val_string( sUA_code ) , val_int( iPeriod ) );
		return alloc_null( );
	}
	DEFINE_PRIM( HypGA_startNewSession , 2 );

	static value HypGA_trackPageView( value sPage ){
		trackPageView( val_string( sPage ) );
		return alloc_null( );
	}
	DEFINE_PRIM( HypGA_trackPageView , 1 );

	static value HypGA_trackEvent( value sCat , value sAction , value sLabel , value iValue ){
		trackEvent( val_string( sCat ) , val_string( sAction ) , val_string( sLabel ) , val_int( iValue ) );
		return alloc_null( );
	}
	DEFINE_PRIM( HypGA_trackEvent , 4 );

	static value HypGA_setCustomVar( value iSlot , value sName , value sValue ){
		setCustomVar( val_int( iSlot ) , val_string( sName ) , val_string( sValue ) );
		return alloc_null( );
	}
	DEFINE_PRIM( HypGA_setCustomVar , 3 );

	static value HypGA_stopSession( ){
		stopSession( );
		return alloc_null( );
	}
	DEFINE_PRIM( HypGA_stopSession , 0 );

#endif
