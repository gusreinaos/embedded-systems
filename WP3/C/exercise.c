// (C) Juan García, Oscar Reina, Jan Manel, group: 19 (2023) 
// Work package 3
// Exercise 3.6
// Submission code: (provided by your TA-s) 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20
void copyString(char text[MAX], char copy2[MAX]);

int main (int argc, char *argv[]){

    //Declaration of the three arrays of chars
    char text[MAX];
    char copy1[MAX];
    char copy2[MAX];

    //Asking for input
    printf("Write something (max 20 char.): \n");

    // using gets method to get either CL input or text file
    gets(text);

    //Using strcpy() to copy the string from text to copy1
    strcpy(copy1,text);
    //Printing the result
    printf("%s\n",copy1);

    //Using copyString() to copy the string from text to copy2
    copyString(text, copy2);
    //Printing the result
    printf("%s\n",copy2);
    return 0;
}

void copyString(char text[MAX], char copy2[MAX]){
    //For loop that copies each element of text into copy2
    for (int i = 0; i < MAX; ++i)
    {
        copy2[i]=text[i];
    }
}