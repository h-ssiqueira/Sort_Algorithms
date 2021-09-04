#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Insertion.h"

/*
typedef struct AVLT{
	int value;
	short BF;
	struct AVLT *left, *right;
}AVLT;


bool Empty(AVLT *tree){
	return tree ? false : true;
}

void Preorder(AVLT *tree){
	if(!Empty(tree)){
		printf("%d(%d) ", tree->value,tree->BF);
		Preorder(tree->left);
		Preorder(tree->right);
	}
}*/

short Height(AVLT *tree){
	short right,left;
	if(Empty(tree))
		return 0;
	right = Height(tree->right);
	left = Height(tree->left);
	return left > right ? (left+1) : (right+1);
}

short CalculateBF(AVLT *tree){
	if(Empty(tree))
		return 0;
	return Height(tree->left) - Height(tree->right);
}

void LeftRotate(AVLT **tree){
	AVLT *aux1 = (*tree)->right, *aux2 = aux1->left;
	aux1->left = (*tree);
	(*tree)->right = aux2;
	(*tree) = aux1;
	(*tree)->BF = CalculateBF(*tree);
    aux1->left->BF = CalculateBF(aux1->left);
    aux1->BF = CalculateBF(aux1);
}

void RightRotate(AVLT **tree){
	AVLT *aux1 = (*tree)->left, *aux2 = aux1->right;
	aux1->right = (*tree);
	(*tree)->left = aux2;
	(*tree) = aux1;
	(*tree)->BF = CalculateBF(*tree);
    aux1->right->BF = CalculateBF(aux1->right);
    aux1->BF = CalculateBF(aux1);
}

void insert(AVLT **tree, long int number){
	if(Empty(*tree)){
		(*tree) = malloc(sizeof(AVLT));
		if(Empty(*tree)) return;
		(*tree)->value = number;
		(*tree)->right = (*tree)->left = NULL;
	}
	else{
		if(number < (*tree)->value)
			insert(&(*tree)->left,number);
		if(number >= (*tree)->value)
			insert(&(*tree)->right,number);
	}
	(*tree)->BF = CalculateBF(*tree);
	//if((*tree)->BF == 2 && (*tree)->left->BF == 1)
	//if((*tree)->BF < -1 && (*tree)->right->BF <= 0)
	if((*tree)->BF < -1 && number >= (*tree)->right->value)
		LeftRotate(&(*tree));
	//if((*tree)->BF == -2 && (*tree)->right->BF == -1)
	//if((*tree)->BF > -1 && (*tree)->left->BF >= 0)
	if((*tree)->BF > 1 && number <= (*tree)->left->value)
		RightRotate(&(*tree));
	//if((*tree)->BF == -2 && (*tree)->right->BF == 1){
	//if((*tree)->BF > 1 && (*tree)->left->BF < 0){
	if((*tree)->BF < -1 && number <= (*tree)->right->value){
		RightRotate(&(*tree)->right);
		LeftRotate(&(*tree));
	}
	//if((*tree)->BF == 2 && (*tree)->left->BF == -1){
	//if((*tree)->BF < -1 && (*tree)->right->BF > 0){
	if((*tree)->BF > 1 && number >= (*tree)->left->value){
		LeftRotate(&(*tree)->left);
		RightRotate(&(*tree));
	}
}

AVLT* FreeMemory(AVLT *tree){
	if(!Empty(tree)){
		FreeMemory(tree->right);
		FreeMemory(tree->left);
		free(tree);
		return NULL;
	}
}
/*
int lv(AVLT *A){
    int aux,aux2;
    if(A->right == NULL && A->left == NULL)
        return 0;
    if(A->left != NULL)
        aux = 1 + lv(A->left);
    if(A->right != NULL)
        aux2 = 1 + lv(A->right);
    return aux > aux2 ? aux : aux2;
}

int leaves(AVLT *a){
    if(!a) return 0;
    if(a->right != NULL || a->left != NULL)
        return leaves(a->right) + leaves(a->left);
    return 1;
}

int totalnodes(AVLT *t){
	if(!t) return 0;
	return 1 + totalnodes(t->left) + totalnodes(t->right);
}*/

void store(long int *array, AVLT *t, int **i){
    if(t != NULL){
        if(t->left != NULL)
            store(array, t->left, &(*i));
        *(array + **i) = t->value;
        (**i)++;
        if(t->right != NULL)
            store(array, t->right, &(*i));
    }
}

void AVLTree_Sort(long int *array, int length){
    AVLT *tree = NULL;
    int *p,i;
    for(i ^= i; i < length; i++)
        insert(&tree,*(i+array));
    i ^= i;
    p = &i;
    store(array,tree,&p);
    tree = FreeMemory(tree);
}

/*
int main(){
    long int array[] = {100,214,267,324,718,128,606,116,811,397}, *i;

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);
    printf("\n\n");

    AVLTree_Sort(array,sizeof(array)/sizeof(long int));

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);
    /*
    srand(time(NULL));
	AVLT *t = NULL;
    long int *array;
    int len = rand() % 10+2;
    array = calloc(len,sizeof(int));
    //long int array[] = {417,564,545}, len = sizeof(array) / sizeof(int);
    for(int j = 0; j < 10; j++){
        for(int i = 0; i < len; i++){
            array[i] = rand() % 1000;
            printf("%d\n",array[i]);
            Insert(&t,array[i]);
        }
        Preorder(t);
        printf("\n%d levels, %d leaves\n",lv(t),leaves(t));
    }
	t = FreeMemory(t);
    free(array);
    *//*
    return 0;
}*/