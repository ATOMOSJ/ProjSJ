import java.util.Scanner;

class Two_D {
    protected double length;
    protected double breadth;

    public Two_D(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    public double area() {
        return length * breadth;
    }
}

class Three_D extends Two_D {
    protected double height;

    public Three_D(double length, double breadth, double height) {
        super(length, breadth);
        this.height = height;
    }

    public double volume() {
        return length * breadth * height;
    }
}

public class PlasticCostCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter length, breadth and height (in feet) of the plastic: ");
        double length = scanner.nextDouble();
        double breadth = scanner.nextDouble();
        double height = scanner.nextDouble();

        Two_D sheet = new Two_D(length, breadth);
        Three_D box = new Three_D(length, breadth, height);

        double sheetCost = sheet.area() * 40.0;
        double boxCost = box.volume() * 60.0;

        System.out.println("Cost of plastic sheet: Rs " + sheetCost);
        System.out.println("Cost of plastic box: Rs " + boxCost);
    }
}

