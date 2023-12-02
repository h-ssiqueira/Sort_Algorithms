#ifndef _INSERTION_H_
#define _INSERTION_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// AVLTree Sort structure
typedef struct AVLT{
	int value;
	short BF;
	struct AVLT *left, *right;
}AVLT;
// Check if the node exists
inline bool isEmpty(AVLT *tree){
    return !tree;
}
// Calculate the height of children nodes
short height(AVLT *tree);
// Calculate the balance factor of left and right children nodes heights
short calculateBF(AVLT *tree);
/* Performs a left rotate in tree to keep balanced
x
.\
..y..->.y
...\...../.\
....z..x..z
*/
void leftRotate(AVLT **tree);
/* Performs a right rotate in tree to keep balanced
....x
.../
..y..->y
./....../.\
z......z..x
*/
void rightRotate(AVLT **tree);
// Insert an element in the AVL tree
void insertNodeAVLTree(AVLT **tree, long int number);
// Release the allocated memory of AVL tree
AVLT* freeMemory(AVLT *tree);
// Store all elements of all nodes back (and sorted) to array
void storeValueAVLTree(long int *array, AVLT *t, int **i);
// Main function to sort the array
void AVLTreeSort(long int *array, int length);

// Binary Insertion Sort
void binaryInsertionSort(long int *array, int length);
// Binary seach for binary insertion sort
int binarySearch(long int *array, int num, int start, int end);

// Cycle Sort
void cycleSort(long int *array, int length);

// Insertion Sort
void insertionSort(long int *array, int length);

// Patience Sort
void patienceSort(long int *array, int length);

// Shell Sort
void shellSort(long int *array, int length);

// Tree Sort (Binary Search tree)
void treeSort(long int *array, int length);
// Structure of the tree
typedef struct node{
    long int value;
    struct node *left, *right;
}Node;
// Function that releases the memory allocated
Node* release(Node *T);
// Function that stores the values of the tree in the array
void storeValueBinaryTree(Node *root, long int *array, int **i);
// Function that insert a value inside the tree
void insertNodeBinaryTree(Node **node, long int value);

#endif