// (C) Juan García, Oscar Reina, Jan Manel, group: 19 (2023) 
// Work package 2 
// Exercise 2.4
// Submission code: 5556 (provided by your TA-s) 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void main (int argc, char *argv[]){
    // ensure user inputs function + 5 field values
    if (argc != 6 ) {
        printf("In order to use this program, write:\n ./code.c <engine_on> <gear_pos> <key_pos> <brake1> <brake2>");
    }
    // declare integer to store user input
    unsigned int number = 0;

    // extract 5 arguments and store in their place
    int engine_on = atoi(argv[1]);
    int gear_pos = atoi(argv[2]);
    int key_pos = atoi(argv[3]);
    int brake1 = atoi(argv[4]);
    int brake2 = atoi(argv[5]);

    // check that arguments are within accepted ranges
    if (engine_on != 1 && engine_on != 0){
        printf("user input for engine_on is faulty, closing program");
        return;
    } else if (gear_pos != 4 && gear_pos != 3 && gear_pos != 2 && gear_pos != 1 && gear_pos != 0){
        printf("user input for gear_pos is faulty, closing program");
        return;
    } else if (key_pos != 2 && key_pos != 1 && key_pos != 0){
        printf("user input for key_pos is faulty, closing program");
        return;
    } else if (brake1 != 1 && brake1 != 0){
        printf("user input for brake1 is faulty, closing program");
        return;
    } else if (brake2 != 1 && brake2 != 0){
        printf("user input for brake2 is faulty, closing program");
        return;
    } else if ( !isdigit(argv[1][0]) || !isdigit(argv[2][0]) ||  !isdigit(argv[3][0]) ||  !isdigit(argv[4][0]) ||  !isdigit(argv[5][0]) ){
            printf("All arguments must be a number.\n");
            return;
    }

    // encode converting into integer

    // this algorithm adds the integer value corresponding to the bit position, E.G.
    // A 1 in bit 7 is worth 128 and so on

    // 7th bit values
    number += 128 * (engine_on);

    //6th, 5th, 4th bit values
    if (gear_pos == 4){
        number += 64;
    } else if (gear_pos == 3){
        number += 48;
    } else if(gear_pos == 2){
        number += 32;
    } else if (gear_pos == 1){
        number += 16;
    }

    // 3rd and 2nd bit value
    if (key_pos == 2){
        number += 8;
    } else if (key_pos == 1){
        number += 4;
    } 
    // 1st bit value
    number+= 2 * brake1;

    // 0th bit value
    number += brake2;

    // cast binary value to char and store it in char_value
    unsigned char char_value = (unsigned char)number;
    
    // algorithm that prints each bit to showcase how it is encoded (only for demonstration purposes)
    int bits[8];
    // for each of the 8 positions
    for (int i = 7 ; i != -1 ; i--) {
        // mask and save it to bits
        bits[i] = (char_value & (1 << i)) != 0;
        // print the specific bit
        printf("%i", bits[i]);
    }
    
    // statement to print in hexadecimal format
    printf("\n%X\n", number);
    
}