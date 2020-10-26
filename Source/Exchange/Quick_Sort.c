#include <stdio.h>
#include <stdlib.h>
#include "Exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n log n)
// Average case performance O(n log n)

void Quick_Sort(long int array[], int start, int end){
    int middle = array[(start + end) / 2], i = start, j = end;
	long int aux;
    
    while(i <= j){
        while(array[i] < middle && i < end)
            i++;
        while(array[j] > middle && j > start)
            j--;
        if(i <= j){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            /*
            array[i] = array[i] ^ array[j];
            array[j] = array[i] ^ array[j];  //XOR swapping doesn't work when the values are the same
            array[i] = array[i] ^ array[j];  //Because the truth table for equal values result in 0
            */
            i++;
            j--;
        }
    }
    if(start < j)
        Quick_Sort(array,start,j);
    if(i < end)
        Quick_Sort(array,i,end);
}

/*
int main(){
    long int array[] = {65,684,13,321,2,14,32,987,55,10},i;
    
    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    
    printf("\n\n");
    
    Quick_Sort(array,0,10-1);
    
    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    
    return 0;
}
*/