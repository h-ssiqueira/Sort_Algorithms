#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Exchange.h"

// Worst case performance O(n**2) comparisons and O(n**2) swaps
// Best case performance O(n) and O(1) swaps
// Average case performance O(n**2) comparisons and O(n**2) swaps

void BubbleSortOptmized(long int array[], int length){
    bool swap;
    long int aux;
	int i, j;
    for(j = 0; j < length; j++){
        swap = false;
        for(i = 0; i < length - j; i++){ // Sort all array and starts decreasing
            if(array[i+1] < array[i]){
                /*
                array[i] = array[i] ^ array[i+1];
                array[i+1] = array[i] ^ array[i+1];
                array[i] = array[i] ^ array[i+1];
                */
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                swap = true;
            }
        }
        if(!swap) // No swapping happened: it's already sorted
            break;
    }
}

/*
int main(){
    long int array[] = {66,600,410,815,779,233,998,510,734,65},i;
    
    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
        
    printf("\n\n");
    
    BubbleSortOptmized(array,10-1);
    
    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);

    return 0;
}
*/