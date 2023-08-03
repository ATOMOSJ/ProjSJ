import java.lang.Object;
import java.io.PrintStream;
class kop {
    int value;
        kop(){
        }
        kop(int value) {
        this.value = value;

    }
    kop(kop ko){
            value=ko.value;
    }
    void display(){
        System.out.println("value="+value);
    }
    protected void finalize()throws Throwable{
    System.out.println("here we go...");
}
//
}
public class top{
    public static void main(String[] args) {
        kop p = new kop(7);

        kop o=new kop();
        o.value=p.value;
        kop op=new kop();
        op=null;
        o.display();
        System.gc();
        int y[]=new int[0];


    }
}

