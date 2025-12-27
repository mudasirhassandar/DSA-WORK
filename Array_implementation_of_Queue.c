#include <stdio.h>
#define MAX 100
typedef struct Queue
{
    int size;
    int front;
    int rear;
    int arr[MAX];
} Queue;
int isFull(struct Queue *q)
{
    if (q->rear == q->size - 1)
        return 1;
    return 0;
}
int isEmpty(struct Queue *q)
{
    if (q->rear == q->front)
        return 1;
    return 0;
}
void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
        printf("Queue is FULL...\n");
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
    }
}
int dequeue(struct Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue is Empty.No more deletions.\n");
    }
    else
    {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}
void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty...");
    }

    else
    {
        printf("\n===Entered Queue===\n\n");
        for (int i = q->front + 1; i <= q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
    }
    printf("\n");
}
int main()
{
    Queue q;
    int n;
    printf("Enter the number of elements (MAX = %d) = ", MAX);
    scanf("%d", &n);
    if (n > MAX)
    {
        printf("Entered number is greater than %d", MAX);
        return 0;
    }
    q.size = n;
    q.front = -1;
    q.rear = -1;
    for (int i = 0; i < n; i++)
    {
        int value;
        printf("Enter %d element = ", i + 1);
        scanf("%d", &value);
        enqueue(&q, value);
    }
    display(&q);
    while (1)
    {
        int choice;
        printf("\nDo you want dequeue ?(1=YES,0=NO) = ");
        scanf("%d", &choice);
        if (choice == 0)
            break;
        int x = dequeue(&q);
        if (x != -1)
        {
            printf("%d is Dequeued\n", x);
            display(&q);
        }
    }

    return 0;
}
