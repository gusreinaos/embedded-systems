// (C) Juan García, Oscar Reina, Jan Manel, group: 19 (2023) 
// Work package 1
// Exercise 1.4
// Submission code: 901234ER (provided by your TA-s) 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main(int argc, char* argv[]){

    //check if there is more than 1 argument
    if (argc != 2 ) {
        printf("In order to use this program, write cast it with only one positive integer\n");
        return 1;
    }

    //check if argument is -h
    else if(strcmp(argv[1], "-h") == 0){
        printf("In order to use this program, write cast it with only one positive integer\n");
        return 1;   
    }


    char *p;
    //we assign to the variable unsigned long number the value of the argument
    //p will point to the last char
    unsigned long number = strtoul(argv[1], &p, 10);

    //check if the argument is text and not a unsigned int
    if (*p != '\0') {
        printf("In order to use this program, write cast it with only one positive integer\n");
        return 1;
    }

    //if number is less than the max number supported by unsigned char we assign it to unsigned char
    if (number <= UCHAR_MAX) {
        unsigned char number= (unsigned char) number;
        
    } else if (number <= USHRT_MAX) {
        //same with unsigned short
        unsigned short number = (unsigned short) number;
        
    } else if (number <= UINT_MAX) {
        //same with unsigned int
        unsigned number = (unsigned int) number;
        
    } else {
        //same with unsigned long
        unsigned long number = number;
    }

    //we declare an array of size of the datatype of the number
    //and we fill it with 0
	int bin[sizeof(number)];
    for (int i = 0; i < sizeof(number); ++i)
    {
        bin[i]= 0;
    }

    int i = 0;
    //while the number is greater than 0 we add to the array the % 2
    while (number > 0) {
        bin[i] = number % 2;
        number = number / 2;
        i++;
    }
  
    //we print backwards the numbers of the array
    for (int j = sizeof(number)-1; j >= 0; j--){
        printf("%d", bin[j]);
    }
    printf("\n");
	return 0;
}