#include "noncomparisonDistribution.h"

// O(N*W)

void countingByDigit(long int *array, int radix, int exp, long int min, int length){
	int bucket;
	long int *buckets = calloc(radix, sizeof(long int)), *output = malloc(length * sizeof(long int)), *i, *j;

	for(i = array; i < array + length; i++){
		bucket = floor(((*i - min) / exp) % radix);
		(*(buckets + bucket))++;
	}

	for(i = buckets + 1; i < buckets + radix; i++)
		*i += *(i - 1);

	for(i = array + length - 1; i >= array; i--){
		bucket = floor(((*i - min) / exp) % radix);
		*(output + (--(*(buckets + bucket)))) = *i;
	}

	for(i = array, j = output; i < array + length; i++, j++)
		*i = *j;
	free(buckets);
	free(output);
}

void radixLSDSort(long int *array, int length, int radix){
	radix |= 10;
	long int min = *array, max = *array, *i;
	int exp = 1;
	for(i = array + 1; i < array + length; i++){
		if(*i < min)
			min = *i;
		else if(*i > max)
			max = *i;
	}
	while((max - min) / exp >= 1){
		countingByDigit(array, radix, exp, min, length);
		exp *= radix;
	}

}
