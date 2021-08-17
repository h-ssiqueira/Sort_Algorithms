#include <stdio.h>
#include <stdbool.h>
#include "Esoteric_Fun_Miscellaneous.h"

// O(n**3)
// Bad implementation of selection sort

void BadSort(long int *array, int length){
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

/*
int main(){
    long int array[] = {131,418,457,76,631,739,462,299,716,68},*i;

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    printf("\n\n");
    BadSort(array,sizeof(array)/sizeof(long int));
    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    return 0;
}
*/