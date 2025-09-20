#include <stdio.h>
#include <string.h>
int main()
{
    char str1[1000];
    printf("Enter the frist string = ");
    fgets(str1, sizeof(str1), stdin);
    char str2[1000];
    printf("Enter the second string = ");
    fgets(str2, sizeof(str2), stdin);
    int i;
    for (i = 0; str1[i] != '\0'; i++);
        

    i--;
    str1[i] = ' ';
    i++;
    // i=strlen(str1)-1 ;
    for (int j = 0; str2[j] != '\0'; j++)
    {
        str1[i] = str2[j];

        i++;
    }
    str1[i] = '\0';
    puts("concatenate string:-");
    puts(str1);

    return 0;
}