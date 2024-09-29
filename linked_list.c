#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    printf("%d stack m entry kra :)\n", data);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack khali hai g\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack khali hai g\n");
        return -1;
    }
    return stack->top->data;
}

int main() {
    struct Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element is %d\n", peek(stack));

    printf("Popped element is %d\n", pop(stack));
    printf("Top element is %d\n", peek(stack));

    return 0;
}