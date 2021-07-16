#include <stdio.h>
#include <stdlib.h>
#include "Insertion.h"

// Worst case performance О(n**2) comparisons
// Best case performance O(n**2) comparisons
// Average performance О(n**2) comparisons

void CycleSort(long int array[], int length){
    long int aux, swap, *i, *j, *k, *pos;

    for(i = array; i < array + length - 2; i++){
        aux = *i;

        pos = i;
        for(j = i + 1; j < array + length; j++) // Find the right position
            if(*j < aux)
                pos++;

        if(pos == i) // If the element is in correct position
            continue;

        while(aux == *pos) // For duplicate elements
            pos++;

        if(pos != i){ // Setting the element in correct position
            /*
            aux = aux ^ *pos;
            *pos = aux ^ *pos;
            aux = aux ^ *pos;
            */
            swap = aux;
            aux = *pos;
            *pos = swap;
        }

        while(pos != i){ // Rotating the cycle
            pos = i;

            for(k = i + 1; k < array + length; k++) // Find the right position
                if(*k < aux)
                    pos++;

            while(aux == *pos) // For duplicate elements
                pos++;

            if(aux != *pos){ // Setting the element in correct position
                /*
                aux = aux ^ *pos;
                *pos = aux ^ *pos;
                aux = aux ^ *pos;
                */
                swap = aux;
                aux = *pos;
                *pos = swap;
            }
        }
    }
}

/*
int main(){
    long int array[] = {807,449,650,900,745,539,390,112,447,973}, *i;

    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);
    printf("\n\n");

    CycleSort(array,10);

    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);
    return 0;
}
*/