#ifndef ESOTERIC_FUN_MISCELLANEOUS_H_
#define ESOTERIC_FUN_MISCELLANEOUS_H_

#include <stdbool.h>

// Auxiliar function that check if the array is sorted
bool is_sorted(int a[], unsigned int n);


// Bad Sort
void BadSort(int array[], unsigned int length);

// Bogo Bogo Sort
void BogoBogoSort(int array[], unsigned int length);

// Bogo Sort
void bogo_sort(int a[], unsigned int n);

// Bubble Bogo Sort
void BubbleBogoSort(int array[], unsigned int length);

// Cocktail Bogo Sort
/////////void CocktailBogoSort(int array[], unsigned int length);

// Exchange Bogo Sort
void ExchangeBogoSort(int array[], unsigned int length);

// Less Bogo Sort
void LessBogoSort(int array[], unsigned int length);

// Pancake Sort
void PancakeSort(int array[], unsigned int length);
// Auxiliar function that "flips" the array
void flip(int array[], unsigned int i);

// Silly Sort
void SillySort(int array[], unsigned int start, unsigned int end);

// Slow Sort
void Slow_Sort(int array[], unsigned int start, unsigned int end);

// Spaghetti Sort
void SpaghettiSort(int array[], unsigned int length);

// Stooge Sort
void StoogeSort(int array[], unsigned int i, unsigned int j);

#endif