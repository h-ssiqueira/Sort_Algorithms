#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n**2)
// Average case performance O(n**2)

void CocktailShakerSort(long int array[], int length){
    int start = 0,end = length - 1,i;
	long int aux;
    while(start < end){
        for(i = start; i < end; i++){
            if(array[i] > array[i+1]){
                /*
                array[i] = array[i] ^ array[i+1];
                array[i+1] = array[i] ^ array[i+1];
                array[i] = array[i] ^ array[i+1];
                */
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
            }
        }
        end--;
        for(i = end; i > start; i--){
            if(array[i] < array[i-1]){
                /*
                array[i] = array[i] ^ array[i-1];
                array[i-1] = array[i] ^ array[i-1];
                array[i] = array[i] ^ array[i-1];
                */
                aux = array[i];
                array[i] = array[i-1];
                array[i-1] = aux;
            }
        }
        start++;
    }
}

/*
int main(){
    long int array[] = {343,380,195,864,185,43,236,41,88,509},i;

    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    printf("\n\n");
    CocktailShakerSort(array,10);

    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    return 0;
}
*/