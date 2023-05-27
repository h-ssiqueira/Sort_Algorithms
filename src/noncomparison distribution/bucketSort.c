#include "noncomparisonDistribution.h"
#define buckets 10

// Worst case performance O(n**2)
// Best case performance O(n + k) k is the number of buckets
// Average performance O(n + k)


void insertionSortBinary(int length, long int **matrix){
	int i,j,k;
	long int aux;
	for(i ^= i; i < buckets; i++){
		for(j = 1; j < length; j++){
			aux = *(*(matrix + i) + j);
			k = j - 1;
			while(k >= 0 && *(*(matrix + i) + k) > aux){
				*(*(matrix + i) + k+1) = *(*(matrix + i) + k);
				k--;
			}
			*(*(matrix + i) + k+1) = aux;
		}
	}
}

void bucketSort(long int *array, int length){
    int i, j, k, range = 1;
	long int **b = calloc(buckets, sizeof(long int *));
	for(i ^= i; i < buckets; i++)
		*(b + i) = calloc(length, sizeof(long int));

    for(i = 1, j = *array; i < length; i++){ // Determine the range of buckets by getting the max value
        if(j < *(array + i))
            j = *(array + i);
    }
    while(j >= 1){ // Count how many digits the number has
        j /= 10;
        range *= 10; // Number of digits (quantity of zeros) to determine the range
    }

    for(i ^= i; i < length; i++){ // Sort the values to each bucket
        j = range / 10;
        k ^= k;
        while(j <= range){
            if(*(array + i) < j){
                *(*(b + k) + i) = *(array + i);
                break;
            }
            k++;
            j += (range / 10);
        }
    }

    insertionSortBinary(length,b); // After set the values to each bucket, sort each one using other algorithm

    for(i ^= i, k ^= k; i < buckets; i++){ // Merge all buckets to the original array
        for(j ^= j; j < length; j++){
            if(*(*(b + i) + j) != 0){
                *(array + k) = *(*(b + i) + j);
                k++;
            }
        }
    }
}
