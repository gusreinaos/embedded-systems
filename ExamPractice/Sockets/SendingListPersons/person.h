#define MAX 20

typedef struct { 
    char sName[MAX];    // Person’s given name 
    char sSurname[MAX]; // Person’s surname 
    char sPnr[MAX];     // Person’s social security number 
    char sAddress[MAX]; // Person’s city of residence 
    int iAge:
    Person* next;
} Person; 

Person* createLinkedList(void);