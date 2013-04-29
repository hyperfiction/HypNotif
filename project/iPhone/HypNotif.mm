/*
Copyright (c) 2013, Hyperfiction
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <HypNotif.h>
#import <UIKit/UIKit.h>
#import <AudioToolbox/AudioToolbox.h>
#import <objc/runtime.h>

@interface HypNotif : NSObject
	@property (nonatomic, retain) NSString *hostString;
	@property (nonatomic, retain) NSString *urlString;
	@property (nonatomic, retain) NSString *user_idString;
	@property (nonatomic, retain) NSString *httpsString;
@end

@interface NMEAppDelegate : NSObject <UIApplicationDelegate>
@end
@interface NMEAppDelegate (HypNotif)
	@property (nonatomic, retain) id hypNotif;
@end

static char const * const HypNotifKey = "hypnotif";

@implementation NMEAppDelegate (HypNotif)
	@dynamic hypNotif;

	- (id)hypNotif {
	    return objc_getAssociatedObject(self, HypNotifKey);
	}

	- (void)setHypNotif:(id)newHypNotif {
	    objc_setAssociatedObject(self, HypNotifKey, newHypNotif, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
	}

	/**
	 * Fetch and Format Device Token and Register Important Information to Remote Server
	 */
	- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)devToken {

		NSLog(@"[HypNotif] application didRegisterForRemoteNotificationsWithDeviceToken ::: ");

		#if !TARGET_IPHONE_SIMULATOR

		// Get Bundle Info for Remote Registration (handy if you have more than one app)
		NSString *appName = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"];
		NSString *appVersion = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];

		// Check what Notifications the user has turned on.  We registered for all three, but they may have manually disabled some or all of them.
		NSUInteger rntypes = [[UIApplication sharedApplication] enabledRemoteNotificationTypes];

		// Set the defaults to disabled unless we find otherwise...
		NSString *pushBadge = @"disabled";
		NSString *pushAlert = @"disabled";
		NSString *pushSound = @"disabled";

		// Check what Registered Types are turned on. This is a bit tricky since if two are enabled, and one is off, it will return a number 2... not telling you which
		// one is actually disabled. So we are literally checking to see if rnTypes matches what is turned on, instead of by number. The "tricky" part is that the
		// single notification types will only match if they are the ONLY one enabled.  Likewise, when we are checking for a pair of notifications, it will only be
		// true if those two notifications are on.  This is why the code is written this way
		if(rntypes == UIRemoteNotificationTypeBadge){
			pushBadge = @"enabled";
		}
		else if(rntypes == UIRemoteNotificationTypeAlert){
			pushAlert = @"enabled";
		}
		else if(rntypes == UIRemoteNotificationTypeSound){
			pushSound = @"enabled";
		}
		else if(rntypes == ( UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeAlert)){
			pushBadge = @"enabled";
			pushAlert = @"enabled";
		}
		else if(rntypes == ( UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeSound)){
			pushBadge = @"enabled";
			pushSound = @"enabled";
		}
		else if(rntypes == ( UIRemoteNotificationTypeAlert | UIRemoteNotificationTypeSound)){
			pushAlert = @"enabled";
			pushSound = @"enabled";
		}
		else if(rntypes == ( UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeAlert | UIRemoteNotificationTypeSound)){
			pushBadge = @"enabled";
			pushAlert = @"enabled";
			pushSound = @"enabled";
		}

		// Get the users Device Model, Display Name, Unique ID, Token & Version Number
		UIDevice *dev = [UIDevice currentDevice];

		NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
		NSString *identifierString = [defaults objectForKey:@"hypudidKey"];

		if( identifierString == nil ) {
			// Generate UDID
				CFUUIDRef identifierObject = CFUUIDCreate(kCFAllocatorDefault);

			// Convert the CFUUID to a string
				NSString *identifierString = (__bridge_transfer NSString *)CFUUIDCreateString(kCFAllocatorDefault, identifierObject);
				CFRelease((CFTypeRef) identifierObject);

			NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
			[defaults setObject:identifierString forKey:@"hypudidKey"];
			[defaults synchronize];
		}

		NSString *deviceUuid = identifierString;
	    NSString *deviceName = dev.name;
		NSString *deviceModel = dev.model;
		NSString *deviceSystemVersion = dev.systemVersion;

		// Prepare the Device Token for Registration (remove spaces and < >)
		NSString *deviceToken = [[[[devToken description]
			stringByReplacingOccurrencesOfString:@"<"withString:@""]
			stringByReplacingOccurrencesOfString:@">" withString:@""]
			stringByReplacingOccurrencesOfString: @" " withString: @""];

		NSString *postString = @"os=ios";
		postString = [postString stringByAppendingString:@"&appname="];
		postString = [postString stringByAppendingString:appName];
		postString = [postString stringByAppendingString:@"&appversion="];
		postString = [postString stringByAppendingString:appVersion];
		postString = [postString stringByAppendingString:@"&deviceuid="];
		postString = [postString stringByAppendingString:deviceUuid];
		postString = [postString stringByAppendingString:@"&userid="];
		postString = [postString stringByAppendingString:[ [self hypNotif] user_idString] ];
		postString = [postString stringByAppendingString:@"&devicetoken="];
		postString = [postString stringByAppendingString:deviceToken];
		postString = [postString stringByAppendingString:@"&devicename="];
		postString = [postString stringByAppendingString:deviceName];
		postString = [postString stringByAppendingString:@"&devicemodel="];
		postString = [postString stringByAppendingString:deviceModel];
		postString = [postString stringByAppendingString:@"&deviceversion="];
		postString = [postString stringByAppendingString:deviceSystemVersion];
		postString = [postString stringByAppendingString:@"&pushbadge="];
		postString = [postString stringByAppendingString:pushBadge];
		postString = [postString stringByAppendingString:@"&pushalert="];
		postString = [postString stringByAppendingString:pushAlert];
		postString = [postString stringByAppendingString:@"&pushsound="];
		postString = [postString stringByAppendingString:pushSound];

		// Register the Device Data
		NSURL *url = [[NSURL alloc] initWithScheme:[[self hypNotif] httpsString] host:[[self hypNotif] hostString] path:[[self hypNotif] urlString]];
		NSLog(@"Register URL: %@", url);
	    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
	    [request setHTTPMethod:@"POST"];
	    [request setHTTPBody:[postString dataUsingEncoding:NSUTF8StringEncoding]];
		NSLog(@"URL request: %@", request);
		NSData *returnData = [NSURLConnection sendSynchronousRequest:request returningResponse:nil error:nil];
		NSString *retour = [[NSString alloc] initWithData:returnData encoding:NSUTF8StringEncoding];
		NSLog(@"Return Data: %@", retour);

		#endif
	}

	/**
	 * Failed to Register for Remote Notifications
	 */
	- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {

		#if !TARGET_IPHONE_SIMULATOR

		NSLog(@"[HypNotif] Error in registration. Error: %@", error);

		#endif
	}

	/**
	 * Remote Notification Received while application was open.
	 */
	- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {

		#if !TARGET_IPHONE_SIMULATOR

		NSLog(@"[HypNotif] remote notification: %@",[userInfo description]);
		NSDictionary *apsInfo = [userInfo objectForKey:@"aps"];

		if( apsInfo != (id)[NSNull null] ) {
			NSString *alert = [apsInfo objectForKey:@"alert"];
			NSLog(@"[HypNotif] Received Push Alert: %@", alert);

			NSString *sound = [apsInfo objectForKey:@"sound"];
			NSLog(@"[HypNotif] Received Push Sound: %@", sound);
			AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);

			NSString *badge = [apsInfo objectForKey:@"badge"];
			NSLog(@"[HypNotif] Received Push Badge: %@", badge);
			if( badge != (id)[NSNull null] ) {
				application.applicationIconBadgeNumber = [badge integerValue];
			}
		}

		#endif
	}



