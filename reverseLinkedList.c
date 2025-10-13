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
struct node *reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
int main()
{
    // ceration of nodes.
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    // allocating memory for node in heap.
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    // assign data.
    head->data = 10;
    second->data = 20;
    third->data = 30;
    // connecting nodes.
    head->next = second;
    second->next = third;
    third->next = NULL;
    traversal(head);
    head = reverse(head);
    printf("Reverse ");
    traversal(head);
    return 0;
}