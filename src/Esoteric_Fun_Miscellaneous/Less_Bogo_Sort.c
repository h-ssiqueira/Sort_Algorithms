#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Esoteric_Fun_Miscellaneous.h"

bool is_sorted5(long int *a, int n){
    while(--n >= 1)
        if(*(a + n) < *(a + n - 1))
            return false;
    return true;
}

void LessBogoSort(long int *array, int length){
    int random;
	long int aux, *i = array;
    while(i != length + array){
        while(!is_sorted5(array, i+1 - array)){ // Tries to sort randomly
            random = rand() % length;
            aux = *(array + random);
            *(array + random) = *i;
            *i = aux;
        }
        i++;
    }
}

/*
int main(){
    srand(time(NULL));
    long int array[] = {180,979,34,25,484,70,341,755,293,365}, *i;
    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    printf("\n\n");

    LessBogoSort(array,sizeof(array)/sizeof(long int));

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);
    return 0;
}
*/