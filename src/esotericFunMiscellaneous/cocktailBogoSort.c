#include "esotericFunMiscellaneous.h"

bool isMinSorted(long int *array, int min, int max){
    for(long int *i = array + max + 1; i < array + min; i++)
        if(*(i - 1) > *i)
            return false;
    return true;
}


bool isMaxSorted(long int *array, int min, int max){
    for(long int *i = array + max - 1; i >= array + min; i--)
        if(*(i+1) < *i)
            return false;
    return true;
}


void cocktailBogoSort(long int *array, int length){
    int min, max = length - 1, random;
	long int aux;
	bool sortedmax, sortedmin;
	min ^= min;
    while(min < max){
        sortedmax = isMaxSorted(array, min, max);
		sortedmin = isMinSorted(array, max+1, min);
        while(!sortedmax && !sortedmin){
			random = rand() % length;
			aux = *(array + random);
			if(aux > *(array + max)){
            	*(array + random) = *(array + max);
            	*(array + max) = aux;
			}
			else if(aux < *(array + min)){
            	*(array + random) = *(array + min);
            	*(array + min) = aux;
			}
            sortedmax = isMaxSorted(array, min, max);
			sortedmin = isMinSorted(array, max+1, min);
        }
        if(sortedmin){
            min++;
            sortedmin = false;
        }
        if(sortedmax){
            max--;
            sortedmax = false;
        }
		if(min < max && !isMinSorted(array, 0, length)){ // If both indexes go through each one
			min--;
			max++;
		}
    }
}
