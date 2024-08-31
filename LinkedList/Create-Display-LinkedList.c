#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function prototypes
struct node* createLinkedList(int n);
void displayAll(struct node *head);
struct node* add_begin(struct node* head, int d);

int main() {
    int n = 0;
    struct node *HEAD = NULL;  // Initialize HEAD to NULL
    
    printf("How many Nodes: \n");
    scanf("%d", &n);

    HEAD = createLinkedList(n);
    displayAll(HEAD);
    
    // Add a node at the beginning with data 4324
    HEAD = add_begin(HEAD, 4324);
    
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

// Function to add a node at the beginning
struct node* add_begin(struct node* head, int d) {
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->next = head;
    
    head = ptr;
    return head; 
}
