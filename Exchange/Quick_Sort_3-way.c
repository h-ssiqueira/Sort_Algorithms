#include <stdio.h>
#include <stdlib.h>
#include "Exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n)
// Average case performance O(n log n)

void QuickSort3way(int array[], unsigned int start, unsigned int end){
	if(end > start){
		unsigned int low = start, great = end, i = start;
		int aux, piv = array[start];
		while(i <= great){ // Set the pivot in the center of the array, sorting greaters and lowers values in the array comparing to pivot
			if(array[i] < piv){ // Compares if the value is lower than pivot
				aux = array[i]; // If so, change the positions of index and low
				array[i] = array[low];
				array[low] = aux;
				low++;
				i++;
			}
			else if(array[i] > piv){ // if the value is greater than pivot
				aux = array[i]; // if so, change the positions of index and great
				array[i] = array[great];
				array[great] = aux;
				great--;
			}
			else // if the value is the same as the pivot
				i++;
		}
		QuickSort3way(array, start, low-1); // Recursively change the pivot
		QuickSort3way(array, great+1, end); // To sort the other elements
	}
}

/*
int main(){
    int array[] = {691,943,746,940,402,962,402,725,140,294},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    
    QuickSort3way(array,0,10-1);
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    return 0;
}
*/