// (C) Juan García, Oscar Reina, Jan Manel, group: 19 (2023) 
// Work package 1
// Exercise 1.2
// Submission code: 901234ER (provided by your TA-s) 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CHARS 30

// Main function in the program
int main (int argc, char *argv[]) {
    // if user input is wrong or user requests help print use instructions
    if (argc != 2 || strcmp(argv[1], "-h") == 0){
        printf("To use this program, run the command ./WP1-2 <length of characters in text to shift>\n");
    }

    //declare variable to store input with length define as Command Line Argument from user
    int charShift = atoi(argv[1]);
    char text[MAX_CHARS];

    //read user input until EOF is detected
    do {
        // request and read user input
        printf("please input a text to encrypt with maximum length of %i \n", MAX_CHARS);
        scanf("%s", &text);
        //variable to store encrypted text
        char encryptedText[MAX_CHARS];

        // short algorithm to encrypt

        //loop over all chars in textHolder variable
        for (int i = 0; i < MAX_CHARS; i++){
            // store ascii value of current character
            int ascii = (int)text[i];
            // if current character is within a and z
            if (ascii >= 97 && ascii <=  122){
                // Add character shift, if it goes outside of ascii letter values, start from beginning
                if (( ascii +charShift ) > 122){
                    encryptedText[i] = 97 + ((ascii + charShift - 1) % 122);
                } else{
                    encryptedText[i] = (char) (ascii + charShift);  
                }  
            // if current character is within A and Z
            } else if (ascii >= 65 && ascii <= 90){
                // Add character shift, if it goes outside of ascii letter values, start from beginning
                if (( ascii +charShift ) > 90){
                    encryptedText[i] = 97 + ((ascii + charShift - 1) % 122);
                } else{
                    encryptedText[i] = (char) (ascii + charShift);  
                }  
            // if current character is not alphabetical
            }else {
                // if not a letter, leave it as it is
                encryptedText[i] = text[i];
            }
        }
        // print encrypted text
        printf("%s\n", encryptedText);
    // do loop until EOF character
    } while (strcmp(text, "^Z") != 0);
}