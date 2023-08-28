#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;

void merge(int arr[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;
    
    while (i < left_size && j < right_size) {
        comparisons++;
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    
    while (i < left_size) {
        arr[k++] = left[i++];
    }
    
    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

void merge_sort(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    int mid = size / 2;
    int *left = (int *)malloc(mid * sizeof(int));
    int *right = (int *)malloc((size - mid) * sizeof(int));
    
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
    
    merge_sort(left, mid);
    merge_sort(right, size - mid);
    
    merge(arr, left, mid, right, size - mid);
    
    free(left);
    free(right);
}

int main() {
    int choice;
    printf("Select sorting type:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("3. Random\n");
    scanf("%d", &choice);
    
    const char *input_files[] = {"inAsce.dat", "inDesc.dat", "inRand.dat"};
    const char *output_files[] = {"outMergeAsce.dat", "outMergeDesc.dat", "outMergeRand.dat"};
    
    FILE *input_file = fopen(input_files[choice - 1], "r");
    
    if (input_file == NULL) {
        printf("File not found.\n");
        return 1;
    }
    
    int size;
    fscanf(input_file, "%d", &size);
    
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        fscanf(input_file, "%d", &arr[i]);
    }
    fclose(input_file);
    
    clock_t start_time = clock();
    merge_sort(arr, size);
    clock_t end_time = clock();
    
    FILE *output_file = fopen(output_files[choice - 1], "w");
    for (int i = 0; i < size; i++) {
        fprintf(output_file, "%d ", arr[i]);
    }
    fclose(output_file);
    
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nComparisons: %d\n", comparisons);
    printf("Execution time: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    
    free(arr);
    
    return 0;
}
