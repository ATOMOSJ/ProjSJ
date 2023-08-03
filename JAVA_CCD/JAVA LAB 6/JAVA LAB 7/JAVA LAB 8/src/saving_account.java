import java.util.Scanner;
public class saving_account {
    static int sa=0;
    static float annual_interest_rate=5;
    private float saving_balance;
    void getvalue(){
        sa++;
        System.out.printf("enter balance %d ",sa);
        Scanner p1 =new Scanner(System.in);
        saving_balance= p1.nextFloat();
    }
    double calculate_monthly_interest(){
        return (annual_interest_rate*saving_balance)/12;
    }
    static void modify_interest_rate(int annual_interest_rate1){
         annual_interest_rate=annual_interest_rate1;

    }
    void pr(){
        System.out.format("\n annual Interest: "+annual_interest_rate+"\n saving balance: "+saving_balance+"\n interest rate is: $ %.4f",calculate_monthly_interest());
    } //NEW DISCOVERY

    public static void main(String[]t) {
        saving_account s1=new saving_account(),s2=new saving_account();
        s1.getvalue();
        s2.getvalue();
        modify_interest_rate(4);
        s1.pr();
        modify_interest_rate(5);
        s2.pr();
    }
}

