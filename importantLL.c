
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traversal(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty..");
    }
    struct node *temp = head;
    printf("\nEntered Lenked List\n\n");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int main()
{
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int n, value;
    printf("Enter the number nodes = ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for %d node = ", i + 1);
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    traversal(head);
    return 0;
}
