#include "noncomparisonDistribution.h"

// Worst case performance O(N + n) N -> range of key values, n -> input size

void pigeonholeSort(long int *array, int length){
    long int max = *array, min = *array, *i, *j;
	int range;

    for(i = array; i < array + length; i++){ // Collect max and min values of array
        if(*i > max)
            max = *i;
        if(*i < min)
            min = *i;
    }
    range = max - min + 1;
    long int *holes = calloc(range, sizeof(long int)); // Creates an array of ranges
    for(i = array; i < array + length; i++)
        (*(holes + *i - min))++; // Put the amount of times the value repeat in hole array in order
    for(i = holes, j = array; i < holes + range; i++)
        while((*i)-- > 0){
            *j = i - holes + min; // Insert the values to main array
			j++;
		}
	free(holes);
}
