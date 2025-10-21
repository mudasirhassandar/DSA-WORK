// insertion in circulare linked list .
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;          // data part
    struct node *next; // stores the address of next node.
};
void traversal(struct node *head)
{

    struct node *current = head;
    if (current == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    // printing the linked list.
    printf("Circular Linked list:\n");
    do
    {
        printf("%d->", current->data);
        current = current->next;
    } while (current != head);
    printf("(Back to head)");
    printf("\n");
    return;
}
struct node *insertionatbegining(struct node *head, int x)
{
    struct node *insert = (struct node *)malloc(sizeof(struct node));
    insert->data = x;
    if (head == NULL)
    {
        insert->next = insert;
        return insert;
    }

    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = insert;
    insert->next = head;
    head = insert;

    return head;
}
struct node *insertionatend(struct node *head, int y)
{
    struct node *insert = (struct node *)malloc(sizeof(struct node));
    insert->data = y;
    if (head == NULL)
    {
        insert->next = insert;
        return insert;
    }

    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = insert;
    insert->next = head;
    return head;
}
struct node *insertionatanypoint(struct node *head, int index, int z)
{
    if (index == 1)
    {
        return insertionatbegining(head, z);
    }
    struct node *insert = (struct node *)malloc(sizeof(struct node));
    insert->data = z;
    struct node *p = head;
    int i = 1;
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    if (p->next == head)
    {
        return insertionatend(head, z);
    }
    insert->next = p->next;
    p->next = insert;
    return head;
}
int main()
{
    // ceration of nodes.
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    struct node *fourth = NULL;
    struct node *fifth = NULL;
    // allocating memory for node in heap.
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    // assign data.
    head->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40;
    fifth->data = 50;
    // connecting nodes.
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;
    traversal(head);
    int x;
    printf("Enter the element you want to insert at begning = ");
    scanf("%d", &x);
    printf("Entered element is %d\n", x);
    head = insertionatbegining(head, x);
    traversal(head);
    int y;
    printf("Enter the element you want to insert at end = ");
    scanf("%d", &y);
    printf("Entered element is %d\n", y);
    head = insertionatend(head, y);
    traversal(head);
    int index;
    printf("Enter the index where you want to insert the element (Index of first element is 1) = ");
    scanf("%d", &index);
    int z;
    printf("Enter the element = ");
    scanf("%d", &z);
    printf("Entered element is %d\n", z);
    head = insertionatanypoint(head, index, z);
    traversal(head);

    return 0;
}