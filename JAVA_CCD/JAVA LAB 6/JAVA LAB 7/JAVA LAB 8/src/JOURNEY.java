class detailso {
    String name,address,serviceno;
    detailso(){}
    detailso(String name, String address,String serviceno){
        this.name=name;
        this.address=address;
        this.serviceno=serviceno;
    }
    void show(){
        System.out.format("name: %s \n address: %s \n service no>: %s \n",name,address,serviceno);
    }

}
class powerbill extends detailso{
    int n;   //to store units
    double total_bill; // the total amount to be paid
    powerbill(int n,String name , String address , String serviceno){
        super(name,address,serviceno);
        this.n=n;
    }
    void show(){
        System.out.format("name: %s\naddress: %s\n service no>: %s\ntotal bill:%.2f",name,address,serviceno,total_bill);
    }
    double cal(){
       if(n>1 && n<= 50){
        return total_bill=(n*2.5);
       } else if (n>51 && n<100) {
           return total_bill=(n*5);
       }else if (n>101 && n<200) {
         return  total_bill=(n * 6);
       }else if (n>200) {
          return total_bill=(n*7.5);
       }else {
           return 0;
       }

    }
}
public class JOURNEY{
    public static void main(String[] args) {
        powerbill p1 =new powerbill(4,"JPS","BBSR","AR456");
        p1.cal();
        p1.show();
    }
}
