#include <stdio.h>
void deletionatk(int *x, int arr[], int k)
{
    for (int i = k; i < *x; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*x)--;
    return;
}
void insertionatk(int *x, int arr[], int a, int k)
{
    (*x)++;
    for (int i = *x - 1; i >= k; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[k] = a;
    return;
}
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
void insertionbeg(int *x, int arr[], int b)
{
    (*x)++;
    for (int i = *x; i >= 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = b;

    return;
}
void insertionend(int *x, int arr[], int a)
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
    printf("\n\n");
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
    while (1)
    {
        int operation;
        printf("Which operation you want = \n");
        printf(" 1) Insertion at end\n");
        printf(" 2) Insertion at begning\n");
        printf(" 3) deletion at end\n");
        printf(" 4) deletion at begning\n");
        printf(" 5) insertion at anywhere\n");
        printf(" 6) deletion at anywhere\n");
        printf(" 0) Exit loop\n");
        printf("Enter = ");
        scanf("%d", &operation);
        if (operation == 0)
        {
            printf("Loop exited");
            break;
        }
        int a;
        int b;
        int k;
        switch (operation)
        {
        case 1:
            printf("Enter the element you want insert at end =  ");
            scanf("%d", &a);
            insertionend(&x, arr, a);
            display(x, arr);
            break;
        case 2:
            printf("Enter the element you want insert at begning =  ");
            scanf("%d", &b);
            insertionbeg(&x, arr, b);
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
        case 5:
            printf("Where you want to insert element = ");
            scanf("%d", &k);
            k = k - 1;
            printf("Enter the element you want insert  =  ");
            scanf("%d", &a);
            insertionatk(&x, arr, a, k);
            display(x, arr);
            break;
        case 6:
            printf("Where you want to delete element = ");
            scanf("%d", &k);
            k = k - 1;
            printf("Delete element is %d\n", arr[k]);
            deletionatk(&x, arr, k);
            display(x, arr);
            break;
        default:
            printf("Invalid operation\n");
            break;
        }
    }
    return 0;
}