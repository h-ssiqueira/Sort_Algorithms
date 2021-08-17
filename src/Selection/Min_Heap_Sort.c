#include <stdio.h>
#include <stdlib.h>
#include "Selection.h"

// Worst case performance O(n log n)
// Best case performance O(n log n)
// Average performance O(n log n)

void heapmin(long int *array, int n, int i){ //n is the size of heap
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
	long int aux;

    if(left < n && array[left] < *(array + smallest)) //Left child is smaller than node
        smallest = left;

    if(right < n && array[right] < *(array + smallest)) //Right child is smaller than node
        smallest = right;

    if(smallest != i){ //smaller is not the actual node
        aux = *(array + i);
        *(array + i) = *(array + smallest);
        *(array + smallest) = aux;

        heapmin(array, n, smallest); //Acess the subtree
    }
}

void MinHeapSort(long int *array, int length){
	int i;
	long int aux;
    for(i = length / 2 - 1; i >= 0; i--)
        heapmin(array, length, i); //Creating the heap

    for(i = length-1; i >= 0; i--){ //Remove each element from heap
        aux = *(array + i);
        *(array + i) = *array;
        *array = aux;

        heapmin(array, i, 0); //Reduced heap
    }
}

/*
int main(){
    long int array[] = {117,612,443,21,894,908,802,687,693,845},*i;

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    printf("\n\n");
    MinHeapSort(array,sizeof(array)/sizeof(long int));

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);
    return 0;
}
*/