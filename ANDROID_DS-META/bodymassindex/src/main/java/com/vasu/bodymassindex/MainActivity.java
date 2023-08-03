package com.vasu.bodymassindex;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button cal;
        EditText weihgti , heihtin , heightf;
        TextView res;
        LinearLayout dick;


        weihgti = findViewById(R.id.iDFORWEIGHT);
        heightf = findViewById(R.id.iDFORHEIGHT1);
        heihtin = findViewById(R.id.iDFORHEIGHT2);
        cal = findViewById(R.id.iDFORCALCULATION);
        res = findViewById(R.id.iDFORRESULT);
        dick = findViewById(R.id.dick);
        cal.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
              int v1=  Integer.parseInt (weihgti.getText().toString());
              int v2=  Integer.parseInt (heightf.getText().toString());
              int v3=  Integer.parseInt (heihtin.getText().toString());
              int totin = v2*12+v3;
              double totcm = totin * 2.53;
              double totm = totcm/100;
              double bmi = v1/(totm*totm);
              if (bmi >18.5 && bmi< 24.9){
                  res.setText("you are healthy");
                  dick.setBackgroundColor(getResources().getColor(R.color.h));
              }else if(bmi >25 && bmi < 29.9){
                  res.setText("you are overweight ");
                  dick.setBackgroundColor(getResources().getColor(R.color.un));
                }else if(bmi > 30) {
                  res.setText("you are obese");
                  dick.setBackgroundColor(getResources().getColor(R.color.ow));
              }else if (bmi < 18.5){
                  res.setText("you are underweight");
                  dick.setBackgroundColor(getResources().getColor(R.color.under));
              }else {
                  res.setText("enter something else");
              }


            }
        });
    }
}