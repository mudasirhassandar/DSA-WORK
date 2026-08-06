#include <stdio.h>
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high + 1;
    while (i < j)
    {
        do
        {
            i++;
        } while (i <= high && arr[i] <= pivot);
        do
        {
            j--;
        } while (j >= low && arr[j] > pivot);
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    return j;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int j = partition(arr, low, high);
        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
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
    printf("\nEntered Array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    quicksort(arr, 0, n - 1);
    printf("\nSorted Array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}