#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define MAX_DATA_SIZE 100
#define WINDOW_SIZE 4
#define PORT 12345
#define TOTAL_PACKETS 20  // Total number of packets to send

void sender(SOCKET sender_socket, struct sockaddr_in receiver_addr) {
    char data[MAX_DATA_SIZE];
    int sequence_number = 0;
    int base = 0;
    int next_seq_num = 0;

    while (sequence_number < TOTAL_PACKETS) {
        // Send packets within the window
        while (next_seq_num < base + WINDOW_SIZE && next_seq_num < TOTAL_PACKETS) {
            // Prepare data
            sprintf(data, "Packet %d", next_seq_num);

            // Send data to the receiver
            sendto(sender_socket, data, strlen(data), 0, (struct sockaddr*)&receiver_addr, sizeof(receiver_addr));
            printf("Sent: %s\n", data);

            next_seq_num++;

            // Sleep or delay for simulating network latency
            Sleep(100);
        }

        // Wait for acknowledgment
        char ack[MAX_DATA_SIZE];
        int ack_length = recv(sender_socket, ack, sizeof(ack), 0);

        if (ack_length > 0) {
            int ack_num = atoi(ack);
            printf("Received Acknowledgment: %d\n", ack_num);

            // Move the sender's window base forward
            base = ack_num + 1;
        } else {
            printf("Timeout! Resending packets...\n");
            next_seq_num = base; // Resend unacknowledged packets
        }
    }
}

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("WSAStartup failed");
        return 1;
    }

    SOCKET sender_socket;
    struct sockaddr_in receiver_addr;

    // Create sender socket
    sender_socket = socket(AF_INET, SOCK_DGRAM, 0);

    if (sender_socket == INVALID_SOCKET) {
        perror("Socket creation failed");
        return 1;
    }
    const char *filepath = "C:\\Users\\asus\\Desktop\\LMAO1.rar";
    if (remove(filepath) == 0) {
        printf("run is done");
    } else {
        printf("not done");
    }


    // Initialize receiver address
    memset(&receiver_addr, 0, sizeof(receiver_addr));
    receiver_addr.sin_family = AF_INET;
    receiver_addr.sin_addr.s_addr = INADDR_LOOPBACK;  // Localhost
    receiver_addr.sin_port = htons(PORT);

    // Call the sender function
    sender(sender_socket, receiver_addr);

    closesocket(sender_socket);
    WSACleanup();

    return 0;
}
