package fr.hyperfiction;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import com.facebook.android.*;
import com.facebook.android.Facebook.*;
import android.util.Log;

public class HypTouchActivity extends Activity {

    Facebook facebook = new Facebook("YOUR_APP_ID");

    @Override
    public void onCreate(Bundle savedInstanceState) {
        Log.i("HypTouchActivity","onCreate");
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.main);

        facebook.authorize(this, new DialogListener() {
            @Override
            public void onComplete(Bundle values) {}

            @Override
            public void onFacebookError(FacebookError error) {}

            @Override
            public void onError(DialogError e) {}

            @Override
            public void onCancel() {}
        });
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
         Log.i("HypTouchActivity","onActivityResult");
        super.onActivityResult(requestCode, resultCode, data);

        facebook.authorizeCallback(requestCode, resultCode, data);
    }
}