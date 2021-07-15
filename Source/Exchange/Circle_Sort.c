#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Exchange.h"

// Worst case performance O(n log n log n)
// Best case performance O(n log n)

bool CircleSortAux(long int *start, long int *end){
	long int *p, *q, t;
	bool swap;

	if(start == end)
        return 0;

	for(swap ^= swap, p = start, q = end; p < q || (p == q && ++q); p++, q--) // (++q for odd center of array)
		if(*p > *q){
			t = *p;
            *p = *q;
            *q = t;
            swap = true;
        }
	return swap | CircleSortAux(start, q) | CircleSortAux(p, end);
}

void CircleSort(long int *array, int length){
	while(CircleSortAux(array, array + (length - 1)))
        continue;
}

/*
int main(){
	long int *array = {894,467,594,559,97,183,923,323,864,540},*i;
    for(i = array; i < array+10; i++)
        printf("%ld ", *i);
    printf("\n");
	CircleSort(array, 10);
    for(i = array; i < array+10; i++)
        printf("%ld ", *i);

	return 0;
}
*/