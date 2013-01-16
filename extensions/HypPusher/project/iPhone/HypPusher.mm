#import "HypPusher.h"
#import "PTPusher.h"
#import "PTPusherEvent.h"
#import "PTPusherChannel.h"
#import "PTPusherDelegate.h"

#define kLOG_ALL_EVENTS
#define kUSE_ENCRYPTED_CHANNELS YES


// Externs

extern "C"
{
	void hyp_on_connect( const char *socketId );
	void hyp_on_subscribed( const char *channel );
	void hyp_on_disconnect( );
	void hyp_on_message( const char *event, const char *data, const char *channel );
}


// Interfaces

	@class PTPusher;

	@interface HypPusherDelegate : NSObject <PTPusherDelegate>
	{}
	@property (nonatomic, strong) PTPusher *pusher;
	@property (nonatomic, strong) NSString *token;
	
	- (PTPusher *)createInstance:(NSString*)apiKey;
	
	@end


// Implementations

@implementation HypPusherDelegate 
	
	@synthesize pusher = _pusher;	
	

	- (void)dealloc
	{
		[[NSNotificationCenter defaultCenter]
		removeObserver:self name:PTPusherEventReceivedNotification object:self.pusher];
		[super dealloc];
	}

	#pragma mark - Event notifications
	
	- (void)handlePusherEvent:(NSNotification *)note
	{
	#ifdef kLOG_ALL_EVENTS
		PTPusherEvent *event = [note.userInfo objectForKey:PTPusherEventUserInfoKey];
		NSLog(@"[pusher] Received event %@", event);
	#endif
	}
	
	#pragma mark - Client creation
	
	- (PTPusher *)createInstance:(NSString*)apiKey
	{
		PTPusher *client		= [PTPusher pusherWithKey:apiKey connectAutomatically:NO encrypted:kUSE_ENCRYPTED_CHANNELS];
		client.reconnectDelay	= 10;
		client.delegate			= self;

		[[NSNotificationCenter defaultCenter] 
			addObserver:self 
			selector:@selector(handlePusherEvent:) 
			name:PTPusherEventReceivedNotification 
			object:self.pusher
		];
  

	  	return client;
	}

	
	#pragma mark - PTPusherDelegate methods
	
	- (void)pusher:(PTPusher *)pusher connectionDidConnect:(PTPusherConnection *)connection
	{
		pusher.reconnectAutomatically = YES;
		NSLog(@"[pusher-%@] Pusher client connected", connection.socketID);

		hyp_on_connect( [connection.socketID UTF8String] );
	}
	
	- (void)pusher:(PTPusher *)pusher connection:(PTPusherConnection *)connection failedWithError:(NSError *)error
	{
		NSLog(@"[pusher-%@] Pusher Connection failed, error: %@", pusher.connection.socketID, error);
	}
	
	- (void)pusher:(PTPusher *)pusher connectionWillReconnect:(PTPusherConnection *)connection afterDelay:(NSTimeInterval)delay
	{
		NSLog(@"[pusher-%@] Reconnecting after %d seconds...", pusher.connection.socketID, (int)delay);
	}
	
	- (void)pusher:(PTPusher *)pusher didSubscribeToChannel:(PTPusherChannel *)channel
	{
		NSLog(@"[pusher-%@] Subscribed to channel %@", pusher.connection.socketID, channel);
		hyp_on_subscribed( [channel.name UTF8String] );
	}
	
	- (void)pusher:(PTPusher *)pusher didFailToSubscribeToChannel:(PTPusherChannel *)channel withError:(NSError *)error
	{
		NSLog(@"[pusher-%@] Authorization failed for channel %@", pusher.connection.socketID, channel);
		if (pusher != self.pusher) {
			[pusher disconnect];
		}
	}
	
	- (void)pusher:(PTPusher *)pusher didReceiveErrorEvent:(PTPusherErrorEvent *)errorEvent
	{
		NSLog(@"[pusher-%@] Received error event %@", pusher.connection.socketID, errorEvent);
	}
	
	- (void)pusher:(PTPusher *)pusher willAuthorizeChannelWithRequest:(NSMutableURLRequest *)request
	{
		NSLog(@"[pusher-%@] Authorizing channel access...", pusher.connection.socketID);
		
		if( _token != [NSNull null]){
			NSMutableData *data = (NSMutableData *)[request HTTPBody];

			[data appendData:[_token dataUsingEncoding:NSUTF8StringEncoding]];	
			[request setHTTPBody:data];
		}
	}
	
	@end
	
namespace hyperfiction {
	
	HypPusherDelegate *hp;
	NSMutableDictionary *bindings;

	void createClient( const char *apiKey )
	{
		NSString *s	= [[NSString alloc] initWithUTF8String:apiKey];
		hp			= [HypPusherDelegate alloc];
		hp.pusher	= [hp createInstance:s];

		bindings = [[NSMutableDictionary alloc] init];
		
		NSLog (@"pusher client created : %s ",apiKey);
	}

	void setAuthEndPoint( const char *url, const char *token )
	{
		NSLog( @"set auth end point and token ::: ");
		hp.token	= [NSString stringWithFormat:@"&token=%s", token];
		
		NSString *s	= [[NSString alloc] initWithUTF8String:url];
		NSURL *ns	= [[NSURL alloc] initWithString:s];
		
		hp.pusher.authorizationURL = ns;
		
		NSLog ( @"auth url : %s with token : %s",url,token );
	}

	void unbindEvent( const char *event )
	{
		NSString *eventString	= [[NSString alloc] initWithUTF8String:event];

		[hp.pusher removeBinding:[bindings objectForKey:eventString]];
		[bindings removeObjectForKey:eventString];
		
	}

	void bindEvent( const char *event )
	{	
		NSString *eventString	= [[NSString alloc] initWithUTF8String:event];
		
		PTPusherEventBinding *evtBind = [hp.pusher bindToEventNamed:eventString handleWithBlock:^(PTPusherEvent *event) {
			NSLog(@"received event binded ::: %@", event );
			NSString *data = [NSString stringWithFormat:@"%@", event.data];
			hyp_on_message( [event.name UTF8String], [data UTF8String], [event.channel UTF8String] );
		}];

		[bindings setObject:evtBind forKey:eventString];
	}

	void sendEvent( const char *event, const char *data, const char *channel )
	{
		NSString *eventString	= [[NSString alloc] initWithUTF8String:event];
		NSString *dataString	= [[NSString alloc] initWithUTF8String:data];
		NSString *channelString	= [[NSString alloc] initWithUTF8String:channel];

		[hp.pusher sendEventNamed: eventString data:dataString channel:channelString];

		NSLog (@"send event %s on channel : %s ",event,channel);
	}

	void connect( )
	{
		[hp.pusher connect];
		NSLog (@"connecting to pusher...");
	}

	void disconnect( )
	{
		[hp.pusher disconnect];
		NSLog (@"disconnecting from pusher ! ");
	}

	void subscribe( const char *channel )
	{
		NSString *s = [[NSString alloc] initWithUTF8String:channel];
		
		[hp.pusher subscribeToChannelNamed:s];
		
		NSLog (@"subscribe to %s ",channel);
	}

}