#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <process.h>

void SenderThread(void* arg) {
    SOCKET senderSocket = *((SOCKET*)arg);

    char message[100];
    int bytesSent;

    while (1) {
        printf("Enter a message to send: ");
        fgets(message, sizeof(message), stdin);
        message[strlen(message) - 1] = '\0';  // Remove the newline character

        // Send message to receiver
        bytesSent = send(senderSocket, message, strlen(message), 0);
        if (bytesSent == SOCKET_ERROR) {
            printf("Message sending failed\n");
            break;
        }
    }
}

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

    // Create socket for receiver
    SOCKET receiverSocket;
    receiverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (receiverSocket == INVALID_SOCKET) {
        printf("Receiver socket creation failed\n");
        WSACleanup();
        return 1;
    }

    // Configure server address for receiver
    struct sockaddr_in receiverAddr;
    receiverAddr.sin_family = AF_INET;
    receiverAddr.sin_port = htons(port);
    receiverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket for receiver
    if (bind(receiverSocket, (struct sockaddr *)&receiverAddr, sizeof(receiverAddr)) == SOCKET_ERROR) {
        printf("Bind failed for receiver\n");
        closesocket(receiverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(receiverSocket, SOMAXCONN) == SOCKET_ERROR) {
        printf("Listen failed for receiver\n");
        closesocket(receiverSocket);
        WSACleanup();
        return 1;
    }

    printf("Waiting for incoming connection...\n");

    // Accept incoming connection for receiver
    SOCKET clientSocket;
    struct sockaddr_in clientAddr;
    int clientAddrLen = sizeof(clientAddr);
    clientSocket = accept(receiverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
    if (clientSocket == INVALID_SOCKET) {
        printf("Accept failed for receiver\n");
        closesocket(receiverSocket);
        WSACleanup();
        return 1;
    }

    // Create sender socket
    SOCKET senderSocket;
    senderSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (senderSocket == INVALID_SOCKET) {
        printf("Sender socket creation failed\n");
        closesocket(receiverSocket);
        WSACleanup();
        return 1;
    }

    // Configure receiver address for sender
    struct sockaddr_in senderAddr;
    senderAddr.sin_family = AF_INET;
    senderAddr.sin_port = htons(port);
    senderAddr.sin_addr.s_addr = inet_addr(ipAddress);

    // Connect to the receiver
    if (connect(senderSocket, (struct sockaddr *)&senderAddr, sizeof(senderAddr)) == SOCKET_ERROR) {
        printf("Connection failed for sender\n");
        closesocket(senderSocket);
        closesocket(receiverSocket);
        WSACleanup();
        return 1;
    }

    // Create sender thread
    HANDLE senderThreadHandle;
    senderThreadHandle = (HANDLE)_beginthread(SenderThread, 0, &senderSocket);

    // Receiving loop for receiver
    char message[100];
    int bytesReceived;

    while (1) {
        bytesReceived = recv(clientSocket, message, sizeof(message) - 1, 0);
        if (bytesReceived == 0 || bytesReceived == SOCKET_ERROR) {
            printf("Connection closed or error for receiver\n");
            break;
        }
        message[bytesReceived] = '\0';

        printf("Received: %s\n", message);

        if (strcmp(message, "exit") == 0) {
            break;
        }
    }

    // Close sender thread
    WaitForSingleObject(senderThreadHandle, INFINITE);
    CloseHandle(senderThreadHandle);

    // Close the sockets and cleanup
    closesocket(clientSocket);
    closesocket(senderSocket);
    closesocket(receiverSocket);
    WSACleanup();

    return 0;
}
