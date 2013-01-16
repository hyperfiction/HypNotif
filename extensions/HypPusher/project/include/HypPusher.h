#ifndef Device
#define Device

namespace hyperfiction {

	void createClient( const char *apiKey );
	void connect( );
	void setAuthEndPoint( const char *url, const char *token );
	void disconnect( );
	void subscribe( const char *channel );
	void sendEvent( const char *event, const char *data, const char *channel );
	void bindEvent( const char *event );
	void unbindEvent( const char *event );
}

#endif