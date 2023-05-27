#include "esotericFunMiscellaneous.h"

void lessBogoSort(long int *array, int length){
    int random;
	long int aux, *i = array;
    while(i != length + array){
        while(!isSortedRandomly(array, i+1 - array)){ // Tries to sort randomly
            random = rand() % length;
            aux = *(array + random);
            *(array + random) = *i;
            *i = aux;
        }
        i++;
    }
}
