#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Main function in the program
int main (int argc, char *argv[]) {
    // if user input is wrong or user requests help print use instructions
    if (argc != 2 || strcmp(argv[1], "-h") == 0){
        printf("To use this program, run the command ./WP1-2 <length of characters in text to encrypt>\n");
    }

    //declare variable to store input with length define as Command Line Argument from user
    int charLimit = atoi(argv[1]);
    char textHolder[charLimit];

    //read user input until EOF is detected
    do {
        // request and read user input
        printf("please input a text to encrypt with maximum length of %i \n", charLimit);
        scanf("%s", &textHolder);
        //variable to store encrypted text
        char encryptedText[charLimit];

        // short algorithm to encrypt

        //loop over all chars in textHolder variable
        for (int i = 0; i < charLimit; i++){
            // store ascii value of current character
            int ascii = (int)textHolder[i];
            // if current character is within a and m
            if (ascii >= 97 && ascii <=  109){
                // add "13" to ascii code to get encrypted character and store in solution char array
                encryptedText[i] = (char) (ascii + 13);
            //if current character is within n and z
            } else if (ascii >= 110 && ascii <= 122){
                // substract "13" to ascii code to get encrypted character and store in solution char array
                encryptedText[i] = (char) (ascii - 13);
            // if current character is within A and M
            } else if (ascii >= 65 && ascii <= 77){
                // substract "13" to ascii code to get encrypted character and store in solution char array
                encryptedText[i] = (char) (ascii + 13);
            // if current character is within N and Z
            } else if (ascii >= 78 && ascii <= 90){
                // substract "13" to ascii code to get encrypted character and store in solution char array
                encryptedText[i] = (char) (ascii - 13);
            }else {
                // if not a letter, leave it as it is
                encryptedText[i] = textHolder[i];
            }
        }
        // print encrypted text
        printf("%s\n", encryptedText);
    // do loop until EOF character
    } while (strcmp(textHolder, "^Z") != 0);
}