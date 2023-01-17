// (C) __Your names here, group: 123 __ (2022) 
// Work package 0 
// Exercise 1 
// Submission code: XXXXXX (provided by your TA-s) 
#include <stdio.h>
#include <string.h>

// Main function in the program, no program arguments supported
int main (int argc, char *argv[]) {
    if (argc != 2 ) {
        printf("In order to use this program, write ./a.out <YourName>");
    }else if(strcmp(argv[1], "-h") == 0){
        printf("In order to use this program, write ./a.out <YourName>");
    }else if (argc == 2){
        printf("Hello World! - I'm %s!\n", argv[1]);
    }
    return 0;
} 