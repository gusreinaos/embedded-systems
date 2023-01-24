#include<stdio.h>

int main(int argc, char *argv[]) {

    int binaryNumber = argv[1];
    int count;

    printf ("Introduce the number you wanna convert to binary: \n");
	scanf_s("%i\n", &binaryNumber);

    int num = 12;
    int bin;
    power = 0;

    for(i=0;num>0;i++){
        bin[i]=n%2;
        num=num/2;
    }

    printf("\nBinary of Given Number is=");

    for(i=i-1;i>=0;i--){
        printf("%d",bin[i]);
    }
	return 0;
}