// Copy the string into another string?
#include <stdio.h>
#include <strings.h>
void copy(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }
    return;
}
int main()
{
    char str1[1000];
    printf("write a string:-\n");
    scanf("%[^\n]s", str1);
    char str2[1000];
    copy(str1, str2);
    puts(str1);
    puts(str2);
    return 0;
}
