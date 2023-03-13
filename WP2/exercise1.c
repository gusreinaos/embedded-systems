// (C) Juan García, Oscar Reina, Jan Manel, group: 19 (2023) 
// Work package 2 
// Exercise 2.4
// Submission code: 5556 (provided by your TA-s) 
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

// define direction enum and robot struct
enum DIRECTION {N,E,S,W}; 
 
typedef struct { 
        int xpos; 
        int ypos; 
        enum DIRECTION dir; 
} ROBOT; 

// declare functions
void turn(ROBOT *robot);
void move(ROBOT *robot);



int main (int argc, char *argv[]) {
    // declare variables to store direction, and user inputs for orders and coordinates
    enum DIRECTION dir = N;
    char orders[10];
    char coordinateString[5];

    // declare robot object
    ROBOT* robot;


    // requesting and storing user input
    printf("please input initial robot coordinates in the format <x,y> E.G. 30,06\n");
    scanf("%s", coordinateString);    

    // create robot instance
    robot = malloc(sizeof(ROBOT));

    //Entering robot position and direction
    robot -> xpos = (int) (coordinateString[0]-'0')*10 + (int)(coordinateString[1]-'0');
    robot -> ypos = (int)(coordinateString[3]-'0')*10 + (int)(coordinateString[4]-'0');
    robot -> dir = dir;
    

    // request orders
    printf("Orders ('-' to exit): ");
    scanf("%s", orders);


    while(orders[0]!='-'){
        //for every char of the orders
        for (int i = 0; i < strlen(orders); ++i)
        {
            switch(orders[i]){
                //if it's m call move
                case 'm':
                    move(robot);
                    break;
                //if its t call turn
                case 't':
                    turn(robot);
                    break;
            }
        }
        //print robot position
        printf("Robot postition: (%d,%d)\n", robot->xpos,robot->ypos);

        //request new robot position and store it
        printf("please input initial robot coordinates in the format <x,y> E.G. 30,06\n");
        scanf("%s", coordinateString);    
        robot -> xpos = (int) (coordinateString[0]-'0')*10 + (int)(coordinateString[1]-'0');
        robot -> ypos = (int)(coordinateString[3]-'0')*10 + (int)(coordinateString[4]-'0');
        //Input new orders
        printf("Orders: ");
        scanf("%s",orders);
    }

    return 0;
    
} 

void move(ROBOT* robot){

    switch(robot->dir){
        //If robot is facing north, we sum 1 to y
        case 0:
            robot->ypos++;
            break;
        //if robot is facing east, we sum 1 to x
        case 1:
            robot->xpos++;
            break;
        //if robot is facing south we substract 1 to y
        case 2:
            robot->ypos--;
            break;
        //if robot is facing west we substract 1 to x
        case 3:
            robot->xpos--;
            break;
    }
}


//we will sum 1 to the direction to face the next clow-wise direction
//in the case that the robot is facing west, we will assign to 0 to face north
void turn(ROBOT *robot){

    // switch case to turn robot 90 degrees making use of enum direction declared at beginning of file
    switch(robot->dir){
        case 3:
            robot->dir=0;
            break;
        default:
            robot->dir++;
            break;
    }
}

