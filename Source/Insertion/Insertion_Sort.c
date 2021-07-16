#include <stdio.h>
#include <stdlib.h>
#include "Insertion.h"

// Worst case performance О(n**2) comparisons
// Best case performance O(n) comparisons
// Average performance О(n**2) comparisons

void Insertion_Sort(long int *array, int length){
	long int aux, *i, *j;
    for(i = array + 1; i < array + length; i++){//i is always one step ahead j
        aux = *i; //collect the value of a position
        j = i - 1; //and the index of previous value
        while(j >= array && aux < *j){ //compares with the previous array until find the lower element
            *(j+1) = *j;//shift all values one index ahead
            j--;
        }
        *(j+1) = aux;//set the value on right position next to 'start' of array comparing with the index of i
    }
}

/*
int main(){
    long int array[] = {354,14,321,52,84,387,10,987,100,5}, *i;

    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);
    printf("\n\n");

    Insertion_Sort(array,10);//10 is the length

    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);
    return 0;
}
*/