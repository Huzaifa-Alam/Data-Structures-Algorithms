#include <stdio.h>
#include <stdlib.h>

// Function to insert an element into a 1-based heap
int* insertHeap(int* array, int size, int value)
{
    size += 1; // Increment size by 1 to accommodate the new element
    array = (int*)realloc(array, (size + 1) * sizeof(int)); // Reallocate memory for the new size
    array[size] = value; // Insert the new value at the end of the heap

    int index = size;
    while (index > 1) // Since we're using 1-based index, compare with 1
    {
        int parent = index / 2; // Find parent node
        if (array[index] < array[parent]) // If child is smaller than parent, swap
        {
            // Swap the child and parent values
            int temp = array[index];
            array[index] = array[parent];
            array[parent] = temp;

            index = parent; // Move up to the parent index
        }
        else
        {
            break; // Exit if the heap property is satisfied
        }
    }
    return array; // Return the updated array
}

int main()
{
    printf("Hello, Heap!\n");

    // Start array with a dummy 0th element for 1-based indexing
    int* array = (int*)malloc(10 * sizeof(int));
    array[1] = 70; array[2] = 50; array[3] = 40; array[4] = 45; array[5] = 35;
    array[6] = 39; array[7] = 16; array[8] = 10; array[9] = 9;

    int size = 9; // Number of elements in the heap

    int value = 42; // Example value to insert
    array = insertHeap(array, size, value); // Insert the value into the heap

    // Print the modified heap
    for (int i = 1; i <= size + 1; i++) {
        printf("%d ", array[i]);
    }

    // Free the dynamically allocated memory
    free(array);

    return 0;
}
