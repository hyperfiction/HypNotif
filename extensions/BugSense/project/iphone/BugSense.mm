#include <BugSense.h>
#import <UIKit/UIKit.h>
#import "BugSenseCrashController.h"

namespace hyperfiction{

	void run_bug_tracker( const char *sCode ){
		printf("run bugsense_run_bugtracker");
		NSString *code = [[NSString alloc] initWithUTF8String:sCode];
		[BugSenseCrashController sharedInstanceWithBugSenseAPIKey:code];
	}

}
