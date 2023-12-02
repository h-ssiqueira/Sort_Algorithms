#ifndef _NETWORKS_CONCURRENT_H_
#define _NETWORKS_CONCURRENT_H_

#include <stdio.h>
#include <stdlib.h>

// Bitonic Sort
void bitonicSort(long int *array, int low, int length, int direction);
// Auxiliar function for merging
void bitonicMerge(long int *array, int start, int length, int direction);

// Pairwise Sort
void pairwiseSort(long int *array, int start, int end, int piv);

#endif