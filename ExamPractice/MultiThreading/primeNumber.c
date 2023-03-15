#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void primeChecker(int num) {
    int i, isPrime = 1;

   //We check until the middle of the element if it is divisible by a number it means it is not prime
   for (i = 2; i <= num/2; ++i) {
      if (num % i == 0) {
         isPrime = 0;
         break;
      }
   }

   if (isPrime) {
      char* primeStr = "Prime";
      printf("%s\n", primeStr);
   }
   else {
      char* notPrimeStr = "Not Prime";
      printf("%s\n", notPrimeStr);
   }
}


int main(int argc, char *argv[]) {
    pthread_t pthreads[argc - 1];
    for(int i = 0; i < argc -1; i++) {
        pthread_create(&pthreads[i], NULL, primeChecker, (void *) atoi(argv[i + 1]));
    }

   //We need to use the join in another loop as we need to wait for every thread to be created
    for(int i = 0; i < argc -1; i++) {
        pthread_join(pthreads[i], NULL);
    }

    return 0;
}