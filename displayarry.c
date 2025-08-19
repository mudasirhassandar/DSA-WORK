// Display array using pointer?
#include <stdio.h>
int fun(int *size)
{
    *size = 5;
    return *size;
}
void display(int arr[], int size)
{
    fun(&size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return;
}

int main()
{
    int arr[20] = {1, 2, 3, 4, 5};
    int size = 0;
    display(arr, size);

    return 0;
}