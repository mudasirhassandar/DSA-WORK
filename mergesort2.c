#include <stdio.h>
void mergesort(int a[], int b[], int c[], int n, int m)
{
    int i, j, k;
    i = j = k = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < n)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < m)
    {
        c[k] = b[j];
        j++;
        k++;
    }
}

int main()
{
    int n;
    printf("Enter the size of Frist array = ");
    scanf("%d", &n);
    int m;
    printf("Enter the size of Second array = ");
    scanf("%d", &m);
    int arr[n];
    int brr[m];
    int crr[n + m];
    printf("Enter frist Array\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element = ", 1 + i);
        scanf("%d", &arr[i]);
    }
    printf("Enter second Array\n");
    for (int i = 0; i < m; i++)
    {
        printf("Enter the %d element = ", 1 + i);
        scanf("%d", &brr[i]);
    }
    printf("\nFrist Entered Array\n");
    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);
    }
    printf("\nSecond Entered Array\n");
    for (int i = 0; i < m; i++)
    {

        printf("%d ", brr[i]);
    }

    mergesort(arr, brr, crr, n, m);
    printf("\nMerge Sorted Array\n");
    for (int i = 0; i < n + m; i++)
    {

        printf("%d ", crr[i]);
    }
    return 0;
}