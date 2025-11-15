#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void traversal(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty.....");
        return;
    }
    printf("Linked List \n");
    struct node *temp = head;
    do
    {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("Back to head");
    printf("\n");
    temp = head->prev;

    printf("Reverse Linked List\n");
    do
    {
        printf("%d->", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);

    printf("Back to head");
    printf("\n");

    return;
}
struct node *insertionatend(struct node *head, int y)
{
    struct node *element = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head->prev;
    element->data = y;
    temp->next = element;
    element->prev = temp;
    element->next = head;
    head->prev = element;
    printf("Enter element is = %d\n", y);
    return head;
}
struct node *insertionatbegining(struct node *head, int x)
{
    struct node *element = (struct node *)malloc(sizeof(struct node));
    element->data = x;
    element->prev = head->prev;
    head->prev->next = element;
    element->next = head;
    head->prev = element;
    head = element;
    printf("Entered element is = %d\n", x);
    return head;
}
struct node *insertionatanypoint(struct node *head, int z, int index)
{
    if (index == 1)
    {
        return insertionatbegining(head, z);
    }
    struct node *element = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    element->data = z;
    int i = 1;
    while (i < index - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == head)
    {
        return insertionatend(head, z);
    }
    element->next = temp->next;
    temp->next->prev = element;
    temp->next = element;
    element->prev = temp;
    printf("Inserted element is = %d\n", z);
    return head;
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
    head->prev = sixth;
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
    sixth->next = head;
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
    printf("Enter the index (index 1 = position of element will be frist) = ");
    scanf("%d", &index);
    int z;
    printf("Enter the element you want to insert at %d = ", index);
    scanf("%d", &z);
    head = insertionatanypoint(head, z, index);
    traversal(head);
    return 0;
}
