#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr; // dynamic array
} stack;

/* DISPLAY */
void display(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack Elements (Top to Bottom)\n");
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->arr[i]);
        }
    }
}

int isempty(stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}
int isfull(stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}
int peek(stack *s)
{
    if (isempty(s))
    {
        printf("Stack is empty..");
        return -1;
    }
    return s->arr[s->top];
}
/* PUSH */
void push(stack *s, int value)
{
    if (isfull(s))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
        printf("%d pushed into stack\n\n", value);
    }
}

/* POP */
int pop(stack *s)
{
    if (isempty(s))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int value = s->arr[s->top];
        s->top--;
        return value;
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
    stack s;
    int n, value;

    printf("Enter numnber of elements = ");
    scanf("%d", &n);

    s.size = n;
    s.top = -1;

    /* DYNAMIC MEMORY ALLOCATION */
    s.arr = (int *)malloc(s.size * sizeof(int));

    if (s.arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    /* PUSH */
    for (int i = 0; i < s.size; i++)
    {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &value);
        push(&s, value);
    }

    display(&s);

    /* POP LOOP */
    while (1)
    {
        int choice;
        printf("\nDo you want to pop? (1 = yes, 0 = no) = ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }

        int popped = pop(&s);
        if (popped != -1)
        {
            printf("Popped element = %d\n\n", popped);
        }
        display(&s);
    }
    int topelement = peek(&s);
    if (topelement != -1)
    {
        printf("\nTop element = %d", topelement);
    }
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
    /* FREE MEMORY */
    free(s.arr);

    return 0;
}
