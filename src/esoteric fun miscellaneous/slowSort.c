#include "esotericFunMiscellaneous.h"

// Multiply and surrender strategy
// O(n)
// Mix of merge sort and bubble sort

void slowSort(long int *array, int start, int end){
    if(start >= end) return;
    int middle = (start + end) / 2;

    slowSort(array,start,middle); // start - middle parts
    slowSort(array,middle + 1,end); // middle - end parts
    if(*(array + end) < *(array + middle)){
        *(array + end) = *(array + end) ^ *(array + middle);
        *(array + middle) = *(array + end) ^ *(array + middle);
        *(array + end) = *(array + end) ^ *(array + middle);
    }
    slowSort(array,start,end-1); // Sort elements decreasing the array
}
