#include <stdio.h>

void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);

        if (i % 8 == 0) {
            printf(".");
        }
    }
}

/*
    Initialize a counter variable i to 0 to keep track of the current index of the binary array.
    In a while loop, check if the decimal number n is greater than 0. If n is 0 or negative, the loop will terminate because all the binary digits have been calculated.
    Calculate the remainder when n is divided by 2 (i.e., n % 2) and store the result in the binary array at index i. This is because the remainder when dividing by 2 will always be either 0 or 1, and these values represent the binary digits.
    Divide the decimal number n by 2 (i.e., n / 2) and store the result back into n. This is because each successive digit in the binary representation represents a division by 2, with the remainder representing the binary digit.
    Increment the counter variable i to move to the next index in the binary array.

*/


/* 
    Overall, this algorithm works by repeatedly dividing the decimal number by 2 and storing the remainder (which is always 0 or 1) in the binary array, until the decimal number becomes 0. This process effectively "shifts" the decimal number 
    right by one bit at a time, while simultaneously constructing the binary representation of the number from right to left.
*/

void decimalToBinaryNormal(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    int binary[32]; // assume 32-bit integers
    int i = 0;

    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main(int argc, char *argv[]) {
    unsigned int num = 100987987907097090;
    printBinary(num);
}

/*
How to know if a year is leap or not (In the Gregorian calendar, a leap year occurs every 4 years, except for years that are divisible by 100 but not by 400. For example, 
the year 1900 was not a leap year, but the year 2000 was.)

(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) checks if the year is divisible by 4 and not by 100, or if it is divisible by 400. If either of these conditions is true, 
the expression evaluates to true; otherwise, it evaluates to false.: 
return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
*/


