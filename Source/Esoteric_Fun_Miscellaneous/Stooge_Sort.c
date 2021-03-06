#include <stdio.h>
#include <stdlib.h>
#include "Esoteric_Fun_Miscellaneous.h"

 // Worst case performance O(n**2.709) or O(n**(log 3 / log 1.5))
 // Best case performance O(n**2.709) or O(n**(log 3 / log 1.5))
 // Average case performance O(n**2.709) or O(n**(log 3 / log 1.5))

void StoogeSort(long int array[], int i, int j){
    long int aux;
    if(*(array + i) > *(array + j)){ // Swap initially the fist and last elements
        aux = *(array + i);
        *(array + i) = *(array + j);
        *(array + j) = aux;
    }
    if(j - i > 1){
        aux = (j - i + 1) / 3;
        StoogeSort(array, i, j - aux); // Swap recursively the first 2/3 elements of the array
        StoogeSort(array, i + aux, j); // Swap recursively the last 2/3 elements of the array
        StoogeSort(array, i, j - aux); // Swap recursively again the first 2/3 elements of the array
    }
}

/*
int main(){
    long int array[] = {25,247,87,960,12,445,662,94,834,787}, *i;

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ", *i);

    printf("\n\n");
    StoogeSort(array,0,sizeof(array)/sizeof(long int)-1);

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ", *i);
    return 0;
}
*/