#include "esotericFunMiscellaneous.h"

// Average case performance O(n**2)

void flip(long int *array, long int *i){
    long int *start = array;
    while(start < i){
        *start = *i ^ *start;
        *i = *i ^ *start;
        *start = *i ^ *start;
        start++;
        i--;
    }
}

void pancakeSort(long int *array, int length){
    long int *aux, *i = array + length, *j;
    for(; i > array + 1; i--){
        aux = array;
        for(j = array; j < i; j++) // Find the position of the greater element of the array
            if(*j > *aux)
                aux = j;
        if(aux != i-1){ // Move he greater element to the end of the array
            flip(array, aux); // Move the number to beginning
            flip(array, i-1); // Reverse the array
        }
    }
}
