#include <stdio.h>

void insertionsort(int n, int arr[])
{
    for (int i = 1; i <= n - 1; i++)
    {
        int j = i;

        while (j > 0 && arr[j] < arr[j - 1])
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
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