/**
 * ...
 * @author shoe[box]
 */
#include <HypVideo.h>
#import <MediaPlayer/MediaPlayer.h> 
#import <UIKit/UIKit.h>

//
    typedef void( *FunctionType)( );
    extern "C"{
        void dispatch_event( const char *sEvent , const char *sArg );
    }

//Interface
    @interface MovieLayer : UIViewController<UIGestureRecognizerDelegate>{ 
        IBOutlet MPMoviePlayerController *videoPlayer; 
    }
        @property(nonatomic,retain)IBOutlet MPMoviePlayerController *videoPlayer;
    @end

//Implementation

    @implementation MovieLayer

        @synthesize videoPlayer;
       
        -(id) init {
            self = [ super init ];
            return self;
        }

        -(void) dealloc {
            [videoPlayer stop];
            [videoPlayer.view removeFromSuperview];
            [videoPlayer release];
            [ super dealloc ];
        }

        -(void) open:(NSString*)NSVideoPath{

            //
                UITapGestureRecognizer *tapGestureRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTapGesture)];
                tapGestureRecognizer.delegate = self;   

            //
                NSLog( @"open >> " );
                NSURL*NSVideoURL=[NSURL URLWithString:NSVideoPath];

            //
                if( videoPlayer == nil )
                    videoPlayer = [[MPMoviePlayerController alloc] initWithContentURL:NSVideoURL ];
                    videoPlayer.shouldAutoplay = YES;
                    videoPlayer.backgroundView.hidden = YES;
                    videoPlayer.controlStyle = MPMovieControlStyleEmbedded;//MPMovieControlStyleEmbedded;

             //
                [videoPlayer.view addGestureRecognizer:tapGestureRecognizer];
                //[videoPlayer setScalingMode:MPMovieScalingModeFill];

            //
                [[NSNotificationCenter defaultCenter]   addObserver:self
                                                        selector:@selector(moviePlayBackDidFinish:)
                                                        name:MPMoviePlayerPlaybackDidFinishNotification
                                                        object:videoPlayer];
            
            //
                [[[UIApplication sharedApplication] keyWindow] addSubview:videoPlayer.view];
                [videoPlayer setFullscreen:YES animated:NO];
   
        }

        - (void) moviePlayBackDidFinish:(NSNotification*)notification {
            NSString *str = [[[notification userInfo] valueForKey:MPMoviePlayerPlaybackDidFinishReasonUserInfoKey] stringValue];
            NSLog(@"moviePlayBackDidFinish >> %@",str);        
            dispatch_event( [ str UTF8String ] , "" );
        }

        #pragma mark - gesture delegate
        // this allows you to dispatch touches
        - (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldReceiveTouch:(UITouch *)touch {
            return YES;
        }
        // this enables you to handle multiple recognizers on single view
        - (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer {
            return YES;
        }

        - ( void ) handleTap : ( UITapGestureRecognizer *) recognizer {
            NSLog(@"moviePlayBackDidFinish >> %@");        
        }
         
    @end

namespace hyperfiction{
    
    static MovieLayer *instance;

    void play_remote( const char *sURL ){

        //
            NSString *NSVideoPath = [ [NSString alloc] initWithUTF8String:sURL ];
            NSLog(@"play_remote >> %@",NSVideoPath);

        //
            if( instance == nil )
                instance = [MovieLayer alloc];
            
            [instance open:NSVideoPath];
    }

    void dispose( ){
        if( instance != nil )
            [ instance dealloc ];
    }


}