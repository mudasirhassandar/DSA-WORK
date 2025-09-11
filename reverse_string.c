// Find the length of string?
#include <stdio.h>
#include <strings.h>
int main()
{
    char str[1000];
    printf("write a string:-\n");
    scanf("%[^\n]s", str);
    puts("Entered string:-");
    puts(str);
    int count = 0;
    // Length of string?
    int k = 0;
    while (str[k] != '\0')
    {
        count++;
        k++;
    }
    puts("Reverse string:-");
    // reverse string?
    int i = 0;
    int j = count - 1;
    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    puts(str);
    return 0;
}
