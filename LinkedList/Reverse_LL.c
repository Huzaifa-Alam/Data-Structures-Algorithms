#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


// Function prototypes
struct node* createLinkedList(int n);
void displayAll(struct node *head);
struct node* ReverseLinkedListiterative(struct node *head);
struct node* ReverseLinkedListRecursive(struct node *head);


// Function to reverse the Linked List using a recursive approach
struct node* ReverseLinkedListRecursive(struct node* head) {
    // Base case: if head is NULL or there's only one element, return head
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursively reverse the rest of the list
    struct node* newHead = ReverseLinkedListRecursive(head->next);
    
    // Adjust the pointers
    head->next->next = head;
    head->next = NULL;
    
    // Return the new head of the reversed list
    return newHead;
}


// Function of ReverseLinkedList Iterative Approach
struct node* ReverseLinkedListiterative(struct node *head){
    struct node *prev = NULL;
    struct node *current = head;
    struct node *after;

    while (current != NULL){
        after = current->next;
        current->next = prev;
        prev = current;
        current = after;
    }
    head =prev;
    return head;
}


int main() {
    int n = 0;
    struct node *HEAD = NULL;  // Initialize HEAD to NULL
    
    printf("How many Nodes: \n");
    scanf("%d", &n);

    HEAD = createLinkedList(n);
    displayAll(HEAD);

    // Reverse the linked list Iterative Approach
    HEAD = ReverseLinkedListiterative(HEAD);
    printf("Reversed Linked List Iterative Approach \n ");
    displayAll(HEAD);

    // Reverse the linked list Recursive Approach
    HEAD = ReverseLinkedListRecursive(HEAD);
    printf("Again reaches Original LinkedList Using Recursive Approach \n ");
    displayAll(HEAD);

    // Reverse the linked list Recursive Approach
    HEAD = ReverseLinkedListRecursive(HEAD);
    printf("Reverse LinkedList Using Recursive Approach \n ");
    displayAll(HEAD);
    return 0;
}

struct node* createLinkedList(int n) {
    int i;
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *p = NULL;

    for (i = 0; i < n; i++) {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter value of node %d: ", i + 1);
        scanf("%d", &(temp->data));
        temp->next = NULL;

        if (head == NULL) {
            head = temp;  
        } else {
            p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
}

void displayAll(struct node *p) {
    while (p != NULL) {
        printf("%d---> ", p->data);
        p = p->next;
    }
    printf("NULL\n");  // Indicate the end of the linked list
}


