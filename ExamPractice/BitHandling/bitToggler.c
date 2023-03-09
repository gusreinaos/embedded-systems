#include <stdio.h>

int main()
{
    int num, n, new_num;
    
    // Input the number and nth bit
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter the nth bit to toggle (0-31): ");
    scanf("%d", &n);
    
    // Toggle the nth bit using bitwise XOR operator
    new_num = num ^ (1 << n);
    
    // Output the new number
    printf("After toggling the nth bit, the new number is: %d", new_num);
    
    return 0;
}