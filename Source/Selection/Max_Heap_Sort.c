#include <stdio.h>
#include <stdlib.h>
#include "Selection.h"

// Worst case performance O(n log n)
// Best case performance O(n log n)
// Average performance O(n log n)

void heapmax(long int *array, int n, int i){ //n is the size of heap
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
	long int aux;

    if(left < n && *(array + left) > *(array + largest)) //Left child is larger than node
        largest = left;

    if(right < n && *(array + right) > *(array + largest)) //Right child is larger than node
        largest = right;

    if(largest != i){ //Larger is not the actual node
        aux = *(array + i);
        *(array + i) = *(array + largest);
        *(array + largest) = aux;

        heapmax(array, n, largest); //Acess the subtree
    }
}

void MaxHeapSort(long int *array, int length){
	int i;
	long int aux;
    for(i = length / 2 - 1; i >= 0; i--)
        heapmax(array, length, i); //Creating the heap

    for(i = length-1; i > 0; i--){ //Remove each element from heap
        aux = *(array + i);
        *(array + i) = *array;
        *array = aux;

        heapmax(array, i, 0); //Reduced heap
    }
}

/*
int main(){
    long int array[] = {423,816,549,499,789,769,463,516,846,473},*i;

    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);

    printf("\n\n");
    MaxHeapSort(array,10);

    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);
    return 0;
}
*/