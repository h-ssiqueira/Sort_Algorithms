#include "networksConcurrent.h"

// Worst case performance O((log n)**2)
// Best case performance O((log n)**2)
// Average performance O((log n)**2)

void bitonicMerge(long int *array, int start, int length, int direction){
	if(length > 1){ // Can only sort sizes of powers of 2
	    int middle = length / 2, aux;

	    for(long int *i = array + start; i < (array + start + middle); i++){
			if(direction == (*i > *(i + middle))){ // Check if the direction and the order are right
				aux = *i;
				*i = *(i + middle);
				*(i + middle) = aux;
			}
		}
	    bitonicMerge(array, start, middle, direction);
	    bitonicMerge(array, start + middle, middle, direction);
	}
}

void bitonicSort(long int *array, int low, int length, int direction){ // Direction refers to ascending or descending order
	if(length > 1){
	    int middle = length / 2;

	    bitonicSort(array, low, middle, 1);
	    bitonicSort(array, low + middle, middle, 0);
	    bitonicMerge(array, low, length, direction);
	}
}
