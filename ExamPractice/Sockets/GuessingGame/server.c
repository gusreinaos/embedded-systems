#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE] = {0};
    int min = 1;
    int max = 100;
    
    // Create the socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Waiting for a client to connect...\n");
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    
    // Send the range to the client
    sprintf(message, "%d %d", min, max);
    send(new_socket, message, strlen(message), 0);
    printf("Sent range to client: %s\n", message);
    
    // Generate a random number within the range
    srand(time(NULL));
    int number = rand() % (max - min + 1) + min;
    printf("Server's number: %d\n", number);
    
    // Play the guessing game
    while (1) {
        // Receive the client's guess
        valread = read(new_socket, buffer, BUFFER_SIZE);
        int guess = atoi(buffer);
        printf("Client's guess: %d\n", guess);
        
        // Check if the guess is correct
        if (guess == number) {
            sprintf(message, "0");
            send(new_socket, message, strlen(message), 0);
            printf("Server's response: %s\n", message);
            break;
        }
        else if (guess < number) {
            sprintf(message, "-1");
            send(new_socket, message, strlen(message), 0);
            printf("Server's response: %s\n", message);
            min = guess;
        }
        else {
            sprintf(message, "1");
            send(new_socket, message, strlen(message), 0);
            printf("Server's response: %s\n", message);
            max = guess;
        }
        
        // Generate a new number within the updated range
        number = rand() % (max - min + 1) + min;
        printf("Server's number: %d\n", number);
    }
    
    // Close the connection
    printf("Closing connection...\n");
    close(new_socket);
    
    return 0;
}