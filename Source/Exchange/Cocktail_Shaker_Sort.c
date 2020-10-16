#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n)
// Average case performance O(n**2)

void CocktailShakerSort(long int array[], int length){
    int start = 0,end = length - 1,i;
	long int aux;
	bool swap = false;
    while(!swap && start < end){
        swap = true;
        for(i = start; i < end; i++){
            if(array[i] > array[i+1]){
                /*
                array[i] = array[i] ^ array[i+1];
                array[i+1] = array[i] ^ array[i+1];
                array[i] = array[i] ^ array[i+1];
                */
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                swap = false;
            }
        }
        end--;
        for(i = end; i > start; i--){
            if(array[i] < array[i-1]){
                /*
                array[i] = array[i] ^ array[i-1];
                array[i-1] = array[i] ^ array[i-1];
                array[i] = array[i] ^ array[i-1];
                */
                aux = array[i];
                array[i] = array[i-1];
                array[i-1] = aux;
                swap = false;
            }
        }
        start++;
    }
}

/*
int main(){
    int array[] = {508,135,423,546,98,809,857,946,225,81},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    printf("\n\n");
    CocktailShakerSort(array,10);
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    return 0;
}
*/