#ifndef EXCHANGE_H_
#define EXCHANGE_H_

#include <stdbool.h>

// Bubble Sort
void Bubble_sort(long int *array, int length);

// Circle Sort
void CircleSort(long int *array, int length);
// Auxiliar function that sort the array
bool CircleSortAux(long int *start, long int *end);

// Cocktail Shaker Sort
void CocktailShakerSort(long int *array, int length);

// Comb Sort
void CombSort(long int *array, int length);

// Dual Pivot Quick Sort
void DualPivotQuickSort(long int *array, int start, int end);

// Gnome Sort
void Gnome_Sort(long int *array, int length);

// Odd-Even Sort
void Odd_Even_Sort(long int *array, int length);

// Optimized Bubble Sort
void BubbleSortOptmized(long int *array, int length);

// Optimized Cocktail Shaker Sort
void OPTCocktailShakerSort(long int *array, int length);

// Optimized Gnome Sort
void Optimized_Gnome_Sort(long int *array, int length);

// 3-way Quick Sort
void QuickSort3way(long int *array, int start, int end);

// Quick Sort
void Quick_Sort(long int *array, int start, int end);

// Stable Quick Sort
void StableQuickSort(long int *array, int start, int end);
// Auxiliar function that sort the array
long int Sort(long int *array, int start, int end);

#endif