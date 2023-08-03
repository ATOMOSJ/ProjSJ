import java.util.Scanner;
interface PersonalLoan{
    float find_simple_intrest(float principle, int year);
}
class Bank1 implements PersonalLoan{
    static int intrest_rate = 10;

    public float find_simple_intrest(float principle, int year){
        float res = principle*(1+intrest_rate*(float)year/100);
        return res;
    }
}
class Bank2 implements PersonalLoan{
    static int intrest_rate = 15;

    public float find_simple_intrest(float principle,int year){
        float res = principle*(1+intrest_rate*(float)year/100);
        return res;
    }
}
public class q31 {
    public static void main(String[] args) {
        Bank1 b1 = new Bank1();
        float res = b1.find_simple_intrest(10000, 5);
        System.out.println("Simple Intrest from bank1 is "+res);
        PersonalLoan b2 = new Bank2();
        res = b2.find_simple_intrest(5000, 10);

        System.out.println("Simple Intrest from bank2 is "+res);
    }
}