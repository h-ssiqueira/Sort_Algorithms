#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Non-Comparison_Distribution.h"

// O(N*W)

void CountingByDigit(long int array[], int radix, int exp, long int min, int length){
	int i, bucket;
	long int buckets[radix], output[length];

	for(i = 0; i < radix; i++)
		buckets[i] = 0;

	for(i = 0; i < length; i++){
		bucket = floor(((array[i] - min) / exp) % radix);
		buckets[bucket]++;
	}

	for(i = 1; i < radix; i++)
		buckets[i] += buckets[i - 1];

	for(i = length - 1; i >= 0; i--){
		bucket = floor(((array[i] - min) / exp) % radix);
		output[--buckets[bucket]] = array[i];
	}

	for(i = 0; i < length; i++)
		array[i] = output[i];
}

void Radix_LSD(long int array[], int length, int radix){
	radix |= 10;
	long int min = array[0], max = array[0];
	int exp = 1;
	for(int i = 1; i < length; i++){
		if(array[i] < min)
			min = array[i];
		else if(array[i] > max)
			max = array[i];
	}
	while((max - min) / exp >= 1){
		CountingByDigit(array, radix, exp, min, length);
		exp *= radix;
	}

}


/*
int main(){
    long int array[] = {838,790,306,768,656,465,890,4,921,430},i;

    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);

    printf("\n\n");

    Radix_LSD(array,10,10);

    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);

    return 0;
}
*/