#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAXNUMBER 20

sem_t sem1, sem2, sem3;

void* thread1(void* arg) {
    int i = 1;
    while (i <= MAXNUMBER) {
        sem_wait(&sem1);
        printf("thread #1: number %d\n", i);
        sem_post(&sem2);
        i += 3;
    }
    pthread_exit(NULL);
}

void* thread2(void* arg) {
    int i = 2;
    while (i <= MAXNUMBER) {
        sem_wait(&sem2);
        printf("thread #2: number %d\n", i);
        sem_post(&sem3);
        i += 3;
    }
    pthread_exit(NULL);
}

void* thread3(void* arg) {
    int i = 0;
    while (i <= MAXNUMBER) {
        sem_wait(&sem3);
        printf("thread #3: number %d\n", i);
        sem_post(&sem1);
        i += 3;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2, t3;
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);
    pthread_create(&t3, NULL, thread3, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    sem_destroy(&sem1);
    sem_destroy(&sem2);
    sem_destroy(&sem3);
    return 0;
}