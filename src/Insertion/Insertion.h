#ifndef _INSERTION_H_
#define _INSERTION_H_

#include <stdbool.h>

// AVLTree Sort structure
typedef struct AVLT{
	int value;
	short BF;
	struct AVLT *left, *right;
}AVLT;
// Check if the node exists
inline bool Empty(AVLT *tree){
    return tree ? false : true;
}
// Calculate the height of children nodes
short Height(AVLT *tree);
// Calculate the balance factor of left and right children nodes heights
short CalculateBF(AVLT *tree);
/* Performs a left rotate in tree to keep balanced
x
.\
..y..->.y
...\...../.\
....z..x..z
*/
void LeftRotate(AVLT **tree);
/* Performs a right rotate in tree to keep balanced
....x
.../
..y..->y
./....../.\
z......z..x
*/
void RightRotate(AVLT **tree);
// Insert an element in the AVL tree
void insert(AVLT **tree, long int number);
// Release the allocated memory of AVL tree
AVLT* FreeMemory(AVLT *tree);
// Store all elements of all nodes back (and sorted) to array
void store(long int *array, AVLT *t, int **i);
// Main function to sort the array
void AVLTree_Sort(long int *array, int length);

// Binary Insertion Sort
void InsertionSort(long int *array, int length);
// Binary seach for binary insertion sort
int BinarySearch(long int *array, int num, int start, int end);

// Cycle Sort
void CycleSort(long int *array, int length);

// Insertion Sort
void Insertion_Sort(long int *array, int length);

// Patience Sort
void PatienceSort(long int *array, int length);

// Shell Sort
void ShellSort(long int *array, int length);

// Tree Sort (Binary Search tree)
void TreeSort(long int *array, int length);
// Structure of the tree
typedef struct node{
    long int value;
    struct node *left, *right;
}Node;
// Function that releases the memory allocated
Node* Release(Node *T);
// Function that stores the values of the tree in the array
void Store(Node *root, long int *array, int **i);
// Function that insert a value inside the tree
void Insert(Node **node, long int value);

#endif