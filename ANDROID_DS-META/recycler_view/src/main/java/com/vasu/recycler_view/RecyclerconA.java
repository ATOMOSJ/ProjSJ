package com.vasu.recycler_view;

import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class RecyclerconA extends RecyclerView.Adapter<RecyclerconA.ViewHolder> {
    Context context;
    ArrayList<contactmodel> aoc;
    RecyclerconA (Context context, ArrayList<contactmodel> aoc){
        this.context=context;
        this.aoc=aoc;
    }
    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
       View v = LayoutInflater.from(context).inflate(R.layout.contact_row,parent,false);
       ViewHolder viewHolder = new ViewHolder(v);
       return viewHolder ;
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, @SuppressLint("RecyclerView") int position) {
        holder.i1.setImageResource(aoc.get(position).image);
        holder.t1.setText(aoc.get(position).name);
        holder.t2.setText(aoc.get(position).number);
        holder.l1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Dialog d =new Dialog(context);
                d.setContentView(R.layout.add);
                EditText e2=d.findViewById(R.id.e2);
                EditText e3=d.findViewById(R.id.e3);
                Button e4 =d.findViewById(R.id.e4);
                TextView w1 = d.findViewById(R.id.w1);
                w1.setText("update");
                e4.setText("update");
                e2.setText((aoc.get(position).name));
                e3.setText(aoc.get(position).number);
                e4.setOnClickListener(new View.OnClickListener() {
                    String name ="",num="";
                    public void onClick(View v) {
                        if (!e2.getText().toString().equals("")){
                            name = e2.getText().toString();
                            num = e3.getText().toString();}else {
                            Toast.makeText(context, "You missed some details fill properly", Toast.LENGTH_SHORT).show();
                        }
                        aoc.set(position,new contactmodel(aoc.get(position).image,name,num));
                        notifyItemChanged(position);
                        d.dismiss();
                    }
                });
d.show();
            }
        });
        holder.l1.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                AlertDialog.Builder b = new AlertDialog.Builder(context)
                .setTitle("delete contact")
                        .setMessage("are you sure").setIcon(R.drawable.baseline_delete_24).setPositiveButton("yes", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                aoc.remove(position);
                                notifyItemRemoved(position);
                            }
                        })
                        .setNegativeButton("no", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {

                            }
                        });
                b.show();
                return true;
            }
        });
    }

    @Override
    public int getItemCount() {
        return aoc.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder{
      TextView t1,t2;
      ImageView i1;
      LinearLayout l1;


        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            t1 = itemView.findViewById(R.id.tc);
            t2= itemView.findViewById(R.id.tn);
            i1= itemView.findViewById(R.id.img);
            l1=itemView.findViewById(R.id.l1);
        }
    }
}
