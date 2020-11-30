#include <stdio.h>
#include <stdlib.h>
#include "Insertion.h"

// Worst case performance O(n log n)
// Best case performance O(n)
// Average case performance O(n log n)

void PatienceSort(long int array[], int length){
	int i,j,row;
	long int *count = (long int*)calloc(sizeof(long int), length), sorted[length], decks[length][length], min;

	for(i = 0; i < length; i++){
		for(j = 0; j < length; j++){
			if(count[j] == 0 || (count[j] > 0 && decks[j][count[j]-1] >= array[i])){
				decks[j][count[j]] = array[i];
				count[j]++;
				break;
			}
		}
	}
	min = decks[0][count[0]-1];
	row = 0;
	for(i = 0; i < length; i++){
		for(j = 0; j < length; j++){
			if(count[j] > 0 && decks[j][count[j]-1] < min){
				min = decks[j][count[j]-1];
				row = j;
			}
		}
		sorted[i] = min;
		count[row]--;
		for(j = 0; j < length; j++)
			if(count[j] > 0){
				min = decks[j][count[j]-1];
				row = j;
				break;
			}
	}
	for(i = 0; i < length; i++)
		array[i] = sorted[i];
	free(count);
}

int main(){
    long int array[] = {476,531,924,866,73,9,987,464,215,487},i;

    for(i = 0; i < 10; i++)
        printf("%ld ", array[i]);

    printf("\n\n");

    PatienceSort(array,10);

    for(i = 0; i < 10; i++)
        printf("%ld ", array[i]);
    return 0;
}