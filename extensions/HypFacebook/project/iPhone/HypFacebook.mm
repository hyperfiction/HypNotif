#import "FBConnect.h"
#import "FBSession.h"
#import "Events.h"
#import <UIKit/UIKit.h>
#include <HypFacebook.h>
#import <FacebookSDK.h>

/*
<key>CFBundleURLTypes</key>
	<array>
		<dict>
			<key>CFBundleURLSchemes</key>
			<array>
				<string>fb210849718975311</string>
			</array>
		</dict>
	</array>
*/

//Externs
	typedef void( *FunctionType)( );
	extern "C"{
		void dispatch_event( int iEventCode , const char *sType , const char *sArgs );
	}
	

//interface

	@interface HypFacebookDelegate : NSObject <FBRequestDelegate, FBDialogDelegate, FBSessionDelegate>{}
		@property (nonatomic, retain) Facebook *facebook;
		+ (HypFacebookDelegate *)instance;	
	@end

	@interface NMEAppDelegate : NSObject <UIApplicationDelegate>
	@end

	@implementation NMEAppDelegate (Test)

		- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)newURL{
			NSLog(@"handleOpenURL");
			return YES;
		}
		- (BOOL)application:(UIApplication *) application 
							openURL:(NSURL *)url
							sourceApplication:(NSString *)sourceApplication
							annotation:(id)annotation {
		    // attempt to extract a token from the url
			NSLog(@"handleOpenURL2");
		    return [[[HypFacebookDelegate instance] facebook] handleOpenURL:url]; 
		}

		/*- (void)applicationDidEnterBackground:(UIApplication *)application{
			NSLog(@"applicationDidEnterBackground");
		}*/

		/*
		- (void)applicationDidBecomeActive:(UIApplication *)application	{
		    // FBSample logic
		    // We need to properly handle activation of the application with regards to SSO
		    //  (e.g., returning from iOS 6.0 authorization dialog or from fast app switching).
		    NSLog(@"applicationDidBecomeActive");
		    [FBSession.activeSession handleDidBecomeActive];
		    [self setActive:true];
		}
		*/

	@end

	

