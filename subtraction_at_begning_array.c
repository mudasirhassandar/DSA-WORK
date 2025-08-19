//subtraction of element at begning 
#include <stdio.h>
void subtract(int arr[], int *size)
{
    int brr[6] = {2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 6; i++)
    {
        arr[*size] = brr[i];
        *size = *size + 1;
    }
    return;
}
void display(int arr[], int size)
{
    subtract(arr, &size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return;
}
int main()
{
    int arr[20] = {1, 2, 3, 4, 5, 6, 7};
    int size = 0;
    display(arr, size);
    return 0;
}