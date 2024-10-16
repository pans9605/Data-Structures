#include <stdio.h>
#include <stdlib.h>
// defination of structure of stack
struct Stack {
    int *arr;
    int top;
    int capacity;
};
// fdefienation of trsucture for queue using stack
typedef struct {
    struct Stack* stack1;
    struct Stack* stack2;
} MyQueue;


struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->arr = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stack1 = createStack(1000);
    queue->stack2 = createStack(1000);
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    while (!isEmpty(obj->stack1)) {
        push(obj->stack2, pop(obj->stack1));
    }
    push(obj->stack1, x);
    while (!isEmpty(obj->stack2)) {
        push(obj->stack1, pop(obj->stack2));
    }
}

int myQueuePop(MyQueue* obj) {
    if (isEmpty(obj->stack1)) {
        printf("Queue is empty\n");
        return -1;
    }
    return pop(obj->stack1);
}

int myQueuePeek(MyQueue* obj) {
    if (isEmpty(obj->stack1)) {
        printf("Queue is empty\n");
        return -1;
    }
    return obj->stack1->arr[obj->stack1->top];
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->stack1);
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1->arr);
    free(obj->stack1);
    free(obj->stack2->arr);
    free(obj->stack2);
    free(obj);
}