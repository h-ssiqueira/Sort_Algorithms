#ifndef INSERTION_H_
#define INSERTION_H_

// Binary Insertion Sort
void InsertionSort(int array[], int length);
// Binary seach for binary insertion sort
int BinarySearch(int array[], int num, int start, int end);

// Cycle Sort
void CycleSort(int array[],int length);

// Insertion Sort
void Insertion_Sort(int array[],int length);

// Shell Sort
void ShellSort(int array[], int length);

// Tree Sort
void TreeSort(int array[], int length);
// Function that releases the memory allocated
Node* Release(Node *T);
// Function that stores the values of the tree in the array
void Store(Node *root, int array[], int **i);
// Function that insert a value inside the tree
void Insert(Node **node, int value)void Insert(Node **node, int value);

#endif