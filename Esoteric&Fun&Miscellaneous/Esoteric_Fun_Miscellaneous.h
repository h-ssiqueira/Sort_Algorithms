#ifndef ESOTERIC_FUN_MISCELLANEOUS_H_
#define ESOTERIC_FUN_MISCELLANEOUS_H_

// Auxiliar function that check if the array is sorted
bool is_sorted(int a[], int n);


// Bad Sort
void BadSort(int array[], int length);

// Bogo Bogo Sort
void BogoBogoSort(int array[],int length);

// Bogo Sort
void bogo_sort(int a[], int n);

// Bubble Bogo Sort
void BubbleBogoSort(int array[], int length);

// Cocktail Bogo Sort
/////////void CocktailBogoSort(int array[], int length);

// Exchange Bogo Sort
void ExchangeBogoSort(int array[], int length);

// Less Bogo Sort
void LessBogoSort(int array[], int length);

// Pancake Sort
int PancakeSort(int array[], int length);
// Auxiliar function that "flips" the array
void flip(int array[], int i);

// Silly Sort
void SillySort(int array[],int start, int end);

// Slow Sort
void Slow_Sort(int array[],int start,int end);

// Spaghetti Sort
void SpaghettiSort(int array[], int length);

// Stooge Sort
void StoogeSort(int array[], int i, int j);

#endif