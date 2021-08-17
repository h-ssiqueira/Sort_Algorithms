#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Exchange.h"

// Worst case performance O(n**2) comparisons and O(n**2) swaps
// Best case performance O(n) and O(1) swaps
// Average case performance O(n**2) comparisons and O(n**2) swaps

void BubbleSortOptmized(long int *array, int length){
    bool swap;
    long int aux, *i, *j;
    for(j = array; j < array+length; j++){
        swap = false;
        for(i = array; i < array+length - (j-array); i++){ // Sort all array and starts decreasing
            if(*(i+1) < *i){
                /*
                *i = *i ^ *(i+1);
                *(i+1) = *i ^ *(i+1);
                *i = *i ^ *(i+1);
                */
                aux = *i;
                *i = *(i+1);
                *(i+1) = aux;
                swap = true;
            }
        }
        if(!swap) // No swapping happened: it's already sorted
            break;
    }
}

/*
int main(){
    long int *array = {66,600,410,815,779,233,998,510,734,65},*i;

    for(i = array; i < array+sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    printf("\n\n");

    BubbleSortOptmized(array,sizeof(array)/sizeof(long int)-1);

    for(i = array; i < array+sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    return 0;
}
*/