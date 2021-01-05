#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Esoteric_Fun_Miscellaneous.h"

bool IsMinSorted(long int array[], int min, int max){
    for(int i = max+1; i < min; i++)
        if(array[i-1] > array[i])
            return false;
    return true;
}


bool IsMaxSorted(long int array[], int min, int max){
    for(int i = max-1; i >= min; i--)
        if(array[i+1] < array[i])
            return false;
    return true;
}


void CocktailBogoSort(long int array[], int length){
    int min = 0, max = length - 1, random;
	long int aux;
	bool sortedmax, sortedmin;

    while(min < max){
        sortedmax = IsMaxSorted(array, min, max);
		sortedmin = IsMinSorted(array, max+1, min);
        while(!sortedmax && !sortedmin){
			random = rand() % length;
			aux = array[random];
			if(aux > array[max]){
            	array[random] = array[max];
            	array[max] = aux;
			}
			else if(aux < array[min]){
			//random = rand() % length;
            	array[random] = array[min];
            	array[min] = aux;
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
        }/*
		if(min < max && !IsMinSorted(array, 0, length)){
			min--;
			max++;
		}*/
    }
}

/*
int main(){
    srand(time(NULL));
    long int array[] = {920,153,587,320/*,302/*,722,902,916,637,346*;/},i;
    for(i = 0; i < 4; i++)
        printf("%ld ",array[i]);

    printf("\n\n");

    CocktailBogoSort(array,4);

    for(i = 0; i < 4; i++)
        printf("%ld ",array[i]);
    return 0;
}
*/