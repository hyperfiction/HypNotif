/*
Copyright (c) 2013, Hyperfiction
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
package fr.hyperfiction;

/**
 *
 * @author louisbl
 */
@:build( org.shoebox.utils.NativeMirror.build() )
class HypNotif {

	var _server    	: String;
	var _protocol  	: String;
	var _host      	: String;
	var _url       	: String;
	var _register  	: String;
	var _unregister	: String;

	#if android
		var _instance	: Dynamic;
	#end

	public function new( protocol : String, host : String, url : String, register : String, unregister : String )
	{
		if( protocol == "https" || protocol == "https://") {
			_protocol = "https";
		} else {
			_protocol = "http";
		}
		_host      	= host;
		_url       	= url;
		_register  	= register;
		_unregister	= unregister;
		_server = _protocol + "://" + _host + _url;
	}

	public function connect( userid : String = "" ) : Void {
		#if android
			#if debug
				_instance = init( _server, _register, _unregister, userid, true );
			#else
				_instance = init( _server, _register, _unregister, userid, false );
			#end
		#end

		#if ios
			hypnotif_init( _protocol, _host, _url+_register, userid );
		#end
	}

	public function stopNotif( ) : Void{
		#if android
			removeNotif( _instance );
		#end
	}

	public function dispose( ) : Void {
		#if android
			_instance = null;
		#end

		#if ios
			hypnotif_dispose( );
		#end
	}

	#if android
		@JNI
		static function init( server : String, register : String, unregister : String, userid : String, debug_check : Bool ) : HypNotif {}
		@JNI
		function removeNotif( instance : Dynamic ) : Void{}
	#end

	#if ios
		@CPP("hypnotif")
		function hypnotif_init( protocol : String, host : String, url : String, userid : String ) : Void {}

		@CPP("hypnotif")
		function hypnotif_dispose( ) : Void {}
	#end
}