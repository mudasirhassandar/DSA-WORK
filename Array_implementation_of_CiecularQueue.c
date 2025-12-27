#include <stdio.h>
#define MAX 100

typedef struct CircularQueue {
    int size;
    int front;
    int rear;
    int arr[MAX];
} CircularQueue;

int isFull(CircularQueue *q) {
    return ((q->rear + 1) % q->size == q->front);
}

int isEmpty(CircularQueue *q) {
    return (q->front == q->rear);
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Circular Queue is FULL...\n");
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = value;
        printf("%d enqueued\n", value);
    }
}

int dequeue(CircularQueue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("Circular Queue is EMPTY...\n");
    } else {
        q->front = (q->front + 1) % q->size;
        a = q->arr[q->front];
    }
    return a;
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Circular Queue is EMPTY...\n");
        return;
    }

    printf("\nQueue Elements:\n");
    int i = (q->front + 1) % q->size;
    while (i != (q->rear + 1) % q->size) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    int n, choice, value;

    printf("Enter queue size (MAX %d) = ", MAX);
    scanf("%d", &n);

    if (n <= 1 || n > MAX) {
        printf("Invalid size\n");
        return 0;
    }

    q.size = n;
    q.front = 0;
    q.rear = 0;

    printf("Note: Maximum elements allowed = %d\n", n - 1);

    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  0.Exit\n");
        printf("Enter choice = ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value = ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;

        case 2:
            value = dequeue(&q);
            if (value != -1)
                printf("%d dequeued\n", value);
            break;

        case 3:
            display(&q);
            break;

        case 0:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
