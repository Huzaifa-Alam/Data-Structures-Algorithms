#include <stdio.h>

int insertHeap(array, size, value)
{
   int * array = (int*)malloc (size * ); 
   size += size;
   array[size] = value;
   int index = size;
   while (index > 1)
   {
      int parent = index / 2;
      if (array[size] < array[parent])
      {
         swap(array[size], array[parent]);
         index = parent;
      }
      else
      {
         return array;
      }
   }
}

int main()
{
   printf("Hello, Heap!\n");
   int value;
   int array = {70, 50, 40, 45, 35, 39, 16, 10, 9};
   int size = sizeof(array) / sizeof(array[0]);

   return 0;
}