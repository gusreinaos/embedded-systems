#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void binaryCounter(int number) {
    int zeroCounter = 0;
    int oneCounter = 0;
    for(int i = 31; i>= 0; i -- ){
        if(((number >> i) & 1) == 1) {
            oneCounter++;
        }
        else{
            zeroCounter++;
        }
        printf("%d", (number >> i) & 1);
    }
    printf("\n");
    printf("Number of zeros: %d \n", zeroCounter);
    printf("Number of ones: %d \n", oneCounter);

}

int main() {
    binaryCounter(22);
}