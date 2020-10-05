#ifndef SELECTION_H_
#define SELECTION_H_

// Double Selection Sort
void Double_Selection_Sort(int array[], int length);

// Min Heap Sort
void MinHeapSort(int array[], int length);
// Auxiliar function to float max values
void heapmin(int array[], int n, int i);

// Max Heap Sort
void MaxHeapSort(int array[], int length);
// Auxiliar function to float min values
void heapmax(int array[], int n, int i);

// Selection Sort
void Selection_Sort(int array[], int length);

#endif