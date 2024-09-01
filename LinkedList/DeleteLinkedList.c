

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next;
};

// FUNCTION PROTOTYPES
struct node *createLinkedList(int n);
void displayAll(struct node *head);
struct node *del_first(struct node *head);
struct node *del_last(struct node *head);
struct node *del_at_pos(struct node *head, int pos);
struct node *add_begin(struct node *head, int d);

struct node *deleteAll(struct node *head);

int main()
{
    int n = 0;
    int i = 0;
    struct node *HEAD = NULL; // Initialize HEAD to NULL
    struct node *header = NULL; // Initialize HEAD to NULL

    printf("How many Nodes: \n");
    scanf("%d", &n);

    HEAD = createLinkedList(n);
    displayAll(HEAD);

    // Uncomment if you want to delete the first node

    printf("How many Nodes for header pointer: \n");
    scanf("%d", &n);
    header = createLinkedList(n);
    header = del_first(header);
    displayAll(header);

    // Uncomment if you want to delete the last node
    // HEAD = del_last(HEAD);
    // displayAll(HEAD);

    // printf("Enter the position to delete the Node: ");
    // int pos;
    // scanf("%d", &pos);
    // HEAD = del_at_pos(HEAD, pos); // Pass HEAD and pos to the function
    // displayAll(HEAD);

    printf("Before delete\n");
    HEAD = deleteAll(HEAD);
    displayAll(HEAD);
    printf("After delete\n");
    return 0;
}

// FUNCTION TO DELETE THE FIRST (1ST) NODE
struct node *del_first(struct node *head)
{
    struct node *temp;
    if (head == NULL)
    {
        printf("Linked List is already empty.\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp); // Free the memory of the deleted node
    }
    return head;
}

// FUNCTION TO DELETE THE LAST NODE
struct node *del_last(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return NULL;
    }

    if (head->next == NULL)
    { // Only one node in the list
        free(head);
        return NULL;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL; // Disconnect the last node
    free(temp);        // Free the memory of the last node
    return head;
}

// FUNCTION TO DELETE A NODE AT NTH POSITION
struct node *del_at_pos(struct node *head, int pos)
{
    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return NULL;
    }

    struct node *temp1 = head;

    if (pos == 1)
    {
        head = head->next;
        free(temp1); // Free the memory of the deleted node
        return head;
    }

    for (int i = 0; i < pos - 2; i++)
    {
        if (temp1->next == NULL)
        {
            printf("Position out of bounds\n");
            return head; // Return if position is out of bounds
        }
        temp1 = temp1->next; // Points to (n-1)th node
    }

    struct node *temp2 = temp1->next; // Points to nth node
    temp1->next = temp2->next;        // Link (n-1)th node to (n+1)th node
    free(temp2);                      // Free the memory of the nth node

    return head;
}

// FUNCTION TO DELETE Alll NODE AT
struct node *deleteAll(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        free(head);
        head = temp;
    }
    return head;
};

// FUNCTION TO CREATE THE LINKED LIST WITH N NODES
struct node *createLinkedList(int n)
{
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *p = NULL;

    for (int i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node)); // Allocate memory for a new node
        printf("Enter value of node %d: ", i + 1);
        scanf("%d", &(temp->data));
        temp->next = NULL;

        if (head == NULL)
        { // If list is empty, make this node the head
            head = temp;
        }
        else
        {
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp; // Link the new node at the end
        }
    }
    return head;
}

// FUNCTION TO DISPLAY ALL NODES
void displayAll(struct node *p)
{
    if (p == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    while (p != NULL)
    {
        printf("%d---> ", p->data);
        p = p->next;
    }
    printf("NULL\n"); // Indicate the end of the linked list
}

// FUNCTION TO ADD A NODE AT THE BEGINNING
struct node *add_begin(struct node *head, int d)
{
    struct node *ptr = malloc(sizeof(struct node)); // Allocate memory for a new node
    ptr->data = d;
    ptr->next = head; // Point the new node to the current head
    head = ptr;       // Make the new node the head
    return head;
}
