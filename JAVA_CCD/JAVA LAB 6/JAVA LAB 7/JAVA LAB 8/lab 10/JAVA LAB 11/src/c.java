public class c {
    public static void main(String[] args) {
        String str1 = "welcome to Java Programming";
        String str2 = "hello world";
        String str3 = "hello";
        String str4 = "good morning";

        // Concatenation of strings
        String str5 = str1.concat(str2);
        System.out.println("Concatenated String: " + str5);

        // Check if a string is empty or not
        boolean isEmpty = str2.isEmpty();
        System.out.println("Is str2 empty? " + isEmpty);

        // Split a string using a delimiter
        String[] strArray = str1.split(" ");
        System.out.println("Words in str1:");
        for (String str : strArray) {
            System.out.println(str);
        }

        // Trim a string by removing leading and trailing whitespaces
        String str6 = "    hello world     ";
        String str7 = str6.trim();
        System.out.println("Original String: " + str6);
        System.out.println("Trimmed String: " + str7);

        // Convert a string to uppercase
        String str8 = str3.toUpperCase();
        System.out.println("Uppercase string: " + str8);

        // Convert a string to lowercase
        String str9 = str4.toLowerCase();
        System.out.println("Lowercase string: " + str9);

        // Replace a substring in a string with another substring
        String str10 = str2.replace("hello", "hi");
        System.out.println("Replaced string: " + str10);

        // Returns a canonical representation for the string object
        String str11 = str1.intern();
        System.out.println("Canonical String: " + str11);
    }
}

