#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//In order to return a string we need to add a pointer to the char
//Operations such as & are only used bitwise

//A number is odd if the least significant bit is 1
char* oddCalculator(int number) {
    int lDigit = (number >> 1) & 1;

    if(lDigit == 1) {
        return "Odd";
    }
    else {
        return "Even";
    }
}

int main() {
    char* string = oddCalculator(1);
    printf("%s\n", string);
}

//Not working for case one