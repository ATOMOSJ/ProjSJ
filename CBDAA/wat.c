#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal number to binary using recursion
void decToBinary(int num, FILE *destFile) {
    if (num > 1) {
        decToBinary(num / 2, destFile);
    }
    fprintf(destFile, "%d", num % 2);
}

int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments are provided
    if (argc != 4) {
        printf("Usage: %s <n> <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    // Extract 'n', source file name, and destination file name from command-line arguments
    int n = atoi(argv[1]);
    char *sourceFileName = argv[2];
    char *destinationFileName = argv[3];

    // Open the source file in read mode
    FILE *sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error opening the source file.\n");
        return 1;
    }

    // Open the destination file in write mode
    FILE *destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Error opening the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    printf("Content of the first %d decimal numbers and their equivalent binary numbers:\n", n);

    // Process the decimal numbers, convert to binary, and store in the destination file
    for (int i = 0; i < n; i++) {
        int decimalNumber;
        if (fscanf(sourceFile, "%d", &decimalNumber) != 1) {
            printf("Error reading decimal number from the source file.\n");
            break;
        }

        // Convert the decimal number to binary and store it in the destination file
        decToBinary(decimalNumber, destinationFile);
        fprintf(destinationFile, "\n");

        // Display the decimal number and its equivalent binary number
        printf("The binary equivalent of %d is ", decimalNumber);
        decToBinary(decimalNumber, stdout);
        printf("\n");
    }

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
