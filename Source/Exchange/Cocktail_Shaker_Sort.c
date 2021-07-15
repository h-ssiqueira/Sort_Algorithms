#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n**2)
// Average case performance O(n**2)

void CocktailShakerSort(long int *array, int length){
    int start ^= start,end = length - 1;
	long int aux, *i;
    while(start < end){
        for(i = array+start; i < array+end; i++){
            if(*i > *(i+1)){
                /*
                *i = *i ^ *(i+1);
                *(i+1) = *i ^ *(i+1);
                *i = *i ^ *(i+1);
                */
                aux = *i;
                *i = *(i+1);
                *(i+1) = aux;
            }
        }
        end--;
        for(i = array+end; i > array+start; i--){
            if(*i < *(i-1)){
                /*
                *i = *i ^ *(i-1);
                *(i-1) = *i ^ *(i-1);
                *i = *i ^ *(i-1);
                */
                aux = *i;
                *i = *(i-1);
                *(i-1) = aux;
            }
        }
        start++;
    }
}

/*
int main(){
    long int *array = {343,380,195,864,185,43,236,41,88,509},*i;

    for(i = array; i < array+10; i++)
        printf("%ld ",*i);
    printf("\n\n");
    CocktailShakerSort(array,10);

    for(i = array; i < array+10; i++)
        printf("%ld ",*i);
    return 0;
}
*/