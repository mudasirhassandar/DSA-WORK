#include <stdio.h>
#include <strings.h>
int main()
{
    char str[1000];
    printf("write a string:-\n");
    scanf("%[^\n]s", str);
    //fgets(str, sizeof(str), stdin);
    puts("your string is :-");
    puts(str);

    return 0;
}
