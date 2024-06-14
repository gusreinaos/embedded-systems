// (C) Juan García, Oscar Reina, Jan Manel, group: 19 (2023) 
// Work package 1 
// Exercise 1.3
// Submission code: 901234ER (provided by your TA-s) 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NUMBER 10

// Main function in the program
int main (int argc, char *argv[]) { 

    // create random integer
    int num = rand() % 100 + 1;

    // create counter for number of guesses by the user
    int guesses = 0;

    // create variable to store input
    int userGuess = -1;

    // create while condition variable
    int endConditionMet = 0;

    // read user input until max guesses or correct guess
    do {
        // request and read user input
        printf("Try to guess the number between 1 and 100, in total you have %i guesses left \n", MAX_NUMBER - guesses);
        scanf("%i", &userGuess);

        // increase guess counter
        guesses++;

        // check if user guessed correctly
        if(userGuess == num){
            // give feedback and end program
            printf("You have guessed %i times and your guess is correct \n", guesses);
            endConditionMet = 1;
        // check if user exceeded max number of guesses
        }else if(guesses == MAX_NUMBER){
            // give feedback and end program
            printf("You guessed too many times, program closed\n");
            endConditionMet = 1;
        // check if user guess was lower than true number
        }else if (userGuess < 1 || userGuess > 100){
            printf("your input was not a number between 1 and 100, try again\n");
        }else if (userGuess < num){
            printf("your guess was wrong, try a bigger number\n");
        // check if user guess was higher than true number 
        } else if (userGuess > num){
            printf("your guess was wrong, try a smaller number\n");
        } 
    } while (endConditionMet == 0);
}