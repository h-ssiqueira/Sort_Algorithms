#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Esoteric_Fun_Miscellaneous.h"

bool IsMinSorted(long int array[], int limit, int aux){
    for(int i = aux + 1; i <= limit; i++)
        if(array[aux] > array[i])
            return false;
    return true;
}

bool IsMaxSorted(long int array[], int min, int max){
    for(int i = max; i >= min; i--)
        if(array[max] < array[i])
            return false;
    return true;
}

void CocktailBogoSort(long int array[], int length){
    int min = 0, max = length - 1, random = -1;
	long int aux;
	bool sortedmax, sortedmin;

    while(min < max){
        sortedmax = IsMaxSorted(array, min, max);
		sortedmin = IsMinSorted(array, max, min);
        while(!sortedmax && !sortedmin){
			random = rand() % max;
            aux = array[random];
            array[random] = array[max];
            array[max] = aux;
            sortedmax = IsMaxSorted(array, min, max);
			sortedmin = IsMinSorted(array, max, min);
        }
        if(sortedmin){
            min++;
            sortedmin = false;
        }
        if(sortedmax){
            max--;
            sortedmax = false;
        }
    }
}

/*
int main(){
    srand(time(NULL));
    long int array[] = {920,153,587,320,302,722,902,916,637,346},i;
    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);

    printf("\n\n");

    CocktailBogoSort(array,10);

    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    return 0;
}
*/