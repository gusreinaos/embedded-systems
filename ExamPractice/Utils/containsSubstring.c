#include <stdio.h>
#include <stdlib.h>

int contains_substring(const char *stringone, const char*substring);

int main() {
    const char *string = "Hello World";
    const char *substring = "World";
    int position = contains_substring(string, substring);
    printf("Position: %d\n", position);
    return 0;

}

int contains_substring(const char *stringone, const char *substring) {
    int len = 0;
    while (substring[len] != '\0') {
        len++;
    }

    int i = 0;
    while (stringone[i] != '\0') {
        int j = 0;
        int counter = 0;
        while (substring[j] != '\0') {
            if (substring[j] != stringone[i + j]) {
                break;
            } else {
                counter++;
            }
            j++;
        }

        if (counter == len) {
            return i;
        }

        i++;
    }

    return -1;
}