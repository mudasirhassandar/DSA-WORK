#include <stdio.h>
int Rbinarysearch(int arr[], int l, int h, int key)
{
    if (l == h)
    {
        if (arr[l] == key)
        {
            return l;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int mid = (l + h) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            return Rbinarysearch(arr, mid + 1, h, key);
        }
        else
        {
            return Rbinarysearch(arr, l, mid - 1, key);
        }
    }

    return -1;
}
int main()
{
    int n;
    printf("Enter the size of Array = ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the %d elements in sorted order\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element = ", i + 1);
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the element you want find = ");
    scanf("%d", &key);
    int index = Rbinarysearch(arr, 0, n, key);
    if (index != -1)
    {
        printf("Element is found at position %d", index + 1);
    }
    else
    {
        printf("Element is not Found..");
    }
    return 0;
}