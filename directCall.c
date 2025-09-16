// Factorial?
#include <stdio.h>
int fact(int n)
{
    if (n == 1 || n == 0)
    {
        printf("fact(%d)=1\n", n);
        return 1;
    }
    printf("%d*fact(%d)\n", n, n - 1);
    return n * fact(n - 1);
}
int main()
{
    int n;
    printf("Enter the number = ");
    scanf("%d", &n);
    // printf("factorial of 5 :-\n");
    // for (int i = n; i >= 1; i--)
    // {
    //     printf("%d ", i);
    //     if (i != 1)
    //         printf("* ");
    // }
    // printf("\n");
    int factorial = fact(n);
    printf("= %d", factorial);

    return 0;
}
