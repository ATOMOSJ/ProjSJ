import java.util.Scanner;

public class q1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter temperature value: ");
        String input = scanner.nextLine();
        double value = 0.0;
        try {
            value = Double.parseDouble(input.substring(0, input.length() - 1));
        } catch (NumberFormatException e) {
            System.out.println("Invalid input, please enter a valid number");
            System.exit(0);
        }

        char scale = input.charAt(input.length() - 1);
        double result = 0.0;
        if (scale == 'F' || scale == 'f') {
            result = (value - 32) * 5 / 9;
            System.out.println(value + "°F is equal to " + result + "°C");
        } else if (scale == 'C' || scale == 'c') {
            result = (value * 9 / 5) + 32;
            System.out.println(value + "°C is equal to " + result + "°F");
        } else {
            System.out.println("Invalid input, please enter a valid temperature scale (F/f or C/c)");
            System.exit(0);
        }
    }
}
