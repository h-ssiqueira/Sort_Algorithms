#include <stdio.h>
#include <stdlib.h>
#include "Insertion.h"

// Worst case performance O(n**3/2)
// Best case performance O(n log n)
// Average case performance undiscovered (h equation is not perfect yet)

void ShellSort(long int *array, int length){
    int h = 1;
	long int aux, *i, *j;

    while(h < length) // Set the value of h until reach the value of length or more
        h = 3 * h + 1;
    for(;h > 0; h /= 3){ // h starts decreasing the array
        for(i = h + array; i < array + length; i++){ // Will take the value of h, incrementing one by one
            aux = *i;
            for(j = i; j > h-1 + array && *(j - h) > aux; j -= h) // And j decreasing until the value of i
                *j = *(j - h); // Implementing the insertion sort
            *j = aux;
        }
    }
}

/*
int main(){
    long int array[] = {119,536,252,970,681,861,222,369,587,468},*i;

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ", *i);

    printf("\n\n");

    ShellSort(array,sizeof(array)/sizeof(long int));

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ", *i);
    return 0;
}
*/