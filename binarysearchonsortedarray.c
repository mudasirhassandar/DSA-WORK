#include <stdio.h>
int binarysearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("Enter the size of an Array = ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Sorted Array\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element = ", i + 1);
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the key you want to find = ");
    scanf("%d", &key);
    int result = binarysearch(arr, n, key);
    if (result == -1)
        printf("Key is not Found\n");
    else
    {
        printf("Key is founded at index = %d", result);
    }
    return 0;
}