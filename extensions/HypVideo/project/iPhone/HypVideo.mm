/**
 * ...
 * @author shoe[box]
 */
#include <HypVideo.h>
#import <UIKit/UIKit.h>

namespace hyperfiction{
	
	void playRemove_video( const char *sVideoURL ){
		NSString *NSVideoURL = [ [NSString alloc] initWithUTF8String:sVideoURL ];
		NSLog(@"playRemove_video %@",NSVideoURL);
	}

}