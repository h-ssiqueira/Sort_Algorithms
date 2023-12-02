#include "insertion.h"

// Worst case performance O(n**3/2)
// Best case performance O(n log n)
// Average case performance undiscovered (h equation is not perfect yet)

void shellSort(long int *array, int length){
    int h = 1;
	long int aux, *i, *j;

    while(h < length) // Set the value of h until reach the value of length or more
        h = 3 * h + 1;
    for(;h > 0; h /= 3){ // h starts decreasing the array
        for(i = h + array; i < array + length; i++){ // Will take the value of h, incrementing one by one
            aux = *i;
            for(j = i; j > h-1 + array && *(j - h) > aux; j -= h) // And j decreasing until the value of i
                *j = *(j - h); // Implementing the insertion sort
            *j = aux;
        }
    }
}
