public class java6q4 {
    public static float vol(int r){
        float x = ((4/3) * (22/7) * r * r * r);
        return x;
    }
    public static double vol(int b, int h){
        return b*h;
    }
    public static double vol(double r , int h){
        return 3.14*r*r*h;
    }
    public static double vol(double r , double h){
        return (3.14*r*r*(.3*h));
    }
    public static int vol(int l,int b, int h){
        return l*b*h;
    }

    public static void main(String[] args) {
        System.out.println("answers are "+vol(8)+" "+vol(6,9)+" "+vol(4.67,7)+ " "+  vol(45.56,78.55)+" "+ vol(8,9,0));

    }

}
