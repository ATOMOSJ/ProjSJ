#include <stdio.h>
#include<stdlib.h>
int main() {
    int N=5;
    int arr[N], prefixSum[N];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        arr[i]=rand()%20;
    }

    prefixSum[0] = arr[0];
    for (int i = 1; i < N; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    printf("The prefix sum array is:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");

    return 0;
}

