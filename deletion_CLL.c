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
struct node *deletionatbegining(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == head)
    {
        printf("Deleted element at begining is %d\n", head->data);
        free(head);
        return NULL;
    }
    struct node *p = head;
    struct node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    printf("Deleted element at begining is %d\n", head->data);
    temp->next = head->next;
    head = head->next;
    free(p);
    return head;
}
struct node *deletionatend(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == head)
    {
        printf("Deleted element at end is %d\n", head->data);
        free(head);
        return NULL;
    }
    struct node *p = head;
    while (p->next->next != head)
    {
        p = p->next;
    }
    struct node *temp = p->next;
    printf("Deleted element at end is %d\n", temp->data);
    p->next = head;
    free(temp);
    return head;
}
struct node *deletionatanypoint(struct node *head, int index)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (index == 1)
    {
        return deletionatbegining(head);
    }
    struct node *p = head;
    int i = 1;
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    if (p->next == head)
    {
        printf("Invalid index! No element deleted.\n");
        return head;
    }
    struct node *temp = p->next;
    if (temp->next == head)
    {
        return deletionatend(head);
    }

    p->next = temp->next;
    printf("Deleted element is %d\n", temp->data);
    free(temp);
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
    struct node *seventh = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));
    seventh = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40;
    fifth->data = 50;
    sixth->data = 60;
    seventh->data = 70;
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = head;
    traversal(head);
    head = deletionatbegining(head);
    traversal(head);
    head = deletionatend(head);
    traversal(head);
    int index;
    printf("Enter the index where you want to delete the element (index of first element is 1) = ");
    scanf("%d", &index);
    head = deletionatanypoint(head, index);
    traversal(head);
    return 0;
}