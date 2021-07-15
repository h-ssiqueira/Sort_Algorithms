#include <stdio.h>
#include <stdlib.h>
#include "Exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n)
// Average case performance O(n log n)

void QuickSort3way(long int *array, int start, int end){
	if(end > start){
		int low = start, great = end;
		long int aux, piv = *(array+start), *i = array+start;
		while(i-array <= great){ // Set the pivot in the center of the array, sorting greaters and lowers values in the array comparing to pivot
			if(*i < piv){ // Compares if the value is lower than pivot
				aux = *i; // If so, change the positions of index and low
				*i = *(array+low);
				*(array+low) = aux;
				low++;
				i++;
			}
			else if(*i > piv){ // if the value is greater than pivot
				aux = *i; // if so, change the positions of index and great
				*i = *(array+great);
				*(array+great) = aux;
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
    long int *array = {691,943,746,940,402,962,402,725,140,294},*i;

    for(i = array; i < array+10; i++)
        printf("%ld ",*i);

    printf("\n\n");

    QuickSort3way(array,0,10-1);

    for(i = array; i < array+10; i++)
        printf("%ld ",*i);

    return 0;
}
*/