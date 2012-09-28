#include <HypGA.h>
#import <UIKit/UIKit.h>
#import "GANTracker.h"

namespace hyperfiction {

	void startNewSession( const char *sUID , int iPeriod ){
		NSString *s = [[NSString alloc] initWithUTF8String:sUID];
		[ [GANTracker sharedTracker] startTrackerWithAccountID:s dispatchPeriod:iPeriod delegate:nil ];
	}
	
	void trackPageView( const char *sPage ){
		NSString *sPageName	= [[NSString alloc] initWithUTF8String:sPage];
		NSError *error;
		if (![[GANTracker sharedTracker] trackPageview:sPageName withError:&error]) {
			NSLog (@"trackPageView ERROR");
		}
	}

	void trackEvent( const char *sCat , const char *sAction,const char *sLabel , int iValue ){
		NSString *cat	= [[NSString alloc] initWithUTF8String:sCat];
		NSString *act	= [[NSString alloc] initWithUTF8String:sAction];
		NSString *lab	= [[NSString alloc] initWithUTF8String:sLabel];
		NSError *error;
		if (![[GANTracker sharedTracker] trackEvent:cat action:act label:lab value:iValue withError:&error]) {
			NSLog (@"trackEvent ERROR");
		}
	}

	void setCustomVar( int iSlot , const char *sName , const char *sValue ){
		NSString *sVarName	= [[NSString alloc] initWithUTF8String:sName];
		NSString *sVarValue	= [[NSString alloc] initWithUTF8String:sValue];
		NSError *error;
		if (![[GANTracker sharedTracker] setCustomVariableAtIndex:iSlot name:sVarName value:sVarValue withError:&error]) {
			NSLog (@"setCustomVariableAtIndex ERROR ! %@" , error);
		}

	}

	void stopSession( ){
		[[GANTracker sharedTracker] stopTracker];
	}
	
}
