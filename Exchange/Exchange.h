#ifndef EXCHANGE_H_
#define EXCHANGE_H_

// Bubble Sort
void Bubble_sort(int array[], unsigned int length);

// Circle Sort
void CircleSort(int array[], unsigned int length);
// Auxiliar function that sort the array
int CircleSortAux(int start[], int end[]);

// Cocktail Shaker Sort
void CocktailShakerSort(int array[], unsigned int length);

// Comb Sort
void CombSort(int array[], unsigned int length);

// Dual Pivot Quick Sort
void DualPivotQuickSort(int array[], unsigned int start, unsigned int end);

// Gnome Sort
void Gnome_Sort(int array[], unsigned int length);

// Odd-Even Sort
void Odd_Even_Sort(int array[], unsigned int length);

// Optimized Bubble Sort
void BubbleSortOptmized(int array[], unsigned int length);

// Optimized Gnome Sort
void Optimized_Gnome_Sort(int array[], unsigned int length);

// 3-way Quick Sort
void QuickSort3way(int array[], unsigned int start, unsigned int end);

// Quick Sort
void Quick_Sort(int array[], unsigned int start, unsigned int end);

// Stable Quick Sort
void StableQuickSort(int array[], unsigned int start, unsigned int end);
// Auxiliar function that sort the array
int Sort(int array[], unsigned int start, unsigned int end);

#endif