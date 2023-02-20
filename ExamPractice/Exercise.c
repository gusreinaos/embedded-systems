#include <stdio.h>
#include <ctype.h>

//String exercises
#define MAX_LINE_LENGTH 1000

/* **********************************************************************
********************** BINARY EXERCISES *********************************
********************************************************************** */

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



/* **********************************************************************
********************** YEAR CALCULATION EXERCISE ************************
********************************************************************** */

/* 
    Overall, this algorithm works by repeatedly dividing the decimal number by 2 and storing the remainder (which is always 0 or 1) in the binary array, until the decimal number becomes 0. This process effectively "shifts" the decimal number 
    right by one bit at a time, while simultaneously constructing the binary representation of the number from right to left.
*/

/*
How to know if a year is leap or not (In the Gregorian calendar, a leap year occurs every 4 years, except for years that are divisible by 100 but not by 400. For example, 
the year 1900 was not a leap year, but the year 2000 was.)

(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) checks if the year is divisible by 4 and not by 100, or if it is divisible by 400. If either of these conditions is true, 
the expression evaluates to true; otherwise, it evaluates to false.: 
return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
*/

int is_leap_year(int year) {
    // Determine if a year is a leap year.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int day_of_year(int day, int month, int year) {
    // Calculate the day of the year for a given date.
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int is_leap = is_leap_year(year);
    int day_count = day;

    for (int i = 0; i < month - 1; i++) {
        day_count += days_in_month[i];
        if (is_leap && i == 1) {
            day_count += 1;  // Add an extra day for February in a leap year.
        }
    }

    return day_count;
}


/* **********************************************************************
********************** STRING EXERCISES *********************************
********************************************************************** */

int sentenceCounter() {
    char line[MAX_LINE_LENGTH];
    int num_chars = 0;
    int num_words = 0;
    int num_lines = 1;  // start at 1 to account for the first line

    printf("Enter text. Press Ctrl+D to end input.\n");
    //Fgets reads up to MAX_LINE_LENGTH characters or until it encounters a newline character
    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        int i = 0;
        int in_word = 0;

        while (line[i] != '\0') {
            if (isspace(line[i])) {
                if (in_word) {
                    num_words++;
                    in_word = 0;
                }
            } else {
                num_chars++;
                in_word = 1;
            }

            if (line[i] == '\n') {
                num_lines++;
            }

            i++;
        }
    }

    printf("Number of characters: %d\n", num_chars);
    printf("Number of words: %d\n", num_words);
    printf("Number of lines: %d\n", num_lines);

    return 0;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str);
    } else {
        for (int i = l; i <= r; i++) {
            swap((str+l), (str+i));
            permute(str, l+1, r);
            swap((str+l), (str+i)); // backtrack
        }
    }
}

void letterCounter(char *str, int l, int r) {
    int vowelCounter = 0;
    int consonantCounter = 0;
    while (l <= r) {
        if(str[l])
        

    }


}

int main() {
    char input[100];
    printf("Enter a sentence to analyse: \n");
    scanf("%c", input);
    letterCounter(input, 0, strlen(input) - 1);
}



