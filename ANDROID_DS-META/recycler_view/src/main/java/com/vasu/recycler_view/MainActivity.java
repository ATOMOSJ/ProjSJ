package com.vasu.recycler_view;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.app.Dialog;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.Toast;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
ArrayList<contactmodel> arc = new ArrayList<>();
    RecyclerconA ad ;
    RecyclerView R1 ;
    FloatingActionButton r0 ;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        r0 = findViewById(R.id.ro1);
        R1 = findViewById(R.id.contact);

        r0.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Dialog d =new Dialog(MainActivity.this);
                d.setContentView(R.layout.add);
                EditText e2 ,e3;
                e2 =d.findViewById(R.id.e2);
                e3 =d.findViewById(R.id.e3);
                Button e4 = d.findViewById(R.id.e4);
                e4.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        String name="";
                        String num="";
                        if (!e2.getText().toString().equals("")){
                      name = e2.getText().toString();
                      num = e3.getText().toString();}else {
                            Toast.makeText(MainActivity.this, "You missed some details fill properly", Toast.LENGTH_SHORT).show();
                        }
                        arc.add(new contactmodel(R.drawable.icons8_apple_tv__1_,name,num));
                        ad.notifyItemInserted(arc.size()-1);
                        R1.scrollToPosition(arc.size()-1);
                        d.dismiss();
                    }
                });
                d.show();
            }
        });
        R1.setLayoutManager(new LinearLayoutManager(this));
        arc.add(new contactmodel(R.drawable.icons8_apple_tv__1_,"JPS Saahil","7008434558"));
        arc.add(new contactmodel(R.drawable.icons8_apple_tv__1_,"vasisth","8903293000"));
        arc.add(new contactmodel(R.drawable.icons8_apple_tv__1_,"faiz","9032456908"));
        arc.add(new contactmodel(R.drawable.icons8_apple_tv__1_,"bhanu","8907678900"));
        arc.add(new contactmodel(R.drawable.icons8_apple_tv__1_,"jhon ","6547890987"));
        arc.add(new contactmodel(R.drawable.icons8_apple_tv__1_,"JPS Saahil","7751967890"));
        arc.add(new contactmodel(R.drawable.icons8_apple_tv__1_,"alisa","7008907558"));
        arc.add(new contactmodel(R.drawable.icons8_apple_tv__1_,"vinod","9856734558"));
        arc.add(new contactmodel(R.drawable.icons8_apple_tv__1_,"Rakesh","70084908124"));

        ad = new RecyclerconA(this,arc);
        R1.setAdapter(ad);

    }
}