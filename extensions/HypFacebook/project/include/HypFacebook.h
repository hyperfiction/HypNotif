#ifndef Device
#define Device

namespace Hyperfiction{

	/*
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
	
	bool connect( );
	const char logout( );
	void authorize( const char *sPerms );
	void dialog( const char *sAction , const char *sParamsNames , const char *sParamsValues );
	void graph_request( const char *sGraphRequest );
	*/

	bool authorize( const char *sPerms );
	bool connect( const char *token );
	const char* request( const char *sGraphRequest );
	void dialog( const char *sAction , const char *sParamsName , const char *sParamsVals );
	void disconnect( );
	void init(  );
}	

#endif