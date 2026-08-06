#include <stdio.h>
void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k] = arr[i];
        k++;
        j++;
    }
    for (int i = 0; i <= high; i++)
    {
        arr[i] = temp[i];
    }
    return;
}
void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    return;
}
int main()
{
    int n;
    printf("Enter the size of Array = ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the Elements of array\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element =  ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Entered Array\n");
    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);
    }
    mergesort(arr, 0, n - 1);
    printf("\nSorted Array\n");
    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);
    }
    return 0;
}