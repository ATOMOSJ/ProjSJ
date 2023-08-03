import java.util.Scanner;

interface currency{
    float moneyConversion(double curr, char type);
    void countrycurrency(char type);
}

class currencyconversion implements currency{
    static double rupeedollar = 0.012;
    static double dollarrupee = 81.94;

    public float moneyConversion(double curr, char type){
        countrycurrency(type);
        if(type == '$'){
            return (float)curr*(float)dollarrupee;
        }
        return (float)curr*(float)rupeedollar;
    }
    public void countrycurrency(char type){
        if(type == '$'){
            System.out.println("This currency is US Dollar");
        }
        else{
            System.out.println("This currency is Indian Rupees");
        }
    }
}
public class q2 {
    public static void main(String[] args) {
        currency c1 = new currencyconversion();
        //c1.moneyConversion(200, '$');
        float res = c1.moneyConversion(2, '$');
        System.out.println(res);
    }
}