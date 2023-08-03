public class q5 {
    public static void main(String[] args) {
        try {
            throw new NullPointerException("null pointer exception");
        } catch (NullPointerException e) {
            System.out.println("Caught null pointer exception: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Caught exception: " + e.getMessage());
        }
    }
}
