// Find the length of string?
#include <stdio.h>
#include <strings.h>
int len(char str[], int *count)
{
    int i = 0;
    while (str[i] != '\0')
    {
        (*count)++;
        i++;
    }
    return *count;
}
int main()
{
    char str[1000];
    printf("write a string:-\n");
    scanf("%[^\n]s", str);
    int count = 0;
    int lenght = len(str, &count);
    printf("Length of string = %d", lenght);

    return 0;
}
