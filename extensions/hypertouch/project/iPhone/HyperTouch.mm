#import <UIKit/UIKit.h>
#include <HyperTouch.h>

//---------------------------------------------------------------------------------------------------
	
	typedef void( *FunctionType)( );
	extern "C"{
		void callbackTap( int touches , int fingers , float fx , float fy );	
		void callbackSwipe( int direction );
		void callbackRotation( float rotation , float velocity );
		void callbackPan( float fx , float fy , float vx , float vy );		
		void callback( const char * type , float* charArray );	
		void callbackPinch( float scale , float velocity );
	} 

//Interface

	@interface TouchDelegate : NSObject<UIGestureRecognizerDelegate>{ }
		@property (nonatomic ) FunctionType fOnTap;
		@property (nonatomic ) FunctionType fOnSwipe;
		@property (nonatomic ) FunctionType fOnRot;
		@property (nonatomic ) FunctionType fOnPan;
		@property (nonatomic ) FunctionType fOnPinch;

		-( bool ) addPan : ( int ) minTouch andMax : ( int ) maxTouch;
		-( bool ) addPinch;
		-( bool ) addRotation;
		-( bool ) addSwipe : ( int ) iFingers andDirection : ( int ) iDirection;
		-( bool ) addTap : ( int ) fingersCount withTapsCount: ( int ) tapsCount;
		-( bool ) removeGestureByCodeName : ( NSString* ) codeName;
		-( bool ) removePan : ( int ) minTouch andMax : ( int ) maxTouch;
		-( bool ) removePinch;
		-( bool ) removeRotation;
		-( bool ) removeSwipe : ( int ) iFingers andDirection : ( int ) iDirection;
		-( bool ) removeTap : ( int ) fingersCount withTapsCount: ( int ) tapsCount;
		-( bool ) testGesture : ( NSString* ) codeName;
		-( int ) getOrientation;
		-( void ) handlePan:( UIPanGestureRecognizer * ) recognizer;
		-( void ) handlePinch:( UIPinchGestureRecognizer * ) recognizer;
		-( void ) handleRot:( UIRotationGestureRecognizer *) recognizer;
		-( void ) handleSwipe:( UISwipeGestureRecognizer *)recognizer;
		-( void ) handleTap : ( UITapGestureRecognizer *) recognizer;
		-( void ) pushGesture : ( NSString* ) codeName withValue : ( UIGestureRecognizer* ) gestureValue;
		-( void ) testView;
		//-( BOOL )gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer ;
	@end

