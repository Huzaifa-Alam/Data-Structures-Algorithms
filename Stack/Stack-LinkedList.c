#include <stdio.h>
#include <stdlib.h>

// Define the structure for the stack node
struct node {
    int data;
    struct node* next;
}* top = NULL;

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to push an element onto the stack
void push(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto the stack.\n", data);
}



// Function to print all elements of the stack
void print() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    struct node* ptr = top;
    printf("Stack elements are: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int choice, user;
    
    while (1) {
        printf("\n*** Stack Menu ***\n");
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) Peek\n");
        printf("4) Print\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &user);
                push(user);
                break;
                
            case 2:
                pop();
                break;

            case 3:
                printf("Top element is %d\n", peek());
                break;
                
            case 4:
                print();
                break;
                
            case 5:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
