#include "esotericFunMiscellaneous.h"

 // Worst case performance O((n + 1)!)
 // Best case performance O(n)
 // Average case performance O((n + 1)!)

void bogoSort(long int *array, int n){
    long int aux, *i;
	int random;
    while(!isSortedRandomly(array,n)){
        for(i = array; i < array + n; i++){ // Tries to sort randomly
            aux = *i;
            random = rand() % n;
            *i = *(array + random);
            *(array + random) = aux;
        }
    }
}
