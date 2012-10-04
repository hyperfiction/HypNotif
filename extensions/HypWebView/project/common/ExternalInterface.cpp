

#ifndef IPHONE
#define IMPLEMENT_API
#endif

#include <hx/CFFI.h>
#include "HypWebView.h"
#include <stdio.h>

using namespace hyperfiction;
extern "C"{
	
	int HypWebView_register_prims(){
		printf("HypWebView: register_prims()\n");
		return 0;
	}
}
#ifdef IPHONE

	static value HypWebView_open( value sUrl , value iPosX , value iPosY , value iWidth , value iHeight ){
		open_webview( 
						val_string( sUrl ) ,
						val_int( iPosX ),
						val_int( iPosY ),
						val_int( iWidth ),
						val_int( iHeight )
					);
		return alloc_null( );
	}
	DEFINE_PRIM( HypWebView_open , 5 );

	static value HypWebView_close( ){
		close_webview( );
		return alloc_null( );
	}
	DEFINE_PRIM( HypWebView_close , 0 );

#endif
