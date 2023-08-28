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
    SOCKET receiverSocket;
    receiverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (receiverSocket == INVALID_SOCKET) {
        printf("Socket creation failed\n");
        WSACleanup();
        return 1;
    }

    // Configure server address
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ipAddress);

    // Bind socket
    if (bind(receiverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        printf("Bind failed\n");
        closesocket(receiverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(receiverSocket, SOMAXCONN) == SOCKET_ERROR) {
        printf("Listen failed\n");
        closesocket(receiverSocket);
        WSACleanup();
        return 1;
    }

    printf("Waiting for incoming connection...\n");

    // Accept incoming connection
    SOCKET clientSocket;
    int clientAddrLen = sizeof(serverAddr);
    clientSocket = accept(receiverSocket, (struct sockaddr *)&serverAddr, &clientAddrLen);
    if (clientSocket == INVALID_SOCKET) {
        printf("Accept failed\n");
        closesocket(receiverSocket);
        WSACleanup();
        return 1;
    }

    char message[100];
    int bytesReceived;

    while (1) {
        bytesReceived = recv(clientSocket, message, sizeof(message) - 1, 0);
        if (bytesReceived == 0 || bytesReceived == SOCKET_ERROR) {
            break;  // Connection closed or error
        }
        message[bytesReceived] = '\0';

        printf("Received: %s\n", message);

        if (strcmp(message, "exit") == 0) {
            break;
        }
    }

    // Close the sockets and cleanup
    closesocket(clientSocket);
    closesocket(receiverSocket);
    WSACleanup();

    return 0;
}
