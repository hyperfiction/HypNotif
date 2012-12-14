package ::APP_PACKAGE::;

import fr.hyperfiction.HypFacebook;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import com.facebook.android.Facebook;

public class MainActivity extends org.haxe.nme.GameActivity {

	protected void onActivityResult( int requestCode , int resultCode , Intent data ) {
		Log.e("trace", "onActivityResult...");
        super.onActivityResult(requestCode, resultCode, data);
        Facebook fb =  HypFacebook.getInstance( );
        if( fb != null )
       		fb.authorizeCallback(requestCode, resultCode, data);
       
     }

}

