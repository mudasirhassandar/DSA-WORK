// sum of the elements of the array?
#include <stdio.h>
int fun(int x, int arr[], int *sum)
{
    for (int i = 0; i < x; i++)
    {
        *sum = *sum + arr[i];
    }
    return *sum;
}
int main()
{
    int x;
    printf("Enter the size of your array = ");
    scanf("%d", &x);
    int arr[x];
    for (int i = 0; i < x; i++)
    {
        printf("Enter the %d element of array\n", i + 1);
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    fun(x, arr, &sum);
    printf("Sum of your elements = %d", sum);
    return 0;
}