#include "insertion.h"

// Worst case performance О(n**2) comparisons
// Best case performance O(n**2) comparisons
// Average performance О(n**2) comparisons

void cycleSort(long int array[], int length){
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
                swap = aux;
                aux = *pos;
                *pos = swap;
            }
        }
    }
}
