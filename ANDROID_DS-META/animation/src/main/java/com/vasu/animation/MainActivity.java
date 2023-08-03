package com.vasu.animation;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView t1;
        Button q1,q2,q3,q4;
        t1=findViewById(R.id.t1);
        q1=findViewById(R.id.q1);
        q2=findViewById(R.id.q2);
        q3=findViewById(R.id.q3);
        q4=findViewById(R.id.q4);

        q3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Animation move;
                move = AnimationUtils.loadAnimation(getApplicationContext(),R.anim.move);
                t1.startAnimation(move);
            }
        });
        q1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Animation scale = AnimationUtils.loadAnimation(getApplicationContext(),R.anim.scale);
                t1.startAnimation(scale);
            }
        });
        q2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Animation rot;
                rot=AnimationUtils.loadAnimation(getApplicationContext(),R.anim.rot);
                t1.startAnimation(rot);

            }
        });
        q4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Animation alpha;
                alpha=AnimationUtils.loadAnimation(getApplicationContext(),R.anim.alpha);
                t1.startAnimation(alpha);
            }
        });

    }
}