

#ifndef IPHONE
#define IMPLEMENT_API
#endif

#include <hx/CFFI.h>
#include "HypWebView.h"
#include <stdio.h>

using namespace hyperfiction;
extern "C"{
	
	int hypwebview_register_prims(){
		printf("hypwebview: register_prims()\n");
		return 0;
	}
}
#ifdef IPHONE

	static value hypwebview_open( value sUrl , value ml , value mt , value mr , value mb ){
		open_webview( 
						val_string( sUrl ) ,
						val_int( ml ),
						val_int( mt ),
						val_int( mr ),
						val_int( mb )
					);
		return alloc_null( );
	}
	DEFINE_PRIM( hypwebview_open , 5 );

	static value hypwebview_loc( value sUrl , value ml , value mt , value mr , value mb ){
		open_local_webview( 
						val_string( sUrl ) ,
						val_int( ml ),
						val_int( mt ),
						val_int( mr ),
						val_int( mb )
					);
		return alloc_null( );
	}
	DEFINE_PRIM( hypwebview_loc , 5 );

	static value hypwebview_close( ){
		close_webview( );
		return alloc_null( );
	}
	DEFINE_PRIM( hypwebview_close , 0 );

#endif
