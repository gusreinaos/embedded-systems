#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20

int countBits(int number)
{      
      // log function in base 2 
      // take only integer part
      return (int)log2(number)+1;
}

// Main function in the program, no program arguments supported
int main (int argc, char *argv[]) {
    
    long n = atoi(argv[1]);
    int bits = countBits(n);
    int a[SIZE];
	int i = 0;

	while (n>0)
	{
		a[i] = n % 2;
		i = i + 1;
		n = n / 2;
	}

	for (i--; i >= 0; i--)
		printf("%d", a[i]);
	printf("\n");
	return 0;
   
} 