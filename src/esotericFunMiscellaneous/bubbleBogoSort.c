#include "esotericFunMiscellaneous.h"

void bubbleBogoSort(long int *array, int length){
    int random;
	long int aux;
    while(!isSortedRandomly(array, length)){
        random = rand() % (length-1);
        if(*(array + random) > *(array + random + 1)){ // Tries to sort randomly the index and index+1
            aux = *(array + random);
            *(array + random) = *(array + random + 1);
            *(array + random + 1) = aux;
        }
    }
}