//implementation
	
	@implementation HypFacebookDelegate
		
		@synthesize facebook;
		
		+ (HypFacebookDelegate *)instance{
  			static HypFacebookDelegate *instance;

  			@synchronized(self){
    			if (!instance)
      				instance = [[HypFacebookDelegate alloc] init];

      			return instance;
  			}
		}

		- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url {
			NSLog(@"handleOpenURL");
		    return [self.facebook handleOpenURL:url];
		}


		/**
		* 
		* 
		* @public
		* @return	void
		*/
		-(bool) connect:(NSString*)NSappID{
			
			NSLog(@"connect with id : %@",NSappID);
			NSLog(@"FBSessionStateCreatedTokenLoaded ::: %@",FBSession.activeSession.state);
			
			//
				facebook = [[Facebook alloc] initWithAppId:NSappID andDelegate : self ];
				facebook.sessionDelegate = self;

			//
				NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
			    if ([defaults objectForKey:@"FBAccessTokenKey"] && [defaults objectForKey:@"FBExpirationDateKey"]) {
			        facebook.accessToken = [defaults objectForKey:@"FBAccessTokenKey"];
			        facebook.expirationDate = [defaults objectForKey:@"FBExpirationDateKey"];
			    }
		    
   			return [facebook isSessionValid];
   			
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		-(void) disconnect{
			[facebook logout];
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		-(void) authorize:(NSArray*)NSAPerms{
			NSLog(@"authorize");		
			return [facebook authorize:NSAPerms];
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		-(NSString*) fbRequest:(NSString*)NSGraphRequest{
			NSLog(@"request %@",NSGraphRequest);
			[facebook requestWithGraphPath:NSGraphRequest andDelegate:self];
			return @"toto";
		}

		/**
		* 
		* 
		* @public
		* @return	void
		*/
		-(void) open_dialog:(NSString*)NSAction andParams:(NSMutableDictionary*)NDParams{
			NSLog(@"dialog %@",NSAction);
			[facebook dialog:NSAction andParams:NDParams andDelegate:self];
		}
		
		// -----------------------------------------------------------------------------------------

		#pragma mark - FBDelegate Methods

		- (void)fbDidLogin {
		    NSLog(@"FB login OK");
		    dispatch_event( CONNECTION_OK , "" , [[facebook accessToken] UTF8String] );
		}

		/**
		 * Called when the user canceled the authorization dialog.
		 */
		-(void)fbDidNotLogin:(BOOL)cancelled {
		    NSLog(@"FB did not login");
		}

		/**
		 * Called when the request logout has succeeded.
		 */
		- (void)fbDidLogout {
		    NSLog(@"FB logout OK");
		 }

		/**
		 * Called when a request returns and its response has been parsed into
		 * an object.
		 *
		 * The resulting object may be a dictionary, an array, a string, or a number,
		 * depending on thee format of the API response.
		 */
		- (void)request:(FBRequest *)request didLoad:(id)result {
		    NSLog(@"FB request OK");
		    NSLog(@"req : %@",request);

		    NSString *req = (NSString*) request.graphPath;
		    NSLog(@"req : %@",req);

		    NSString *res = [NSString stringWithFormat:@"%@", result];
		    NSLog(@"res : %@",res);


		   dispatch_event( ON_REQUEST_COMPLETE , [req UTF8String] , [res UTF8String] );

		}

		/**
		 * Called when an error prevents the Facebook API request from completing
		 * successfully.
		 */
		- (void)request:(FBRequest *)request didFailWithError:(NSError *)error {
			NSLog(@"FB error: %@", [error localizedDescription]);
			NSString *req = (NSString*) request.graphPath;
			dispatch_event( ON_REQUEST_FAILED , [(NSString*) request.graphPath UTF8String] , [[error localizedDescription] UTF8String] );
		}

		/**
		 * Called when a UIServer Dialog successfully return.
		 */
		- (void)dialogDidComplete:(FBDialog *)dialog {
		    NSLog(@"published successfully on FB %@",dialog);
		    dispatch_event( ON_DIALOG_SUCCESS , "" , "" );
		} 

		-(void)fbSessionInvalidated{

		}

		- (void)fbDidExtendToken:(NSString*)accessToken expiresAt:(NSDate*)expiresAt{
		
		}

	@end

//
namespace Hyperfiction{

	/**
	* 
	* 
	* @public
	* @return	void
	*/
	void init(  ){
		NSLog(@"init");
	}

	/**
	* 
	* 
	* @public
	* @return	void
	*/
	bool connect( const char *sAppID ){
		NSString *NSAppID = [ [NSString alloc] initWithUTF8String:sAppID ];
		NSLog(@"connect %@",NSAppID);
		return [[HypFacebookDelegate instance] connect:NSAppID];
	}

	/**
	* 
	* 
	* @public
	* @return	void
	*/
	void disconnect( ){
		[[HypFacebookDelegate instance] disconnect];				
	}

	/**
	* 
	* 
	* @public
	* @return	void
	*/
	bool authorize( const char *sPerms ){
		NSString *NSPerms = [ [NSString alloc] initWithUTF8String:sPerms ];
		NSLog(@"authorize %@",NSPerms);
		[[HypFacebookDelegate instance] authorize:[NSPerms componentsSeparatedByString:@"|"]];
		return false;
	}

	/**
	* 
	* 
	* @public
	* @return	void
	*/
	const char* request( const char *sGraphRequest ){

		NSString *NSReq = [[NSString alloc] initWithUTF8String:sGraphRequest];
		NSString *NSRes = [[HypFacebookDelegate instance] fbRequest:NSReq];
		return [ NSRes UTF8String];
	}

	/**
	* 
	* 
	* @public
	* @return	void
	*/
	void dialog( const char *sAction , const char *sParamsName , const char *sParamsVals ){		

		NSArray *NSANames = [[[NSString alloc] initWithUTF8String:sParamsName] componentsSeparatedByString:@"|"];
		NSArray *NSAValues = [[[NSString alloc] initWithUTF8String:sParamsVals] componentsSeparatedByString:@"|"];
		
		int l = [NSANames count];

		NSMutableDictionary *NDParams = [[NSMutableDictionary alloc] initWithCapacity:l];

		
		for( int i=0 ; i<l ; i++ ){
			NSLog(@"key ::: %@",[NSANames objectAtIndex:i]);
			NSLog(@"val ::: %@",[NSAValues objectAtIndex:i]);
			[NDParams setValue:[NSAValues objectAtIndex:i] forKey:[NSANames objectAtIndex:i]];
		}

		NSLog(@"Dictionary: %@", [NDParams description]);
		
		 NSMutableDictionary *params = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                                   @"Facebook SDK for iOS", @"name",
                                   @"Build great social apps and get more installs.", @"caption",
                                   @"The Facebook SDK for iOS makes it easier and faster to develop Facebook integrated iOS apps.", @"description",
                                   @"https://developers.facebook.com/ios", @"link",
                                   @"https://raw.github.com/fbsamples/ios-3.x-howtos/master/Images/iossdk_logo.png", @"picture",
                                   nil];
		NSLog(@"Dictionary: %@", [params description]);
		
		[[HypFacebookDelegate instance] open_dialog:[[NSString alloc] initWithUTF8String:sAction] andParams:NDParams];
	}
}