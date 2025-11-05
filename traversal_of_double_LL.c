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

    while (temp!= NULL)
    {
        printf("%d->", temp->data);
        temp = temp->prev;
    }
    printf("NULL");

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
    return 0;
}
