#include <stdio.h>

int main() {
    
    //declare variables
    int input;
    
    do {
        printf("Please input a number from 1 to 5 \n");
        //Scan the input from the user
        scanf("%d", &input);

        //Case for input 1
        if(input == 1) {
        printf("You have entered number %d\n", input);
        }
        //Case for input 2
        else if(input == 2){
            printf("You have entered number %d\n", input);

        }
        //Case for input 3
        else if(input ==3){
            printf("You have entered number %d\n", input);
            
        }
        //Case for input 4
        else if(input ==4){
            printf("You have entered number %d\n", input);
            
        }
        //Case for input 5
        else if(input ==5){
            printf("You have entered number %d\n", input);
            
        }
    }
    //Keep reading until a number that is not within the range 1-5 is inputted
    while(input > 0 && input < 6); 
}