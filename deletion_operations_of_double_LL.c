#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *deletionatend(struct node *head)
{
    struct node *temp = head;
    while (temp->next != NULL)

    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    printf("deleted element is = %d\n", temp->data);
    free(temp);
    return head;
}
struct node *deletionatbegining(struct node *head)
{

    struct node *temp = head;
    head->next->prev = NULL;
    head = head->next;
    printf("Deleted element is = %d\n", temp->data);
    free(temp);
    return head;
}
struct node *deletionatanypoint(struct node *head, int index)
{
    if (index == 1)
    {
        return deletionatbegining(head);
    }
    struct node *temp = head;
    int i = 1;
    while (i < index)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL)
    {
        return deletionatend(head);
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;

    printf("Deleted element is = %d\n", temp->data);
    free(temp);
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
    head = deletionatbegining(head);
    traversal(head);
    head = deletionatend(head);
    traversal(head);
    int index;
    printf("Enter the index where you want to delete the element = ");
    scanf("%d", &index);
    head = deletionatanypoint(head, index);
    traversal(head);
    return 0;
}
