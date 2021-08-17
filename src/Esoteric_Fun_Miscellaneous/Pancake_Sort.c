#include <stdio.h>
#include <stdlib.h>
#include "Esoteric_Fun_Miscellaneous.h"

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

void PancakeSort(long int *array, int length){
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

/*
int main(){
    long int array[] = {82,458,594,767,876,700,943,751,7,368},*i;

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    printf("\n\n");
    PancakeSort(array,sizeof(array)/sizeof(long int));
    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    return 0;
}
*/