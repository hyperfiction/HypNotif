

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
#ifdef IPHONE

	static value HypSystem_isConnectedtoInternet( value sUrl ){
		isConnectedtoInternet( val_string( sUrl ));
		return alloc_null( );
	}
	DEFINE_PRIM( HypSystem_isConnectedtoInternet , 1 );

#endif
