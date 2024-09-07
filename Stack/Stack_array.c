#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX 10

// Stack array and the top index
int stackArr[MAX];
int top = -1;

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to push an element onto the stack
void push(int data) {
    if (isFull()) {
        printf("Stack Overflow: Unable to push %d onto the stack.\n", data);
        return;
    }
    stackArr[++top] = data;
    printf("Pushed %d onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow: Unable to pop from the stack.\n");
        exit(1);  // Exit the program to avoid returning invalid data
    }
    int poppedValue = stackArr[top--];
    printf("Popped %d from the stack.\n", poppedValue);
    return poppedValue;
}

// Function to print all elements of the stack
void printStack() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stackArr[i]);
    }
    printf("\n");
}

// Function to peek the top element of the stack
int peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        exit(1);  // Exit the program to avoid returning invalid data
    }
    return stackArr[top];
}

int main() {
    push(10);
    push(20);
    push(30);

    printStack();

    pop();
    // printStack();

    printf("Top element is %d\n", peek());

    return 0;
}



