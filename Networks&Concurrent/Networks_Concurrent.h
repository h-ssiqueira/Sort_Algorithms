#ifndef NETWORKS_CONCURRENT_H_
#define NETWORKS_CONCURRENT_H_

// Bitonic Sort
void BitonicSort(int array[], unsigned int low, unsigned int length, int direction);
// Auxiliar function for merging
void BitonicMerge(int array[], unsigned int start, unsigned int length, int direction);

// Pairwise Sort
void Pairwise_Sort(int array[], unsigned int start, unsigned int end, unsigned int piv);

#endif