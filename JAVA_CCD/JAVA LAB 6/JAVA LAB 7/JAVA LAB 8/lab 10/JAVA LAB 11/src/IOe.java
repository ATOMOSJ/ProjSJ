import java.io.IOException;

class IO {
    void method () throws IOException{
        throw new IOException("error occured in input and output");
    }
}
public class IOe{
    public static void main(String[] args) {
        try {
            IO e =new IO();
            e.method();
        }catch(Exception e){
            System.out.println(" the error is handled ");
        }
        System.out.println("running the remaining code");
    }
}
