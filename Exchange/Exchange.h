#ifndef EXCHANGE_H_
#define EXCHANGE_H_

// Bubble Sort
void Bubble_sort(int array[],int length);

// Circle Sort
void CircleSort(int array[], int length);
// Auxiliar function that sort the array
int CircleSortAux(int start[], int end[]);

// Cocktail Shaker Sort
void CocktailShakerSort(int array[], int length);

// Comb Sort
void CombSort(int array[], int length);

// Dual Pivot Quick Sort
void DualPivotQuickSort(int array[], int start, int end);

// Gnome Sort
void Gnome_Sort(int array[], int length);

// Odd-Even Sort
void Odd_Even_Sort(int array[],int length);

// Optimized Bubble Sort
void BubbleSortOptmized(int array[], int length);

// Optimized Gnome Sort
void Optimized_Gnome_Sort(int array[],int i);

// 3-way Quick Sort
void QuickSort3way(int array[], int start, int end);

// Quick Sort
void Quick_Sort(int array[], int start, int end);

// Stable Quick Sort
void StableQuickSort(int array[], int start, int end);
// Auxiliar function that sort the array
int Sort(int array[], int start, int end);

#endif