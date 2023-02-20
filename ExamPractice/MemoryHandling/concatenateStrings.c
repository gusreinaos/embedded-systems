#include <stdio.h>
#include <stdlib.h>

char* concatenateStrings(char* str1, char* str2){ 
    
    int len1 = 0; 
    int len2 = 0;
    //'\0' indicates termination of the array of chars as it is located in the last position of it
    while(str1[len1] != '\0') len1++;
    while(str2[len2] != '\0') len2++;

    //Adding one since we need space for the last character of the array
    char* result = malloc((len1 + len2 + 1) * sizeof(char));

    int i, j;
    for (i = 0; i < len1; i++) {  // copy characters of first string to result string
        result[i] = str1[i];
    }
    for (j = 0; j < len2; j++) {  // copy characters of second string to result string
        result[i + j] = str2[j];
    }
    result[i + j] = '\0';  // add null character at end of result string

    return result;

}

//Every time we want to do memory allocation in a dynamic away we need to know how much memory, so we need to figure out the length of things beforehand
int main(){
    char str1[50], str2[50];
    printf("Input string1: ");
    fgets(str1, 50, stdin);
    printf("Input string2: ");
    fgets(str2, 50, stdin);

    char* result = concatenateStrings(str1, str2);
    printf("Concatenated string: %s", result);

    free(result);  // free dynamically allocated memory
    return 0;
}