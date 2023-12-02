#ifndef _SELECTION_H_
#define _SELECTION_H_

#include <stdio.h>
#include <stdlib.h>

void doubleSelectionSort(long int *array, int length);

void minHeapSort(long int *array, int length);
// Auxiliar function to float max values
void heapMin(long int *array, int n, int i);

void maxHeapSort(long int *array, int length);
// Auxiliar function to float min values
void heapMax(long int *array, int n, int i);

void selectionSort(long int *array, int length);

#endif