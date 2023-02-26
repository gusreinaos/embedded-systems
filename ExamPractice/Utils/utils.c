#include <stdio.h>

//Swap method
void swapMethod( int *x, int *y){
     int temp = *x;
     *x = *y;
     *y = temp;
}

int calculate_string_length(char* str) {
    int length = 0;

    // Loop through each character in the string
    while (*str != '\0') {
        length++;
        str++;
    }

    return length;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    int length = calculate_string_length(str);
    printf("Length of the string is: %d", length);

    return 0;
}

/* GENERAL COMMENTS */
//In summary, malloc() is used to dynamically allocate memory when the size of the object is not known at compile time, or when we want to create a variable that persists beyond the current scope.

