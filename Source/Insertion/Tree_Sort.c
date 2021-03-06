#include <stdio.h>
#include <stdlib.h>
#include "Insertion.h"

// Worst case performance О(n**2) comparisons
// Best case performance O(n log n) comparisons
// Average performance О(n log n) comparisons
/*
typedef struct node{
    int value;
    struct node *left, *right;
}Node;
*/

// Function that releases the tree
Node* Release(Node *T){
	if(T->right != NULL) // Check if there's a node on right
		Release(T->right);
	if(T->left != NULL) // Check if there's a node on left
		Release(T->left);
	free(T); // Reaches a leaf and releases the node
	return NULL;
}

// Function that stores the elements of the sorted tree in the array
void Store(Node *root, long int *array, int **i){
    if(root != NULL){
        if(root->left != NULL)
            Store(root->left, array, &(*i));
        *(array + **i) = root->value;
        (**i)++;
        if(root->right != NULL)
            Store(root->right, array, &(*i));
    }
}

// Function that creates new nodes for the tree
void Insert(Node **node, long int value){
    if(!(*node)){
        (*node) = (Node*)malloc(sizeof(Node));
        if(!(*node)) return;
        (*node)->value = value;
        (*node)->left = (*node)->right = NULL;
    }
    else{
        if(value < (*node)->value)
            Insert(&(*node)->left,value);
        else// if(n > (*node)->value)
            Insert(&(*node)->right,value);
    }
}

void TreeSort(long int *array, int length){
    Node *root = NULL;
    int i,*p;

    for(i ^= i; i < length; i++)
        Insert(&root, *(array + i));

    i ^= i;
    p = &i;
    Store(root, array, &p); // Store the values in the array
    root = Release(root);
}

/*
int main(){
    long int array[] = {236,120,317,146,425,379,400,160,242,3}, *i;

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);
    printf("\n\n");

    TreeSort(array,sizeof(array)/sizeof(long int));

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);
    return 0;
}
*/