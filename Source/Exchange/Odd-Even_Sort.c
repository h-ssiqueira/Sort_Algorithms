#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n)

void Odd_Even_Sort(long int *array, int length){
    long int aux, *i, *j;
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for(i = array+1, j = array+2; i < array+length - 1; i += 2, j += 2){
            if(*i > *(i+1)){
                /*
                *i = *i ^ *j;
                *j = *i ^ *j;
                *i = *i ^ *j;
                */
                aux = *i;
                *i = *j;
                *j = aux;
                sorted = false;
            }
        }
        for(i = array, j = array+1; i < array+length - 1; i += 2, j += 2){
            if(*i > *(i+1)){
                /*
                *i = *i ^ *j;
                *j = *i ^ *j;
                *i = *i ^ *j;
                */
                aux = *i;
                *i = *j;
                *j = aux;
                sorted = false;
            }
        }
    }
}

/*
int main(){
    long int *array = {416,647,874,428,309,898,464,335,47,82},*i;

    for(i = array; i < array+sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);
    printf("\n\n");

    Odd_Even_Sort(array,sizeof(array)/sizeof(long int));

    for(i = array; i < array+sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);
    return 0;
}
*/