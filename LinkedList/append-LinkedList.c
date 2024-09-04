#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node
{
    int Data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to append a new node with given data to the end of the list
void appendNode(int num) {
    struct Node *temp, *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->Data = num;
    newNode->next = NULL;

    if (head == NULL) { 
        // If the list is empty, the new node becomes the head
        head = newNode;
    } else {
        // Traverse to the end of the list and append the new node
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Main function
int main() {
    int user;
    printf("Enter Value:\n");
    scanf("%d", &user);

    appendNode(user); // Append the user's input to the list
    printf("Head data: %d\n", head->Data); // Display the data in the head node
    
    return 0;
}
