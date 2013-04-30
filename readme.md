HypNotif
========
A native extension to add notifications to your NME application
---------------------------------------------------------------

This native extension brings you Apple Push Notification Service for iOS and Google Cloud Messaging for Android.
The iOS part is based on [Easy APNs](https://github.com/manifestinteractive/easyapns).
The Android part is based on the [GCM Demo Application](http://developer.android.com/google/gcm/demo.html).

For the APNs server you can use [Easy APNs](https://github.com/manifestinteractive/easyapns).

Installation
------------
There is an [include.nmml](https://github.com/hyperfiction/HypNotif/blob/master/include.nmml) file and [ndll](https://github.com/hyperfiction/HypNotif/tree/master/ndll) are compiled for:
* ios armv6
* ios armv7
* android armv6

*You can't use notification in the iOS simulator*


Usage
-----

    var hn = new HypNotif( "http", "example.com", "/notification", "/register", "/unregister" );
    hn.connect( <user id> );

You pass your server URL to the constructor with:
* the protocol
* the host name
* the path on your server
* the register end point
* the unregister end point (for android only)

When the device is registered it sends to the server the following values:
* the name of the OS ("and" or "ios")
* the prefered language of the system
* the package name of the application
* the version of the application
* the device name
* the device model
* the device version
* a device unique id (the register ID for android)
* the device token (only for ios)
* for iOS, if user allow badges, alerts and/or sounds
* a custom user id

On Android when the stopNotif method is called it sends the following values:
* the package name of the application
* the version of the application
* a device unique id (the register ID for android)
* a custom user id

Made at [Hyperfiction](http://hyperfiction.fr)
----------------------------------------------
Developed by :
- [Louis Beltramo](https://github.com/louisbl) [@louisbl](https://twitter.com/louisbl)

License
-------
This work is under BSD simplified License.