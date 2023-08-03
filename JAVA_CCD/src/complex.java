import java.util.Scanner;

public class complex {
    int real,imaginary;
    public void get(){
        System.out.println("enter the real and the imaginary part of the complex number");
        Scanner j = new Scanner(System.in);
        real= j.nextInt();
        imaginary=j.nextInt();
    }
    public void disp(){
        System.out.println("your complex no. is: "+ real + " + "+ imaginary+" i ");
    }
    public static void add(complex a,complex b){
        int x, y;
        x = a.real + b.real;
        y=a.imaginary+b.imaginary;
        System.out.println("your complex no. after addition is: "+ x + " + "+ y +" i ");
    }
    public static void sub(complex v,complex l){
        int x, y;
        x = v.real - l.real;
        y=v.imaginary-l.imaginary;
        System.out.println("your complex no. after subtraction is: "+ x + " + "+ y +" i ");

    }

    public static void main(String[] args) {
        complex lol =new complex(),lol1=new complex();
        lol.get();
        lol1.get();
        lol.disp();
        lol1.disp();
        add(lol,lol1);
        sub(lol,lol1);

    }

}
