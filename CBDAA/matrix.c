#include <stdio.h>
#include <limits.h>

void print_optimal_parenthesization(int S[][10], int i, int j);

void matrix_chain_multiplication(int dims[], int n) {
    int M[10][10]; // Increase the size if necessary
    int S[10][10]; // Increase the size if necessary

    for (int i = 1; i < n; i++) {
        M[i][i] = 0;
    }

    for (int chain_len = 2; chain_len < n; chain_len++) {
        for (int i = 1; i < n - chain_len + 1; i++) {
            int j = i + chain_len - 1;
            M[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = M[i][k] + M[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < M[i][j]) {
                    M[i][j] = cost;
                    S[i][j] = k;
                }
            }
        }
    }

    printf("M Table:\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    printf("S Table:\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            printf("%d ", S[i][j]);
        }
        printf("\n");
    }

    printf("Optimal parenthesization: ");
    // Function to print the optimal parenthesization
    print_optimal_parenthesization(S, 1, n - 1);
    printf("\n");
    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", M[1][n - 1]);
}

void print_optimal_parenthesization(int S[][10], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_optimal_parenthesization(S, i, S[i][j]);
        print_optimal_parenthesization(S, S[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n; // Number of matrices
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dims[n + 1]; // Increase the size by 1
    printf("Enter the dimensions of matrices:\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &dims[i]);
    }

    matrix_chain_multiplication(dims, n + 1);

    return 0;
}
