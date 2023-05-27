#ifndef _MERGE_H_
#define _MERGE_H_

#include <stdio.h>
#include <stdlib.h>

// Bottom-Up Merge Sort
void bottomupMergeSort(long int *array, int length);
// Auxiliar funciont to merge two subarrays
void mergeBottomup(long int *array, int start, int middle, int end);

// In Place Merge Sort
void mergeSortInPlace(long int *array, int start, int end);
// Auxiliar function to merge two subarrays
void mergeInPlace(long int *array, int start, int middle, int end);

// Merge Sort
void mergeSort(long int *array, int start, int end);
// Auxiliar function to merge two subarrays
void merge(long int *array, int start, int middle, int end);

#endif