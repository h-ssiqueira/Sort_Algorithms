#ifndef SELECTION_H_
#define SELECTION_H_

// Double Selection Sort
void Double_Selection_Sort(int array[], unsigned int length);

// Min Heap Sort
void MinHeapSort(int array[], unsigned int length);
// Auxiliar function to float max values
void heapmin(int array[], unsigned int n, unsigned int i);

// Max Heap Sort
void MaxHeapSort(int array[], unsigned int length);
// Auxiliar function to float min values
void heapmax(int array[], unsigned int n, unsigned int i);

// Selection Sort
void Selection_Sort(int array[], unsigned int length);

#endif