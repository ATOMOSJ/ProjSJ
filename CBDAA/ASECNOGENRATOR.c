#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int num_elements = 20000; // Change this to the desired number of random numbers
    const char *file_name = "inAsce.dat"; // Change this to your desired file name
    
    srand(time(NULL)); // Seed the random number generator with current time
    
    FILE *file = fopen(file_name, "w");
    
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    
    fprintf(file, "%d\n", num_elements); // Write the number of elements to the file
    
    int *random_numbers = (int *)malloc(num_elements * sizeof(int));
    
    for (int i = 0; i < num_elements; i++) {
        random_numbers[i] = rand() % 5600; // Generate a random number between 0 and 99
    }
    
    qsort(random_numbers, num_elements, sizeof(int), compare);
    
    for (int i = 0; i < num_elements; i++) {
        fprintf(file, "%d ", random_numbers[i]); // Write the random numbers to the file
    }
    
    free(random_numbers);
    fclose(file);
    printf("Random numbers (ascending) written to %s\n", file_name);
    
    return 0;
}
