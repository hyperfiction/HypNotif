#ifndef Device
#define Device

namespace hyperfiction{

	void open_local_webview( const char *sUrl , int iPosX , int iPosY , int iWidth , int iHeight );
	void open_webview( const char *sUrl , int iPosX , int iPosY , int iWidth , int iHeight );
	void close_webview( );
	
}

#endif