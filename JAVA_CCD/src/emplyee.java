import java.util.Scanner;

public class emplyee {
    int empid,salary;
    String name;
    static String c_name = "VOLVO";
    public void getdata(){
        Scanner m =new Scanner(System.in);
        System.out.println("enter the name: ");
        name=m.nextLine();
        System.out.println("enter the employee id: ");
        empid=m.nextInt();
        System.out.println("enter the salary");
        salary=m.nextInt();

    }
    public void display(){
        System.out.format("name: %s \n empid: %d \n salary: %d \n comapny name: %s",name,empid,salary,c_name);
    }

    public static void main(String[] args) {
        emplyee y = new emplyee();
        y.getdata();
        y.display();
    }

}
