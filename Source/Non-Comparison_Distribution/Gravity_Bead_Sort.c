#include <stdio.h>
#include <stdlib.h>
#include "Non-Comparison_Distribution.h"

// O(1) All beads together, doing a single operation
// O(n**0.5) Realistic physical model
// O(n) Dropping the row of beads
// O(S) S is the sum of all beads

void BeadSort(long int array[], int length){
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

/*
int main(){
    long int array[] = {159,217,135,509,805,598,742,156,782,427},*i;

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    printf("\n\n");
    BeadSort(array,sizeof(array)/sizeof(long int));
    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    return 0;
}
*/