#include "merge.h"

// Worst case performance O(n log n)
// Best case performance O(n log n), O(n) natural variant
// Average case performance O(n log n)
// Worst case comparisons between (n lg n − n + 1) and (n lg n + n + O(lg n))

void merge(long int *array, int start, int middle, int end){
    int i;
	long int *aux = malloc((end - start + 1) * sizeof(long int)), *count1 = array + start, *count2 = array + middle + 1;

    for(i ^= i; count1 <= middle + array && count2 <= array + end; i++){
        if(*count1 < *count2){
            *(aux + i) = *count1;
            count1++;
        }
        else{
            *(aux + i) = *count2;
            count2++;
        }
    }
    while(count1 <= middle + array){
        *(aux + i) = *count1;
        i++;
        count1++;
    }
    while(count2 <= end + array){
        *(aux + i) = *count2;
        i++;
        count2++;
    }
    for(i = start; i <= end; i++)
        *(array + i) = *(aux + i - start);
    free(aux);
}

void mergeSort(long int *array, int start, int end){
    if(start < end){
        int middle = (start + end) / 2;

        mergeSort(array, start, middle); // first - middle parts
        mergeSort(array, middle + 1, end); // middle - end parts
        if(array[middle] < array[middle+1]) // Check if both parts are already sorted, if so, merge is useless
            return;
        merge(array, start, middle, end); // sort
    }
}
