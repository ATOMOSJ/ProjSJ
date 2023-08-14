#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (!outputFile) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    int num1, num2;
    while (fscanf(inputFile, "%d %d", &num1, &num2) == 2) {
        int result = gcd(num1, num2);
        fprintf(outputFile, "The GCD of %d and %d is %d\n", num1, num2, result);
    }

    printf("GCD calculations completed and written to %s.\n", argv[2]);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
