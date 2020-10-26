#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Esoteric_Fun_Miscellaneous.h"

bool is_sorted5(long int a[], int n){
    while(--n >= 1){
        if(a[n] < a[n-1]) 
            return false;
    }
    return true;
}

void LessBogoSort(long int array[], int length){
    int index = 0,random;
	long int aux;
    while(index != length){
        while(!is_sorted5(array, index+1)){ // Tries to sort randomly
            random = rand() % length;
            aux = array[random];
            array[random] = array[index];
            array[index] = aux;
        }
        index++;
    }
}

/*
int main(){
    srand(time(NULL));
    long int array[] = {180,979,34,25,484,70,341,755,293,365},i;
    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    
    printf("\n\n");
    
    LessBogoSort(array,10);
    
    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    return 0;
}
*/