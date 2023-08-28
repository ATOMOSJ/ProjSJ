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
int main() {
  
  int A[3][3] = { {1.5, 2.5, 3.5}, {4.5, 5.5, 6.5}, {7.5, 8.5, 9.5} };
  round_matrix(n, A);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }

  return 0;
}
