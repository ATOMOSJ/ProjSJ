#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <time.h>
int factorial(int n) {
    // Base case: factorial of 0 is 1
    if (n == 0) {
        return 1;
    }
    // Recursive case: factorial of n is n * factorial of (n-1)
    else {
        return n * factorial(n - 1);
    }
}
int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    int clientAddrLen = sizeof(clientAddr);
    char buffer[1024];

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed\n");
        return 1;
    }

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        printf("Socket creation failed\n");
        WSACleanup();
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(12345);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        printf("Binding failed\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    if (listen(serverSocket, 5) == SOCKET_ERROR) {
        printf("Listening failed\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    printf("Server listening on port 12345...\n");

    while (1) {
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (clientSocket == INVALID_SOCKET) {
            printf("Acceptance failed\n");
            continue;
        }
        
        printf("fucking with client: %s:%d\n",
               inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
               Sleep(2000);
           clock_t start_time = clock();
        // Receive two numbers from the client
        recv(clientSocket, buffer, sizeof(buffer), 0);
        int num1 = atoi(buffer);
        recv(clientSocket, buffer, sizeof(buffer), 0);
        int num2 = atoi(buffer);
        
        int sum = num1 + num2;
          Sleep(factorial(5000));
                 clock_t end_time = clock();
                   double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        // Convert the sum to a string and send it back to the client
        snprintf(buffer, sizeof(buffer), "%d", sum);
        send(clientSocket, buffer, sizeof(buffer), 0);
        snprintf(buffer, sizeof(buffer), "%d", execution_time);
        send(clientSocket, buffer, sizeof(buffer), 0);

        closesocket(clientSocket);
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
