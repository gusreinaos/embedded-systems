#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]){
    // store binary value in integer variable
    int bin = atoi(argv[1]);

    // declare 
    int dec = 0, i = 1, res;

    while(bin != 0){
        res = bin %10;
        dec = dec + res * i;
        i = i * 2;
        bin = bin / 10;
    }

    printf("%X\n",dec);
    return 0;
}