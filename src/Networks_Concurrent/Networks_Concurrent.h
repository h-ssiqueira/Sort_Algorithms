#ifndef _NETWORKS_CONCURRENT_H_
#define _NETWORKS_CONCURRENT_H_

// Bitonic Sort
void BitonicSort(long int *array, int low, int length, int direction);
// Auxiliar function for merging
void BitonicMerge(long int *array, int start, int length, int direction);

// Pairwise Sort
void Pairwise_Sort(long int *array, int start, int end, int piv);

#endif