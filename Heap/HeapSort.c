
#include <stdio.h>
#define MAX 100

int array[] = {15, 5, 20, 1, 17, 10, 30};    // Initialize the array properly
int size = sizeof(array) / sizeof(array[0]); // Get the size of the array

void heapSort(int array[], int n)
{
    int size = n;

    while (size > 1)
    {
        // Move largest element to end ALGO 1
        int temp = array[0];
        array[0] = array[size - 1];
        array[size - 1] = temp;
        size = size - 1;

        // Heapify the root element
        maxHeap(array, size, 0); // Use index 0 as the root for heapify
    }
}

void maxHeap(int array[], int size, int i)
{
    int largest = i;       // Initialize largest as root
    int left = (2 * i) + 1;  // Left child index
    int right = (2 * i) + 2; // Right child index

    // Check if left child exists and is greater than root
    if (left < size && array[left] > array[largest])
    {
        largest = left;
    }

    // Check if right child exists and is greater than the largest so far
    if (right < size && array[right] > array[largest])
    {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        // Recursively heapify the affected sub-tree
        maxHeap(array, size, largest);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    printf("Original array: ");
    printArray(array, size);

    // Build a max heap
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        maxHeap(array, size, i);
    }

    printf("Max heap: ");
    printArray(array, size);

    printf("Sorted array by HeapSort : ");
    heapSort(array, size);
    printArray(array, size);
    return 0;
}
