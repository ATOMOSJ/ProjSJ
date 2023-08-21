#include <stdio.h>

int findLargestDifference(int arr[], int n) {
    int maxDiff = arr[1] - arr[0];
    int minElement = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - minElement > maxDiff) {
            maxDiff = arr[i] - minElement;
        }
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    return maxDiff;
}

int main() {
    int a[] = {2,-3,4,6,7};
    int n = sizeof(a) / sizeof(a[0]);

    int largestDiff = findLargestDifference(a, n);
    printf("Largest difference between A[j] and A[i] is: %d\n", largestDiff);

    return 0;
}
