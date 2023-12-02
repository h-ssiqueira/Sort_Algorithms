#include "exchange.h"

// Worst case performance O(n**2) comparisons and O(n**2) swaps
// Best case performance O(n) and O(1) swaps
// Average case performance O(n**2) comparisons and O(n**2) swaps

void bubbleSortOptmized(long int *array, int length){
    bool swap;
    long int aux, *i, *j;
    for(j = array; j < array+length; j++){
        swap = false;
        for(i = array; i < array+length - (j-array); i++){ // Sort all array and starts decreasing
            if(*(i+1) < *i){
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
