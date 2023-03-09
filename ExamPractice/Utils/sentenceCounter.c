#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char input_string[MAX_LENGTH];
    int num_chars = 0, num_words = 0, num_lines = 0;
    int i;

    printf("Enter a string:\n");
    fgets(input_string, MAX_LENGTH, stdin);

    num_chars = strlen(input_string);

    for (i = 0; input_string[i] != '\0'; i++) {
        if (input_string[i] == ' ' || input_string[i] == '\t') {
            num_words++;
        }
        if (input_string[i] == '\n') {
            num_words++;
            num_lines++;
        }
    }

    if (num_chars > 0) {
        num_lines++;
    }

    printf("Number of characters: %d\n", num_chars);
    printf("Number of words: %d\n", num_words);
    printf("Number of lines: %d\n", num_lines);

    return 0;
}