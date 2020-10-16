#ifndef INSERTION_H_
#define INSERTION_H_

// Binary Insertion Sort
void InsertionSort(long int array[], int length);
// Binary seach for binary insertion sort
int BinarySearch(long int array[], int num, int start, int end);

// Cycle Sort
void CycleSort(long int array[], int length);

// Insertion Sort
void Insertion_Sort(long int array[], int length);

// Shell Sort
void ShellSort(long int array[], int length);

// Tree Sort
void TreeSort(long int array[], int length);
// Structure of the tree
typedef struct node{ 
    long int value;
    struct node *left, *right; 
}Node; 
// Function that releases the memory allocated
Node* Release(Node *T);
// Function that stores the values of the tree in the array
void Store(Node *root, long int array[], int **i);
// Function that insert a value inside the tree
void Insert(Node **node, long int value);

#endif