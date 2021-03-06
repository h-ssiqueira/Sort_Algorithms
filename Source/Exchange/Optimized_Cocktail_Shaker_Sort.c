#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n)
// Average case performance O(n**2)

void OPTCocktailShakerSort(long int *array, int length){
    int start,end = length - 1;
	long int aux, *i;
	bool swap = false;
	start ^= start;
    while(!swap && start < end){
        swap = true;
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
                swap = false;
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
                swap = false;
            }
        }
        start++;
    }
}

/*
int main(){
    long int *array = {508,135,423,546,98,809,857,946,225,81},*i;

    for(i = array; i < array+sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);
    printf("\n\n");
    OPTCocktailShakerSort(array,sizeof(array)/sizeof(long int));

    for(i = array; i < array+sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);
    return 0;
}
*/
