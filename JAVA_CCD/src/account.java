import java.util.Scanner;

public class account {
    int cust_id,balance;
    String name, branch;
    public void get(){
        System.out.println("enter the customer id: ");
        Scanner jol =new Scanner(System.in);
        cust_id=jol.nextInt();
        System.out.println("enter the balance of the account ");
        balance=jol.nextInt();
        System.out.println("enter the branch: ");
        branch=jol.next();

    }
    public void display(){
        System.out.printf("name : %s \n balance : %d \n branch : %s ",cust_id,balance,branch);
    }
    public static int withdraw(account c,int amt){

        return c.balance-amt;
    }
    public static int diposite( account v,int amt){
        return  v.balance+amt;
    }

    public static void main(String[] args) {
        System.out.println("Account details: ");
        account moron = new account();
        moron.get();
        moron.display();
        System.out.println();
        System.out.println(" AFTER WITHDRAW AMOUNT "+ withdraw(moron,500));
        System.out.println("AFTER THE DEPOSITE "+diposite(moron,500));
    }
}
