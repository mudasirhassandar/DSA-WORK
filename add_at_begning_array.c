// add an element at begning of the array ?

#include <stdio.h>
void add(int arr[], int *size) {
    int brr[6] = {0,1, 2, 3, 4, 5};
    for (int i = 0; i < 6; i++) {
        arr[*size] = brr[i];
        (*size)++;
    }
}
void display(int arr[], int size)
{
    add(arr,&size);
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