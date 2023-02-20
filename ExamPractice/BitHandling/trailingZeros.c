#include <stdio.h>


int trailingZeros(int number) {
    int counter = 0;
    //When we mention number it always takes the least significant bit 
    while((number & 1) == 0) {
        counter ++;
        number = number >> 1;

    }
    return counter;
}

int main() {
    int zeros = trailingZeros(10000);
    printf("%d", zeros);
}