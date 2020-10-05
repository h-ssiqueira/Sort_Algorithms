#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n)

void Odd_Even_Sort(int array[],int length){
    int i, j, aux;
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for(i = 1, j = 2; i < length - 1; i += 2, j += 2){
            if(array[i] > array[i+1]){
                /*
                array[i] = array[i] ^ array[j];
                array[j] = array[i] ^ array[j];
                array[i] = array[i] ^ array[j];
                */
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
                sorted = false;
            }
        }
        for(i = 0, j = 1; i < length - 1; i += 2, j += 2){
            if(array[i] > array[i + 1]){
                /*
                array[i] = array[i] ^ array[j];
                array[j] = array[i] ^ array[j];
                array[i] = array[i] ^ array[j];
                */
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
                sorted = false;
            }
        }
    }
}

/*
int main(){
    int array[] = {416,647,874,428,309,898,464,335,47,82},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    printf("\n\n");
    
    Odd_Even_Sort(array,10);
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    return 0;
}
*/