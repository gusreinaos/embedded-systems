/*
This code is a client program that connects to a server on a specified IP address and port number. 
The server sends information about a number of persons in a register over the connection. The client receives this information and creates a linked list of Person structures with the received data. 
Finally, the client prints the linked list on the console, frees the memory allocated for the linked list, and closes the connection.

The code first creates a socket using the socket() system call with the arguments AF_INET, SOCK_STREAM, and 0. 
It then initializes the serv_addr structure with the IP address and port number of the server to connect to. 
The inet_pton() function is used to convert the IP address from text to binary form. Finally, the connect() function is used to establish a connection to the server.

After the connection is established, the client reads the number of persons in the register using the read() function and stores it in the num_persons variable. 
It then creates a linked list of Person structures by looping through each person in the register and using the read() function to receive their information. 
The received information is parsed and used to create a new Person structure using the create_person() function. The head and current pointers are used to keep track of the head and tail of the linked list as new persons are added to it.

Once the linked list is created, the client prints it on the console by looping through each element in the list and using the printf() function to print their information. 
Finally, the memory allocated for the linked list is freed using the free_linked_list() function and the connection is closed using the close() function.

Note that some helper functions and macros (such as create_person(), free_linked_list(), MAX, and Person) are assumed to be defined in an included header file (person.h) and are not shown in this code snippet.
*/

#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    
    // Create the socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    
    memset(&serv_addr, '0', sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    
    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    // Receive the number of persons in the register
    valread = read(sock, buffer, BUFFER_SIZE);
    buffer[valread] = '\0';
    int num_persons = atoi(buffer);
    printf("Number of persons in the register: %d\n", num_persons);
    
    // Receive each person separately and create a linked list
    Person* head = NULL;
    Person* current = NULL;
    for (int i = 0; i < num_persons; i++) {
        valread = read(sock, buffer, BUFFER_SIZE);
        buffer[valread] = '\0';
        
        char* token = strtok(buffer, " ");
        char sName[MAX];
        strncpy(sName, token, MAX);
        
        token = strtok(NULL, " ");
        char sSurname[MAX];
        strncpy(sSurname, token, MAX);
        
        token = strtok(NULL, " ");
        char sPnr[MAX];
        strncpy(sPnr, token, MAX);
        
        token = strtok(NULL, " ");
        char sAddress[MAX];
        strncpy(sAddress, token, MAX);
        
        token = strtok(NULL, " ");
        int iAge = atoi(token);
        
        Person* person = create_person(sName, sSurname, sPnr, sAddress, iAge);
        if (head == NULL) {
            head = person;
            current = person;
        } else {
            current->next = person;
            current = person;
        }
        
        printf("Received person: %s %s %s %s %d\n", sName, sSurname, sPnr, sAddress, iAge);
    }
    
    // Print the list on the console
    printf("List of persons:\n");
    current = head;
    while (current != NULL) {
        printf("%s %s %s %s %d\n", current->sName, current->sSurname, current->sPnr, current->sAddress, current->iAge);
        current = current->next;
    }
    
    // Free memory and close the connection
    free_linked_list(head);
    printf("Closing connection...\n");
    close(sock);
    
    return 0;
}