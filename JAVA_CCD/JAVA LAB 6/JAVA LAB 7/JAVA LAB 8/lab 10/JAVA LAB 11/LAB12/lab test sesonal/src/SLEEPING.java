import java.util.Scanner;

class sleepingadi extends Exception{
    sleepingadi(String s){
        super(s);
    }
}
public class SLEEPING {
    static void sleepchecker(String s)throws sleepingadi{
        if(s.equalsIgnoreCase("sleeping")){
            throw new sleepingadi("adi has been thrown");
        }else{
            System.out.println("adi nintendo mai porn dekh raha hai");
        }
    }

    public static void main(String[] args) {
        System.out.println("adi ka status dal");
        Scanner n=new Scanner(System.in);
        String u = n.nextLine();
        try{
            sleepchecker(u);

        }catch(Exception madhar){
            System.out.println("sleeping adi exception has been handled");
            System.out.println(madhar);
            madhar.getStackTrace();

        }
    }
}
