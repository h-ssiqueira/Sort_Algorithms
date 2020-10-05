#ifndef INSERTION_H_
#define INSERTION_H_

// Binary Insertion Sort
void InsertionSort(int array[], unsigned int length);
// Binary seach for binary insertion sort
unsigned int BinarySearch(int array[], int num, unsigned int start, unsigned int end);

// Cycle Sort
void CycleSort(int array[], unsigned int length);

// Insertion Sort
void Insertion_Sort(int array[], unsigned int length);

// Shell Sort
void ShellSort(int array[], unsigned int length);

// Tree Sort
void TreeSort(int array[], unsigned int length);
// Structure of the tree
typedef struct node{ 
    int value; 
    struct node *left, *right; 
}Node; 
// Function that releases the memory allocated
Node* Release(Node *T);
// Function that stores the values of the tree in the array
void Store(Node *root, int array[], unsigned int **i);
// Function that insert a value inside the tree
void Insert(Node **node, int value);

#endif