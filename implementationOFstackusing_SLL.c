
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL; // global

int isfull(struct node *element)
{
    if (element == NULL)
        return 1;
    else
        return 0;
}
int isempty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
int peek()
{
    if (isempty())
    {
        printf("\nstack is empty..\n");
        return -1;
    }
    else
        return top->data;
}
void display()
{
    if (isempty())
    {
        printf("Stack is empty...\n");
        return;
    }

    printf("\nStack (top to bottom)\n\n");
    struct node *temp = top;
    while (temp != NULL)
    {
        printf("%d\n|\nV\n", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
int pop()
{
    if (isempty())
    {
        printf("Stack is Underflow....\n");
        return -1;
    }
    else
    {
        struct node *temp = top;
        top = top->next;
        int x = temp->data;
        free(temp);
        return x;
    }
}
void push(int value)
{
    struct node *element = (struct node *)malloc(sizeof(struct node));
    if (isfull(element))
    {
        printf("Stack Overflow....\n");
    }
    else
    {
        element->data = value;
        element->next = top;
        top = element;
        printf("%d is pushed\n", value);
    }
}
int access(int i)
{
    if (i <= 0)
    {
        printf("Invalid position...\n");
        return -1;
    }
    else
    {
        struct node *temp = top;
        int k = 0;
        while (k < i - 1)
        {
            temp = temp->next;
            k++;
        }
        if (temp == NULL)
        {
            printf("Invalid position...\n");
            return -1;
        }
        return temp->data;
    }
}

int main()
{

    int n, value;
    printf("Enter the number nodes = ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data of %d node = ", i + 1);
        scanf("%d", &value);
        push(value);
    }
    display();
    while (1)
    {
        int choice;
        printf("\nDo you want to pop? (1 = yes, 0 = no) = ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }

        int popped = pop();
        if (popped != -1)
        {
            printf("Popped Node = %d\n\n", popped);

            display();
        }
    }
    int top = peek();
    if (top != -1)
        printf("Top of stack = %d", top);

    while (1)
    {
        int choice, i;
        printf("\nDo You want to access any Node? (1 = yes, 0 = no) = ");
        scanf("%d", &choice);
        if (choice == 0)
            break;
        printf("Enter the position of Node = ");
        scanf("%d", &i);
        int element = access(i);
        if (element != -1)
        {
            printf("\nYour Node = %d", element);
        }
    }

    return 0;
}
