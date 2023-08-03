import java.util.Scanner;

public class ArrayOperations {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Initialize the array
        int[] arr = {3, 5, 8, 9, 6, 3, 4, 4, 7, 1, 2, 4, 6, 9, 9};

        // Find pairs of numbers whose consecutive numbers subtraction is equal to zero
        System.out.println("Pairs of numbers whose consecutive numbers subtraction is equal to zero:");
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] - arr[i + 1] == 0) {
                System.out.println("(" + arr[i] + ", " + arr[i + 1] + ")");
            }
        }

        // Find transpose of a 3x3 matrix
        int[][] matrix = new int[3][3];
        System.out.println("Enter 3x3 matrix elements:");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        System.out.println("Original Matrix:");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(matrix[i][j] + "\t");
            }
            System.out.println();
        }

        System.out.println("Transpose of Matrix:");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(matrix[j][i] + "\t");
            }
            System.out.println();
        }

        sc.close();
    }
}
