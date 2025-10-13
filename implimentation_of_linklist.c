// implimentation of linked list for 3 nodes.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;          // data part
    struct node *next; // stores the address of next node.
};
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
    // printing the linked list.
    printf("Linked list:\n");
    struct node *temp = head; // now head remains head node always . and temp becomes NULL .
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    return 0;
}