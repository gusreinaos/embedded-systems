#include <stdio.h>
#include <stdlib.h>

void bit_toggler(int number, int bit) {
    
    int bit = (number >> bit) & 1;

    if (/* condition */)
    {
        /* code */
    }
    

}


int main() {

    int number;
    int bit;
    
    printf("Enter a number: \n");
    scanf("%i", &number);

    printf("Enter a bit to toggle: \n");
    scanf("%i", &bit);

    bit_toggler(number, bit);

}