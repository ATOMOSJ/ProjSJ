#include <stdio.h>
#include <math.h>
void roundMatrix(int n, double matrix[n][n], int rounded[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rounded[i][j] = (int)round(matrix[i][j]);
        }
    }
}
void printMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);
    
    double matrix[n][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    
    int rounded[n][n];
    roundMatrix(n, matrix, rounded);
    
    printf("\nRounded matrix:\n");
    printMatrix(n, rounded);
    
    return 0;
}
