#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int highestOrder(int number) {
    int index = 0;
    //Every time we shift we create a new number, therefore we need to check whether this number is greater than 0 and the number it lands on then with 
    //the amount of iterations we can get the index
    while(number > 0) {
        number = number >> 1;
        index++;
    }
}

int main() {

}