#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int arr[], int left, int right);
int partition(int arr[], int left, int right);

int main() {
    int choice, num_elements;
    const char *input_files[] = {"inAsce.dat", "inDesc.dat", "inRand.dat"};
    const char *output_files[] = {"outQuickAsce.dat", "outQuickDesc.dat", "outQuickRand.dat"};
    
    printf("Menu:\n");
    printf("1. Ascending Order\n");
    printf("2. Descending Order\n");
    printf("3. Random Order\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter the number of elements (between 0 and 20000): ");
    scanf("%d", &num_elements);
    
    if (num_elements < 0 || num_elements > 20000) {
        printf("Invalid number of elements.\n");
        return 1;
    }
    
    FILE *input_file = fopen(input_files[choice - 1], "r");
    
    if (input_file == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }
    
    int *arr = (int *)malloc(num_elements * sizeof(int));
    
    for (int i = 0; i < num_elements; i++) {
        fscanf(input_file, "%d", &arr[i]);
    }
    
    fclose(input_file);
    
    printf("Unsorted Array:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    clock_t start_time, end_time;
    start_time = clock();
    
    quick_sort(arr, 0, num_elements - 1);
    
    end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Sorted Array:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int comparisons = 0;
    
    FILE *output_file = fopen(output_files[choice - 1], "w");
    
    if (output_file == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }
    
    fprintf(output_file, "%d\n", num_elements);
    
    for (int i = 0; i < num_elements; i++) {
        fprintf(output_file, "%d ", arr[i]);
    }
    
    fclose(output_file);
    
    
    printf("Execution Time: %.6f seconds\n", execution_time);
    
    
    return 0;
}

void quick_sort(int arr[], int left, int right) {
    if (left < right) {
        int pivot_index = partition(arr, left, right);
        quick_sort(arr, left, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, right);
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    
    return i + 1;
}
