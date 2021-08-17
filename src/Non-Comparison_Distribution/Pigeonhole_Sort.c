#include <stdio.h>
#include <stdlib.h>
#include "Non-Comparison_Distribution.h"

// Worst case performance O(N + n) N -> range of key values, n -> input size

void Pigeonhole_Sort(long int *array, int length){
    long int max = *array, min = *array, *i, *j;
	int range;

    for(i = array; i < array + length; i++){ //collect max and min values of array
        if(*i > max)
            max = *i;
        if(*i < min)
            min = *i;
    }
    range = max - min + 1;
    long int *holes = calloc(range, sizeof(long int)); //creates an array of ranges
    for(i = array; i < array + length; i++)
        (*(holes + *i - min))++; //put the amount of times the value repeat in hole array in order
    for(i = holes, j = array; i < holes + range; i++)
        while((*i)-- > 0){
            *j = i - holes + min; //insert the values to main array
			j++;
		}
	free(holes);
}

/*
int main(){
    long int array[] = {2,20,1,7,3,5,2,-11,2,1},*i;

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    printf("\n\n");

    Pigeonhole_Sort(array,sizeof(array)/sizeof(long int));

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    return 0;
}
*/