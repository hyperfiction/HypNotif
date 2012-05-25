#import <UIKit/UIKit.h>
#include <Fb.h>
#import "FBConnect.h"


//----------------------------------------------------------

typedef void( *FunctionType)( );

//Interface

	@interface FBDelegate : NSObject<FBSessionDelegate>{ }
		@property (nonatomic) FunctionType onFbLogin;
	@end

// Implementation

	@implementation FBDelegate

		@synthesize onFbLogin;

		- ( id ) init {
			self = [ super init ];
			return self;
		}

		- ( void ) dealloc {
			[ super dealloc ];
		}

		//FBSessionDelegate methods

			- (void)fbDidNotLogin:(BOOL)cancelled{
				NSLog( @"fbDidNotLogin" );
			}

			- (void)fbDidLogout{
				NSLog( @"fbDidLogout" );
			}

			- (void)fbDidExtendToken:(NSString*)accessToken expiresAt:(NSDate*)expiresAt{
				NSLog( @"fbDidExtendToken" );
			}
			- (void)fbSessionInvalidated{
				NSLog( @"fbSessionInvalidated" );
			}
			- (void)fbDidLogin{
				NSLog( @"fbDidLogin" );
				onFbLogin( );
			}

			/*
			- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url {
				NSLog( @"handleOpenURL" );
			    return [ facebook handleOpenURL:url];
			}
			*/

	@end

//----------------------------------------------------------

	//Callback externs
		extern "C"{
			void callback( const char* data , const char* data );
		}

	namespace Hyperfiction{
		
		static FBDelegate *fbDel = nil;
		static Facebook *fbInstance = nil;

		void onLogin( );

		bool fbInit( const char *token ){

			NSString *sToken = [ [NSString alloc] initWithUTF8String:token ];
			NSLog( @"Init with token %@" , sToken );

			fbDel = [ [ FBDelegate alloc] init ];
			fbDel.onFbLogin = &onLogin;

			fbInstance = [ [Facebook alloc] initWithAppId:sToken andDelegate : fbDel ];
			fbInstance.sessionDelegate = fbDel;

			[ sToken release ];
			return [ fbInstance isSessionValid ];
		}

		void fbDispose( ){
			[ fbDel dealloc ];
		}

		void fbConnect( ){

			NSLog( @"Connect" );
			if( ![ fbInstance isSessionValid ]){
				NSLog( @"Session is not valid authorizing..." );
				[ fbInstance authorize : nil ];
			}else{
				NSLog( @"Session is valid");
			}			

		}

		void fbAppRequest(  const char *title , const char *message ){

			NSString *sTitle   = [ [NSString alloc] initWithUTF8String:title ];
			NSString *sMessage = [ [NSString alloc] initWithUTF8String:message ];

			//NSMutableDictionary* params = [NSMutableDictionary dictionaryWithObjectsAndKeys:sTitle , sMessage , nil];
			NSMutableDictionary* params = [NSMutableDictionary dictionaryWithObjectsAndKeys:
												sTitle 	 , @"title",
												sMessage , @"message",
												nil
											];

		    [fbInstance dialog:@"apprequests" andParams:params andDelegate:nil];
		    [ sTitle release ];
		    [ sMessage release ];
		}

		void fbAppRequestToUser( const char *title , const char *message , const char *userId ){
			NSString *sTitle   = [ [NSString alloc] initWithUTF8String:title ];
			NSString *sMessage = [ [NSString alloc] initWithUTF8String:message ];
			NSString *friendId = [ [NSString alloc] initWithUTF8String:userId ];

			NSLog(@"%@",friendId);

			NSMutableDictionary* params = [NSMutableDictionary dictionaryWithObjectsAndKeys:
												sTitle 	 , @"title",
												sMessage , @"message",
												friendId , @"to",
												nil
											];

			 [fbInstance dialog:@"apprequests" andParams:params  andDelegate:nil];
		}

		void fbFeed( 
						const char *title , 
						const char *caption  , 
						const char *description , 
						const char *link , 
						const char *pictureUrl  
					){
			NSLog( @"fbFeed");
			
			NSString *sTitle       = [ [ NSString alloc ] initWithUTF8String:title ];
			NSString *sCaption     = [ [ NSString alloc ] initWithUTF8String:caption ];
			NSString *sDescription = [ [ NSString alloc ] initWithUTF8String:description ];
			NSString *sLink        = [ [ NSString alloc ] initWithUTF8String:link ];
			NSString *sPictureUrl  = [ [ NSString alloc ] initWithUTF8String:pictureUrl ];

			NSMutableDictionary *params = 
	        [NSMutableDictionary dictionaryWithObjectsAndKeys:
					sTitle			, @"name",
					sCaption		, @"caption",
					sDescription	, @"description",
					sLink			, @"link",
					sPictureUrl		, @"picture",
					nil
		    ];  
		    [fbInstance dialog:@"feed" andParams:params andDelegate : nil];

		    [ sTitle release ];
		    [ sCaption release ];
		    [ sDescription release ];
		    [ sLink release ];
		    [ sPictureUrl release ];
		  
		}

		//Callbacks

			void onLogin( ){
				NSLog( @"onLogin %@", [ fbInstance accessToken ] );
				
				callback( "ON_LOGIN" , ( const char *) [[ fbInstance accessToken] UTF8String] );

				NSUserDefaults *defaults = [ NSUserDefaults standardUserDefaults ];
				[defaults setObject:[ fbInstance accessToken ] forKey:@"FBAccessTokenKey" ];
				[defaults setObject:[ fbInstance expirationDate ] forKey:@"FBExpirationDateKey" ];
				[defaults synchronize];
			}

	}

