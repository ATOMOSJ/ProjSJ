#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#define PORT 12345
#define ARRAY_SIZE 10

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket1, clientSocket2;
    struct sockaddr_in serverAddr, clientAddr;
    int clientAddrLen = sizeof(clientAddr);

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("WSAStartup failed");
        exit(EXIT_FAILURE);
    }

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Bind socket
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        perror("Bind failed");
        closesocket(serverSocket);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 2) == SOCKET_ERROR) {
        perror("Listen failed");
        closesocket(serverSocket);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    printf("Server is waiting for connections...\n");

    // Accept first client connection
    clientSocket1 = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
    if (clientSocket1 == INVALID_SOCKET) {
        perror("Accept failed for client 1");
        closesocket(serverSocket);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    printf("Client 1 connected\n");

    // Accept second client connection
    clientSocket2 = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
    if (clientSocket2 == INVALID_SOCKET) {
        perror("Accept failed for client 2");
        closesocket(serverSocket);
        closesocket(clientSocket1);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    printf("Client 2 connected\n");

    int receivedArray[ARRAY_SIZE];
    int frequency[10] = {0};

    // Receive array from client 1
    if (recv(clientSocket1, (char*)receivedArray, sizeof(receivedArray), 0) < 0) {
        perror("Receive failed from client 1");
    } else {
        // Calculate frequency
        for (int i = 0; i < ARRAY_SIZE; i++) {
            frequency[receivedArray[i]]++;
        }

        // Send frequency to client 2
        if (send(clientSocket2, (char*)frequency, sizeof(frequency), 0) < 0) {
            perror("Send failed to client 2");
        }
    }

    // Cleanup
    closesocket(serverSocket);
    closesocket(clientSocket1);
    closesocket(clientSocket2);
    WSACleanup();

    return 0;
}

