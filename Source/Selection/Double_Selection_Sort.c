#include <stdio.h>
#include <stdlib.h>
#include "Selection.h"

// Worst case performance O(n**2) comparisons and O(n) swaps
// Best case performance O(n**2) comparisons and O(n) swaps
// Average performance O(n**2) comparisons and O(n) swaps

//(n**2 - n)/4 comparisons


void Double_Selection_Sort(long int *array, int length){
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

/*
int main(){
    long int array[] = {5,98,-1,0,11,321,654,555,44,2}, *i;

    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);

    printf("\n\n");
    Double_Selection_Sort(array,10);

    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);

    return 0;
}
*/