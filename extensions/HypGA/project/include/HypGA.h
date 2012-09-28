#ifndef Device
#define Device

namespace hyperfiction{

	void startNewSession( const char *sUA_code , int iPeriod );
	void trackPageView( const char *sPage );
	void trackEvent( const char *sCat , const char *sAction,const char *sLabel , int iValue );
	void setCustomVar( int iSlot , const char *sName , const char *sValue );
	void stopSession( );
}

#endif