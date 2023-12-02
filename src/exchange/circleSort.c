#include "exchange.h"

// Worst case performance O(n log n log n)
// Best case performance O(n log n)

bool circleSortAux(long int *start, long int *end){
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
	return swap | circleSortAux(start, q) | circleSortAux(p, end);
}

void circleSort(long int *array, int length){
	while(circleSortAux(array, array + (length - 1)))
        continue;
}
