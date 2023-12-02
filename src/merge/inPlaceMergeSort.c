#include "merge.h"

// Complexity O(n log n)

void mergeInPlace(long int *array, int start, int middle, int end){
	long int value, *middle2 = array + middle + 1, *i;

    if(*(array + middle) <= *middle2) // If already sorted
        return;

    while(start <= middle && middle2 <= end + array){ // Merge both halves
        if(*(array + start) <= *middle2) // If the element is in place
            start++;
        else{
            value = *middle2;
            i = middle2;
            // Shift all the elements between element 1
            // element 2, right by 1.
            while(i != array + start){ // Move all elements until the beginning
                *i = *(i - 1);
                i--;
            }
            *(array + start) = value;
            start++;
            middle++;
            middle2++;
        }
    }
}

void mergeSortInPlace(long int *array, int start, int end){
    if(start < end){
        int middle = (end + start) / 2;

        mergeSortInPlace(array, start, middle); // First halves
        mergeSortInPlace(array, middle + 1, end); // Second halves
        if(*(array + middle) < *(array + middle + 1)) // Check if both parts are already sorted, if so, merge is useless
            return;
        mergeInPlace(array, start, middle, end);
    }
}
