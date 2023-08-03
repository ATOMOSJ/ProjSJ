public class q2 {
    public static void main(String[] args) {
        // A. ArrayIndexOutOfBoundsException
        try {
            int[] arr = {1, 2, 3};
            try {
                System.out.println(arr[3]);
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Inner catch: ArrayIndexOutOfBoundsException caught: " + e.getMessage());
            }
        } catch (Exception e) {
            System.out.println("Outer catch: Exception caught: " + e.getMessage());
        }

        // B. NumberFormatException
        try {
            String str = "abc";
            try {
                int num = Integer.parseInt(str);
            } catch (NumberFormatException e) {
                System.out.println("Inner catch: NumberFormatException caught: " + e.getMessage());
            }
        } catch (Exception e) {
            System.out.println("Outer catch: Exception caught: " + e.getMessage());
        }
    }
}
