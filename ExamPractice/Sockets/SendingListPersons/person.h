#define MAX 10

typedef struct { 
    char sName[MAX];   // Person’s given name 
    char sSurname[MAX]; // Person’s surname 
    char sPnr[MAX];  // Person’s social security number 
    char sAddress[MAX]; // Person’s city of residence 
} Person; 

Person *create_list(void);
void print_list(Person *head);