@end

@implementation HypNotif
	@synthesize hostString;
	@synthesize urlString;
	@synthesize httpsString;
	@synthesize user_idString;

	- (id)init {
		hostString   	= @"www.example.com";
		urlString    	= @"/apns/register.php?";
		httpsString  	= @"http";
		user_idString	= @"";

		return self;
	}

	- (void)register {
		NSLog(@"[HypNotif] application register");
		[[UIApplication sharedApplication]
			registerForRemoteNotificationTypes:(UIRemoteNotificationTypeAlert | UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeSound)];
		[UIApplication sharedApplication].applicationIconBadgeNumber = 0;
	}

	- (void)applicationDidBecomeActive:(UIApplication *)application	{
	    NSLog(@"applicationDidBecomeActive");
		[UIApplication sharedApplication].applicationIconBadgeNumber = 0;
	}

@end

namespace hypnotif {

	HypNotif *hn;

	void init( const char *protocol, const char *host, const char *url, const char *user_id ) {
		NSLog(@"[HypNotif] init ::: %s | %s | %s | %s ",protocol,host,url,user_id);
		NSString *protocolString	= [ [NSString alloc] initWithUTF8String:protocol];
		NSString *hostString    	= [ [NSString alloc] initWithUTF8String:host];
		NSString *urlString     	= [ [NSString alloc] initWithUTF8String:url];
		NSString *user_idString 	= [ [NSString alloc] initWithUTF8String:user_id];

		hn              	= [[HypNotif alloc] init];
		hn.httpsString  	= protocolString;
		hn.hostString   	= hostString;
		hn.urlString    	= urlString;
		hn.user_idString	= user_idString;

		NMEAppDelegate *app = [[UIApplication sharedApplication] delegate];
		[app setHypNotif:hn];
		[hn register];
	}

}