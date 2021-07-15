#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n log n)
// Average case performance O(n**2/2**p) (p = number of increments)

void CombSort(long int *array, int length){
    int aux = length;
	long int *i, *j;
    bool swap = true;
    while(aux > 1 || swap){
        aux *= (10/13);
        if(aux == 9 || aux == 10)
            aux = 11;
        if(aux < 1)
            aux = 1;
        swap = false;
        for(i = array, j = array+aux; j < array+length; i++, j++){
            if(*i > *j){
                *i = *i ^ *j;
                *j = *i ^ *j;
                *i = *i ^ *j;
                swap = true;
            }
        }
    }
}

/*
int main(){
    long int *array = {276,64,534,43,658,425,794,921,766,878},*i;

    for(i = array; i < array+10; i++)
        printf("%ld ",*i);
    printf("\n\n");
    CombSort(array,10);

    for(i = array; i < array+10; i++)
        printf("%ld ",*i);
    return 0;
}
*/