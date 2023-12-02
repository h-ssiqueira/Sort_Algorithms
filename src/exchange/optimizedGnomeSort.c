#include "exchange.h"

// *Worst case performance O(n**2)
// *Best case performance O(n)
// *Average case performance O(n**2)

void optimizedGnomeSort(long int *array, int length){
    long int aux, *j, *i;
	for(i = array; i < array+length; i++){
		j = i;
		while(j > array && *(j-1) > *j){
			aux = *j;
			*j = *(j-1);
			*(j-1) = aux;
			j--;
		}
	}
}
