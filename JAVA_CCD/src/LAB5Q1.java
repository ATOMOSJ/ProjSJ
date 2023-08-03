import java.util.Scanner;
class student2 {
    int roll, fee;
    String name, sec, university;

    void getstudentinfo() {
        System.out.println("enter the name and roll no.");
        Scanner n = new Scanner(System.in);
        name = n.nextLine();
        roll = n.nextInt();
        System.out.println("enter the  sec name, university name and fee details");
        sec = n.next();
        university = n.next();
        fee = n.nextInt();
    }

    void displaystudentinfo() {
        System.out.println("here are the info:");
        System.out.println("NAME: " + name);
        System.out.println("your Roll no.: " + roll + "your section: " + sec);
        System.out.println("university: " + university + "fee amount " + fee);
    }
}
public class LAB5Q1 {
        public static void main(String[] args) {
            student2 s = new student2();
            s.getstudentinfo();
            s.displaystudentinfo();


        }
    }

