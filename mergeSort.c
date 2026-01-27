#include <stdio.h>

    void merge(int brr[], int arr[], int low, int high, int mid)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            brr[k] = arr[i];
            i++;
        }
        else
        {
            brr[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left subarray
    while (i <= mid)
    {
        brr[k++] = arr[i++];
    }

    // Copy remaining elements of right subarray
    while (j <= high)
    {
        brr[k++] = arr[j++];
    }

    // Copy back to original array
    for (i = low; i <= high; i++)
    {
        arr[i] = brr[i];
    }
    return;
}



void mergesort(int brr[],int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(brr,arr, low, mid);
        mergesort(brr,arr, mid + 1, high);
        merge(brr,arr, low, high,mid);
    }
    return;
}
int main()
{
    int n;
    printf("Enter the size of array = ");
    scanf("%d", &n);
    int arr[n];
    int brr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element = ", 1 + i);
        scanf("%d", &arr[i]);
    }
    printf("\nEntered Array\n");
    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);
    }
    mergesort(brr,arr, 0, n - 1);
    printf("\nSorted Array\n");
    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);
    }
    return 0;
}