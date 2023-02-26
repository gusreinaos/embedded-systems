#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>

#define SERVER_ADDRESS "127.0.0.1"
#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    srand(time(NULL)); // Initialize random seed

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER_ADDRESS, &server_address.sin_addr) < 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Receive the minimum and maximum range from the server
    int min_range, max_range;
    char buffer[BUFFER_SIZE] = {0};
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    sscanf(buffer, "%d %d", &min_range, &max_range);
    printf("The number is between %d and %d\n", min_range, max_range);

    // Guess the number
    int guess = (rand() % (max_range - min_range + 1)) + min_range;
    printf("Guessing %d...\n", guess);
    sprintf(buffer, "%d", guess);
    send(sock, buffer, strlen(buffer), 0);

    // Receive the server's response
    int response;
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    sscanf(buffer, "%d", &response);
    if (response == 0) {
        printf("You guessed the number!\n");
        close(sock);
        return 0;
    } else {
        printf("Response: %d\n", response);
    }

    // Guess again if the number was not correct
    while (1) {
        if (response == -1) {
            min_range = guess + 1;
        } else if (response == 1) {
            max_range = guess - 1;
        }
        guess = (rand() % (max_range - min_range + 1)) + min_range;
        printf("Guessing %d...\n", guess);
        sprintf(buffer, "%d", guess);
        send(sock, buffer, strlen(buffer), 0);
        if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        sscanf(buffer, "%d", &response);
        if (response == 0) {
            printf("You guessed the number!\n");
            break;
        } else {
            printf("Response: %d\n", response);
        }
    }

    // Close the socket
    close(sock);

    return 0;
}