#include <stdio.h>
#include <stdlib.h>
#include "Insertion.h"

// Worst case performance O(n log n)
// Best case performance O(n)
// Average case performance O(n log n)

void PatienceSort(long int *array, int length){
	int i,j,row;
	long int *count = (long int*)calloc(sizeof(long int), length), *sorted = malloc(length * sizeof(long int)), **decks = malloc(length * sizeof(long int *)), min;
	for(i ^= i; i < length; i++)
		*(decks + i) = malloc(length * sizeof(long int));

	for(i ^= i; i < length; i++){
		for(j ^= j; j < length; j++){
			if(*(count + j) == 0 || (*(count + j) > 0 && *(*(decks + j) + *(count + j) - 1) >= *(array + i))){
				*(*(decks + j) + *(count +j)) = *(array + i);
				(*(count + j))++;
				break;
			}
		}
	}
	min = *(*decks + *count - 1);
	row = 0;
	for(i ^= i; i < length; i++){
		for(j ^= j; j < length; j++){
			if(*(count + j) > 0 && *(*(decks + j) + *(count + j) - 1) < min){
				min = *(*(decks + j) + *(count + j) - 1);
				row = j;
			}
		}
		*(sorted + i) = min;
		(*(count + row))--;
		for(j ^= j; j < length; j++)
			if(*(count + j) > 0){
				min = *(*(decks + j) + *(count + j) - 1);
				row = j;
				break;
			}
	}
	for(i ^= i; i < length; i++)
		*(array + i) = *(sorted + i);
	free(sorted);
	for(i ^= i; i < length; i++)
		free(*(decks + i));
	free(decks);
	free(count);
}

/*
int main(){
    long int array[] = {476,531,924,866,73,9,987,464,215,487},*i;

    for(i = array; i < array + 10; i++)
        printf("%ld ", *i);

    printf("\n\n");

    PatienceSort(array,10);

    for(i = array; i < array + 10; i++)
        printf("%ld ", *i);
    return 0;
}
*/