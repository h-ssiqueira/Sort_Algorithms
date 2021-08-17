#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Esoteric_Fun_Miscellaneous.h"

 // Worst case performance O((n + 1)!)
 // Best case performance O(n)
 // Average case performance O((n + 1)!)

bool is_sorted2(long int *a, int n){
    while(--n >= 1)
        if(*(a + n) < *(a + n - 1))
            return false;
    return true;
}

void bogo_sort(long int *array, int n){
    long int aux, *i;
	int random;
    while(!is_sorted2(array,n)){
        for(i = array; i < array + n; i++){ // Tries to sort randomly
            aux = *i;
            random = rand() % n;
            *i = *(array + random);
            *(array + random) = aux;
        }
    }
}

/*
int main(){
    srand(time(NULL));
    long int array[] = {1,10,9,7,3,0,50,654,222,-2}, *i;

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ", *i);

    printf("\n\n");
    bogo_sort(array,sizeof(array)/sizeof(long int));

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ", *i);
    return 0;
}
*/