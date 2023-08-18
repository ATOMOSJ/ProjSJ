#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define PORT 12345

int main(int argc, char *argv[]) {
    // Initialize Winsock
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        perror("WSAStartup failed");
        return 1;
    }

    // Create socket
    SOCKET senderSocket;
    senderSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (senderSocket == INVALID_SOCKET) {
        perror("Socket creation failed");
        return 1;
    }

    // Configure server address
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Loopback address
    char message[100];

    while (1) {
        printf("Enter message: ");
        gets(message);

        // Send data to receiver
        sendto(senderSocket, message, strlen(message), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

        if (strcmp(message, "exit") == 0 || strcmp(message, "EXIT") == 0) {
            break;
        }
    }

    // Close the socket and cleanup
    closesocket(senderSocket);
    WSACleanup();

    return 0;
}
