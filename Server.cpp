// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <arpa/inet.h>
// #define SERVER_PORT 12345 #define
// BUFFER_SIZE 1024
// int main() {
// int sockfd;

// struct sockaddr_in server_addr, client_addr;
// socklen_t client_len = sizeof(client_addr);
// char buffer[BUFFER_SIZE];
// // Create a UDP socket
// sockfd = socket(AF_INET, SOCK_DGRAM, 0);
// if (sockfd < 0) { perror("Error in socket
// creation"); exit(1);
// }
// // Configure server address
// memset(&server_addr, 0, sizeof(server_addr));
// server_addr.sin_family = AF_INET;
// server_addr.sin_addr.s_addr = INADDR_ANY;
// server_addr.sin_port = htons(SERVER_PORT);
// // Bind the socket to the server address
// if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
// perror("Error in binding");
// exit(1);
// }
// printf("UDP chat server is running on port %d...\n", SERVER_PORT);
// while (1) {
// // Receive data from a client ssize_t recv_len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0,
// (struct sockaddr *)&client_addr,
// &client_len); if (recv_len < 0) {
// perror("Error in recvfrom");
// exit(1);
// }
// // Null-terminate the received data
// buffer[recv_len] = '\0';
// // Display the message received from the client
// printf("Client %s:%d: %s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port),
// buffer);
// // Get a message from the server's console and send it to the client
// printf("Server: ");
// fgets(buffer, BUFFER_SIZE, stdin);

// if (buffer[0] == 'q') {
// break;
// }
// // Send the message to the client
// sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr, client_len);
// }
// close(sockfd);
// return 0;
// }



#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
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
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error in binding" << std::endl;
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        std::cerr << "Error in listening" << std::endl;
        exit(1);
    }

    std::cout << "TCP chat server is running on port " << SERVER_PORT << "..." << std::endl;

    while (true) {
        // Accept a new client connection
        new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
        if (new_sockfd < 0) {
            std::cerr << "Error in accepting connection" << std::endl;
            continue;  // You might want to exit here based on your design
        }

        std::cout << "Client connected: " << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << std::endl;

        while (true) {
            // Receive data from the client
            ssize_t recv_len = recv(new_sockfd, buffer, BUFFER_SIZE, 0);
            if (recv_len <= 0) {
                std::cerr << "Client disconnected or error in recv" << std::endl;
                break;  // Exit the loop if the client disconnects
            }

            // Null-terminate the received data
            buffer[recv_len] = '\0';

            // Display the message received from the client
            std::cout << "Client: " << buffer << std::endl;

            // Get a message from the server's console and send it to the client
            std::cout << "Server: ";
            std::cin.getline(buffer, BUFFER_SIZE);

            // Send the message to the client
            send(new_sockfd, buffer, strlen(buffer), 0);
        }

        // Close the client socket
        close(new_sockfd);
    }

    // Close the server socket
    close(sockfd);
    return 0;
}
