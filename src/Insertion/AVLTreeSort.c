#include "insertion.h"

short height(AVLT *tree){
	short right,left;
	if(isEmpty(tree))
		return 0;
	right = height(tree->right);
	left = height(tree->left);
	return left > right ? (left+1) : (right+1);
}

short calculateBF(AVLT *tree){
	if(isEmpty(tree))
		return 0;
	return height(tree->left) - height(tree->right);
}

void leftRotate(AVLT **tree){
	AVLT *aux1 = (*tree)->right, *aux2 = aux1->left;
	aux1->left = (*tree);
	(*tree)->right = aux2;
	(*tree) = aux1;
	(*tree)->BF = calculateBF(*tree);
    aux1->left->BF = calculateBF(aux1->left);
    aux1->BF = calculateBF(aux1);
}

void rightRotate(AVLT **tree){
	AVLT *aux1 = (*tree)->left, *aux2 = aux1->right;
	aux1->right = (*tree);
	(*tree)->left = aux2;
	(*tree) = aux1;
	(*tree)->BF = calculateBF(*tree);
    aux1->right->BF = calculateBF(aux1->right);
    aux1->BF = calculateBF(aux1);
}

void insertNodeAVLTree(AVLT **tree, long int number){
	if(isEmpty(*tree)){
		(*tree) = malloc(sizeof(AVLT));
		if(isEmpty(*tree)) return;
		(*tree)->value = number;
		(*tree)->right = (*tree)->left = NULL;
	}
	else{
		if(number < (*tree)->value)
			insertNodeAVLTree(&(*tree)->left,number);
		if(number >= (*tree)->value)
			insertNodeAVLTree(&(*tree)->right,number);
	}
	(*tree)->BF = calculateBF(*tree);
	//if((*tree)->BF == 2 && (*tree)->left->BF == 1)
	//if((*tree)->BF < -1 && (*tree)->right->BF <= 0)
	if((*tree)->BF < -1 && number >= (*tree)->right->value)
		leftRotate(&(*tree));
	//if((*tree)->BF == -2 && (*tree)->right->BF == -1)
	//if((*tree)->BF > -1 && (*tree)->left->BF >= 0)
	if((*tree)->BF > 1 && number <= (*tree)->left->value)
		rightRotate(&(*tree));
	//if((*tree)->BF == -2 && (*tree)->right->BF == 1){
	//if((*tree)->BF > 1 && (*tree)->left->BF < 0){
	if((*tree)->BF < -1 && number <= (*tree)->right->value){
		rightRotate(&(*tree)->right);
		leftRotate(&(*tree));
	}
	//if((*tree)->BF == 2 && (*tree)->left->BF == -1){
	//if((*tree)->BF < -1 && (*tree)->right->BF > 0){
	if((*tree)->BF > 1 && number >= (*tree)->left->value){
		leftRotate(&(*tree)->left);
		rightRotate(&(*tree));
	}
}

AVLT* freeMemory(AVLT *tree){
	if(!isEmpty(tree)){
		freeMemory(tree->right);
		freeMemory(tree->left);
		free(tree);
		return NULL;
	}
}

void storeValueAVLTree(long int *array, AVLT *t, int **i){
    if(t != NULL){
        if(t->left != NULL)
            storeValueAVLTree(array, t->left, &(*i));
        *(array + **i) = t->value;
        (**i)++;
        if(t->right != NULL)
            storeValueAVLTree(array, t->right, &(*i));
    }
}

void AVLTreeSort(long int *array, int length){
    AVLT *tree = NULL;
    int *p,i;
    for(i ^= i; i < length; i++)
        insertNodeAVLTree(&tree,*(i+array));
    i ^= i;
    p = &i;
    storeValueAVLTree(array,tree,&p);
    tree = freeMemory(tree);
}
