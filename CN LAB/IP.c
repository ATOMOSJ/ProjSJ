#include <stdio.h>
#include <string.h>

// Structure to store incoming data
struct Packet {
    char sourceCode[1000];
    char ipAddress[20];
    char protocolName[50];
};

int main() {
    // Create a packet structure
    struct Packet packet;

    // Receive input from the source machine
    printf("Enter source code: ");
    fgets(packet.sourceCode, sizeof(packet.sourceCode), stdin);
    packet.sourceCode[strcspn(packet.sourceCode, "\n")] = '\0'; // Remove newline from input

    printf("Enter IP address: ");
    fgets(packet.ipAddress, sizeof(packet.ipAddress), stdin);
    packet.ipAddress[strcspn(packet.ipAddress, "\n")] = '\0'; // Remove newline from input

    printf("Enter protocol name: ");
    fgets(packet.protocolName, sizeof(packet.protocolName), stdin);
    packet.protocolName[strcspn(packet.protocolName, "\n")] = '\0'; // Remove newline from input

    // Display the received packet
    printf("\nPacket:\n");
    printf("Source Code: %s\n", packet.sourceCode);
    printf("IP Address: %s\n", packet.ipAddress);
    printf("Protocol Name: %s\n", packet.protocolName);

    return 0;
}
