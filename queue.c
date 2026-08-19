#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

/* Initialize queue */
void init(Queue *q, int capacity) {
    q->arr = (int *)malloc(capacity * sizeof(int));

    if (q->arr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->capacity = capacity;
}

/* Resize queue */
void resize(Queue *q) {
    int new_capacity;
    int *new_arr;
    int i;

    new_capacity = q->capacity * 2;

    new_arr = (int *)malloc(new_capacity * sizeof(int));

    if (new_arr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    /* Copy elements in correct queue order */
    for (i = 0; i < q->size; i++) {
        new_arr[i] = q->arr[(q->front + i) % q->capacity];
    }

    free(q->arr);

    q->arr = new_arr;
    q->capacity = new_capacity;
    q->front = 0;
    q->rear = q->size;
}

/* Enqueue */
void enqueue(Queue *q, int value) {
    if (q->size == q->capacity) {
        resize(q);
    }

    q->arr[q->rear] = value;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

/* Dequeue */
int dequeue(Queue *q) {
    int value;

    if (q->size == 0) {
        printf("Queue Underflow\n");
        return -1;
    }

    value = q->arr[q->front];

    q->front = (q->front + 1) % q->capacity;
    q->size--;

    return value;
}

/* Get front element */
int peek(Queue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }

    return q->arr[q->front];
}

/* Check if empty */
int is_empty(Queue *q) {
    return q->size == 0;
}

/* Get queue size */
int queue_size(Queue *q) {
    return q->size;
}

/* Free memory */
void destroy(Queue *q) {
    free(q->arr);

    q->arr = NULL;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->capacity = 0;
}

int main(void) {
    Queue q;

    init(&q, 2);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Front: %d\n", peek(&q));

    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));

    printf("Front: %d\n", peek(&q));

    enqueue(&q, 50);
    enqueue(&q, 60);

    printf("Front: %d\n", peek(&q));
    printf("Size: %d\n", queue_size(&q));

    destroy(&q);

    return 0;
}