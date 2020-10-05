#include <stdio.h>
#include <stdlib.h>
#include "Non-Comparison_Distribution.h"

// O(1) All beads together, doing a single operation
// O(n**0.5) Realistic physical model
// O(n) Dropping the row of beads
// O(S) S is the sum of all beads
  
void BeadSort(int array[], unsigned int length){
	unsigned int i, j, max;
	int sum;
	char *beads;
 
	for(i = 1, max = array[0]; i < length; i++){
		if(array[i] > max) 
            max = array[i];
    }
 
	beads = (char*)calloc(1, max * length);
 
	for(i = 0; i < length; i++){ // Set the beads
		for(j = 0; j < array[i]; j++)
			beads[i * max + j] = 1;
    }
 
	for(j = 0; j < max; j++){ // Count how many beads has each position
		for(sum = i = 0; i < length; i++){
			sum += beads[i * max + j];
			beads[i * max + j] = 0;
		}
		for(i = length - sum; i < length; i++) // Set bottom sum beads
            beads[i * max + j] = 1;
	}
 
	for(i = 0; i < length; i++){
		for(j = 0; j < max && beads[i * max + j]; j++)
            continue;
		array[i] = j;
	}
	free(beads);
}

/*
int main(){
    int array[] = {159,217,135,509,805,598,742,156,782,427},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    BeadSort(array,10);
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    return 0;
}
*/