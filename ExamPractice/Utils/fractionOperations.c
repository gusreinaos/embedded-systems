#include <stdio.h>

double addFraction(int a, int b, int c, int d) {
    return ((double)a/b + (double)c/d);
}


double subFraction(int a, int b, int c, int d) {
    return ((double)a * d - b * c) / ((double)c * d);
}

double multFraction(int a, int b, int c, int d) {
    return ((double)a * c) / ((double)b * d);
}


int main()
{
    
    double result = addFraction(1, 2, 1, 4);
    printf("%.2f", result);
    return 0;
}
