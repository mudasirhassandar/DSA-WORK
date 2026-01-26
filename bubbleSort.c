#include <stdio.h>
#include <stdbool.h>
void bubblesort(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flage = true;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flage = false;
            }
        }
        if (flage == true)
            break;
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

    bubblesort(n, arr);
    printf("\nSorted Array\n");
    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);
    }

    return 0;
}