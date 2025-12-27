#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *front = NULL;
node *rear = NULL;
void enqueue(int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed...\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;
    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void traversal()
{
    if (front == NULL)
    {
        printf("Queue is empty..\n");
    }
    else
    {
        printf("--QUEUE--\n");
        node *temp = front;
        while (temp != NULL)
        {
            printf("%d-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int dequeue()
{
    int a = -1;
    if (front == NULL)
    {
        printf("Queue is Empty....\n");
    }
    else
    {
        node *temp = front;
        front = front->next;
        a = temp->data;
        free(temp);
        if (front == NULL)
            rear = NULL;
    }
    return a;
}
int main()
{

    int n;
    printf("Enter the number no nodes = ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int value;
        printf("Enter data for %d node = ", i + 1);
        scanf("%d", &value);
        enqueue(value);
    }
    traversal();
    while (1)
    {
        int choice;
        printf("\nDo you want dequeue ?(1=YES,0=NO) = ");
        scanf("%d", &choice);
        if (choice == 0)
            break;
        int x = dequeue();
        if (x != -1)
        {
            printf("%d is Dequeued\n", x);
            traversal();
        }
    }
    return 0;
}