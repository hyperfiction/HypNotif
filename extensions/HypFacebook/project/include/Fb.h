#ifndef Device
#define Device

namespace Hyperfiction{
	bool fbInit( const char *token );
	void fbDispose( );
	void fbConnect( );
	void fbAppRequest( const char *title , const char *message );
	void fbAppRequestToUser( const char *title , const char *message  , const char *friendId  );
	void fbFeed( 
					const char *title , 
					const char *caption  , 
					const char *description , 
					const char *link , 
					const char *pictureUrl 
				 );
}

#endif