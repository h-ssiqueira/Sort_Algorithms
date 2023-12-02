#include "merge.h"

// Worst case performance O(n log n)
// Best case performance O(n log n), O(n) natural variant
// Average case performance O(n log n)
// Worst case comparisons between (n lg n − n + 1) and (n lg n + n + O(lg n))

void mergeBottomup(long int *array, int start, int middle, int end){
    int count1 = start, count2 = middle + 1, i;
	long int *aux = malloc((end - start + 1) * sizeof(long int));

    for(i ^= i; count1 <= middle && count2 <= end; i++){
        if(*(array + count1) < *(array + count2)){
            *(aux + i) = *(array + count1);
            count1++;
        }
        else{
            *(aux + i) = *(array + count2);
            count2++;
        }
    }
    while(count1 <= middle){
        *(aux + i) = *(array + count1);
        i++;
        count1++;
    }
    while(count2 <= end){
        *(aux + i) = *(array + count2);
        i++;
        count2++;
    }
    for(i = start; i <= end; i++)
        *(array + i) = *(aux + i - start);
    free(aux);
}

void bottomupMergeSort(long int *array, int length){
	int i, j;
    for(i = 1; i < length; i += i){ // Start sorting the elements 1-1, 2-2... powers of 2
        for(j ^= j; j < length - i; j += i + i){
            j + i + i - 1 < length-1 ? mergeBottomup(array, j, j + i - 1, j + i + i - 1) : mergeBottomup(array, j, j + i - 1, length -1); // merge
        }
    }
}
