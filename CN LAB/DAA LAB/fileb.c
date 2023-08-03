#include <stdio.h>
#include <stdlib.h>
void decToBinary(int num, FILE *destFile) {
    if (num > 1) {
        decToBinary(num / 2, destFile);
    }
    fprintf(destFile, "%d", num % 2);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {

        return 1;
    }
    int n = atoi(argv[1]);
    char *sourceFileName = argv[2];
    char *destinationFileName = argv[3];
    FILE *sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error opening the source file.\n");
        return 1;
    }
    FILE *destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Error opening the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    printf("Content of the first %d decimal numbers and their equivalent binary numbers:\n", n);
    for (int i = 0; i < n; i++) {
        int decimalNumber;
        if (fscanf(sourceFile, "%d", &decimalNumber) != 1) {
            printf("Error reading decimal number from the source file.\n");
            break;
        }


        decToBinary(decimalNumber, destinationFile);
        fprintf(destinationFile, "\n");
        printf("The binary equivalent of %d is ", decimalNumber);
        decToBinary(decimalNumber, stdout);
        printf("\n");
    }

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
