#include <stdlib.h> 
#include <stdio.h> 
 
// -----typedefs ------- 
typedef struct { 
        char firstname[20]; 
        char famname[20]; 
        char pers_number[13]; // yyyymmddnnnc 
} PERSON; 
 
// Function declaration (to be extend)  
PERSON input_record(void);             // Reads a person’s record. 
void write_new_file(PERSON *inrecord);  // Creates a file and  
// writes the first record 
void printfile(void);     // Prints out all persons in the file 
void search_by_firstname(char *name); // Prints out the person if    
// in list  
void append_file(PERSON *inrecord);    // appends a new person to the file 

// -----Functions Implementation ------- 
PERSON input_record(void) {

}

void write_new_file(PERSON *inrecord){

}

void printfile(void) {

}

void search_by_firstname(char *name) {

}

void append_file(PERSON *inrecord) {
    
}
 
int main(){ 

    PERSON ppost;
    int input;

    do {
        
        printf("%s", "\n1 Create a new and delete the old file.\n2 Add a new person to the file. \n3 Search for a person in the file.\n4 Print out all in the file.\n5 Exit the program. \n\n");

        scanf("%d", &input);

        if(input == 1){
           
        }
        else if(input == 2) {

        }
        else if(input == 3) {
            
        }
        else if(input == 4) {
            
        }
        else if(input == 5) {
            
        }
    }
    //Keep reading until a number that is not within the range 1-5 is inputted
    while(input > 0 && input < 6); 
  
} 