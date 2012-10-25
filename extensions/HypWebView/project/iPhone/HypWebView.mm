#include <HypWebView.h>
#import <UIKit/UIKit.h>


//Interface
	@interface BrowserController : UIViewController {
	    IBOutlet UIWebView *webView;
	}

	@property(nonatomic,retain)IBOutlet UIWebView *webView;

	-(void) open_local_file:(NSString*)sUrl marginL:(int)ml marginT:(int)mt marginR:(int)mr marginB:(int)mb;
	-(void) open:(NSString*)sUrl marginL:(int)ml marginT:(int)mt marginR:(int)mr marginB:(int)mb;
	-(void) close;

	@end

//Implementation

	@implementation BrowserController

	@synthesize webView;

	//
		-(id) init {
			self = [ super init ];
			return self;
		}

		-(void) dealloc {
			[ super dealloc ];
		}

		-(void) open_local_file:(NSString*)sUrl marginL:(int)ml marginT:(int)mt marginR:(int)mr marginB:(int)mb{
			NSString *sResolvedPath = [[NSBundle mainBundle] pathForResource:sUrl ofType:@"html"];
			NSLog(@"open_local_file %@",sResolvedPath);
			//open( sResolvedPath , x , y , w , h );
			[self open:sResolvedPath marginL:ml marginT:mt marginR:mr marginB:mb];
		}

		-(void) open:(NSString*)sUrl marginL:(int)ml marginT:(int)mt marginR:(int)mr marginB:(int)mb{

			NSLog(@"open %@",sUrl);

			//
				NSURLRequest *request = [NSURLRequest requestWithURL:[NSURL URLWithString:sUrl]];
			
			//
				if( webView == nil )
					webView	= [[UIWebView alloc] init];//WithFrame:CGRectMake(ml,mt,[[UIScreen mainScreen] bounds].size.width -mr, [[UIScreen mainScreen] bounds].size.height)-mb];
					webView.frame = CGRectMake( 
												ml , 
												mt , 
												[[UIScreen mainScreen] bounds].size.width - ml - mr,
												[[UIScreen mainScreen] bounds].size.height - mt - mb
											);
				for (id subview in webView.subviews){
 					if ([[subview class] isSubclassOfClass: [UIScrollView class]]){
   						((UIScrollView *)subview).bounces = NO;
   					}
   				}
   				
			//	
				[webView loadRequest:request];

			//
				[[[UIApplication sharedApplication] keyWindow] addSubview:webView];
				[super viewDidLoad];
		}

		-(void) close{
			NSLog(@"close");
			[webView loadHTMLString: @"" baseURL: nil];
			NSLog(@"loadHTMLString");
			[webView removeFromSuperview];
			NSLog(@"removeFromSuperview");
      	 	[webView dealloc];
			NSLog(@"dealloc");
			webView = NULL;
      	}

	@end


namespace hyperfiction {

	static BrowserController *instance;

	void open_webview( const char *sUrl , int ml , int mt , int mr , int mb ){
		
		//
			if( instance == nil )
				instance = [[BrowserController alloc] init];
		
		//
			NSString *sPageURL = [[NSString alloc] initWithUTF8String:sUrl];

		//
			//[instance open:sPageURL marginL:marginL marginT:marginT withW:marginR withH:marginB];
			[instance open:sPageURL marginL:ml marginT:mt marginR:mr marginB:mb];
	}

	void  open_local_webview( const char *sUrl , int ml , int mt , int mr , int mb ){

		//
			if( instance == nil )
				instance = [[BrowserController alloc] init];
		
		//
			NSString *nsURL = [[NSString alloc] initWithUTF8String:sUrl];
			//NSString *nsEXT = [[NSString alloc] initWithUTF8String:sExtension];

		//
			//[instance open_local_file:nsURL marginL:marginL marginT:marginT withW:marginR withH:marginB];*
			[instance open_local_file:nsURL marginL:ml marginT:mt marginR:mr marginB:mb];
			//[instance open:sPageURL marginL:ml marginT:mt marginR:mr marginB:mb];
	}

	void close_webview( ){
		[instance close];
		instance = nil;
	}


	/*
	UIWebView *webView;

	void open_webview( const char *sUrl , int iPosX , int iPosY , int iWidth , int iHeight ){
		NSString *sPageURL	= [[NSString alloc] initWithUTF8String:sUrl];
		
		webView	= [[UIWebView alloc]init]; 
		webView.scrollView.bounces = NO;
		[webView loadRequest: [NSURLRequest requestWithURL: [NSURL URLWithString:sPageURL]]]; 
		webView.frame = CGRectMake( iPosX , iPosY , iWidth , iHeight ); 
		[[[UIApplication sharedApplication] keyWindow] addSubview:webView];
	}
	
	void close_webview( ){
		[webView loadHTMLString: @"" baseURL: nil];
		[webView removeFromSuperview];
        [webView cleanForDealloc];
        webView = NULL;
	}
	*/
	
}
