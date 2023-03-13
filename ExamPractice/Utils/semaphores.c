#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAXNUMBER 10

sem_t sem1;
sem_t sem2; 
sem_t sem3;


void first_thread() {
    for(int i = 1; i <= MAXNUMBER; i++) {
        //Wait for permission
        sem_wait(&sem1);
        printf("thread #1: number %d\n", i);
        //Give permission
        sem_post(&sem2);
    }
}

void second_thread() {
    for(int i = 2; i <= MAXNUMBER; i++) {
        //Wait for permission
        sem_wait(&sem2);
        printf("thread #2: number %d\n", i);
        sem_post(&sem3);
    }
}

void third_thread() {
    for(int i = 3; i <= MAXNUMBER; i++) {
        //Wait for permission
        sem_wait(&sem3);
        printf("thread #3: number %d\n", i);
        sem_post(&sem1);
    }
}

int main()
{
    //Initialized to 1 as it is going to be the first ones in execute and the others are going to be waiting
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);
    
    //Initialize threads
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    
    //Create threads
    pthread_create(&thread1, NULL, first_thread, NULL);
    pthread_create(&thread2, NULL, second_thread, NULL);
    pthread_create(&thread3, NULL, third_thread, NULL);
    
    //Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    
    sem_destroy(&sem1);
    sem_destroy(&sem2);
    sem_destroy(&sem3);
    
    return 0;
}
