public    class q4 {
    public static void main(String[] args) {
        try {
            // some code that may throw exceptions
            int a = 10;
            int b = 0;
            int result = a / b;
            String str = null;
            System.out.println(str.length());
            int[] arr = {1, 2, 3};
            System.out.println(arr[3]);
            String str2 = "abc";
            int num = Integer.parseInt(str2);
        } catch (ArithmeticException e) {
            System.out.println("ArithmeticException caught: " + e.getMessage());
        } catch (NullPointerException e) {
            System.out.println("NullPointerException caught: " + e.getMessage());
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ArrayIndexOutOfBoundsException caught: " + e.getMessage());
        } catch (NumberFormatException e) {
            System.out.println("NumberFormatException caught: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Exception caught: " + e.getMessage());
        }
    }
}
