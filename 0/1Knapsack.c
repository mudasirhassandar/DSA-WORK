#include <stdio.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int knapsack(int profit[], int weight[], int capacity, int n)
{
    int k[50][50];
    int i,j;
    for ( i = 0; i <= n; i++)
    {
        for ( j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                k[i][j] = 0;
            else if (weight[i-1] <= j)
                k[i][j] = max(profit[i - 1]+k[i-1][j-weight[i-1]],k[i-1][j]);
                else{
                    k[i][j]=k[i-1][j];
                }
        }
    }
    return k[n][capacity];
}
int main()
{
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int capacity = 50;
    int n = 3; // number od items;
    int maximumprofit = knapsack(profit, weight, capacity, n);
    printf("Maximum Profit = %d",maximumprofit);
}