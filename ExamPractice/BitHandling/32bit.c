#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_bin(int number) {
    for (int i = 31; i >= 0; --i)
    {
        int bit = (number >> i) & 1;
        
        printf("%i", bit);

        if (i % 8 == 0 && i!= 0)
        {
            printf(".");
        }
    }
}

int main() {
    print_bin(15);
}