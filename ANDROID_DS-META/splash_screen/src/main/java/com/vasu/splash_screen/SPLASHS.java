package com.vasu.splash_screen;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;

import java.util.logging.LogRecord;

public class SPLASHS extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splashs);
        Intent go = new Intent(SPLASHS.this,MainActivity.class);

       new Handler().postDelayed(new Runnable() {
           @Override
           public void run() {
               startActivity(go);
               finish();
           }
       },5000);
    }
}
