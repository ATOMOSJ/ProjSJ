package com.vasu.intent;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button btn;
        btn = findViewById(R.id.ok);
        Intent nxt = new Intent(MainActivity.this,clickthrough.class);
        nxt.putExtra("title","home");
        nxt.putExtra("studentname","vasu");
        nxt.putExtra("rollno",10);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(nxt);
            }
        });
    }
}