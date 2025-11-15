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
struct node *deletionatend(struct node *head)
{

    struct node *temp = head->prev;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("deleted element is = %d\n", temp->data);
    free(temp);
    return head;
}
struct node *deletionatbegining(struct node *head)
{
    struct node *temp = head;
    head->next->prev = head->prev;
    head->prev->next = head->next;
    head = head->next;
    printf("deleted element is = %d\n", temp->data);
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
    if (temp->next == head)
    {
        return deletionatend(head);
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("deleted element is = %d\n", temp->data);
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

    head = deletionatbegining(head);
    traversal(head);

    head = deletionatend(head);
    traversal(head);
    int index;
    printf("Enter the index (index 1 = position of element will be frist) = ");
    scanf("%d", &index);

    head = deletionatanypoint(head, index);
    traversal(head);
    return 0;
}
