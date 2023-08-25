#include <stdio.h>

// Function to round the elements of a matrix to the nearest integer
void round_matrix(int n, int A[][n]) {
  // Declare variables
  int row_sums[n];
  int col_sums[n];

  // Initialize the row and column sums
  for (int i = 0; i < n; i++) {
    row_sums[i] = 0;
  }
  for (int j = 0; j < n; j++) {
    col_sums[j] = 0;
  }

  // Iterate over all elements of the matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // Update the row and column sums
      row_sums[i] += A[i][j];
      col_sums[j] += A[i][j];
    }
  }

  // Iterate over all elements of the matrix again
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // Round the element to the nearest integer
      if (A[i][j] + 0.5 > row_sums[i] - col_sums[j]) {
        A[i][j] = (int)(A[i][j]);
      } else {
        A[i][j] = (int)(A[i][j]) + 1;
      }
    }
  }
}

// Time complexity analysis
// The time complexity of this algorithm is O(n^2), where n is the size of the matrix.
// This is because we need to iterate over all rows and columns of the matrix twice.
// The first iteration is to calculate the row and column sums, and the second iteration is to round the elements of the matrix.

int main() {
  // Create a 3x3 matrix
  int n = 3;
  int A[3][3] = { {1.5, 2.5, 3.5}, {4.5, 5.5, 6.5}, {7.5, 8.5, 9.5} };

  // Round the elements of the matrix
  round_matrix(n, A);

  // Print the rounded matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }

  return 0;
}
