class Saving_account{
    static int annual_intrest_rate = 4;
    private double saving_balance; // current balance
    double monthly_intrest;
    Saving_account(double currbalance){
        saving_balance = currbalance;
    }
    public void calculate_monthly_intrest(){
        monthly_intrest = saving_balance*annual_intrest_rate/100;
        monthly_intrest/=12;
        saving_balance+=monthly_intrest;
    }
    static void modify_intrest_rate(int n){
        annual_intrest_rate = n;
    }
    void display(){
        System.out.println("Monthly intrest is "+monthly_intrest+" and currentbalance is "+saving_balance+"\n\n");
    }
}
public class q3 {
    public static void main(String[] args) {
        Saving_account saver1 = new Saving_account(2000);
        Saving_account saver2 = new Saving_account(3000);

        saver1.calculate_monthly_intrest();
        saver2.calculate_monthly_intrest();

        System.out.println("Monthly intrest and saving balance for saver1 is ");
        saver1.display();

        System.out.println("Monthly intrest and saving balance for saver 2 is ");
        saver2.display();

        Saving_account.modify_intrest_rate(5);
        System.out.println("Monthly intrest and saving balance for saver1 is ");
        saver1.calculate_monthly_intrest();
        saver1.display();

        System.out.println("Monthly intrest and saving balance for saver 2 is ");
        saver2.calculate_monthly_intrest();
        saver2.display();
    }
}