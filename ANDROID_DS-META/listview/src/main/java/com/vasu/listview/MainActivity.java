package com.vasu.listview;

import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.Spinner;

import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    Spinner l2;
AutoCompleteTextView L3;
//ArrayList<String > arrn = new ArrayList<>(); //arraylist for dynamic no. of content
    ArrayList<String> ar = new ArrayList<>();
    ArrayList<String> arr = new ArrayList<>();

//int[] arrnn= new  int[]{1,2,3,4,5};
// simple array for limited no of content
//simple list view
//        L1 =findViewById(R.id.L1);
//        arrn.add("vinay");
//        arrn.add("vinay");
//        arrn.add("vinay");
//        arrn.add("vinay");
//        ArrayAdapter<String> ada = new ArrayAdapter<>(getApplicationyContext(), android.R.layout.simple_list_item_1,arrn);
//        L1.setAdapter(ada);
//        L1.setOnItemClickListener(new AdapterView.OnItemClickListener() {
//            @Override
//            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
//                if (position == 0){
//                    Toast.makeText(MainActivity.this, "clicked on first item", Toast.LENGTH_SHORT).show();
//                } else if (position==1) {
//                    Toast.makeText(MainActivity.this, "clicked onn second item", Toast.LENGTH_SHORT).show();
//                }
//            }
//        });
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //spinner list
        l2 =findViewById(R.id.L2);
        L3 =findViewById(R.id.L3);


        ar.add("odisha");
        ar.add("bihar");
        ArrayAdapter<String> ad = new ArrayAdapter<>(getApplicationContext(), android.R.layout.simple_spinner_dropdown_item,ar);
        l2.setAdapter(ad);
        // Autocompletetextview

         arr.add("bitch");
         arr.add("bagula");
         arr.add("banko");
         ArrayAdapter<String> lo = new ArrayAdapter<>(getApplicationContext(), android.R.layout.simple_list_item_1,arr);
         L3.setAdapter(lo);
         L3.setThreshold(2);
    }
}