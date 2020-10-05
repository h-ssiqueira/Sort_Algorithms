#include <stdio.h>
#include <stdlib.h>
#include "Esoteric_Fun_Miscellaneous.h"

// Multiply and surrender strategy
// O(n)
// Mix of bubble sort and merge sort

void SillySort(int array[], unsigned int start, unsigned int end){ 
    if(start < end){
		unsigned int mid = start + ((end - start) / 2); // Calculate the middle of the (sub)array
		
		SillySort(array, start, mid); // Calls recursively until rech pairs of the elements (array[i]->array[i+1])
		SillySort(array, mid + 1, end);
		if(array[start] > array[mid+1]){ // Sort the two elements
            array[start] = array[start] ^ array[mid+1];
            array[mid+1] = array[start] ^ array[mid+1];
            array[start] = array[start] ^ array[mid+1];
        }
		SillySort(array, start + 1, end); // Do the same but for start+1
	}
}

/*
int main(){
    int array[] = {17,691,128,110,238,445,690,183,288,607},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    SillySort(array,0,10-1);
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    return 0;
}
*/