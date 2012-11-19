

#ifndef IPHONE
#define IMPLEMENT_API
#endif

#include <hx/CFFI.h>
#include "HypSystem.h"
#include <stdio.h>

using namespace hyperfiction;
extern "C"{
	
	int HypSystem_register_prims(){
		printf("HypSystem: register_prims()\n");
		return 0;
	}
}

#ifdef BLACKBERRY
	static void HypSystem_show_loading( ){
		show_loading( );
	}
	DEFINE_PRIM( HypSystem_show_loading , 0 );

	static void HypSystem_hide_loading( ){
		hide_loading( );
	}
	DEFINE_PRIM( HypSystem_hide_loading , 0 );

	static value HypSystem_get_system_lang( ){
		return alloc_string( get_system_lang( ) );
	}
	DEFINE_PRIM( HypSystem_get_system_lang , 0 );
#endif

#ifdef IPHONE
	static value HypSystem_isConnectedtoInternet( value sUrl ){
		return alloc_bool( isConnectedtoInternet( val_string( sUrl ) ));
	}
	DEFINE_PRIM( HypSystem_isConnectedtoInternet , 1 );

	static value HypSystem_is_iphone( ){
		return alloc_bool( isiPhone( ) );
	}
	DEFINE_PRIM( HypSystem_is_iphone , 0 );

	static value HypSystem_screen_width( ){
		return alloc_int( get_screen_width( ) );
	}
	DEFINE_PRIM( HypSystem_screen_width , 0 );

	static value HypSystem_screen_height( ){
		return alloc_int( get_screen_height( ) );
	}
	DEFINE_PRIM( HypSystem_screen_height , 0 );

	static value HypSystem_get_system_lang( ){
		return alloc_string( get_system_lang( ) );
	}
	DEFINE_PRIM( HypSystem_get_system_lang , 0 );

#endif
