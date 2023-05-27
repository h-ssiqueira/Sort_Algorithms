#include "selection.h"

// Worst case performance O(n log n)
// Best case performance O(n log n)
// Average performance O(n log n)

void heapMin(long int *array, int n, int i){ // n is the size of heap
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
	long int aux;

    if(left < n && array[left] < *(array + smallest)) // Left child is smaller than node
        smallest = left;

    if(right < n && array[right] < *(array + smallest)) // Right child is smaller than node
        smallest = right;

    if(smallest != i){ // Smaller is not the actual node
        aux = *(array + i);
        *(array + i) = *(array + smallest);
        *(array + smallest) = aux;

        heapMin(array, n, smallest); //Acess the subtree
    }
}

void minHeapSort(long int *array, int length){
	int i;
	long int aux;
    for(i = length / 2 - 1; i >= 0; i--)
        heapMin(array, length, i); // Creating the heap

    for(i = length-1; i >= 0; i--){ // Remove each element from heap
        aux = *(array + i);
        *(array + i) = *array;
        *array = aux;

        heapMin(array, i, 0); // Reduced heap
    }
}
