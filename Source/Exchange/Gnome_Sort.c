#include <stdio.h>
#include <stdlib.h>
#include "Exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n)
// Average case performance O(n**2)

void Gnome_Sort(long int array[], int length){
    long int aux;
	int i = 1;

    while(i < length){
        if(array[i] >= array[i-1])
            i++;
        else{
            /*
            array[i] = array[i] ^ array[i-1];
            array[i-1] = array[i] ^ array[i-1];
            array[i] = array[i] ^ array[i-1];
            */
            aux = array[i];
            array[i] = array[i-1];
            array[i-1] = aux;
            if(i != 1)
                i--;
        }
    }
}

/*
int main(){
    long int array[] = {9,5,3,7,6,4,8,1,2,10},i;

    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    printf("\n\n");

    Gnome_Sort(array,10);

    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    return 0;
}
*/