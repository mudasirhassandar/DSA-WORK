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
    printf("Linked list:\n");

    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL");
    printf("\n");

    return;
}
// function for insertion at begning
struct node *insertionatbegning(int x, struct node *head)
{
    struct node *insert = (struct node *)malloc(sizeof(struct node));
    insert->data = x;
    insert->next = head;
    return insert;
}
// function for insertion at point
struct node *insertionatanypoint(int index, struct node *head, int y)
{
    struct node *insert = (struct node *)malloc(sizeof(struct node));
    if (index == 1)
    {
        insert->data = y;
        insert->next = head;
        return insert;
    }
    struct node *p = head;
    int i = 1;
    while (i < index - 1 && p->next != NULL)
    {
        p = p->next;
        i++;
    }
    insert->data = y;
    insert->next = p->next;
    p->next = insert;
    return head;
}
// function of insertion at end
struct node *insertionatend(struct node *head, int z)
{
    struct node *insert = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    insert->data = z;
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
    // struct node *insert = NULL; // node for inserted element.
    // allocating memory for node in heap.
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    // insert = (struct node *)malloc(sizeof(struct node));  // new node for insert.
    //  assign data.
    head->data = 10;
    second->data = 20;
    third->data = 30;
    // connecting nodes.
    head->next = second;
    second->next = third;
    third->next = NULL;
    traversal(head);
    // code for insertion.
    int x;
    printf("Enter the element you want to insert at begning = ");
    scanf("%d", &x);
    head = insertionatbegning(x, head);
    traversal(head);
    int index;
    printf("NOTE:- INDEX -> if you want insert at begning your index is 1. \n");
    printf("Enter the index = ");
    scanf("%d", &index);
    int y;
    printf("Enter the element you want to insert at %d index = ", index);
    scanf("%d", &y);
    if (index == 1)
        head = insertionatanypoint(index, head, y);
    else
        insertionatanypoint(index, head, y);
    traversal(head);
    int z;
    printf("Enter the element you want to insert at end = ");
    scanf("%d", &z);
    insertionatend(head, z);
    traversal(head);

    return 0;
}
