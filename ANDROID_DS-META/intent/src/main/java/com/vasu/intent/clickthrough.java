package com.vasu.intent;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class clickthrough extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_clickthrough);
        Intent grt = getIntent();
        String title = grt.getStringExtra("title");
        String studentname = grt.getStringExtra("studentname");
        int rl = grt.getIntExtra("rollno",0);
        TextView yu;
        yu = findViewById(R.id.yu);
        yu.setText("roll no:"+ rl +"name"+ studentname);
        getSupportActionBar().setTitle(title);
    }
}