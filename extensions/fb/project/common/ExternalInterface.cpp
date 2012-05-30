#include <hx/Macros.h>
#include <hx/CFFI.h>

#include "Fb.h"

using namespace Hyperfiction;
AutoGCRoot *eval_onConnect = 0;

extern "C"{

	void nme_extensions_main(){
		printf("fb_extensions_main()\n");
	}
	//DEFINE_ENTRY_POINT(nme_extensions_main);
	
	int fb_register_prims(){
		printf("fb: register_prims()\n");
		//nme_extensions_main( );
		return 0;
	}
	#ifdef IPHONE
	void callback( const char* cbType , const char* data ){
		val_call2( eval_onConnect->get( ), alloc_string( cbType ) , alloc_string( data ) );
	}
	#endif

}

/* Device
**************************************************/
/*
value hyp_fb_os(){
    return alloc_string(os());
}
DEFINE_PRIM(hyp_fb_os,0);
*/
#ifdef IPHONE

value hyp_fb_init( value token ){
	return alloc_bool( fbInit( val_string( token ) ) );
}
DEFINE_PRIM( hyp_fb_init , 1 );

value hyp_fb_connect(){
	fbConnect( );
	return alloc_null( );
}
DEFINE_PRIM( hyp_fb_connect , 0 );

value hyp_fb_apprequest( value title , value message ){
	fbAppRequest( val_string( title ) , val_string( message ) );
	return alloc_null( );
}
DEFINE_PRIM( hyp_fb_apprequest , 2 );

value hyp_fb_apprequest_to_user( value title , value message , value friendId ){
	fbAppRequestToUser( val_string( title ) , val_string( message ) , val_string( friendId ) );
	return alloc_null( );
}
DEFINE_PRIM( hyp_fb_apprequest_to_user , 3 );

static value hypfb_set_callback( value onCall ){
	eval_onConnect = new AutoGCRoot( onCall );
    return alloc_bool( true );
}
DEFINE_PRIM( hypfb_set_callback , 1 );

static value hypfb_feed( 
								value title,
								value caption,
								value description,
								value link,
								value pictureUrl
							){
	fbFeed( 
			val_string( title ) , 
			val_string( caption ) ,
			val_string( description ) ,
			val_string( link ) ,
			val_string( pictureUrl ) 
		);

	return alloc_null( );
}
DEFINE_PRIM( hypfb_feed , 5 );

#endif

