#include <HypWebView.h>
#import <UIKit/UIKit.h>


//Interface
	@interface BrowserController : UIViewController {
	    IBOutlet UIWebView *webView;
	}

	@property(nonatomic,retain)IBOutlet UIWebView *webView;

	-(void) open:(NSString*)sUrl atPosX:(int)x atPosY:(int)y withW:(int)w withH:(int)h;
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

		-(void) open_local_file:(NSString*)sPath atPosX:(int)x atPosY:(int)y withW:(int)w withH:(int)h{
			NSString *sResolvedPath = [[NSBundle mainBundle] pathForResource:sPath ofType:@"html"];
			NSLog(@"open_local_file %@",sResolvedPath);
			//open( sResolvedPath , x , y , w , h );
			[self open:sResolvedPath atPosX:x atPosY:y withW:w withH:h];
		}

		-(void) open:(NSString*)sUrl atPosX:(int)x atPosY:(int)y withW:(int)w withH:(int)h{

			NSLog(@"open %@",sUrl);
						
			//
				NSURLRequest *request = [NSURLRequest requestWithURL:[NSURL URLWithString:sUrl]];
			
			//
				if( webView == nil )
					webView	= [[UIWebView alloc]init]; 
					webView.frame = CGRectMake( x , y , w , h ); 
				
				//
					for (id subview in webView.subviews){
  						if ([[subview class] isSubclassOfClass: [UIScrollView class]]){
    						((UIScrollView *)subview).bounces = NO;
    					}
    				}

					//webView.scrollView.decelerationRate = UIScrollViewDecelerationRateNormal;

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

	void open_webview( const char *sUrl , int iPosX , int iPosY , int iWidth , int iHeight ){
		
		//
			if( instance == nil )
				instance = [[BrowserController alloc] init];
		
		//
			NSString *sPageURL = [[NSString alloc] initWithUTF8String:sUrl];

		//
			[instance open:sPageURL atPosX:iPosX atPosY:iPosY withW:iWidth withH:iHeight];
		
	}

	void  open_local_webview( const char *sUrl , int iPosX , int iPosY , int iWidth , int iHeight ){

		//
			if( instance == nil )
				instance = [[BrowserController alloc] init];
		
		//
			NSString *nsURL = [[NSString alloc] initWithUTF8String:sUrl];
			//NSString *nsEXT = [[NSString alloc] initWithUTF8String:sExtension];

		//
			[instance open_local_file:nsURL atPosX:iPosX atPosY:iPosY withW:iWidth withH:iHeight];
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
