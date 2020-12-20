#include <stdio.h>
#include <stdbool.h>
#include "Esoteric_Fun_Miscellaneous.h"

// O(n**3)
// Bad implementation of selection sort

void BadSort(long int array[], int length){
    int smaller;
	long int aux;
    bool check;
    for(int i = 0; i < length; i++){
        smaller = i;
        for(int j = i; j < length; j++){ // Find the smaller element
            check = true;
            for(int k = j + 1; k < length; k++){
                if(array[j] > array[k]){ // Check if array[j] is the smaller
                    check = false;
                    break;
                }
            }
            if(check){
                smaller = j;
                break;
            }
        }
        aux = array[i];
        array[i] = array[smaller];
        array[smaller] = aux;
    }
}

/*
int main(){
    long int array[] = {131,418,457,76,631,739,462,299,716,68},i;

    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);

    printf("\n\n");
    BadSort(array,10);
    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);

    return 0;
}
*/