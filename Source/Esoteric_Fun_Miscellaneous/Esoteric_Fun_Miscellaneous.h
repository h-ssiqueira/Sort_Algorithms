#ifndef _ESOTERIC_FUN_MISCELLANEOUS_H_
#define _ESOTERIC_FUN_MISCELLANEOUS_H_

#include <stdbool.h>

// Auxiliar functions that check if the array is sorted

bool is_sorted1(long int *a, int n);
bool is_sorted2(long int *a, int n);
bool is_sorted3(long int *a, int n);
bool is_sorted4(long int *a, int n);
bool is_sorted5(long int *a, int n);
bool is_sorted6(long int *a, int n);


// Bad Sort
void BadSort(long int *array, int length);

// Bogo Bogo Sort
void BogoBogoSort(long int *array, int length);

// Bogo Sort
void bogo_sort(long int *array, int n);

// Bubble Bogo Sort
void BubbleBogoSort(long int *array, int length);

// Cocktail Bogo Sort
void CocktailBogoSort(long int *array, int length);
// Auxiliar functions that check if the subarrays is sorted

bool IsMaxSorted(long int *array, int min, int max);
bool IsMinSorted(long int *array, int min, int max);

// Exchange Bogo Sort
void ExchangeBogoSort(long int *array, int length);

// Less Bogo Sort
void LessBogoSort(long int *array, int length);

// Pancake Sort
void PancakeSort(long int *array, int length);
// Auxiliar function that "flips" the array
void flip(long int *array, long int *i);

// Silly Sort
void SillySort(long int *array, int start, int end);

// Slow Sort
void Slow_Sort(long int *array, int start, int end);

// Spaghetti Sort
void SpaghettiSort(long int *array, int length);

// Stooge Sort
void StoogeSort(long int *array, int i, int j);

#endif