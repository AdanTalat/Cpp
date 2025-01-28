#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#define SERVER_IP "127.0.0.1" // Server IP address
#define SERVER_PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error in socket creation" << std::endl;
        exit(1);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error in connecting to server" << std::endl;
        exit(1);
    }

    while (true) {
        // Get a message from the client's console and send it to the server
        std::cout << "Client: ";
        std::cin.getline(buffer, BUFFER_SIZE);
        if (buffer[0] == 'q') {
            break;  // Exit if the input starts with 'q'
        }

        // Send the message to the server
        send(sockfd, buffer, strlen(buffer), 0);

        // Receive data from the server
        ssize_t recv_len = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (recv_len < 0) {
            std::cerr << "Error in recv from server" << std::endl;
            exit(1);
        }

        // Null-terminate the received data
        buffer[recv_len] = '\0';

        // Display the message received from the server
        std::cout << "Server: " << buffer << std::endl;
    }

    // Close the socket
    close(sockfd);
    return 0;
}






