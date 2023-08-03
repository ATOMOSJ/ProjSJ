import java.util.Scanner;
    public class Distance {
        private int feet;
        private int inches;

        public Distance(int feet, int inches) {
            this.feet = feet;
            this.inches = inches;
        }

        public Distance add(Distance d) {
            int newFeet = this.feet + d.feet;
            int newInches = this.inches + d.inches;
            if (newInches >= 12) {
                newFeet += newInches / 12;
                newInches %= 12;
            }
            return new Distance(newFeet, newInches);
        }

        public Distance subtract(Distance d) {
            int newFeet = this.feet - d.feet;
            int newInches = this.inches - d.inches;
            if (newInches < 0) {
                newFeet -= 1;
                newInches += 12;
            }
            return new Distance(newFeet, newInches);
        }

        public String toString() {
            return feet + " feet " + inches + " inches";
        }

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);

            System.out.print("Enter the first distance in feet and inches: ");
            int feet1 = sc.nextInt();
            int inches1 = sc.nextInt();
            Distance d1 = new Distance(feet1, inches1);

            System.out.print("Enter the second distance in feet and inches: ");
            int feet2 = sc.nextInt();
            int inches2 = sc.nextInt();
            Distance d2 = new Distance(feet2, inches2);

            Distance sum = d1.add(d2);
            System.out.println("Sum of distances: " + sum);

            Distance difference = d1.subtract(d2);
            System.out.println("Difference of distances: " + difference);

            sc.close();
        }
    }


