#include<stdio.h>

int array[100];
int size = 0;
void insertHeap(int value){
    array[++size] = value;
    int index = size;

    while (index>1)
    {
        int parentIndex = index / 2; 
        if (array[parentIndex] < array[index])
        {
            int temp = array[parentIndex]; 
            array[parentIndex] = array[index];
            array[index] = temp;
            index = parentIndex;
        }
        else{
            return;
        }
    }   
}
void print(){
        for (int i =1 ; i <= size ; i++){
            printf("%d " ,array[i]); 
        }
        printf("\n");
    }
int main() {
    printf("1) Hello, world1\n");  
    insertHeap(30);
    insertHeap(32);
    insertHeap(12);
    insertHeap(40);
    insertHeap(42);
    insertHeap(99);

    print();

    printf("2) Hello, world 2\n");
    return 0;
}


