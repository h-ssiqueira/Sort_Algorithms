#include "esotericFunMiscellaneous.h"

void exchangeBogoSort(long int *array, int length){
    int random1, random2;
	long int aux;
    while(!isSortedRandomly(array, length)){
        random1 = rand() % length;
        random2 = rand() % length;
        if(random1 < random2){ // Check the positions
            if(*(array + random1) > *(array + random2)){ // Check if it's sorted
                aux = *(array + random1);
                *(array + random1) = *(array + random2);
                *(array + random2) = aux;
            }
        }
        else{
            if(*(array + random1) < *(array + random2)){ // Check if it's sorted
                aux = *(array + random1);
                *(array + random1) = *(array + random2);
                *(array + random2) = aux;
            }
        }
    }
}
