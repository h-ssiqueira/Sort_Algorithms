#include "esotericFunMiscellaneous.h"

// Multiply and surrender strategy
// O(n)
// Mix of bubble sort and merge sort

void sillySort(long int *array, int start, int end){
    if(start < end){
		int mid = start + ((end - start) / 2); // Calculate the middle of the (sub)array

		sillySort(array, start, mid); // Calls recursively until rech pairs of the elements (array[i]->array[i+1])
		sillySort(array, mid + 1, end);
		if(*(array + start) > *(array + mid + 1)){ // Sort the two elements
            *(array + start) = *(array + start) ^ *(array + mid + 1);
            *(array + mid + 1) = *(array + start) ^ *(array + mid + 1);
            *(array + start) = *(array + start) ^ *(array + mid + 1);
        }
		sillySort(array, start + 1, end); // Do the same but for start+1
	}
}
