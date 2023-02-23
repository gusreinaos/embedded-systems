#include <stdio.h>
#include <stdlib.h>

// Define the positions of the bits in the byte
#define ENGINE_ON_POS 7
#define FLOOR_POS_POS 4
#define DOOR_POS_POS 2
#define BRAKE1_POS 1
#define BRAKE2_POS 0

int main(int argc, char* argv[]) {
  // Check the number of arguments
  if (argc != 6) {
    printf("Usage: %s engine_on floor_pos door_pos brake1 brake2\n", argv[0]);
    return 1;
  }

  // Parse the arguments
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

  // Pack the values into a byte
  unsigned char status = 0;
  status |= engine_on << ENGINE_ON_POS;
  status |= floor_pos << FLOOR_POS_POS;
  status |= door_pos << DOOR_POS_POS;
  status |= brake1 << BRAKE1_POS;
  status |= brake2 << BRAKE2_POS;

  // Print the status in hexadecimal form
  printf("0x%02X\n", status);

  return 0;
}

/*
The program first checks the number of arguments, which should be 6 (the name of the program and 5 values). If the number is not correct, it prints an error message and returns 1.

Next, it parses the arguments using the atoi function, which converts a string to an integer. It also checks the validity of each argument: engine_on must be 0 or 1, floor_pos must be between 0 and 7, door_pos, brake1 and brake2 must be 0 or 1. If any argument is invalid, it prints an error message and returns 1.

Finally, it packs the values into a byte using bitwise operators (|= and <<) and prints the byte in hexadecimal form using the format specifier %02X, which prints the value in 2 digits with leading zeros if necessary.
*/

//FOR SETTING BINARY VALUES WE USE THE BITWISE OR OPERATOR

//FOR COMPARING OR CHECKING WE CAN USE THE AND BITWISE OPERATOR AND THEREFORE MASK THE VALUE 