package com.vasu.recycler_view;

public class contactmodel {
    int image;
    String name,number;
    public contactmodel(int image,String name,String number){
        this.image=image;
        this.name=name;
        this.number =number;

    }
    public contactmodel(String name,String number){
        this.name =name;
        this.number =number;
    }
}
