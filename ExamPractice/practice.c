#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSTEPS 10
#define MAXNUMBER 10

int main() {
    
    int steps = 0;

    srand(time(NULL));

    int random_number = rand() % MAXNUMBER + 1;
    int guess;
    char forfeit;

    FILE *fileptr;

    fileptr = fopen("textfile.log", "a");

    if (fileptr == NULL)
    {
        printf("Could not open the file");
        return -1;
    }
    

    do
    {
        printf("Please enter your guess from 0 to %i\n", MAXNUMBER);
        scanf("%i", &guess);

        steps++;

        fwrite(&guess, sizeof(int), 1, fileptr);

        if (guess < random_number)
        {
            printf("%i was too low of a guess. You have %i tries left.\nWould you like to forfeit (y/n)?\n", guess, (MAXSTEPS-steps));
            
            scanf("%c" ,&forfeit);
            if (forfeit == 'y')
            {
                printf("\nThank you for playing!\n");
                return -1;
            }
            
        }
        else if (guess > random_number)
        {
            printf("%i was too high of a guess. You have %i tries left.\nWould you like to forfeit (y/n)?", guess, (MAXSTEPS-steps));
            scanf("%c" ,&forfeit);
            if (forfeit == 'y')
            {
                printf("Thank you for playing!\n");
                return -1;
            }
        }
        else
        {
            printf("You guessed it! \n");
            break;
        }
        

    } while (steps < MAXSTEPS);

    fclose(fileptr);
}