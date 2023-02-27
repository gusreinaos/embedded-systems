#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {

    // Check the number of arguments
    if (argc != 6) {
        printf ("Usage: %s engine_on floor_pos door_pos brake1 brake2\n",
            argv[0]);
        return 1;
    }
    
    int engine_on = atoi(argv[1]);
    int floor_pos = atoi(argv[2]);
    int door_pos = atoi(argv[3]);
    int brake1 = atoi(argv[4]);
    int brake2 = atoi(argv[5]);
    
    // Check the validity of the arguments
    if (engine_on != 0 && engine_on != 1) {
        printf("Error: engine_on must be 0 or 1\n");
        return 1;
    }
    if (floor_pos < 0 || floor_pos > 7) {
        printf("Error: floor_pos must be between 0 and 7\n");
        return 1;
    }
    if (door_pos != 0 && door_pos != 1) {
        printf("Error: door_pos must be 0 or 1\n");
        return 1;
    }
    if (brake1 != 0 && brake1 != 1) {
        printf("Error: brake1 must be 0 or 1\n");
        return 1;
    }
    if (brake2 != 0 && brake2 != 1) {
        printf("Error: brake2 must be 0 or 1\n");
        return 1;
    }

    //Construimos un byte de derecha a izquierda echando los elementos hacie la cabeza del byte
    //Empujamos el valor << tantas posiciones
    
    //We define the byte as 0 so that in binary it is 0 therefore we can set all of the new values better
    //We set the value engine_on from the 0 value and shifting 7 positions to the left as it only takes one bit
    unsigned char byte = 0;
      byte |= engine_on << 7;
      byte |= floor_pos << 4;
      byte |= door_pos << 3;
      byte |= brake1 << 1;
      byte |= brake2 << 0;
    
    printf("0x%02X\n", byte);

    return 0;

}
//One byte starts counting from 0 until 7 giving 8 SPACES

/*
The program first checks the number of arguments, which should be 6 (the name of the program and 5 values). If the number is not correct, it prints an error message and returns 1.

Next, it parses the arguments using the atoi function, which converts a string to an integer. It also checks the validity of each argument: engine_on must be 0 or 1, floor_pos must be between 0 and 7, door_pos, brake1 and brake2 must be 0 or 1. If any argument is invalid, it prints an error message and returns 1.

Finally, it packs the values into a byte using bitwise operators (|= and <<) and prints the byte in hexadecimal form using the format specifier %02X, which prints the value in 2 digits with leading zeros if necessary.
*/

//FOR SETTING BINARY VALUES WE USE THE BITWISE OR OPERATOR

//FOR COMPARING OR CHECKING WE CAN USE THE AND BITWISE OPERATOR AND THEREFORE MASK THE VALUE 