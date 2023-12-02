#include "insertion.h"

// Worst case performance О(n**2) comparisons
// Best case performance O(n) comparisons
// Average performance О(n**2) comparisons

void insertionSort(long int *array, int length){
	long int aux, *i, *j;
    for(i = array + 1; i < array + length; i++){ // i is always one step ahead j
        aux = *i; // Collect the value of a position
        j = i - 1; // And the index of previous value
        while(j >= array && aux < *j){ // Compares with the previous array until find the lower element
            *(j+1) = *j; // Shift all values one index ahead
            j--;
        }
        *(j+1) = aux; // Set the value on right position next to 'start' of array comparing with the index of i
    }
}
