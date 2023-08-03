#include <stdio.h>

// Function to swap two elements
void EXCHANGE(int* p, int* q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

// Function to rotate the first p2 elements of the array to the right by one position
void ROTATE_RIGHT(int* arr, int p2) {
    for (int i = 0; i < p2; i++) {
        EXCHANGE(&arr[i], &arr[p2 - 1]);
    }
}

int main() {
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int A[100];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int p2;
    printf("Enter the number of elements to be rotated: ");
    scanf("%d", &p2);

    printf("Before ROTATE:");
    for (int i = 0; i < N; i++) {
        printf(" %d", A[i]);
    }

    ROTATE_RIGHT(A, p2);

    printf("\nAfter ROTATE:");
    for (int i = 0; i < N; i++) {
        printf(" %d", A[i]);
    }
    printf("\n");

    return 0;
}
