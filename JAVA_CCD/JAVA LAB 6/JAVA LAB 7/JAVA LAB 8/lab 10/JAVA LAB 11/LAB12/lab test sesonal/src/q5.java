import java.util.Scanner;

class volume{
    volume(double radius){
        // calculates volume of sphere
        double res = (4.0/3.0)*Math.PI*radius*radius*radius;
        System.out.println("Volume of sphere is "+res+"\n\n");
    }
    volume(double radius,double height){
        //calculates volume of cylinder
        double res = Math.PI*radius*radius*height;
        System.out.println("Volume of cylinder is "+res+"\n\n");
    }
    volume(double len,double breadth,double height){
        // calculates volume of the cuboid
        double res = len*breadth*height;
        System.out.println("Volume of cuboid is "+res+"\n\n");
    }
}
public class q5 {
    public static void main(String[] args) {
        volume v1 = new volume(5);
        volume v2 = new volume(5.5, 10.3);
        volume v3 = new volume(12, 0.55, 20.3);
    }
}