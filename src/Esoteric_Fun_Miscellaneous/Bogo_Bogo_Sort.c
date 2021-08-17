#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "Esoteric_Fun_Miscellaneous.h"

// Worst case performance O((n + 1)!)
// Best case performance O(n)
// Average case performance O((n + 1)!)

bool is_sorted1(long int *a, int n){
    while(--n >= 1)
        if(*(a + n) < *(a + n - 1))
            return false;
    return true;
}

void BogoBogoSort(long int *array, int length){
    int size = 2,random;
	long int aux, *i;
    bool notsorted = true;

    while(notsorted){
        if(is_sorted1(array, size))
            size == length ? notsorted = false : size++;
        else
            size = 2;
        if(notsorted){
            for(i = array; i < array + size; i++){ //tries to sort randomly
                aux = *i;
                random = rand() % size;
                *i = *(array + random);
                *(array + random) = aux;
            }
        }
    }
}

/*
int main(){
    srand(time(NULL));
    long int array[] = {299,581,698,6,451,285,366,253,531,686},*i;

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    printf("\n\n");
    BogoBogoSort(array,sizeof(array)/sizeof(long int));

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);
    return 0;
}
*/