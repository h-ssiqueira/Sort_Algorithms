#include "selection.h"

// Worst case performance O(n**2) comparisons and O(n) swaps
// Best case performance O(n**2) comparisons and O(n) swaps
// Average performance O(n**2) comparisons and O(n) swaps

//(n**2 - n)/2 comparisons

void selectionSort(long int *array, int length){
    long int aux, *change, *i, *j;

    for(i = array; i < length-1 + array; i++){ // Last element won't have other to compair
        change = i;
        for(j = i+1; j < length + array; j++)
            if(*change > *j) // If the element is lower, collect the position
                change = j;
        if(i != change){ // If it has been modified, swap positions
            aux = *i;
            *i = *change;
            *change = aux;
        }
    }
}