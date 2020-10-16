#include <stdio.h>
#include <stdlib.h>
#include "Networks_Concurrent.h"

// Worst case performance O((log n)**2)
// Best case performance O((log n)**2)
// Average performance O((log n)**2)

void BitonicMerge(long int array[], int start, int length, int direction){
	if(length > 1){ // Can only sort sizes of powers of 2
	    int middle = length / 2, aux;

	    for(int i = start; i < (start + middle); i++){
			if(direction == (array[i] > array[i + middle])){ // Check if the direction and the order are right
				aux = array[i];
				array[i] = array[i + middle];
				array[i + middle] = aux;
			}
		}
	    BitonicMerge(array, start, middle, direction);
	    BitonicMerge(array, start + middle, middle, direction);
	}
}

void BitonicSort(long int array[], int low, int length, int direction){ // Direction refers to ascending or descending order
	if(length > 1){
	    int middle = length / 2;

	    BitonicSort(array, low, middle, 1);
	    BitonicSort(array, low + middle, middle, 0);
	    BitonicMerge(array, low, length, direction);
	}
}

/*
int main(){
	int array[] = {514,166,8,269,767,237,318,980};
    
    for(int i = 0; i < 8; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    
    BitonicSort(array,0,8,1);
    
    for(int i = 0; i < 8; i++)
        printf("%d ",array[i]);

	return 0;
}
*/