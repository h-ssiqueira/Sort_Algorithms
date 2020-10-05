#ifndef NETWORKS_CONCURRENT_H_
#define NETWORKS_CONCURRENT_H_

// Bitonic Sort
void BitonicSort(int array[], int low, int length, int direction);
// Auxiliar function for merging
void BitonicMerge(int array[], int start, int length, int direction);

// Pairwise Sort
void Pairwise_Sort(int array[], int start, int end, int piv);

#endif