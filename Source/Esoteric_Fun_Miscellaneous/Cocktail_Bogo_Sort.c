#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Esoteric_Fun_Miscellaneous.h"

bool IsMinSorted(long int *array, int min, int max){
    for(long int *i = array + max + 1; i < array + min; i++)
        if(*(i - 1) > *i)
            return false;
    return true;
}


bool IsMaxSorted(long int *array, int min, int max){
    for(long int *i = array + max - 1; i >= array + min; i--)
        if(*(i+1) < *i)
            return false;
    return true;
}


void CocktailBogoSort(long int *array, int length){
    int min, max = length - 1, random;
	long int aux;
	bool sortedmax, sortedmin;
	min ^= min;
    while(min < max){
        sortedmax = IsMaxSorted(array, min, max);
		sortedmin = IsMinSorted(array, max+1, min);
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
            sortedmax = IsMaxSorted(array, min, max);
			sortedmin = IsMinSorted(array, max+1, min);
        }
        if(sortedmin){
            min++;
            sortedmin = false;
        }
        if(sortedmax){
            max--;
            sortedmax = false;
        }
		if(min < max && !IsMinSorted(array, 0, length)){ // If both indexes go through each one
			min--;
			max++;
		}
    }
}

/*
int main(){
    srand(time(NULL));
    long int array[] = {920,153,587,320,302,722,902,916,637,346},*i;
    for(i = array; i < array + 5; i++)
        printf("%ld ",*i);

    printf("\n\n");

    CocktailBogoSort(array,5);

    for(i = array; i < array + 5; i++)
        printf("%ld ",*i);
    return 0;
}
*/