#include <stdio.h>

int main() {
    
    //declare variables

    int input;
    
    do {

        printf("Please input a number from 1 to 5 \n");
        scanf("%d", &input);
        printf("%d\n", input);

        if(input == 1) {
        printf("You have entered number %d\n", input);
        }
        else if(input == 2){
            printf("You have entered number %d\n", input);

        }
        else if(input ==3){
            printf("You have entered number %d\n", input);
            
        }
        else if(input ==4){
            printf("You have entered number %d\n", input);
            
        }
        else if(input ==5){
            printf("You have entered number %d\n", input);
            
        }
    }
    
    while(input > 0 && input < 6); 
}