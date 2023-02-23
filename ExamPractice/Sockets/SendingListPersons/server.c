#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "person.h"

#define PORT 5000

int main()
{
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind to port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    int bind_result = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (bind_result == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    int listen_result = listen(sockfd, 1);
    if (listen_result == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Create linked list of persons
    Person *first_person = create_person_list();

    // Print list to console
    print_person_list(first_person);

    // Accept incoming connection
    int clientfd = accept(sockfd, NULL, NULL);
    if (clientfd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Send number of persons in list
    int num_persons = count_persons(first_person);
    send(clientfd, &num_persons, sizeof(num_persons), 0);

    // Send each person in list
    Person *current_person = first_person;
    while (current_person != NULL) {
        send(clientfd, current_person, sizeof(Person), 0);
        current_person = current_person->next;
    }

    // Close sockets and free memory
    close(clientfd);
    close(sockfd);
    free_person_list(first_person);

    return 0;
}