#include "exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n)
// Average case performance O(n log n)

void quickSort3Way(long int *array, int start, int end){
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
		quickSort3Way(array, start, low-1); // Recursively change the pivot
		quickSort3Way(array, great+1, end); // To sort the other elements
	}
}
