#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define PORT 12345

int main() {
    // Initialize Winsock
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        perror("WSAStartup failed");
        return 1;
    }

    // Create socket
    SOCKET receiverSocket;
    receiverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (receiverSocket == INVALID_SOCKET) {
        perror("Socket creation failed");
        return 1;
    }

    // Configure server address
    struct sockaddr_in serverAddr, clientAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(receiverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        perror("Bind failed");
        return 1;
    }

    char message[100];

    while (1) {
        int len = sizeof(clientAddr);

        // Receive data from sender
        int bytesReceived = recvfrom(receiverSocket, message, sizeof(message) - 1, 0, (struct sockaddr *)&clientAddr, &len);
        if (bytesReceived == SOCKET_ERROR) {
            perror("Receive failed");
            return 1;
        }
        message[bytesReceived] = '\0'; // Null-terminate the received data

        printf("Received: %s\n", message);

        if (strcmp(message, "exit") == 0) {
            break;
        }
    }

    // Close the socket and cleanup
    closesocket(receiverSocket);
    WSACleanup();

    return 0;
}