// Implementation

	@implementation TouchDelegate

		static NSMutableDictionary *gestures = [[NSMutableDictionary alloc] init];
		UIView *refView;
		@synthesize fOnTap;
		@synthesize fOnSwipe;
		@synthesize fOnRot;
		@synthesize fOnPan;
		@synthesize fOnPinch;

		//
			- ( id ) init {
				self = [ super init ];
				return self;
			}

			- ( void ) dealloc {
				[ super dealloc ];
			}

			- (void ) testView{
				refView = [[UIView alloc] initWithFrame:CGRectMake(0,0,2,2)];
		        refView.alpha = 0;
		        [[[UIApplication sharedApplication] keyWindow] addSubview:refView];
			}

			- ( int ) getOrientation{
				return [UIApplication sharedApplication].statusBarOrientation;
			}

		
		//Tap
		//---------------------------------------------------------------------------------------------------
			-( bool ) addTap : ( int ) fingersCount withTapsCount: ( int ) tapsCount{
				
				//NSLog(@"addTap with %i fingers" , fingersCount );
				NSString *codeName = [ NSString stringWithFormat:@"TAP_fingers_%i_taps_%i", fingersCount , tapsCount ];

				if( [ self testGesture:codeName ] ){
					//NSLog( @"gesture already ON");
					[codeName release];
					return false;
				}				

				UITapGestureRecognizer * 	g = [
													[UITapGestureRecognizer alloc] 
													initWithTarget:self 
													action:@selector(handleTap:)
												];
			    							g.delegate = self;
			    //
			    	[ g setNumberOfTapsRequired 	: tapsCount ];
			    	[ g setNumberOfTouchesRequired 	: fingersCount ];

				//[[[UIApplication sharedApplication] keyWindow] addGestureRecognizer:g];
			    [[[[[UIApplication sharedApplication] keyWindow] subviews] objectAtIndex:0 ] addGestureRecognizer:g];
				[ self pushGesture:codeName withValue : g ];
				[codeName release];
				
				return true;
			}

			-( bool ) removeTap : ( int ) fingersCount withTapsCount: ( int ) tapsCount{
			
				return [ self removeGestureByCodeName : [ NSString stringWithFormat:@"TAP_fingers_%i_taps_%i", fingersCount , tapsCount ] ];
			
			}

			

		//Swipes
		//---------------------------------------------------------------------------------------------------
			//-( bool ) addSwipe : ( int ) fingersCount withDirection: ( UISwipeGestureRecognizerDirection ) direction{
			-( bool ) addSwipe : ( int ) iFingers andDirection : ( int ) iDirection{

				//NSLog( @"addSwipe with %i fingers in to direction : %i",iFingers , iDirection);
				NSString *codeName = [ NSString stringWithFormat:@"SWY_%ifinger_dir%i", iFingers , iDirection ];
				UIDeviceOrientation interfaceOrientation = [[UIDevice currentDevice] orientation];
				//NSLog(@"orientation: %d", interfaceOrientation);
				if( [ self testGesture:codeName ] ){
					//NSLog( @"gesture already ON");
					[codeName release];
					return false;
				}				

				UISwipeGestureRecognizer * 	g = [
													[UISwipeGestureRecognizer alloc] 
													initWithTarget:self 
													action:@selector(handleSwipe:)
												];
    										g.delegate = self;

    			//TBLR
    				switch( iDirection ){

    					case 1:
    						[ g setDirection : UISwipeGestureRecognizerDirectionRight ];
    						break;
    					
    					case 2:
    						[ g setDirection : UISwipeGestureRecognizerDirectionLeft ];
    						break;

    					case 4:
    						[ g setDirection : UISwipeGestureRecognizerDirectionUp ];
    						break;

    					case 8:
    						[ g setDirection : UISwipeGestureRecognizerDirectionDown ];
    						break;

    				}

    			[ g setNumberOfTouchesRequired : iFingers ];
				//[[[UIApplication sharedApplication] keyWindow] addGestureRecognizer:g];
				[[[[[UIApplication sharedApplication] keyWindow] subviews] objectAtIndex:0]addGestureRecognizer:g];
				[ self pushGesture : codeName withValue : g ];
				[codeName release];
				return true;
			}

			-( bool ) removeSwipe : ( int ) iFingers andDirection : ( int ) iDirection{
				
				return [ self removeGestureByCodeName : [ NSString stringWithFormat:@"SWY_%ifinger_dir%i", iFingers , iDirection ] ];
			
			}

		//Zoom
		//---------------------------------------------------------------------------------------------------

			-( bool ) addRotation{
				//NSLog( @"addRotation gesture" );
				
				if( [ self testGesture:@"ROT" ] ){
					//NSLog( @"gesture already ON");
					return false;
				}	

				UIRotationGestureRecognizer * 	g = [
																[UIRotationGestureRecognizer alloc] 
																initWithTarget:self 
																action:@selector(handleRot:)
															];
    											g.delegate = self;
    			//[[[UIApplication sharedApplication] keyWindow] addGestureRecognizer:g];
    			[[[[[UIApplication sharedApplication] keyWindow] subviews] objectAtIndex:0]addGestureRecognizer:g];
				[ self pushGesture : @"ROT" withValue : g ];
				return true;
			}

			-( bool ) removeRotation{		
				//NSLog( @"removeRotation gesture" );	
				return [ self removeGestureByCodeName : @"ROT" ];			
			}

		//Pan
		//---------------------------------------------------------------------------------------------------
			-( bool ) addPan : ( int ) minTouch andMax : ( int ) maxTouch{

				NSLog( @"addPan gesture min touch : %i max : %i" , minTouch , maxTouch );
				
				NSString *codeName = [ NSString stringWithFormat:@"PAN_%i_%i", minTouch , maxTouch ];
				if( [ self testGesture:codeName ] ){
					NSLog( @"gesture already ON");
					[codeName release];
					return false;
				}				

				UIPanGestureRecognizer * 	g = [
																[UIPanGestureRecognizer alloc] 
																initWithTarget:self 
																action:@selector(handlePan:)
															];
   											g.delegate = self;
   											g.minimumNumberOfTouches = minTouch;
   											g.maximumNumberOfTouches = maxTouch;
    			//[[[UIApplication sharedApplication] keyWindow] addGestureRecognizer:g];
				[[[[[UIApplication sharedApplication] keyWindow] subviews] objectAtIndex:0]addGestureRecognizer:g];   											
				[ self pushGesture : codeName withValue : g ];
				[codeName release];
				return true;
			}

			-( bool ) removePan : ( int ) minTouch andMax : ( int ) maxTouch{
				return [ self removeGestureByCodeName : [ NSString stringWithFormat:@"PAN_%i_%i", minTouch , maxTouch ] ];		
			}

		//Pinch
		//---------------------------------------------------------------------------------------------------
			-( bool ) addPinch{
				
				if( [ self testGesture:@"PINCH" ] ){
					return false;
				}	

				UIPinchGestureRecognizer  *	g = [
													[UIPinchGestureRecognizer alloc] 
													initWithTarget:self 
													action:@selector(handlePinch:)
												];
    										g.delegate = self;
    			//[[[UIApplication sharedApplication] keyWindow] addGestureRecognizer:g];
    			[[[[[UIApplication sharedApplication] keyWindow] subviews] objectAtIndex:0]addGestureRecognizer:g];
				[ self pushGesture : @"PINCH" withValue : g ];
				return true;
			}

			-( bool ) removePinch{
				return [ self removeGestureByCodeName : @"PINCH" ];	
			}

		//---------------------------------------------------------------------------------------------------
		//
			-( bool ) testGesture : ( NSString* ) codeName{
				
				if( gestures == nil ){
					gestures = [NSMutableDictionary alloc];
					return false;
				}
				return  [ gestures objectForKey : codeName ] ;
			}

		//
			-( void ) pushGesture : ( NSString* ) codeName withValue : ( UIGestureRecognizer* ) gestureValue {
				[ gestures setObject : gestureValue forKey:codeName ];
			}

		//
			-( bool ) removeGestureByCodeName : ( NSString* ) codeName{

				if( [ self testGesture:codeName ] == nil ){
					return false;
				}	
				
				UIGestureRecognizer* 	g = (UIGestureRecognizer*) [ gestures objectForKey : codeName ];
										g.enabled = FALSE;
				
				[ gestures removeObjectForKey : codeName ];										
				//
				//[[[UIApplication sharedApplication] keyWindow] removeGestureRecognizer:g];
				[[[[[UIApplication sharedApplication] keyWindow] subviews] objectAtIndex:0]removeGestureRecognizer:g];
				[ g release ];
				[ codeName release ];
				return true;
			}

		//---------------------------------------------------------------------------------------------------
		
			- ( void ) handleTap : ( UITapGestureRecognizer *) recognizer { 

				CGPoint tapPoint = [ 
										recognizer locationInView:[UIApplication sharedApplication].keyWindow.rootViewController.view
									];
				//NSLog(@"handleTap : %@ direction touches : %i taps : %i",NSStringFromCGPoint( tapPoint ) ,recognizer.numberOfTouchesRequired , recognizer.numberOfTapsRequired);

				callbackTap( 
								recognizer.numberOfTouchesRequired , 
								recognizer.numberOfTapsRequired , 
								tapPoint.x , 
								tapPoint.y 
							);
				
			}

			- (void)handleSwipe:( UISwipeGestureRecognizer *)recognizer {
				//NSLog( @"handleSwipe %i" , recognizer.direction );
				callbackSwipe( recognizer.direction );
			}

			- (void)handleRot:( UIRotationGestureRecognizer *) recognizer{
				//NSLog( @"handleRotation rotation %f velocity : %f " , recognizer.rotation , recognizer.velocity);
				callbackRotation( recognizer.rotation , recognizer.velocity );
			}

			- (void)handlePan:( UIPanGestureRecognizer * ) recognizer{
				CGPoint location = [recognizer locationInView:recognizer.view];
				CGPoint velocity = [recognizer velocityInView:recognizer.view];
				//NSLog( @"handlePan location %@ , velocity %@" , NSStringFromCGPoint(location) , NSStringFromCGPoint(velocity));
				callbackPan( location.x , location.y , velocity.x , velocity.y );
			}

			-( void ) handlePinch:( UIPinchGestureRecognizer * ) recognizer{
				//NSLog( @"handlePinch scale %f, velocity %f",recognizer.scale,recognizer.velocity);
				callbackPinch( recognizer.scale , recognizer.velocity );
			}

		//---------------------------------------------------------------------------------------------------

			- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer{
			   
			    // if either of the gesture recognizers is the long press, don't allow simultaneous recognition
			    if ([gestureRecognizer isKindOfClass:[UILongPressGestureRecognizer class]] || [otherGestureRecognizer isKindOfClass:[UILongPressGestureRecognizer class]])
			        return NO;

			    return YES;
			}

			

	@end

