#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

// FUNCTION PROTOTYPES
struct node* createLinkedList(int n);
void displayAll(struct node *head);
struct node*  add_begin(struct node *head, int d);
struct node*  add_the_end(struct node *head, int d);

int main()
{
    int n = 0;
    struct node *HEAD = NULL; // Initialize HEAD to NULL

    printf("How many Nodes: \n");
    scanf("%d", &n);

    HEAD = createLinkedList(n);
    displayAll(HEAD);

    // Add a node at the beginning with data 4324
    HEAD = add_begin(HEAD, 142);
    HEAD = add_begin(HEAD, 14);
    HEAD = add_begin(HEAD, 432);
    displayAll(HEAD);

    // Add a node at the ending with data 6969
    HEAD = add_the_end(HEAD, 32);
    HEAD = add_the_end(HEAD, 132);
        displayAll(HEAD);
    return 0;
}


// FUNCTION TO CREATE THE NODES
struct node *createLinkedList(int n)
{
    int i;
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *p = NULL;

    for (i = 0; i < n; i++){
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter value of node %d: ", i + 1);
        scanf("%d", &(temp->data));
        temp->next = NULL;

        if (head == NULL){
            head = temp;
        }
        else{
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;}
    }
    return head;
}


// FUNCTION TO DISPLAY THE ALL NODES
void displayAll(struct node *p) // funtion prototype is must define above
{                               //p is L.L here
    while (p != NULL)       // data of is not NULL so run
    {
        printf("%d---> ", p->data); 
        p = p->next;
    }
    printf("NULL\n"); // Indicate the end of the linked list
}

// FUNCTION TO ADD A NODE AT THE BEGINNING
struct node *add_begin(struct node *head, int d)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->next = head;

    head = ptr;
    return head;
}


// FUNCTION TO ADD A NODE AT THE END
struct node *add_the_end(struct node *head, int d){
    struct node *temp = malloc(sizeof(struct node)); // dynamic location of temprary node
    temp->data = d; // innsert data in temprary node
    temp->next = NULL; ///link is null of temp variable
    // If the list is empty, the new node becomes the head
    if (head == NULL){ // means data of head(starting node) is null then we hv NO node
        head = temp; //so temp would become our first node
    }
    else{
        struct node *ptr = head; //ptr is our 1st node
        while (ptr->next != NULL) // link of 1st node is not null true conditoin run
        {
            ptr = ptr->next; // update link of ptr
        }
        ptr->next = temp; // ptr->link is NULL so put temp in it
    }
    return head;  // Return the (possibly updated) head pointer
}

