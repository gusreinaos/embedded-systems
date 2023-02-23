#include <stdio.h>
#include <string.h>

void sortString(char* str) {
    int n = strlen(str);

    // Bubble sort the string
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (*(str+j) > *(str+j+1)) {
                char temp = *(str+j);
                *(str+j) = *(str+j+1);
                *(str+j+1) = temp;
            }
        }
    }
}

int areAnagrams(char* str1, char* str2) {
    int n1 = strlen(str1);
    int n2 = strlen(str2);

    // If strings are of different length, they cannot be anagrams
    if (n1 != n2) {
        return 0;
    }

    // Sort both strings
    sortString(str1);
    sortString(str2);

    // Compare sorted strings
    for (int i = 0; i < n1; i++) {
        if (*(str1+i) != *(str2+i)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    if (areAnagrams(str1, str2)) {
        printf("%s and %s are anagrams.\n", str1, str2);
    } else {
        printf("%s and %s are not anagrams.\n", str1, str2);
    }

    return 0;
}