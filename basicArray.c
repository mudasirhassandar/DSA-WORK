#include <stdio.h>
void deletionbeg(int *x, int arr[])
{
    for (int i = 0; i < *x; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*x)--;
    return;
}
void deletionend(int *x, int arr[])
{
    (*x)--;
    return;
}
void inserationbeg(int *x, int arr[], int b)
{
    (*x)++;
    for (int i = *x; i >= 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = b;

    return;
}
void inserationend(int *x, int arr[], int a)
{
    (*x)++;
    arr[*x - 1] = a;
    return;
}
void display(int x, int arr[])
{
    printf("New array:-\n");
    for (int i = 0; i < x; i++)
    {
        printf("%d,", arr[i]);
    }
}
int main()
{
    int x;
    printf("Enter the number of elements you want in array = ");
    scanf("%d", &x);
    int arr[100];
    for (int i = 0; i < x; i++)
    {
        printf("Enter the %d element = ", i + 1);
        scanf("%d", &arr[i]);
    }
    int operation;
    printf("Which operation you want = \n");
    printf(" 1) Inseration at end\n");
    printf(" 2) Inseration at begning\n");
    printf(" 3) deletion at end\n");
    printf(" 4) deletion at begning\n");
    printf("Enter = ");
    scanf("%d", &operation);
    int a;
    int b;
    switch (operation)
    {
    case 1:
        printf("Enter the element you want insert at end =  ");
        scanf("%d", &a);
        inserationend(&x, arr, a);
        display(x, arr);
        break;
    case 2:
        printf("Enter the element you want insert at begning =  ");
        scanf("%d", &b);
        inserationbeg(&x, arr, b);
        display(x, arr);
        break;
    case 3:
        printf("Deleted element is %d \n", arr[x - 1]);
        deletionend(&x, arr);
        display(x, arr);
        break;
    case 4:
        printf("Delete element is %d\n", arr[0]);
        deletionbeg(&x, arr);
        display(x, arr);
        break;

    default:
        printf("Invalid operation\n");
        break;
    }

    return 0;
}