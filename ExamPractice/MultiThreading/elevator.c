#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MIN_FLOOR 0
#define MAX_FLOOR 15

int current_floor = 0;
int destination_floor = 0;
int is_moving = 0;

void *elevator(void *arg) {
    int floors = *(int*)arg;
    clock_t start_time = clock();

    for (int i = 0; i < floors; i++) {
        is_moving = 1;
        printf("Moving from floor %d to floor %d\n", current_floor, i + 1);
        while (clock() < start_time + CLOCKS_PER_SEC);
        current_floor = i + 1;
        printf("Arrived at floor %d\n", current_floor);
    }
    is_moving = 0;
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number of floors>\n", argv[0]);
        return 1;
    }

    int num_floors = atoi(argv[1]);

    if (num_floors < 1 || num_floors > MAX_FLOOR) {
        printf("Number of floors must be between 1 and %d\n", MAX_FLOOR);
        return 1;
    }

    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, elevator, &num_floors);

    while (1) {
        if (!is_moving) {
            printf("Waiting for user...\n");
            scanf("%d", &destination_floor);
            if (destination_floor == current_floor) {
                printf("Already at floor %d\n", current_floor);
            } else if (destination_floor < MIN_FLOOR || destination_floor > num_floors) {
                printf("Invalid floor\n");
            } else {
                pthread_cancel(elevator_thread);
                pthread_join(elevator_thread, NULL);
                int diff = abs(destination_floor - current_floor);
                pthread_create(&elevator_thread, NULL, elevator, &diff);
            }
        } else {
            printf("Moving to floor %d...\n", destination_floor);
        }
    }

    return 0;
}
/*
This code creates two threads: the main thread, which waits for user input and controls the elevator movement, and the child thread, which simulates the elevator moving between floors.

The elevator function takes a single argument floors, which is the number of floors the elevator should travel. It uses a loop to move the elevator to each floor, and prints a message when it arrives at each floor. It also sets the is_moving flag to 0 when it has finished moving.

The main function first checks
*/
