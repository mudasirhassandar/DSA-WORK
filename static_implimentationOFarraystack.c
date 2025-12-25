#include <stdio.h>
#define MAX 100
typedef struct stack
{
    int size;
    int top;
    int arr[MAX];
} stack;
void display(stack *s)
{
    if (s->top == -1)
        printf("Stack is Empty\n");
    else
    {
        printf("Stack Element (Top to Bottom)\n");
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->arr[i]);
        }
    }
}

int isEmpty(stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

int isFull(stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    return 0;
}

int peek(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return s->arr[s->top];
}
int pop(stack *s)
{
    int value;
    if (isEmpty(s))
    {
        printf("Stack UnderFlow");
        return -1;
    }
    else
    {
        value = s->arr[s->top];
        s->top--;
    }
    return value;
}
void push(stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
        printf("%d pushed into stack\n\n", value);
    }
}
int access(stack *s, int i)
{
    int index = s->top - i + 1;
    if (index < 0)
    {
        printf("invalid index...");
        return -1;
    }

    return s->arr[index];
}
int main()
{
    int n, value;
    printf("Enter the number of elements (max = %d)= ", MAX);
    scanf("%d", &n);
    if (n > MAX)
    {
        printf("Error: Please enter number of element lesser or equal to %d", MAX);
        return 1;
    }
    stack s;
    s.size = n;
    s.top = -1; // stack is empty
    // push
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element = ", i + 1);
        scanf("%d", &value);
        push(&s, value);
    }
    display(&s);
    while (1)
    {
        int choice;
        printf("\nDo You want pop? (yes = 1,NO = 0) = ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            display(&s);
            break;
        }
        else
        {
            int popped = pop(&s);
            if (popped != -1)
            {
                printf("Popped element = %d\n\n", popped);
            
            display(&s);
            }
        }
    }
    int topElement = peek(&s);
    if (topElement != -1)
        printf("\nTop element = %d\n\n", topElement);
    while (1)
    {
        int choice, i;
        printf("\nDo You want to access any element? (1 = yes, 0 = no) = ");
        scanf("%d", &choice);
        if (choice == 0)
            break;
        printf("Enter the position of element = ");
        scanf("%d", &i);
        int element = access(&s, i);
        if (element != -1)
        {
            printf("\nYour element = %d", element);
        }
    }

    return 0;
}
