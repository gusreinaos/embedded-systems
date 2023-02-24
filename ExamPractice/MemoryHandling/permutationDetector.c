
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 10

void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

/*
If the left index is not equal to the right index, the function enters a loop that generates all permutations of the substring that starts at the left index. 
The loop iterates over each character in the substring, and for each character, it swaps the character at the left index with the character at the current iteration index (i). 
Then, it recursively generates all permutations of the remaining substring (the substring that starts at the next index after the left index), by calling itself with the left index incremented by 1. 
Once the recursive call returns, the function swaps the characters back to their original positions, so that the next iteration of the loop can swap a different character.
By repeatedly swapping characters and recursively generating permutations of the remaining substring, the function generates all possible permutations of the original string.
*/

void permutationDetector(char* str, int left, int right) {
    if (left == right) {
        printf("%s  ", str);
    }
    else {
        for (int i = left; i <= right; i++) {
            swap((str + left), (str + i));
            permutationDetector(str, left + 1, right);
            swap((str + left), (str + i));
        }
    }
}

int main()
{
    char str[LENGTH];
    printf("String to analyse: ");
    fgets(str, LENGTH, stdin);
    
    // Remove the newline character at the end of the string
    str[strcspn(str, "\n")] = '\0';
    
    permutationDetector(str, 0, strlen(str) - 1);

    return 0;
}
