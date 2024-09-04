#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *next;
};

struct Node *head = NULL;

void Append(int num) {
    struct Node *temp, *nw;
    nw = (struct Node *)malloc(sizeof(struct Node));
    nw->Data = num;
    nw->next = NULL;

    if (head == NULL) { 
        // If the list is empty, the new node is the first node, so set head to nw
        head = nw;
    } else {
        // Otherwise, find the last node and link it to the new node
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nw;
    }
}

// MAIN
int main() {
    int user;
    printf("Enter Value:\n");
    scanf("%d", &user);

    Append(34);
    printf("Head data: %d\n", head->Data); // Display the data in the head node
    
    return 0;
}
