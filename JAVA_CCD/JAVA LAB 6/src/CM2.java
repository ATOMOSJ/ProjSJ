public class CM2 {
    public class LargestNumber {
        public static void main(String[] args) {
            int[] numbers = new int[5];
            for (int i = 0; i < args.length; i++) {
                numbers[i] = Integer.parseInt(args[i]);
            }
            int largest = numbers[0];
            for (int i = 1; i < numbers.length; i++) {
                if (numbers[i] > largest) {
                    largest = numbers[i];
                }
            }
            System.out.println("The largest number is: " + largest);
        }
    }

}
