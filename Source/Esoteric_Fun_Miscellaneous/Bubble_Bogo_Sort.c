#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Esoteric_Fun_Miscellaneous.h"

bool is_sorted3(long int *a, int n){
    while(--n >= 1)
        if(*(a + n) < *(a + n - 1))
            return false;
    return true;
}

void BubbleBogoSort(long int *array, int length){
    int random;
	long int aux;
    while(!is_sorted3(array, length)){
        random = rand() % (length-1);
        if(*(array + random) > *(array + random + 1)){ // Tries to sort randomly the index and index+1
            aux = *(array + random);
            *(array + random) = *(array + random + 1);
            *(array + random + 1) = aux;
        }
    }
}

/*
int main(){
    srand(time(NULL));
    long int array[] = {517,418,663,859,992,119,508,887,672,407}, *i;
    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    printf("\n\n");

    BubbleBogoSort(array,sizeof(array)/sizeof(long int));

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);
    return 0;
}
*/