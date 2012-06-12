#ifndef Device
#define Device

namespace Hyperfiction{

	#ifdef IPHONE
	bool addTapRecognizer( int fingers , int taps );
	bool removeTapRecognizer( int fingers , int taps );

	bool addSwipeRecognizer( int fingers , int direction );
	bool removeSwipeRecognizer( int fingers , int direction );

	bool addRotationRecognizer( );
	bool removeRotationRecognizer( );

	bool addPanRecognizer( int min , int max );
	bool removePanRecognizer( int min , int max );
	
	bool addPinchRecognize( );
	bool removePinchRecognize( );
	
	void init_hyp_touch( );
	
	void callbackTap( int touches , int fingers , float fx , float fy );	
	void callbackSwipe( int direction );
	void callbackRotation( float rotation , float velocity );
	void callbackPan( float fx , float fy , float vx , float vy );		
	void callback( const char * type , float* charArray );	
	void callbackPinch( float scale , float velocity );
	
	int getOrientation( );
	#endif
	
	#ifdef ANDROID
	int TwoPlusTwo ();
	#endif
}

#endif