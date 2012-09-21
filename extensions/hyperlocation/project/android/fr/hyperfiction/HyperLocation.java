package fr.hyperfiction;

import android.content.Context;
import android.os.Bundle;
import android.location.Location;
import android.location.LocationManager;
import android.location.LocationListener;
import android.util.Log;
import org.haxe.nme.GameActivity;
import android.opengl.GLSurfaceView;
import android.view.View;
import android.app.Activity;

public class HyperLocation implements LocationListener {
	
	private Location 		_location;
	private long 			_minTime;
	private float 			_minDistance;
	private float 			_isBetterWindow;
	private boolean 		_testIfIsBetter;

    static public native void onHypLocationChanged( long locTime, double lat, double lgt, double alt );
    static public native void onHypProviderDisabled( String provider );
    static public native void onHypProviderEnabled( String provider );
    static public native void onHypStatusChanged( String provider, int status, int satellites );

	static {
		System.loadLibrary( "hyperlocation" );
	}

	public static String TAG = "HyperLocation";

	public static HyperLocation createInstance( ){
		Log.i( TAG, " createInstance ::: " );
		return new HyperLocation( );
	}

	public void HyperLocation( ) {
		Log.i( TAG, " constructor ::: " );
		_isBetterWindow = 1000 * 10;
	}

	public void setDurationToTestBetter( float duration ) {
		_isBetterWindow = duration;
	}

	public void setTestIfBetter( boolean test ) {
		_testIfIsBetter = test;
	}

	public void beginLocationUpdates( long minTime, float minDistance ) {
		Log.i( TAG, " beginLocationUpdates ::: " );
		_minTime		= minTime;
		_minDistance	= minDistance;
		GameActivity.getInstance().runOnUiThread( new Runnable() {
			public void run( ) {
				LocationManager locManager;
				locManager = ( LocationManager ) GameActivity.getContext().getSystemService(Context.LOCATION_SERVICE);
				if( locManager != null ) {
					HyperLocation.this.onLocationChanged( locManager.getLastKnownLocation(LocationManager.GPS_PROVIDER) );
					locManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, HyperLocation.this._minTime, HyperLocation.this._minDistance, HyperLocation.this);
					locManager.requestLocationUpdates(LocationManager.NETWORK_PROVIDER, HyperLocation.this._minTime, HyperLocation.this._minDistance, HyperLocation.this);
				}
			}
		});
	}

	public void stopLocationUpdates( ) {
		Log.i( TAG, "stopLocationUpdates ::: " );
		GameActivity.getInstance().runOnUiThread( new Runnable() {
			public void run( ) {
				LocationManager locManager;
				locManager = ( LocationManager ) GameActivity.getContext().getSystemService(Context.LOCATION_SERVICE);
				if( locManager != null )
					locManager.removeUpdates(HyperLocation.this);
			}
		});
	}

	public void onLocationChanged( Location newLocation ) {
		Log.i( TAG, " on location changed ::: "+newLocation );
		if( !_testIfIsBetter || isBetterLocation(newLocation, _location) ) {
			_location = newLocation;
			if( _location != null )
				HyperLocation.onHypLocationChanged( _location.getTime(), _location.getLatitude(), _location.getLongitude(), _location.getAltitude() );
		}
	}

	public void onProviderDisabled( String provider ) {
		Log.i( TAG, " provider disabled ::: "+provider );
		HyperLocation.onHypProviderDisabled( provider );
	}

	public void onProviderEnabled( String provider ) {
		Log.i( TAG, " provider enabled ::: "+provider );
		beginLocationUpdates( _minTime, _minDistance );
		HyperLocation.onHypProviderEnabled( provider );
	}

	public void onStatusChanged( String provider, int status, Bundle extras ) {
		Log.i( TAG, " on provider    ::: "+provider );
		Log.i( TAG, " status changed ::: "+ status);
		HyperLocation.onHypStatusChanged( provider, status, extras.getInt( "satellites" ) );
	}

	/** http://developer.android.com/guide/topics/location/strategies.html
	* Determines whether one Location reading is better than the current Location fix
  	* @param location  The new Location that you want to evaluate
  	* @param currentBestLocation  The current Location fix, to which you want to compare the new one
  	*/
	protected boolean isBetterLocation(Location location, Location currentBestLocation) {
	    if (currentBestLocation == null) {
	        return true;
	    }

	    // Check whether the new location fix is newer or older
	    long timeDelta = location.getTime() - currentBestLocation.getTime();
	    boolean isSignificantlyNewer = timeDelta > _isBetterWindow;
	    boolean isSignificantlyOlder = timeDelta < _isBetterWindow;
	    boolean isNewer = timeDelta > 0;

	    // If it's been more than _isBetterWindow (ms) since the current location, use the new location
	    // because the user has likely moved
	    if (isSignificantlyNewer) {
	        return true;
	    // If the new location is more than two minutes older, it must be worse
	    } else if (isSignificantlyOlder) {
	        return false;
	    }

	    // Check whether the new location fix is more or less accurate
	    int accuracyDelta = (int) (location.getAccuracy() - currentBestLocation.getAccuracy());
	    boolean isLessAccurate = accuracyDelta > 0;
	    boolean isMoreAccurate = accuracyDelta < 0;
	    boolean isSignificantlyLessAccurate = accuracyDelta > 200;

	    // Check if the old and new location are from the same provider
	    boolean isFromSameProvider = isSameProvider(location.getProvider(),
	            currentBestLocation.getProvider());

	    // Determine location quality using a combination of timeliness and accuracy
	    if (isMoreAccurate) {
	        return true;
	    } else if (isNewer && !isLessAccurate) {
	        return true;
	    } else if (isNewer && !isSignificantlyLessAccurate && isFromSameProvider) {
	        return true;
	    }
	    return false;
	}

	/** Checks whether two providers are the same */
	private boolean isSameProvider(String provider1, String provider2) {
	    if (provider1 == null) {
	      return provider2 == null;
	    }
	    return provider1.equals(provider2);
	}
}