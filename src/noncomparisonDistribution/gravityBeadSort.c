#include "noncomparisonDistribution.h"

// O(1) All beads together, doing a single operation
// O(n**0.5) Realistic physical model
// O(n) Dropping the row of beads
// O(S) S is the sum of all beads

void beadSort(long int *array, int length){
	int j,k;
	long int sum, *i, max;
	char *beads;

	for(i = array + 1, max = *array; i < array + length; i++)
		if(*i > max)
            max = *i;

	beads = calloc(1, max * length);

	for(k ^= k; k < length; k++) // Set the beads
		for(j ^= j; j < *(array + k); j++)
			*(beads + k * max + j) = 1;

	for(j ^= j; j < max; j++){ // Count how many beads has each position
		for(sum = k ^= k; k < length; k++){
			sum += *(beads + k * max + j);
			*(beads + k * max + j) = 0;
		}
		for(k = length - sum; k < length; k++) // Set bottom sum beads
            *(beads + k * max + j) = 1;
	}

	for(k ^= k; k < length; k++){
		for(j ^= j; j < max && *(beads + k * max + j); j++)
            continue;
		*(array + k) = j;
	}
	free(beads);
}
