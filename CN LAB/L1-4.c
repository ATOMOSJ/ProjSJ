#include <stdio.h>

// Define the structure
struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    int num;

    // Input the number from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Store the number across the structure
    struct pkt packet;
    packet.ch1 = (char)(num & 0xFF);             // Store the least significant byte
    packet.ch2[0] = (char)((num >> 8) & 0xFF);   // Store the second byte
    packet.ch2[1] = (char)((num >> 16) & 0xFF);  // Store the third byte
    packet.ch3 = (char)((num >> 24) & 0xFF);     // Store the most significant byte

    // Print the content of each member of the structure
    printf("Content of each member of the structure:\n");
    printf("ch1: %d\n", packet.ch1);
    printf("ch2[0]: %d\n", packet.ch2[0]);
    printf("ch2[1]: %d\n", packet.ch2[1]);
    printf("ch3: %d\n", packet.ch3);

    // Aggregate the members to form the original number
    int originalNumber = packet.ch1 |
                        ((int)(packet.ch2[0]) << 8) |
                        ((int)(packet.ch2[1]) << 16) |
                        ((int)(packet.ch3) << 24);

    // Print the original number
    printf("\nOriginal number formed from the structure: %d\n", originalNumber);

    return 0;
}
