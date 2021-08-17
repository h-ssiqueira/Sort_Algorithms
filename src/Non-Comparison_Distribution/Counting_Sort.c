#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Non-Comparison_Distribution.h"

// Worst case performance O(n + k), k -> range of the non-negative key values
// Best case performance O(n + k)
// Average performance O(n + k)

void Counting_Sort(long int *array, int length){
    long int *output = malloc(length * sizeof(long int)), max = *array, min = *array, *i, *j;

    for(i = array; i < array + length; i++){
        if(*i > max) max = *i;
        if(*i < min) min = *i;
    }

    int range = max - min + 1;
	long int *count = calloc(range, sizeof(long int));

    for(i = array; i < array + length; i++)// Count how many times the value repeat
        (*(count + *i - min))++;
    for(i = count + 1; i < count + range; i++) // Count the amount of previous incidences
        *i += *(i - 1);
    for(i = array + length - 1; i >= array; i--){
		*(output + *(count + *i - min) - 1) = *i;// Putting the value on the corrected position && already sorted to an auxiliary array
		(*(count + *i - min))--;
	}
    for(i = array, j = output; i < array + length; i++, j++) // Transfering to original array
        *i = *j;
	free(count);
}

/*
int main(){
    long int array[] = {305,224,575,587,589,891,810,158,872,805}, *i;

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    printf("\n\n");
    Counting_Sort(array,sizeof(array)/sizeof(long int));
    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    return 0;
}
*/