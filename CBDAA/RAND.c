#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_elements = 20000; // Change this to the desired number of random numbers
    const char *file_name = "inRand.dat"; // Change this to your desired file name
    
    srand(time(NULL)); // Seed the random number generator with current time
    
    FILE *file = fopen(file_name, "w");
    
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    
    fprintf(file, "%d\n", num_elements); // Write the number of elements to the file
    
    for (int i = 0; i < num_elements; i++) {
        int random_number = rand() % 20000; // Generate a random number between 0 and 99
        fprintf(file, "%d ", random_number); // Write the random number to the file
    }
    
    fclose(file);
    printf("Random numbers (random order) written to %s\n", file_name);
    
    return 0;
}
