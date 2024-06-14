// (C) Juan García, Oscar Reina, Jan Manel, group: 19 (2023) 
// Work package 0 
// Exercise 1.1
// Submission code: 901234ER (provided by your TA-s) 
#include <stdio.h>

int main() {
    //declare variables
    int input;
    do{
        // request and scan user input
        printf("please input a number from 1 to 5 \n");
        scanf("%d", &input);
        // if input int is equal to 1
        if (input == 1){
            printf("hey, your input was the number 1\n");
        }
        // if input int is equal to 2
        else if(input == 2){
            printf("hey, your input was the number 2\n");
        }
        // if input int is equal to 3
        else if(input == 3){
            printf("hey, your input was the number 3\n");
        }
        // if input int is equal to 4
        else if(input == 4){
            printf("hey, your input was the number 4\n");
        }
        // if input int is equal to 5
        else if(input == 5){
            printf("hey, your input was the number 5\n");
        }
    } 
    // break loop when input is not within 1 and 5
    while (input < 6 && input >0); 
    printf("Your input was not within 1 and 5, program closed\n");
}