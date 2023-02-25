#include "person.h"
#include <stdlib.h>
#include <string.h>

Person* create_person(char* sName, char* sSurname, char* sPnr, char* sAddress, int iAge) {
    Person* new_person = (Person*)malloc(sizeof(Person));
    strcpy(new_person->sName, sName);
    strcpy(new_person->sSurname, sSurname);
    strcpy(new_person->sPnr, sPnr);
    strcpy(new_person->sAddress, sAddress);
    new_person->iAge = iAge;
    new_person->next = NULL;
    return new_person;
}

Person* create_linked_list() {
    
    Person* head = create_person("John", "Doe", "1234567890", "New York", 30);
    head->next = create_person("Jane", "Doe", "0987654321", "Los Angeles", 25);
    head->next->next = create_person("Bob", "Smith", "1111111111", "Chicago", 40);
    head->next->next->next = create_person("Alice", "Johnson", "2222222222", "Houston", 50);
    head->next->next->next->next = create_person("Eve", "Lee", "3333333333", "San Francisco", 35);
    return head;
}