#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>

#define WINDOW_SIZE 9
#define PACKET_SIZE 2000
#define PORT 12345

typedef struct {
    int sequence_number;
    char data[PACKET_SIZE];
} Packet;

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("WSAStartup failed");
        return 1;
    }

    // Create a UDP socket
    SOCKET socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == INVALID_SOCKET) {
        perror("socket creation failed");
        return 1;
    }

    // Server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return 1;
    }

    // Simulated received data
    char received_data[PACKET_SIZE * WINDOW_SIZE];
    memset(received_data, 0, sizeof(received_data));

    int expected_sequence_number = 0;
    int base_sequence_number = 0;
    Packet packets[WINDOW_SIZE];

    while (1) {
        Packet received_packet;
        struct sockaddr_in client_addr;
        int addr_len = sizeof(client_addr);

        // Receive a packet
        if (recvfrom(socket_fd, (char*)&received_packet, sizeof(received_packet), 0,
                     (struct sockaddr*)&client_addr, &addr_len) == SOCKET_ERROR) {
            perror("recvfrom failed");
            return 1;
        }

        // Simulate packet loss
        if (rand() % 10 < 3) {
            printf("Packet loss, sequence number %d\n", received_packet.sequence_number);
            continue;
        }

        // If the received packet is within the window, store it
        if (received_packet.sequence_number >= base_sequence_number &&
            received_packet.sequence_number < base_sequence_number + WINDOW_SIZE) {
            packets[received_packet.sequence_number - base_sequence_number] = received_packet;

            // Check if the received packet is the expected one
            while (packets[0].sequence_number == expected_sequence_number) {
                // Process the packet (e.g., write to a file)
                memcpy(received_data + expected_sequence_number * PACKET_SIZE, packets[0].data, PACKET_SIZE);
                printf("Received packet with sequence number %d\n", expected_sequence_number);

                // Slide the window
                for (int i = 0; i < WINDOW_SIZE - 1; i++) {
                    packets[i] = packets[i + 1];
                }

                // Increase sequence numbers
                base_sequence_number++;
                expected_sequence_number++;
            }
        }

        // Acknowledge the last successfully received packet
        int ack_number = expected_sequence_number - 1;
        if (sendto(socket_fd, (char*)&ack_number, sizeof(ack_number), 0,
                    (struct sockaddr*)&client_addr, sizeof(client_addr)) == SOCKET_ERROR) {
            perror("sendto failed");
            return 1;
        }
    }

    // Clean up
    closesocket(socket_fd);
    WSACleanup();

    return 0;
}