#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
int size = 0; // Track the size of the queue

// Function prototypes
void Enqueue(int xdata);
void Dequeue();
void Display();
int Peek();
int IsEmpty();
void Clear();

void Enqueue(int xdata) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = xdata;
    newNode->next = NULL;
    if (rear == NULL) {
        // Queue is empty
        front = rear = newNode;
    } else {
        // Queue is not empty
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

void Dequeue() {
    if (front == NULL) {
        // Queue is empty
        printf("Underflow\n");
        return;
    }
    struct node* temp = front;
    front = front->next;
    if (front == NULL) {
        // Queue becomes empty after dequeue
        rear = NULL;
    }
    free(temp);
    size--;
}

void Display() {
    struct node* temp = front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int Peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1; // Return -1 or an appropriate value to indicate empty queue
    }
    return front->data;
}

int IsEmpty() {
    return front == NULL;
}

void Clear() {
    while (front != NULL) {
        Dequeue();
    }
    printf("Queue cleared\n");
}

int main() {
    Enqueue(24);
    Enqueue(754);
    Enqueue(312);
    Enqueue(46);
    Enqueue(12);
    
    printf("Front element: %d\n", Peek()); // Peek at the front element
    Display();
    printf("Queue size: %d\n", size);
    
    Dequeue();
    Dequeue();
    Display();
    printf("Queue size: %d\n", size);
    
    Clear();
    Display();
    printf("Queue size: %d\n", size);

    return 0;
}











// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node *next;
// };

// struct node *front = NULL;
// struct node *rear = NULL;

// // Function prototypes
// void Enqueue(int xdata);
// void Dequeue();
// void Display();

// void Enqueue(int xdata) {
//     struct node *newNode = (struct node*) malloc(sizeof(struct node));
//     if (newNode == NULL) {
//         printf("Memory allocation failed\n");
//         return;
//     }
//     newNode->data = xdata;
//     newNode->next = NULL;
//     if (rear == NULL) {
//         // Queue is empty
//         front = rear = newNode;
//     } else {
//         // Queue is not empty
//         rear->next = newNode;
//         rear = newNode;
//     }
// }

// void Dequeue() {
//     if (front == NULL) {
//         // Queue is empty
//         printf("Underflow\n");
//         return;
//     }
//     struct node* temp = front;
//     front = front->next;
//     if (front == NULL) {
//         // Queue becomes empty after dequeue
//         rear = NULL;
//     }
//     free(temp);
// }

// void Display() {
//     struct node* temp = front;
//     if (temp == NULL) {
//         printf("Queue is empty\n");
//         return;
//     }
//     printf("Queue elements: ");
//     while (temp != NULL) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// int main() {
//     Enqueue(24);
//     Enqueue(754);
//     Enqueue(312);
//     Enqueue(46);
//     Enqueue(12);
//     Display();
//     Dequeue();
//     Dequeue();
//     Display();

//     return 0;
// }
