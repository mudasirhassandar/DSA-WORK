#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traversal(struct node *head)
{
    struct node *current = head;
    if (current == NULL)
    {
        printf("List is empty....");
        return;
    }

    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL");
    printf("\n");
    return;
}
struct node *merge(struct node *head, struct node *head1)
{
    if (head == NULL)
        return head1;
    if (head1 == NULL)
        return head;
    struct node *merged = NULL;
    // Choose the smaller data node as starting node
    if (head->data <= head1->data)
    {
        merged = head;
        merged->next = merge(head->next, head1);
    }
    else
    {
        merged = head1;
        merged->next = merge(head, head1->next);
    }
    return merged;
}
int main()
{
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    second->data = 20;
    third->data = 50;
    head->next = second;
    second->next = third;
    third->next = NULL;
    printf("First list :\n");
    traversal(head);
    struct node *head1 = NULL;
    struct node *second1 = NULL;
    struct node *third1 = NULL;
    head1 = (struct node *)malloc(sizeof(struct node));
    second1 = (struct node *)malloc(sizeof(struct node));
    third1 = (struct node *)malloc(sizeof(struct node));
    head1->data = 40;
    second1->data = 70;
    third1->data = 80;
    head1->next = second1;
    second1->next = third1;
    third1->next = NULL;
    printf("Seconf list :\n");
    traversal(head1);
    printf("Concatenated list :\n");
    head = merge(head, head1);
    traversal(head);
    return 0;
}