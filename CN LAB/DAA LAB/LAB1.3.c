#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time.

    int n, numbers[100], total_duplicates = 0, most_repeating_element, max_count = 0;

    printf("Enter how many numbers you want to generate: ");
    scanf("%d", &n);

    printf("The content of the array: ");
    for (int i = 0; i < n; i++) {
        numbers[i] = rand() % 100; // Generate random numbers between 0 and 99.
        printf("%d ", numbers[i]);
    }

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i + 1; j < n; j++) {
            if (numbers[i] == numbers[j]) {
                count++;
            }
        }
        if (count > 0) {
            total_duplicates++;
            if (count > max_count) {
                max_count = count;
                most_repeating_element = numbers[i];
            }
        }
    }

    printf("\nTotal number of duplicate values = %d\n", total_duplicates);
    printf("The most repeating element in the array = %d\n", most_repeating_element);

    return 0;
}
