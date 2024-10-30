#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int is_empty() {
    return front == -1;
}

int is_full() {
    return (rear + 1) % MAX_SIZE == front;
}

void enqueue(int item) {
    if (is_full()) {
        printf("Queue Overflow\n");
        return;
    }
    if (is_empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = item;
    printf("%d enqueued to queue\n", item);
}

int dequeue() {
    if (is_empty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return item;
}

int peek() {
    if (is_empty()) {
        printf("Queue is Empty\n");
        return -1;
    }
    return queue[front];
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Front element is %d\n", peek());

    printf("%d dequeued from queue\n", dequeue());
    printf("%d dequeued from queue\n", dequeue());

    enqueue(40);
    printf("Front element is %d\n", peek());

    // Trying to enqueue more elements than the queue capacity
    enqueue(50);
    enqueue(60);

    return 0;
}