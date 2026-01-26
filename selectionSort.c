#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
void insertionsort(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = INT_MAX;
        int minidx = -1;
        bool flage = true;
        for (int j = i; j <= n - 1; j++)
        {

            if (arr[j] < min)
            {
                min = arr[j];
                minidx = j;
            }
        }
        int temp = arr[minidx];
        arr[minidx] = arr[i];
        arr[i] = temp;
    }

    return;
}
int main()
{
    int n;
    printf("Enter the size of Array = ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element = ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Entered Array\n");
    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);
    }

    insertionsort(n, arr);
    printf("\nSorted Array\n");
    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);
    }

    return 0;
}