#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#define MAX_NUMBER 10

int main ()
{
    //We initalise the random generation of numbers so that it does not return the same number every execution 
    srand ( time(NULL) );
    //Create a random number from (0 - 99 as the modulo %100) + 1
    int randomNumber =  rand() %100 + 1;
    //Store input from the user
    int input;
    //Store the number of guesses by the user
    int numberOfGuesses = 0;
    //Max number of tries the user is able to input 
    int maxNumber = 10;

    do {
        //printf("%d\n", randomNumber);
        
        //Scan input from user
        printf("%s","Please enter a number from 1 - 100 (included): ");
        scanf("%d", &input);

        //Checking whether input is not between the 1 - 100 range, not for a letter
        if(input > 100 || input < 1) {
            printf("%s\n", "Please enter a valid integer between 1 - 100");
            continue;
        }
        
        //Check if the input from the user if higher or lower than the stablished random number
        if (input < randomNumber){
            //Acknowledging the user that the number chosen is too low
            printf("%s\n", "Your guess is too low.");
            //Incrementng by one the count of guesses
            numberOfGuesses = numberOfGuesses + 1;
            printf("%d\n", numberOfGuesses);
        }
        else if(input > randomNumber){
             //Acknowledging the user that the number chosen is too high
            printf("%s\n", "Your guess is too high.");
            //Incrementng by one the count of guesses
            numberOfGuesses = numberOfGuesses + 1;
            printf("%d\n", numberOfGuesses);
        }
        else {
            printf("You have guessed correctly after %d times\n", numberOfGuesses);
        }
        
    } while(input != randomNumber && numberOfGuesses < MAX_NUMBER);

    if(numberOfGuesses == 10) {
        printf("%s\n", "You have run out of tries");
    }

  return 0;
}