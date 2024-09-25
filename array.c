#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100  // Define maximum size of the stack

int stack[MAXSIZE];
int top = -1;  // Stack is initially empty

// Initialize Stack
void initializeStack() 
{
    top = -1;
}

// Push Operation
void push(int data) 
{
    if (top == MAXSIZE - 1) 
    {
        printf("Stack Overflow hori hai :(\n");  // Stack is full
    } 
    else 
    {
        top = top + 1;
        stack[top] = data;  // Insert the element at top position
    }
}

// Pop Operation
int pop()
 {
    if (top == -1) 
    {
        printf("Stack Underflow hai :)\n");  // Stack is empty
        return -1;
    } 
    else 
    {
        int data = stack[top];
        top = top - 1;
        return data;  // Remove and return the top element
    }
}

// Peek Operation
int peek() 
{
    if (top == -1) 
    {
        printf("Stack khali h g :( fill kro\n");
        return -1;
    } 
    else 
    {
        return stack[top];  // Return the top element without removing it
    }
}

// isEmpty Operation
bool isEmpty() 
{
    return top == -1;
}

int main() {
    initializeStack();
    
    push(20);
    push(30);
    push(40);
    
    printf("Top element is %d\n", peek());
    printf("Popped element is %d\n", pop());
    printf("Top element is %d\n", peek());
    
    if (isEmpty()) 
    {
        printf("Stack khali hai :(\n");
    } 
    else 
    {
        printf("Stack ko fill kro :)\n");
    }
    
    return 0;
}
