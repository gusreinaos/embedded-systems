#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//Defining the maximum number of characters for first and family name
#define MAXLEN 20
//Defining the maximum number of characters for the personal number
#define MAXNUM 13
 
// -----typedefs ------- 
typedef struct { 
        char firstname[MAXLEN]; 
        char famname[MAXLEN]; 
        char pers_number[MAXNUM]; // yyyymmddnnnc 
} PERSON; 
 
// Function declaration (to be extend)  
PERSON input_record(void);             // Reads a person’s record. 
void write_new_file(PERSON *inrecord);  // Creates a file and  
// writes the first record 
void printfile(void);     // Prints out all persons in the file 
void search_by_firstname(char *name); // Prints out the person if    
// in list  
void append_file(PERSON *inrecord);    // appends a new person to the file 


// -----Functions Utils -------

int has_no_digits(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// -----Functions Implementation -------

PERSON input_record(void) {

    PERSON person;
    int len;
    
    //Input for the first name of the person record
    do{
        //Scanning the input of the user
        printf("%s", "Please enter a  valid first name (max 20 characters with no digits): " );
        scanf("%s", person.firstname);

        //Checking whether the input has digits and the length is not more than 20
        len = strlen(person.firstname);
        if (!has_no_digits(person.firstname) || len > MAXLEN) {
            printf("Invalid input for first name.\n");
        }

    }while(!has_no_digits(person.firstname) || len > MAXLEN);

    //Input for the family name of the person record
    do{
        //Scanning the input of the user
        printf("%s", "Please enter a  valid family name (max 20 characters with no digits): " );
        scanf("%s", person.famname);

        //Checking whether the input has digits and the length is not more than 20
        len = strlen(person.famname);
        if (!has_no_digits(person.famname) || len > MAXLEN) {
            printf("Invalid input for family name.\n");
        }

    }while(!has_no_digits(person.famname) || len > MAXLEN);
    
    //Input for the personal number of the person record
    do{
        //Scanning the input of the user
        printf("%s", "Please enter a  valid personal number (max 13 characters with no digits with the format yyyymmddnnnc): " );
        scanf("%s", person.pers_number);

        //Checking whether the input has digits and the length is not more than 13
        len = strlen(person.pers_number);
        if (has_no_digits(person.pers_number) || len > MAXNUM) {
            printf("Invalid input for first name.\n");
        }

    }while(has_no_digits(person.pers_number) || len > MAXNUM);

    //Returning the new record of person created
    return person;
}

void write_new_file(PERSON *inrecord){
    
    //Creating an opening for the file we want to open
    FILE* fileptr;
    //Opening the database binary file in order to write on it
    fileptr = fopen("database.bin", "wb");

    //Checking for any errors during opening the file
    if(fileptr == NULL){
        printf("Error opening the file");
        //Stopping the execution of the method
        return;
    }

    //If no errors then we write the dummy person record in the file and then close it
    fwrite(inrecord, sizeof(PERSON), 1, fileptr);
    //Closing the file with its pointer after the action is fiinished
    fclose(fileptr);
}

void printfile(void) {
    //Creating a pointer for the file we want to open
    FILE* fileptr;
    //Opening the database binary file in order to read its content
    fileptr = fopen("database.bin", "rb");

    //Checking for any errors during opening the file
    if (fileptr == NULL){
        printf("Unable to open the file \n");
        //Stopping the execution of the method
        return;
    }

    //Creating a pointer for the person we are looking for
    PERSON *personptr;
    //Allocating the person in memory since it allows us to allocate memory dynamically on the heap, which has a larger size than the stack
    personptr  = malloc(sizeof(PERSON));

    //While there is still a record to read in the file of a person, keep reading
    while (fread(personptr, sizeof(PERSON), 1, fileptr) == 1) {
        //Printing the first name of the person record found
        printf("First name: %s\n", personptr -> firstname);
        //Printing the family name of the person record found
        printf("Family name: %s\n", personptr -> famname);
        //Printing the personal number of the person record found
        printf("Personal number: %s\n\n", personptr -> pers_number);
    }
    //Closing the file with its pointer after the action is finished
    fclose(fileptr);
    //Freeing the memory allocated in the heap for the reading of each record
    free(personptr);
}

void search_by_firstname(char *name) {
    //Declare the number of matches
    int num_matches = 0;
    //Creating a pointer for the file we want to open
    FILE *fileptr;
    //Opening the database binary file in order to read its content
    fileptr = fopen("database.bin", "rb");
    //Checking for any errors during opening the file
    if (fileptr == NULL) {
        printf("Error opening file.\n");
        //Stopping the execution of the method
        return;
    }
    //Allocating the person in memory since it allows us to allocate memory dynamically on the heap, which has a larger size than the stack
    PERSON *personptr = malloc(sizeof(PERSON));
    //Checking for any errors during opening the file
    if (personptr == NULL) {
        printf("Error allocating memory.\n");
        //Stopping the execution of the method
        return;
    }
    //While there is still a record to read in the file of a person, keep reading
    while (fread(personptr, sizeof(PERSON), 1, fileptr) == 1) {
        //Checking whether the first name of the person read equals the first name provided by the user
        if ((strcmp(personptr -> firstname, name) == 0) || ((strcmp(personptr -> famname, name) == 0))) {
            //If the first name of the user read and the first name provided match then print all of the attributes of that person
            printf("\nFirstname: %s\n", personptr -> firstname);
            printf("Famname: %s\n", personptr -> famname);
            printf("Personal Number: %s\n", personptr -> pers_number);
            //Increase the number of matches for that first name
            num_matches++;
        }
    }
    //Checking whether there were no matches provided for the first name provided, and therefore printing it as so to the user
    if (num_matches == 0) {
        printf("\n%s not found.\n\n", name);
    } else {
        //Printing the number of matches found for the first name
        printf("\n%d matches found.\n\n", num_matches);
    }
    //Closing the file with its pointer after the action is finished
    fclose(fileptr);
    //Freeing the memory allocated in the heap for the reading of each record
    free(personptr);
    
}

void append_file(PERSON *inrecord) {
    //Creating a pointer for the file we want to open
    FILE* fileptr;
    //Opening the database binary file in order to read its content
    fileptr = fopen("database.bin", "ab");
    //Checking for any errors during opening the file
    if (fileptr == NULL){
        printf("Unable to open the file \n");
        //Stopping the execution of the method
        return;
    }
    //If no errors then we write the person record in the file and then close it
    fwrite(inrecord, sizeof(PERSON), 1, fileptr);
    fclose(fileptr);
}
 
int main(){ 
    //Initial declarations for future use along main
    PERSON* ppost;
    int input;

    do {
        //Present the menu options for the user
        printf("1 Create a new and delete the old file.\n2 Add a new person to the file. \n3 Search for a person in the file.\n4 Print out all in the file.\n5 Exit the program. \n");
        //Ask the user for an option of the menu and scan it
        printf("Please introduce your option: ");
        scanf("%d", &input);
        printf("\n");

        //Option 1: Create a new and delete the old file
        if(input == 1){
            //Save in memory the person we want to write information of
            ppost=malloc(sizeof(PERSON)); 

            //Copy into the char arrays of the person record
            strcpy(ppost[0].firstname, "Firstnameexample");
            strcpy(ppost[0].famname, "Familynameexample");
            strcpy(ppost[0].pers_number, "0303046031");

            //Call the method to write the dummy data
            write_new_file(ppost);
            //Free the memory used for creating the dummy persond ata
            free(ppost);
        }

        //Option 2: Add a new person to the file.
        else if(input == 2) {
            //Create the person we want to add to the file with a pointer
            PERSON person = input_record();
            PERSON *personptr = &person;
            //Add the person to the file in the following function
            append_file(personptr);

        }
        //Option 3: Add a new person to the file.
        else if(input == 3) {
            
            char fname[MAXLEN];
            int len;

             //Input for the first name of the person record
             do {
                //Scanning the input of the user
                printf("%s", "Please enter a  valid either first or last name (max 20 characters with no digits): " );
                scanf("%s", fname);

                //Checking whether the input has digits and the length is not more than 20
                len = strlen(fname);
                if (!has_no_digits(fname) || len > MAXLEN) {
                    printf("Invalid input for first name.\n");
                }

            } while(!has_no_digits(fname) || len > MAXLEN);

            //Assign the name we want to look for to a pointer
            char* ptrtoname = fname;
            //Passing the name to the function we want to look in the file
            search_by_firstname(ptrtoname);
        }
        //Option4: Print out all in the file.
        else if(input == 4) {
            printfile();
        }
        //Option5: Exit the system
        else if (input == 5){
            input = 7;
            printf("Exiting the program, see you soon!\n");
        }
        //Another option asks for another input
        else {
           input = 4;
           printf("Invalid option, please enter another one.\n");
        }
    }
    //Keep reading until a number that is not within the range 1-5 is inputted
    while(input > 0 && input < 6); 
} 