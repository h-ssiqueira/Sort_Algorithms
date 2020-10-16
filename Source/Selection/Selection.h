#ifndef SELECTION_H_
#define SELECTION_H_

// Double Selection Sort
void Double_Selection_Sort(long int array[], int length);

// Min Heap Sort
void MinHeapSort(long int array[], int length);
// Auxiliar function to float max values
void heapmin(long int array[], int n, int i);

// Max Heap Sort
void MaxHeapSort(long int array[], int length);
// Auxiliar function to float min values
void heapmax(long int array[], int n, int i);

// Selection Sort
void Selection_Sort(long int array[], int length);

#endif