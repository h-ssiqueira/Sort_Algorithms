#ifndef _HYBRIDS_H_
#define _HYBRIDS_H_

#include <stdio.h>
#include <stdlib.h>

// Tim Sort
void timSort(long int *array, int length);
// Auxiliar selection sort for tim sort
void insertionSortTim(long int *array, int left, int right);
// Auxiliar merge for tim sort
void mergeTim(long int *array, int l, int m, int r);


#endif