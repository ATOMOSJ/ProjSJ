#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>

#define MAX_DATA_SIZE 100
#define PORT 12345

// Function to receive and process UTF-8 encoded data
void receiver(SOCKET receiver_socket) {
    char utf8_data[MAX_DATA_SIZE];
    struct sockaddr_in sender_addr;
    int sender_len = sizeof(sender_addr);

    while (1) {
        // Receive data from sender
        int data_length = recvfrom(receiver_socket, utf8_data, sizeof(utf8_data), 0, (struct sockaddr*)&sender_addr, &sender_len);
        if (data_length > 0) {
            // Null-terminate the received data
            utf8_data[data_length] = '\0';

            // Convert UTF-8 to UTF-16 (wide character)
            int utf16_length = MultiByteToWideChar(CP_UTF8, 0, utf8_data, -1, NULL, 0);
            wchar_t utf16_data[MAX_DATA_SIZE];
            MultiByteToWideChar(CP_UTF8, 0, utf8_data, -1, utf16_data, utf16_length);

            // Print UTF-16 encoded data
            wprintf(L"Received: %s\n", utf16_data);

            // Send acknowledgment
            sendto(receiver_socket, "ACK", 3, 0, (struct sockaddr*)&sender_addr, sender_len);
        }
    }
}

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("WSAStartup failed");
        return 1;
    }

    SOCKET receiver_socket;
    struct sockaddr_in receiver_addr;

    // Create receiver socket
    receiver_socket = socket(AF_INET, SOCK_DGRAM, 0);

    if (receiver_socket == INVALID_SOCKET) {
        perror("Socket creation failed");
        return 1;
    }

    // Initialize receiver address
    memset(&receiver_addr, 0, sizeof(receiver_addr));
    receiver_addr.sin_family = AF_INET;
    receiver_addr.sin_addr.s_addr = INADDR_ANY;
    receiver_addr.sin_port = htons(PORT);

    // Bind the socket to a specific port
    if (bind(receiver_socket, (struct sockaddr*)&receiver_addr, sizeof(receiver_addr)) == SOCKET_ERROR) {
        perror("Socket binding failed");
        closesocket(receiver_socket);
        WSACleanup();
        return 1;
    }

    // Call the receiver function
    receiver(receiver_socket);

    closesocket(receiver_socket);
    WSACleanup();

    return 0;
}
