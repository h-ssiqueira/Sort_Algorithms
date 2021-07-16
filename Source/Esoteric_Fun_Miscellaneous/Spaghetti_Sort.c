#include <stdio.h>
#include <stdlib.h>
#include "Esoteric_Fun_Miscellaneous.h"

// Average case performance O(n)

void SpaghettiSort(long int *array, int length){
	long int *aux = malloc(length * sizeof(long int)), min = *array, max = *array, *i, *j, k;
    for(i = array; i < array + length; i++){ // Find the max and min values in the array
        if(*i > max)
            max = *i;
        if(*i < min)
            min = *i;
    }
    for(k = min, j = aux; k <= max; k++){
        for(i = array; i < array + length; i++){
            if(*i == k){ // Find the followed elements after min value to write in the aux array
                *j = *i;
                j++;
            }
        }
    }
    for(i = array, j = aux; i < array + length; i++, j++) // Return the elements in the main array
        *i = *j;
	free(aux);
}

/*
int main(){
    long int array[] = {323,669,285,167,862,674,733,331,475,445},*i;

    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);

    printf("\n\n");
    SpaghettiSort(array,10);
    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);

    return 0;
}
*/