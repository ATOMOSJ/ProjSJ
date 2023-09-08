#include <stdio.h>
#include <winsock2.h>

int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    int num1, num2;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed\n");
        return 1;
    }

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        printf("Socket creation failed\n");
        WSACleanup();
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  
    serverAddr.sin_port = htons(12345);

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        printf("Connection failed\n");
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    snprintf(buffer, sizeof(buffer), "%d", num1);
    send(clientSocket, buffer, sizeof(buffer), 0);
    snprintf(buffer, sizeof(buffer), "%d", num2);
    send(clientSocket, buffer, sizeof(buffer), 0);
    recv(clientSocket, buffer, sizeof(buffer), 0);
    int sum = atoi(buffer);
    recv(clientSocket, buffer, sizeof(buffer), 0);
    int et = atoi(buffer);
    printf("Sum received from server: %d\n", sum);
    printf("latency time %lf\n", et);
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
