
#include <stdio.h>
#define MAX 10

// Prototypes
void EnQueue(int data);
void DeQueue();
void Display();
int IsFull();
int IsEmpty();
int Peek();
int QueueSize();
void ClearQueue();

int Queue[MAX];
int front = -1;
int rear = -1;

void EnQueue(int data)
{
    if (IsFull()) // Check if the queue is full
    {
        printf("Overflow\n");
        return;
    }

    if (IsEmpty()) // If the queue is empty
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX; // Move rear forward and wrap around if necessary
    }
    Queue[rear] = data;
}

void DeQueue() 
{
    if (IsEmpty()) // Check if the queue is empty
    {
        printf("Underflow\n");
        return;
    }
    else if (front == rear) // If there's only one element, reset the queue
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX; // Move front forward and wrap around if necessary
    }
}

int IsFull()
{
    return (rear + 1) % MAX == front;
}

int IsEmpty()
{
    return front == -1 && rear == -1;
}

int Peek()
{
    if (IsEmpty())
    {
        printf("Queue is empty, cannot peek.\n");
        return -1; // Return an invalid value to indicate empty queue
    }
    return Queue[front];
}

int QueueSize()
{
    if (IsEmpty())
    {
        return 0;
    }
    if (rear >= front)
    {
        return rear - front + 1;
    }
    else
    {
        return MAX - front + rear + 1;
    }
}

void ClearQueue()
{
    front = rear = -1;
    printf("Queue has been cleared.\n");
}

void Display()
{
    if (IsEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int i = front;
        printf("Queue elements are: ");
        while (i != rear)
        {
            printf("%d ", Queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", Queue[rear]);
    }
}

int main()
{
    EnQueue(4);
    EnQueue(42);
    EnQueue(4);
    EnQueue(-404);
    Display(); // Display the elements in the queue
    printf("Front element: %d\n", Peek()); // Peek at the front element
    printf("Queue size: %d\n", QueueSize()); // Display the queue size
    DeQueue(); // Remove an element from the queue
    Display(); // Display the queue again after dequeue
    ClearQueue(); // Clear the queue
    Display(); // Display after clearing the queue

    return 0;
}


