#include <stdio.h>
#include <string.h>

void sortString(char *str)
{
    int i, j, n = strlen(str);
    char temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (*(str+i) > *(str+j))
            {
                temp = *(str+i);
                *(str+i) = *(str+j);
                *(str+j) = temp;
            }
        }
    }
}

int checkAnagram(char *str1, char *str2)
{
    int i, n1 = strlen(str1), n2 = strlen(str2);
    if (n1 != n2)
        return 0;
    sortString(str1);
    sortString(str2);
    for (i = 0; i < n1; i++)
    {
        if (*(str1+i) != *(str2+i))
            return 0;
    }
    return 1;
}

int main()
{
    char str1[100], str2[100];
    printf("Input the first String : ");
    scanf("%s", str1);
    printf("Input the second String : ");
    scanf("%s", str2);
    if (checkAnagram(str1, str2))
        printf("The two strings are anagrams.\n");
    else
        printf("The two strings are not anagrams.\n");
    return 0;
}