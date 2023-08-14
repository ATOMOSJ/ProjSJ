#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int binarySearchLeftmostRecursive(int arr[], int low, int high, int key, int *numComparisons) {
    if (low > high) {
        return -1; // Element not found
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == key) {
        *numComparisons += 1;
        int leftmostInLeftHalf = binarySearchLeftmostRecursive(arr, low, mid - 1, key, numComparisons);
        return (leftmostInLeftHalf == -1) ? mid : leftmostInLeftHalf;
    } else if (arr[mid] < key) {
        *numComparisons += 1;
        return binarySearchLeftmostRecursive(arr, mid + 1, high, key, numComparisons);
    } else {
        *numComparisons += 1;
        return binarySearchLeftmostRecursive(arr, low, mid - 1, key, numComparisons);
    }
}

int binarySearchLeftmost(int arr[], int size, int key, int *numComparisons) {
    int low = 0;
    int high = size - 1;
    int leftmost = -1; // Initialize leftmost position to -1 (not found)

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            leftmost = mid; // Update leftmost position
            high = mid - 1; // Narrow the search to the left half
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }

        (*numComparisons)++;
    }

    return leftmost;
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int)); 
    printf("Generated array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d",&arr[i]);
    }
    printf("\n");
 for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int key;
    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    int numComparisons = 0;

    // Record the start time
    clock_t startTime = clock();

    int leftmostPosition = binarySearchLeftmost(arr, size, key, &numComparisons);
      int leftmostPosition1 = binarySearchLeftmostRecursive(arr, 0, size - 1, key, &numComparisons);
    // Calculate runtime
    clock_t endTime = clock();
    double runtime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    

    if (leftmostPosition != -1) {
        printf("%d found at index position %d\n", key, leftmostPosition1);
        printf("Number of comparisons: %d\n", numComparisons);
    } else {
        printf("%d not found in the array.\n", key);
    }
    if (leftmostPosition != -1) {
        printf("%d found at index position %d\n", key, leftmostPosition);
        printf("Number of comparisons: %d\n", numComparisons);
        printf("Runtime: %.19f seconds\n", runtime);
    } else {
        printf("%d not found in the array.\n", key);
    }

    return 0;
}
