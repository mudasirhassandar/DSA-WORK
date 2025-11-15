#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *insertionatend(struct node *head, int y)
{
    struct node *temp = head;
    struct node *element = (struct node *)malloc(sizeof(struct node));
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    element->data = y;
    element->next = NULL;
    element->prev = temp;
    temp->next = element;
    printf("Inserted element is = %d\n", y);
    return head;
}
struct node *insertionatbegining(struct node *head, int x)
{
    struct node *element = (struct node *)malloc(sizeof(struct node));
    element->data = x;
    struct node *temp = head;
    head = element;
    element->next = temp;
    element->prev = NULL;
    temp->prev = element;

    printf("Inserted element is = %d\n", x);
    return head;
}
struct node *insertionatanypoint(struct node *head, int z, int index)
{
    if (index == 1)
    {
        return insertionatbegining(head, z);
    }
    struct node *temp = head;
    int i = 1;
    while (i < index - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL)
    {
        return insertionatend(head, z);
    }
    struct node *element = (struct node *)malloc(sizeof(struct node));
    element->data = z;
    element->next = temp->next;
    temp->next->prev = element;
    temp->next = element;
    element->prev = temp;
    printf("Inserted element is = %d\n", z);
    return head;
}
void traversal(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty.....");
        return;
    }
    printf("Linked List \n");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Reverse Linked List\n");

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->prev;
    }
    printf("NULL");
    printf("\n");

    return;
}
int main()
{
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    struct node *fourth = NULL;
    struct node *fifth = NULL;
    struct node *sixth = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40;
    fifth->data = 50;
    sixth->data = 60;
    head->prev = NULL;
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;
    fifth->next = sixth;
    sixth->prev = fifth;
    sixth->next = NULL;
    traversal(head);
    int x;
    printf("Enter the element you want to insert at begining = ");
    scanf("%d", &x);
    head = insertionatbegining(head, x);
    traversal(head);
    int y;
    printf("Enter the element you want to insert at end = ");
    scanf("%d", &y);
    head = insertionatend(head, y);
    traversal(head);
    int index;
    printf("Enter the index (frist position = index 1) = ");
    scanf("%d", &index);
    int z;
    printf("Enter the element you want to insert at position %d = ", index);
    scanf("%d", &z);
    head = insertionatanypoint(head, z, index);
    traversal(head);
    return 0;
}
