#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> // Include the correct header for socket functions

int main() {
    int sockfd;
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Use AF_INET instead of PF_INET
    
    if (sockfd == -1) {
        perror("socket");
        return 1; // Return an error code
    }
    
    // Close the socket when done
    close(sockfd);
    
    return 0; // Return success
}
