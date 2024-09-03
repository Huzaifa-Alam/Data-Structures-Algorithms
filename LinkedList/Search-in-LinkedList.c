#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// FUNCTION TO CREATE THE LINKED LIST WITH N NODES
struct node *createLinkedList(int n) {
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *p = NULL;

    for (int i = 0; i < n; i++) {
        temp = (struct node *)malloc(sizeof(struct node)); // Allocate memory for a new node
        printf("Enter value of node %d: ", i + 1);
        scanf("%d", &(temp->data));
        temp->next = NULL;

        if (head == NULL) { // If list is empty, make this node the head
            head = temp;
        } else {
            p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp; // Link the new node at the end
        }
    }
    return head;
}

// FUNCTION TO SEARCH FOR AN ELEMENT IN THE LINKED LIST
void search(struct node *start, int data) {
    struct node *ptr = start;

    while (ptr != NULL) { // Traverse the list
        if (ptr->data == data) { // Check if current node's data matches the data
            printf("Successful search. Element %d found.\n", data);
            return;
        }
        ptr = ptr->next; // Move to the next node
    }
    printf("Unsuccessful search. Element %d not found.\n", data);
}

int main() {
    int n = 0;
    struct node *start = NULL; // Initialize start to NULL

    // Create the linked list
    printf("How many Nodes: \n");
    scanf("%d", &n);
    start = createLinkedList(n); // Create a linked list with n nodes

    // User input for search
    int user;
    printf("Search the element in the Linked List: ");
    scanf("%d", &user);
    search(start, user); // Search for the user's element in the linked list

    // Display the linked list
    struct node *ptr = start; // Pointer to traverse the list
    while (ptr != NULL) {
        printf("%d--> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n"); // Indicate the end of the linked list

    return 0;
}