//---------------------------------------------------------------------------------------------------
	
	//Callback externs
		extern "C"{
			
		}

	namespace Hyperfiction{
		
		const int TAP = 0;
	
		static bool *bTap_ON     = false;
		static bool *bTap2_ON    = false;
		static TouchDelegate *td;

		static UITapGestureRecognizer *tapRecognizer = nil;

		//
			void init_hyp_touch( ){
				NSLog( @"init" );
				td = [ TouchDelegate alloc ];
				[ td testView ];
			}


		//Gestures
		//-----------------------------------------------------------
			bool addTapRecognizer( int fingers , int taps ){
				return [ td addTap : fingers withTapsCount : taps ];
			}

			bool removeTapRecognizer( int fingers , int taps ){
				return [ td removeTap : fingers withTapsCount : taps ];
			}

		//-----------------------------------------------------------

			bool addSwipeRecognizer( int fingers , int direction ){
				return [ td addSwipe : fingers andDirection : direction ];
			}

			bool removeSwipeRecognizer( int fingers , int direction ){
				return [ td removeSwipe : fingers andDirection : direction ];
			}

		//-----------------------------------------------------------

			bool addRotationRecognizer( ){
				return [ td addRotation ];	
			}

			bool removeRotationRecognizer( ){
				return [ td removeRotation ];	
			}

		//-----------------------------------------------------------

			bool addPanRecognizer( int min , int max ){
				return [ td addPan : min andMax : max];
			}

			bool removePanRecognizer( int min , int max ){
				return [ td removePan : min andMax : max];
			}

		//-----------------------------------------------------------

			bool addPinchRecognize( ){
				return [ td addPinch ];	
			}

			bool removePinchRecognize( ){
				return [ td removePinch ];	
			}

		//Callbacks

			void onLogin( ){
				//callback( "ON_LOGIN" , ( const char *) [[ fbInstance accessToken] UTF8String] );
			}

			int getOrientation( ){
				return [ td getOrientation ];
			}


	}
