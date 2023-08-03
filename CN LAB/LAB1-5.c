#include <stdio.h>

// Function to check the endianness of the host machine
int is_little_endian() {
    int num = 1;
    char *ptr = (char *)&num;
    return (*ptr);
}

// Function to swap the endianness of a 32-bit integer
unsigned int swap_endianness(unsigned int num) {
    return ((num >> 24) & 0xFF) | ((num >> 8) & 0xFF00) | ((num << 8) & 0xFF0000) | ((num << 24) & 0xFF000000);
}

int main() {
    unsigned int number;
    printf("Enter a 32-bit unsigned integer: ");
    scanf("%u", &number);

    printf("\nByte content in memory:\n");
    char *ptr = (char *)&number;
    for (int i = 0; i < sizeof(unsigned int); i++) {
        printf("Byte %d: %02X\n", i, ptr[i] & 0xFF);
    }

    if (is_little_endian()) {
        printf("\nHost machine is Little Endian.\n");
        number = swap_endianness(number);
        printf("Number converted to Big Endian: %u\n", number);
    } else {
        printf("\nHost machine is Big Endian.\n");
        number = swap_endianness(number);
        printf("Number converted to Little Endian: %u\n", number);
    }

    return 0;
}
