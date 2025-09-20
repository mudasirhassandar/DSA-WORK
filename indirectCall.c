#include <stdio.h>
int f(int n);
int g(int n);
int g(int n)
{
    printf("g(%d)=%d-f(%d)\n", n, n, n - 2);
    if (n <= 0)
        return 2;
    else
        return n - f(n - 2);
}
int f(int n)
{
    printf("f(%d)=%d*g(%d)\n", n, n, n - 1);
    if (n <= 0)
        return 1;
    else
        return n * g(n - 1);
}
int main()
{
    int n;
    printf("Enter the number = ");
    scanf("%d", &n);
    int fn = f(n);
    printf("->> f(%d)=%d\n\n", n, fn);
    int gn = g(n);
    printf("->> g(%d)=%d", n, gn);
    return 0;
}
