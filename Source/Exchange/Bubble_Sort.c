#include <stdio.h>
#include <stdlib.h>
#include "Exchange.h"

// Worst case performance O(n**2) comparisons and O(n**2) swaps
// Best case performance O(n) and O(1) swaps
// Average case performance O(n**2) comparisons and O(n**2) swaps

void Bubble_sort(long int array[], int length){
    while(length > 1){ // Each loop eleminates the last element in array which is already sorted
        for(int i = 0; i < length; i++){ // length - 1 comparisons for each loop
            if(array[i] > array[i+1]){ // Compare each 2 elements of the array
                array[i] = array[i] ^ array[i+1];
                array[i+1] = array[i] ^ array[i+1];
                array[i] = array[i] ^ array[i+1];
            }
        }
        length--;
    }
}

/*
int main(){
    long int array[] = {5,9,4,22,51,3,10,65,111,49},i;

    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    printf("\n\n");
    Bubble_sort(array,10-1);

    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);

    return 0;
}
*/