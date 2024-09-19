#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


// Function prototypes
struct node* createLinkedList(int n);
void displayAll(struct node *head);
struct node* ReverseLinkedList(struct node *head);


// Function of ReverseLinkedList
struct node* ReverseLinkedList(struct node *head){
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

    // Reverse the linked list
    HEAD = ReverseLinkedList(HEAD);
    printf("Reversed Linked List \n ");
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


