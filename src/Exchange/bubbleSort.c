#include "exchange.h"

// Worst case performance O(n**2) comparisons and O(n**2) swaps
// Best case performance O(n) and O(1) swaps
// Average case performance O(n**2) comparisons and O(n**2) swaps

void bubbleSort(long int *array, int length){
    while(length > 1){ // Each loop eleminates the last element in array which is already sorted
        for(long int *i = array; i < array + length; i++){ // length - 1 comparisons for each loop
            if(*i > *(i+1)){ // Compare each 2 elements of the array
                *i = *i ^ *(i+1);
                *(i+1) = *i ^ *(i+1);
                *i = *i ^ *(i+1);
            }
        }
        length--;
    }
}
