#include <stdio.h>
#include <stdlib.h>
#include "Selection.h"

// Worst case performance O(n**2) comparisons and O(n) swaps
// Best case performance O(n**2) comparisons and O(n) swaps
// Average performance O(n**2) comparisons and O(n) swaps

//(n**2 - n)/2 comparisons

void Selection_Sort(long int *array, int length){
    long int aux, *change, *i, *j;

    for(i = array; i < length-1 + array; i++){ // last element won't have other to compair
        change = i;
        for(j = i+1; j < length + array; j++)
            if(*change > *j) // if the element is lower, collect the position
                change = j;
        if(i != change){// if it has been modified, swap positions (using xor)
            /*
            *i = *i ^ *change;
            *change = *i ^ *change;
            *i = *i ^ *change;
            */
            aux = *i;
            *i = *change;
            *change = aux;
        }
    }
}

/*
int main(){
    long int array[] = {3,67,31,90,1,44,654,89,21,20}, *i;

    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);

    printf("\n\n");

    Selection_Sort(array,10);

    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);

    return 0;
}
*/