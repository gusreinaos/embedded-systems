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