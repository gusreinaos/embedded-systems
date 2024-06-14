// (C) Juan García, Oscar Reina, Jan Manel, group: 19 (2023) 
// Work package 3
// Exercise 3.5
// Submission code: (provided by your TA-s) 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10
void main (int argc, char *argv[]){
    // declare array with size MAX
    int array[MAX];

    // declare pointer adress to be used in later print statements
    int *address = &array;

    // For loop to populate arrays with random numbers between 1 and 99
    for (int i = 0; i < MAX ; i++){
        array[i] = (rand() % 99) + 1;
    }

    // print statements as requested by exercise specification
    printf("The value of the address of the array (pointer) is:  %p\n", address);
    printf("First integer in the array is (array[0]):   %d\n", array[0]);
    printf("The last integer in the array is:   %d\n", array[MAX-1]);
    printf("The size of an integer (number of bytes) is: %zu\n", sizeof(int));
    printf("The size of the whole array in bytes is:  %d\n", sizeof(array));

    // for loop to print value of each element and its value when multiplied by 2 accesed with pointers
    // pointer is increased to access each element after every loop iteration
    for (int i = 0; i < MAX ; i++){
        printf("Value accessed by pointer: %i \n", *address);
        printf("Value times 2 accessed by pointer: %i \n", *address*2);
        address++;
    }
}