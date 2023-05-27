#include "esotericFunMiscellaneous.h"

// Worst case performance O((n + 1)!)
// Best case performance O(n)
// Average case performance O((n + 1)!)

void bogoBogoSort(long int *array, int length){
    int size = 2,random;
	long int aux, *i;
    bool notsorted = true;

    while(notsorted){
        if(isSortedRandomly(array, size))
            size == length ? notsorted = false : size++;
        else
            size = 2;
        if(notsorted){
            for(i = array; i < array + size; i++){ //tries to sort randomly
                aux = *i;
                random = rand() % size;
                *i = *(array + random);
                *(array + random) = aux;
            }
        }
    }
}
