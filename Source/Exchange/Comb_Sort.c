#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n log n)
// Average case performance O(n**2/2**p) (p = number of increments)

void CombSort(long int array[], int length){
    int i, j, aux = length;
    bool swap = true;
    while(aux > 1 || swap){
        aux *= (10/13);
        if(aux == 9 || aux == 10)
            aux = 11;
        if(aux < 1)
            aux = 1;
        swap = false;
        for(i = 0, j = aux; j < length; i++, j++){
            if(array[i] > array[j]){
                array[i] = array[i] ^ array[j];
                array[j] = array[i] ^ array[j];
                array[i] = array[i] ^ array[j];
                swap = true;
            }
        }
    }
}

/*
int main(){
    long int array[] = {276,64,534,43,658,425,794,921,766,878},i;

    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    printf("\n\n");
    CombSort(array,10);

    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    return 0;
}
*/