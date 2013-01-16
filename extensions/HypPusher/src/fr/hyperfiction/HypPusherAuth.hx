package fr.hyperfiction;

import nme.net.URLLoader;
import nme.net.URLRequest;
import nme.net.URLRequestMethod;
import nme.net.URLVariables;

import nme.events.EventDispatcher;
import nme.events.Event;
import nme.events.SecurityErrorEvent;
import nme.events.IOErrorEvent;

import org.shoebox.utils.system.Signal;
import org.shoebox.utils.system.Signal1;

class HypPusherAuth extends EventDispatcher
{

	public var sgAuthSuccessful : Signal1<String>;
	public var sgAuthFailed 	: Signal;
	public var sgAuthError 		: Signal;

	public function new() {
		sgAuthSuccessful 	= new Signal1<String>();
		sgAuthFailed 		= new Signal();
		sgAuthError 		= new Signal();

		super();
	}

	public function authenticate( socketID : String, endPoint : String, channelName : String) : Void {
		
		trace( " auth endpoint ::: "+endPoint );

		var urlLoader	: URLLoader;
		var urlRequest	: URLRequest;
		var postVars	: URLVariables;
		
		urlLoader	= new URLLoader();
		urlRequest	= new URLRequest(endPoint);
		postVars	= new URLVariables();
		
		postVars.socket_id		= socketID;
		postVars.channel_name	= channelName;
		
		urlRequest.data		= postVars;	
		urlRequest.method	= URLRequestMethod.POST;
		
		urlLoader.addEventListener(Event.COMPLETE, _onComplete);
		urlLoader.addEventListener(SecurityErrorEvent.SECURITY_ERROR, _onSecurityError);
		urlLoader.addEventListener(IOErrorEvent.IO_ERROR, _onIOError);
		
		try {
			urlLoader.load(urlRequest);
		} catch (error : Dynamic) {
			trace('unable to load authentication request! (' + error.message + ')');
		}
	}

	function _onComplete( event : Event ) : Void {
		var loader : URLLoader = event.target;

		trace( "loader ::: "+loader.data );
		var decodedData : Dynamic;
		
		try {
			decodedData = haxe.Json.parse(loader.data);
		} catch ( e : Dynamic ){
			trace('authentication failed! Property "data" not found in response data!');
			sgAuthFailed.emit();
			loader.close();
			return;
		}

		if( Reflect.hasField( decodedData, 'auth' ) ) {
			var authString:String = decodedData.auth;
			trace('authentication successful (auth: ' + authString + ')');
			
			sgAuthSuccessful.emit( authString );	
		
		} else {
			trace('authentication failed! Property "auth" not found in response data!');
			sgAuthFailed.emit();
		}
		
		loader.close();
	}
	
	function _onSecurityError( event : SecurityErrorEvent ) : Void {
		trace('security error! (' + event + ')');
		
		sgAuthError.emit();
		
		var loader : URLLoader = event.target;
		loader.close();
	}
	
	function _onIOError( event : IOErrorEvent ) : Void {
		trace('io error! (' + event + ')');
		
		sgAuthError.emit();
		
		var loader : URLLoader = event.target;
		loader.close();
	}
}