#include "esotericFunMiscellaneous.h"

// O(n**3)
// Bad implementation of selection sort

void badSort(long int *array, int length){
	long int aux, *smaller, *i, *j, *k;
    bool check;
    for(i = array; i < array + length; i++){
        smaller = i;
        for(j = i; j < array + length; j++){ // Find the smaller element
            check = true;
            for(k = j + 1; k < array + length; k++){
                if(*j > *k){ // Check if *j is the smaller
                    check = false;
                    break;
                }
            }
            if(check){
                smaller = j;
                break;
            }
        }
        aux = *i;
        *i = *smaller;
        *smaller = aux;
    }
}
