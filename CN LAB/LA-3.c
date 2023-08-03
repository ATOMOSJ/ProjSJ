#include <stdio.h>

void extractBytes( long num) {
    // Extracting each byte from the given number
    unsigned char byte1 = num & 0xFF;          
    unsigned char byte2 = (num >> 8) & 0xFF;   
    unsigned char byte3 = (num >> 16) & 0xFF;  
    unsigned char byte4 = (num >> 24) & 0xFF;  

    // Printing the content of the variables
    printf("Byte1: %d\n", byte1);
    printf("Byte2: %d\n", byte2);
    printf("Byte3: %d\n", byte3);
    printf("Byte4: %d\n", byte4);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Extracting bytes and printing their content
    printf("Extracting bytes from the number %d:\n", num);
    extractBytes(num);

    return 0;
}
