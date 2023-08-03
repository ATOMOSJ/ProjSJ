public class complex {
    public int real,imaginary;

    public complex(int real,int imaginary) {
        this.real = real;
        this.imaginary=imaginary;
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
        complex y=new complex(4,5);
        complex x=new complex(4,5);
        add(y,x);
        sub(x,y);

    }
}
