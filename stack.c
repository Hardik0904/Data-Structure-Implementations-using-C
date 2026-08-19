#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;

/* Initialize stack */
void init(Stack *s, int capacity) {
    s->arr = (int *)malloc(capacity * sizeof(int));

    if (s->arr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    s->top = -1;
    s->capacity = capacity;
}

/* Resize the stack */
void resize(Stack *s) {
    int new_capacity;
    int *new_arr;
    int i;

    new_capacity = s->capacity * 2;

    new_arr = (int *)malloc(new_capacity * sizeof(int));

    if (new_arr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i <= s->top; i++) {
        new_arr[i] = s->arr[i];
    }

    free(s->arr);

    s->arr = new_arr;
    s->capacity = new_capacity;
}

/* Push */
void push(Stack *s, int value) {
    if (s->top == s->capacity - 1) {
        resize(s);
    }

    s->top++;
    s->arr[s->top] = value;
}

/* Pop */
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }

    return s->arr[s->top--];
}

/* Peek */
int peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }

    return s->arr[s->top];
}

/* Check if empty */
int is_empty(Stack *s) {
    return s->top == -1;
}

/* Free stack */
void destroy(Stack *s) {
    free(s->arr);
    s->arr = NULL;
    s->top = -1;
    s->capacity = 0;
}

int main(void) {
    Stack s;

    init(&s, 2);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    printf("Top: %d\n", peek(&s));

    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));

    printf("Top: %d\n", peek(&s));

    destroy(&s);

    return 0;
}