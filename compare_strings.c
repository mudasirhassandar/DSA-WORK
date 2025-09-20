#include <stdio.h>
#include <string.h>
int main()
{
    char str1[1000];
    printf("write firts string:-\n");
    fgets(str1, sizeof(str1), stdin);
    char str2[1000];
    printf("Enter second string;-\n");
    fgets(str2, sizeof(str2), stdin);
    // printf("Frist string :-\n");
    // puts(str1);
    // printf("second string :-\n");
    // puts(str2);
    int result = 0;
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
    {

        if (str1[i] != str2[i])
        {
            result = str1[i] - str2[i];
            break;
        }
    }
    if (result == 0)
        printf("Strings are equal");
    else if (result > 0)
        printf("String frist is greater than string second");
    else
        printf("String second is greater than string first");
    return 0;
}
