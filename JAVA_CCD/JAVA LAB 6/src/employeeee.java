import java.util.Scanner;
//import java.io.BufferedReader;
//import java.io.InputStreamReader;
import java.io.*;
import java.io.IOException;

public class employeeee {
    String name;
    int empid,salary;

    public employeeee(int empid,String name,int salary) {
        this.empid = empid;
        this.name=name;
        this.salary=salary;
    }
    employeeee(employeeee o){
        this.empid = o.empid;
        this.name=o.name;
        this.salary=o.salary;
    }

    public void show(){
        System.out.format("name: %s \n empid: %d \n salary: %d \n",name,empid,salary);
    }

    public static void main(String[] args)throws IOException {
        InputStreamReader ISR = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(ISR);
        System.out.println("enter empid,name,salary");
        int em=Integer.parseInt(br.readLine());
        String name=br.readLine();
        int sal=Integer.parseInt(br.readLine());

        employeeee y = new employeeee(em,name,sal);
         employeeee i=new employeeee(y);
         i.show();
    }
}
