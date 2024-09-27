// #include <stdio.h>

// int array[100];
// int size = 0;

// void insertHeap(int value)
// {
//     array[++size] = value; // Insert the new value at the end of the heap
//     int index = size;

//     while (index > 1)
//     {
//         int parentIndex = index / 2;
//         if (array[parentIndex] < array[index])
//         {
//             // Swap parent and child to maintain heap property
//             int temp = array[parentIndex];
//             array[parentIndex] = array[index];
//             array[index] = temp;
//             index = parentIndex; // Move up the heap
//         }
//         else
//         {
//             return; // If heap property is maintained, exit
//         }
//     }
// }

// void deletefromHeap()
// {
//     if (size == 0)
//     {
//         return; // If the heap is empty, there's nothing to delete
//     }

//     array[1] = array[size]; // Replace root with the last element
//     size--; // Reduce the heap size by one

//     int i = 1;
//     while (i <= size) // Changed from `i < size` to `i <= size` to ensure proper comparison with children
//     {
//         int leftChild = 2 * i;
//         int rightChild = 2 * i + 1;

        
//         if (leftChild <= size && array[i] < array[leftChild]) 
//         {
//             // Swap with left child if necessary
//             int temp = array[i];
//             array[i] = array[leftChild];
//             array[leftChild] = temp;
//             i = leftChild; // Move down the heap to the left child
//         }

// // Corrected condition to make sure we check left and right bounds correctly
//         else if (rightChild <= size && array[i] < array[rightChild]) 
//         {
//             // Swap with right child if necessary
//             int temp = array[i];
//             array[i] = array[rightChild];
//             array[rightChild] = temp;
//             i = rightChild; // Move down the heap to the right child
//         }


//         else
//         {
//             return; // If heap property is maintained, exit
//         }
//     }
// }

// void print()
// {
//     for (int i = 1; i <= size; i++)
//     {
//         printf("%d ", array[i]); // Print the heap array
//     }
//     printf("\n");
// }

// int main()
// {
//     // Inserting elements into the heap
//     insertHeap(30);
//     insertHeap(32);
//     insertHeap(12);
//     insertHeap(40);
//     insertHeap(42);
//     insertHeap(99);

//     print(); // Print heap before deletion
//     deletefromHeap(); // Delete the root element from the heap
//     print(); // Print heap after deletion

//     return 0;
// }



#include <stdio.h>

int array[100];
int size = 0;

void insertHeap(int value)
{
    array[++size] = value; // Insert the new value at the end of the heap
    int index = size;

    while (index > 1)
    {
        int parentIndex = index / 2;
        if (array[parentIndex] < array[index])
        {
            // Swap parent and child to maintain heap property
            int temp = array[parentIndex];
            array[parentIndex] = array[index];
            array[index] = temp;
            index = parentIndex; // Move up the heap
        }
        else
        {
            return; // If heap property is maintained, exit
        }
    }
}

void deletefromHeap()
{
    if (size == 0)
    {
        return; // If the heap is empty, there's nothing to delete
    }

    array[1] = array[size]; // Replace root with the last element
    size--; // Reduce the heap size by one

    int i = 1;
    while (i <= size)
    {
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;

        // Corrected logic to swap with the larger child
        if (leftChild <= size && rightChild <= size)
        {
            if (array[leftChild] > array[rightChild] && array[i] < array[leftChild])
            {
                // Swap with left child if it's larger
                int temp = array[i];
                array[i] = array[leftChild];
                array[leftChild] = temp;
                i = leftChild;
            }
            else if (array[i] < array[rightChild])
            {
                // Swap with right child if it's larger
                int temp = array[i];
                array[i] = array[rightChild];
                array[rightChild] = temp;
                i = rightChild;
            }
            else
            {
                return;
            }
        }
        else if (leftChild <= size && array[i] < array[leftChild])
        {
            // Swap with left child if right child doesn't exist
            int temp = array[i];
            array[i] = array[leftChild];
            array[leftChild] = temp;
            i = leftChild;
        }
        else if (rightChild <= size && array[i] < array[rightChild])
        {
            // Swap with right child if left child doesn't exist
            int temp = array[i];
            array[i] = array[rightChild];
            array[rightChild] = temp;
            i = rightChild;
        }
        else
        {
            return; // If heap property is maintained, exit
        }
    }
}

void print()
{
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", array[i]); // Print the heap array
    }
    printf("\n");
}

int main()
{
    // Inserting elements into the heap
   
    print(); // Print heap before deletion
    deletefromHeap(); // Delete the root element from the heap
    print(); // Print heap after deletion

    return 0;
}
