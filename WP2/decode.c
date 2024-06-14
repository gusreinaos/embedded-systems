// (C) Juan García, Oscar Reina, Jan Manel, group: 19 (2023) 
// Work package 2 
// Exercise 2.4
// Submission code: 5556 (provided by your TA-s) 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main (int argc, char *argv[]){
    // ensure user inputs function + 5 field values
    if (argc != 2 ) {
        printf("In order to use this program, write:\n ./decode.c <Number In Hexadecimal Base>, max is FF");
        return;
    }

    // check if argument length is faulty
    int length = strlen(argv[1]);

    // if argument is faulty close program
    if (length < 1 || length > 2){
        printf("user input is faulty, closing program a");
        return;
    }

    // store number depending on length
    char hex[2];
    // here i use array positions to store numbers in array of char length 2
    // if number only has one "digit" store in second position
    if (length == 1){
        hex[0] = '0';
        hex[1] = argv[1][0];

    // if number has 2 "digits" store in positions 1 and 2
    } else {
        hex[0] = argv[1][0];
        hex[1] = argv[1][1];
    }
    
    
    // variables for decimal conversion
    int decimal;
    
    // store ascii values of hexadecimal characters of user input
    int ascii [2];
    ascii[0] = (int) hex[0];
    ascii[1] = (int) hex[1];

    // convert first position

    // the value of the second "digit" in hexadecimal is multiplied by 16 and added to decimal
    // if value is between numbers 0 and 9, multiply directly
    if (ascii[0] >= 48 && ascii[0] <= 57){
        decimal = 16 * (ascii[0]-48);
    // if value is in letters from A to F, multiply by their correct value from (10-15)
    } else if (ascii[0] >= 65 && ascii[0] <= 70){
        decimal = 16 * (ascii[0] - 55);
    // if value is not hexadecimal 0-9 or A-F, close program
    } else {
        printf("user input is faulty, closing program %i", ascii[0]);
        return;
    }

    // convert second position

    // the value of the first "digit" in hexadecimal is multiplied by 1 and added to decimal
    // if value is between numbers 0 and 9, multiply directly
    if (ascii[1] >= 48 && ascii[1] <= 57){
        decimal =  decimal + ascii[1] - 48;
    // if value is in letters from A to F, multiply by their correct value from (10-15)
    } else if (ascii[1] >= 65 && ascii[1] <= 70){
        decimal = decimal + (ascii[1] - 55);
    // if value is not hexadecimal 0-9 or A-F, close program
    } else {
        printf("user input is faulty, closing program");
        return;
    }

    // declare variables to store decoded values
    int engine_on;
    int gear_pos;
    int key_pos;
    int brake1;
    int brake2;

    // decode extracting decimal value based on bit position

    // if decimal variable contains 128 or larger value, engine_on must be 1, otherwise 0
    if (decimal >= 128){
        engine_on = 1;
        decimal -= 128;
    } else{
        engine_on = 0;
    }

    // same process is applied for gear_pos, where the values correspond as such
    // >= 64  -> gear_pos = 4
    // >= 48  -> gear_pos = 3
    // >= 32  -> gear_pos = 2
    // >= 16  -> gear_pos = 1
    // else   -> gear_pos = 0
    if (decimal >= 64){
        gear_pos = 4;
        decimal -= 64;
    } else if (decimal >= 48){
        gear_pos = 3;
        decimal -= 48;
    } else if (decimal >= 32){
        gear_pos = 2;
        decimal -= 32;
    } else if (decimal >= 16){
        gear_pos = 1;
        decimal -= 16;
    } else {
        gear_pos = 0;
    }

    // same process is applied for key_pos
    // >= 8  -> key_pos = 2
    // >= 4  -> key_pos = 1
    // else  -> key_pos = 0
    if (decimal >= 8){
        key_pos = 2;
        decimal -= 8;
    } else if (decimal >= 4){
        key_pos = 1;
        decimal -= 4;
    } else{
        key_pos = 0;
    }

    // same process applied to brake1
    // >= 2  -> brake1 = 1
    // else  -> brake1 = 0
    if (decimal >= 2){
        brake1 = 1;
        decimal -= 2;
    } else {
        brake1 = 0;
    }

    // same process applied to brake2
    // >= 1  -> brake2 = 1
    // else  -> brake2 = 0
    if (decimal > 0){
        brake2 = 1;
    } else {
        brake2 = 0;
    }

    //print values in format requested by exercise
    printf("Name                 Value    \n");
    printf("----------------------------- \n");
    printf("engine_on            %i\n",engine_on);
    printf("gear_pos             %i\n",gear_pos);
    printf("key_pos              %i\n",key_pos);
    printf("brake1               %i\n",brake1);
    printf("brake2               %i\n",brake2);

    return;
    
}