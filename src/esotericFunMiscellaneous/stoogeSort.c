#include "esotericFunMiscellaneous.h"

 // Worst case performance O(n**2.709) or O(n**(log 3 / log 1.5))
 // Best case performance O(n**2.709) or O(n**(log 3 / log 1.5))
 // Average case performance O(n**2.709) or O(n**(log 3 / log 1.5))

void stoogeSort(long int *array, int i, int j){
    long int aux;
    if(*(array + i) > *(array + j)){ // Swap initially the fist and last elements
        aux = *(array + i);
        *(array + i) = *(array + j);
        *(array + j) = aux;
    }
    if(j - i > 1){
        aux = (j - i + 1) / 3;
        stoogeSort(array, i, j - aux); // Swap recursively the first 2/3 elements of the array
        stoogeSort(array, i + aux, j); // Swap recursively the last 2/3 elements of the array
        stoogeSort(array, i, j - aux); // Swap recursively again the first 2/3 elements of the array
    }
}
