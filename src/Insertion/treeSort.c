#include "insertion.h"

// Worst case performance О(n**2) comparisons
// Best case performance O(n log n) comparisons
// Average performance О(n log n) comparisons

// Function that releases the tree
Node* release(Node *T){
    if(T != NULL) {
        if(T->right != NULL) // Check if there's a node on right
            release(T->right);
        if(T->left != NULL) // Check if there's a node on left
            release(T->left);
        free(T); // Reaches a leaf and releases the node
    }
	return NULL;
}

// Function that stores the elements of the sorted tree in the array
void storeValueBinaryTree(Node *root, long int *array, int **i){
    if(root != NULL){
        if(root->left != NULL)
            storeValueBinaryTree(root->left, array, i);
        *(array + **i) = root->value;
        (**i)++;
        if(root->right != NULL)
            storeValueBinaryTree(root->right, array, i);
    }
}

// Function that creates new nodes for the tree
void insertNodeBinaryTree(Node **node, long int value){
    if(!(*node)){
        (*node) = malloc(sizeof(Node));
        if(!(*node)) return;
        (*node)->value = value;
        (*node)->left = (*node)->right = NULL;
    }
    else{
        if(value < (*node)->value)
            insertNodeBinaryTree(&(*node)->left,value);
        else// if(n > (*node)->value)
            insertNodeBinaryTree(&(*node)->right,value);
    }
}

void treeSort(long int *array, int length){
    Node *root = NULL;
    int i,*p;

    for(i ^= i; i < length; i++)
        insertNodeBinaryTree(&root, *(array + i));

    i ^= i;
    p = &i;
    storeValueBinaryTree(root, array, &p); // Store the values in the array
    root = release(root);
}
