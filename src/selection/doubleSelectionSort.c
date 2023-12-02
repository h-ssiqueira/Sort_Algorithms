#include "selection.h"

// Worst case performance O(n**2) comparisons and O(n) swaps
// Best case performance O(n**2) comparisons and O(n) swaps
// Average performance O(n**2) comparisons and O(n) swaps

//(n**2 - n)/4 comparisons


void doubleSelectionSort(long int *array, int length){
    long int *i = array, *j = array + length - 1, *min = i, *max = j, aux;

    for(; i <= j; j--, i++, min = i, max = j){
        for(long int *k = i; k <= j; k++){
            if(*k > *max) // Find the max element in the range
                max = k;
            if(*k < *min) // Find the min element in the range
                min = k;
        }
        if(max == i) // Check if has conflict with the index of the left
            max = min;

		aux = *i;
		*i = *min;
		*min = aux;

		aux = *j;
		*j = *max;
		*max = aux;
    }
}
