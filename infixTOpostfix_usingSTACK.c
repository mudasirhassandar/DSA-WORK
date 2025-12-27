#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
typedef struct stack
{
    int size;
    int top;
    char arr[MAX];
} stack;
void push(struct stack *s, char value)
{
    if (s->top == s->size - 1)
    {
        printf("Stack Overflow...\n");
        return;
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
    }
}
char pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow...\n");
        return -1;
    }
    else
    {
        char value = s->arr[s->top];
        s->top--;
        return value;
    }
}
int isoperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}
char *infixtopostfix(char *infix, char *postfix, struct stack *s)
{

    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else if (s->top == -1 || precedence(infix[i]) > precedence(s->arr[s->top]))
        {
            push(s, infix[i]);
            i++;
        }
        else
        {
            postfix[j] = pop(s);
            j++;
        }
    }
    while (s->top != -1)
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{

    char infix[MAX];
    printf("Enter your expression (MAX = 100 characters):\n");
    scanf("%99s", infix);
    if (strlen(infix) >= MAX)
    {
        printf("Your string have more characters....");
        return 0;
    }
    char postfix[strlen(infix) + 1];
    printf("Your expression is accepted : %s", infix);
    stack s;
    s.size = MAX;
    s.top = -1;
    char *expression = infixtopostfix(infix, postfix, &s);
    printf("\nPostfix Expression = %s\n", expression);
    return 0;
}
