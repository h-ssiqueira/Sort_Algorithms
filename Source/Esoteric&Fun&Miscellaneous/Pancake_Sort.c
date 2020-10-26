#include <stdio.h>
#include <stdlib.h>
#include "Esoteric_Fun_Miscellaneous.h"

// Average case performance O(n**2)

void flip(long int array[], int i){ 
    int start = 0; 
    while(start < i){ 
        array[start] = array[i] ^ array[start];
        array[i] = array[i] ^ array[start];
        array[start] = array[i] ^ array[start];
        start++; 
        i--; 
    }
}
  
void PancakeSort(long int array[], int length){
    int aux,i = length,j;
    for(; i > 1; i--){ 
        aux = 0;
        for(j = 0; j < i; j++){ // Find the position of the greater element of the array
            if(array[j] > array[aux])
                aux = j;
        }
        if(aux != i-1){ // Move he greater element to the end of the array
            flip(array, aux); // Move the number to beginning
            flip(array, i-1); // Reverse the array
        } 
    }
}
 
/*
int main(){
    long int array[] = {82,458,594,767,876,700,943,751,7,368},i;
    
    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    
    printf("\n\n");
    PancakeSort(array,10);
    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    
    return 0;
}
*/