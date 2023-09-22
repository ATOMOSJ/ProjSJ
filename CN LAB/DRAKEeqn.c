#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#define PORT 12345
#define ARRAY_SIZE 10

int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    struct sockaddr_in serverAddr;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("WSAStartup failed");
        exit(EXIT_FAILURE);
    }

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        perror("Socket creation failed");
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to the server's IP address
    serverAddr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        closesocket(clientSocket);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    int inputArray[ARRAY_SIZE];

    // Input array from user
    printf("Enter %d numbers separated by spaces: ", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &inputArray[i]);
    }

    // Send array to the server
    if (send(clientSocket, (char*)inputArray, sizeof(inputArray), 0) < 0) {
        perror("Send failed");
    }

    // Cleanup
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
