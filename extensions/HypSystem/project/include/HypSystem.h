#ifndef Device

#define Device

namespace hyperfiction{
	
	bool isConnectedtoInternet( const char *sURL );
	bool isiPhone( );
	int get_screen_height( );
	int get_screen_width( );
	const char* get_system_lang( );
	
	#ifdef BLACKBERRY
		void show_loading( );
		void hide_loading( );
		bool LaunchBrowser( const char *inUtf8Url );
	#endif

}

#endif