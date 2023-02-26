/*
This code is a server that listens for incoming connections, accepts them, and then sends a list of persons to the client. 
It uses sockets to communicate between the server and the client.

The code first creates a linked list of persons using the function create_linked_list() from person.h header file. 
Then it prints the list on the console.

It then creates a socket using the socket() function and sets the socket options using setsockopt(). 
It then binds the socket to the specified port and starts listening for incoming connections using the listen() function.

The code enters an infinite loop and waits for incoming connections using the accept() function. 
Once a client connects, it sends the number of persons in the register to the client using the send() function. 
It then sends each person in the register separately by iterating over the linked list and formatting each person's data as a string using sprintf() before sending it using send().

Once all persons have been sent, it closes the connection using close() and waits for another connection. 
If an error occurs during any of these steps, it prints an error message and exits.

Overall, this code implements a simple server that sends a list of persons to a client over a network using sockets.

*/


#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    // Create the linked list of persons
    Person* head = create_linked_list();
    
    // Print the list on the console
    printf("List of persons:\n");
    Person* current = head;
    while (current != NULL) {
        printf("%s %s %s %s %d\n", current->sName, current->sSurname, current->sPnr, current->sAddress, current->iAge);
        current = current->next;
    }
    
    // Create the socket
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE] = {0};
    
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
    
    // Accept incoming connections and send the person register
    while (1) {
        printf("Waiting for a client to connect...\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        // Send the number of persons in the register
        int num_persons = 0;
        current = head;
        while (current != NULL) {
            num_persons++;
            current = current->next;
        }
        sprintf(message, "%d", num_persons);
        send(new_socket, message, strlen(message), 0);
        printf("Sent number of persons in the register: %s\n", message);
        
        // Send each person separately
        current = head;
        while (current != NULL) {
            sprintf(message, "%s %s %s %s %d", current->sName, current->sSurname, current->sPnr, current->sAddress, current->iAge);
            send(new_socket, message, strlen(message), 0);
            printf("Sent person: %s\n", message);
            current = current->next;
        }
        
        // Close the connection
        printf("Closing connection...\n");
        close(new_socket);
    }
    
    return 0;
}