#include <stdio.h>
#include <stdlib.h>
#include "Selection.h"

// Worst case performance O(n**2) comparisons and O(n) swaps
// Best case performance O(n**2) comparisons and O(n) swaps
// Average performance O(n**2) comparisons and O(n) swaps

//(n**2 - n)/4 comparisons


void Double_Selection_Sort(long int array[], int length){
    int i = 0, j = length - 1, k, min = i, max = j;
	long int aux;

    for(; i <= j; j--, i++, min = i, max = j){
        for(i = i; i <= j; i++){
            if(array[i] > array[max]) // Find the max element in the range
                max = i;
            if(array[i] < array[min]) // Find the min element in the range
                min = i;
        }
        if(max == i) // Check if has conflict with the index of the left
            max = min;

		aux = array[i];
		array[i] = array[min];
		array[min] = aux;

        aux = array[j];
		array[j] = array[max];
		array[max] = aux;
    }
}

/*
int main(){
    long int array[] = {5,98,-1,0,11,321,654,555,44,2};

    for(int i = 0; i < 10; i++)
        printf("%ld ",array[i]);

    printf("\n\n");
    Double_Selection_Sort(array,10);

    for(int i = 0; i < 10; i++)
        printf("%ld ",array[i]);

    return 0;
}
*/