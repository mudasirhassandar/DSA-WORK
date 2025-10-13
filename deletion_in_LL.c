#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    struct node *current = head;
    printf("Linked list: ");
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct node *deletionatbegning(struct node *head)
{
    if (head == NULL)
        return NULL;
    struct node *temp = head;
    head = head->next;
    printf("Deleted element = %d\n", temp->data);
    free(temp);
    return head;
}

struct node *deletionatend(struct node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        printf("Deleted element = %d\n", head->data);
        free(head);
        return NULL;
    }
    struct node *p = head;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    printf("Deleted element = %d\n", p->next->data);
    free(p->next);
    p->next = NULL;
    return head;
}

struct node *deletionatanypoint(int index, struct node *head)
{
    if (head == NULL)
        return NULL;
    if (index == 1)
    {
        return deletionatbegning(head);
    }

    struct node *p = head;
    int i = 1;
    while (i < index - 1 && p->next != NULL)
    {
        p = p->next;
        i++;
    }

    if (p->next == NULL)
    {
        printf("Index out of range!\n");
        return head;
    }

    struct node *temp = p->next;
    printf("Deleted element = %d\n", temp->data);
    p->next = temp->next;
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
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = fifth;
    fifth->data = 50;
    fifth->next = sixth;
    sixth->data = 60;
    sixth->next = seventh;
    seventh->data = 70;
    seventh->next = NULL;

    traversal(head);

    head = deletionatbegning(head);
    traversal(head);

    head = deletionatend(head);
    traversal(head);

    int index;
    printf("Enter the index to delete (1 = first): ");
    scanf("%d", &index);
    head = deletionatanypoint(index, head);
    traversal(head);

    return 0;
}
