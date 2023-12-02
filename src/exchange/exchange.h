#ifndef _EXCHANGE_H_
#define _EXCHANGE_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(long int *array, int length);

void circleSort(long int *array, int length);
// Auxiliar function that sort the array
bool circleSortAux(long int *start, long int *end);

void cocktailShakerSort(long int *array, int length);

void combSort(long int *array, int length);

void dualPivotQuickSort(long int *array, int start, int end);

void gnomeSort(long int *array, int length);

void oddEvenSort(long int *array, int length);

void bubbleSortOptmized(long int *array, int length);

void optimizedCocktailShakerSort(long int *array, int length);

void optimizedGnomeSort(long int *array, int length);

void quickSort3Way(long int *array, int start, int end);

void quickSort(long int *array, int start, int end);

void stableQuickSort(long int *array, int start, int end);
// Auxiliar function that sort the array
long int sort(long int *array, int start, int end);

#endif