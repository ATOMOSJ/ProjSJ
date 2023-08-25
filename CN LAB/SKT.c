#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return 1;
    }

    const char *ipAddress = argv[1];
    int port = atoi(argv[2]);

    // Initialize Winsock
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Winsock initialization failed\n");
        return 1;
    }

    // Create socket
    SOCKET senderSocket;
    senderSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (senderSocket == INVALID_SOCKET) {
        printf("Socket creation failed\n");
        WSACleanup();
        return 1;
    }

    // Configure receiver address
    struct sockaddr_in receiverAddr;
    receiverAddr.sin_family = AF_INET;
    receiverAddr.sin_port = htons(port);
    receiverAddr.sin_addr.s_addr = inet_addr(ipAddress);

    char message[100];
    int bytesSent;

    while (1) {
        printf("Enter a message: ");
        fgets(message, sizeof(message), stdin);
        message[strlen(message) - 1] = '\0';  // Remove the newline character

        if (strcmp(message, "exit") == 0) {
            break;
        }

        // Send message to receiver
        bytesSent = sendto(senderSocket, message, strlen(message), 0, (struct sockaddr *)&receiverAddr, sizeof(receiverAddr));
        if (bytesSent == SOCKET_ERROR) {
            printf("Message sending failed\n");
            closesocket(senderSocket);
            WSACleanup();
            return 1;
        }
    }

    // Close the socket and cleanup
    closesocket(senderSocket);
    WSACleanup();

    return 0;
}
