#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Packet {
    int codeNumber;
    char ipAddress[20];
    char protocolName[50];
};

// Function to display the packet data
void destination(const struct Packet *packet) {
    printf("\nPacket:\n");
    printf("Code Number: %d\n", packet->codeNumber);
    printf("IP Address: %s\n", packet->ipAddress);
    printf("Protocol Name: %s\n", packet->protocolName);
}

int main() {
    struct Packet packet;

    // Use pointers to scan data
    int *codeNumberPtr = &packet.codeNumber;

    printf("Enter code number: ");
    scanf("%d", codeNumberPtr);
    getchar(); // Clear the input buffer

    printf("Enter IP address: ");
    fgets(packet.ipAddress, sizeof(packet.ipAddress), stdin);
    packet.ipAddress[strcspn(packet.ipAddress, "\n")] = '\0'; // Remove newline from input

    printf("Enter protocol name: ");
    fgets(packet.protocolName, sizeof(packet.protocolName), stdin);
    packet.protocolName[strcspn(packet.protocolName, "\n")] = '\0'; // Remove newline from input

    // Display the packet data using the destination function
    destination(&packet);

    return 0;
}
