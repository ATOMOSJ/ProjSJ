#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define MAX_PACKETS 2000
#define WINDOW_SIZE 9
#define TIMEOUT_MS 1000

typedef struct {
    int seq_num;
    char data[1024];
} Packet;

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("WSAStartup failed.");
        return 1;
    }
    SOCKET clientSocket;
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        perror("Socket creation failed.");
        return 1;
    }
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345);  // Use the desired port number
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Set the server IP address
    int base = 0;
    int next_seq_num = 0;
    Packet packets[MAX_PACKETS];
    int sent = 0;
    while (sent < MAX_PACKETS) {
        // Send packets in the current window
        while (next_seq_num < base + WINDOW_SIZE && next_seq_num < MAX_PACKETS) {
            // Construct and send the packet
            Packet packet;
            packet.seq_num = next_seq_num;
            snprintf(packet.data, sizeof(packet.data), "Packet %d", next_seq_num);
            sendto(clientSocket, (char *)&packet, sizeof(Packet), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
            printf("Sent Packet %d\n", next_seq_num);
            next_seq_num++;
        }
        // Set a timeout for receiving ACKs
        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = TIMEOUT_MS * 1000;
        setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout));
        // Receive ACKs and update the window
        int ack;
        while (recvfrom(clientSocket, (char *)&ack, sizeof(int), 0, NULL, NULL) > 0) {
            if (ack >= base) {
                base = ack + 1;
                printf("Received acknowledgement %d\n", ack);
            }
        }
    }
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}

