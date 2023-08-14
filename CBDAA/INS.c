#include <stdio.h>
#include<stdlib.h>
#include <time.h>
// Function to perform Insertion Sort
int insertionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

// Function to print array content
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int option;
    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR\n");
    scanf("%d", &option);

    FILE *inputFile;
    FILE *outputFile;

    switch (option) {
        case 1:
            inputFile = fopen("inAsce.dat", "r");
            outputFile = fopen("outInsAsce.dat", "w");
            break;
        case 2:
            inputFile = fopen("inDesc.dat", "r");
            outputFile = fopen("outInsDesc.dat", "w");
            break;
        case 3:
            inputFile = fopen("inRand.dat", "r");
            outputFile = fopen("outInsRand.dat", "w");
            break;
        default:
            printf("Invalid option. Exiting.\n");
            return 1;
    }

    if (!inputFile || !outputFile) {
        printf("Error opening files.\n");
        return 1;
    }

    int n;
    fscanf(inputFile, "%d", &n);
   int *arr = (int *)malloc(n * sizeof(int)); 

    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }

    fclose(inputFile);

    printf("Before Sorting: Content of the input file\n");
    printArray(arr, n);
     clock_t startTime = clock();
    int comparisons = insertionSort(arr, n);
      clock_t endTime = clock();
    double runtime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("After Sorting: Content of the output file\n");
    printArray(arr, n);
      printf("Runtime: %.19f seconds\n", runtime);
    printf("Number of comparisons: %d\n", comparisons);

    fclose(outputFile);

    return 0;
}
