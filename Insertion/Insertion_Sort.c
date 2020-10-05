#include <stdio.h>
#include <stdlib.h>
#include "Insertion.h"

// Worst case performance О(n**2) comparisons 
// Best case performance O(n) comparisons 
// Average performance О(n**2) comparisons

void Insertion_Sort(int array[], unsigned int length){
	int aux;
    for(unsigned int i = 1, j; i < length; i++){//i is always one step ahead j
        aux = array[i]; //collect the value of a position
        j = i - 1; //and the index of previous value
        while(j >= 0 && aux < array[j]){ //compares with the previous array until find the lower element
            array[j+1] = array[j];//shift all values one index ahead
            j--;
        }
        array[j+1] = aux;//set the value on right position next to 'start' of array comparing with the index of i
    }
}

/*
int main(){
    int array[] = {354,14,321,52,84,387,10,987,100,5}, i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    printf("\n\n");
    
    Insertion_Sort(array,10);//10 is the length
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    return 0;
}
*/