package ::APP_PACKAGE::;

import com.facebook.Session;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends org.haxe.nme.GameActivity {

	protected void onActivityResult( int requestCode , int resultCode , Intent data ) {
		Log.w("trace", "onActivityResult...");
        super.onActivityResult(requestCode, resultCode, data);
        Session.getActiveSession().onActivityResult(this, requestCode, resultCode, data);
     }

}

