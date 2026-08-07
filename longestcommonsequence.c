#include <stdio.h>
#include <string.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int main()
{
    char x[50], y[50];
    int L[50][50];
    int m, n;
    printf("Enter first string = ");
    scanf("%s", x);
    printf("Enter second string = ");
    scanf("%s", y);
    m = strlen(x);
    n = strlen(y);
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (x[i - 1] == y[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else
            {
                L[i][j] = max(L[i][j - 1], L[i - 1][j]);
            }
        }
    }
    printf("Length of LCS = %d", L[m][n]);
    return 0;
}