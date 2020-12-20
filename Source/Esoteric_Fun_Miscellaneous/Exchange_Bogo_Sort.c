#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Esoteric_Fun_Miscellaneous.h"

bool is_sorted4(long int a[], int n){
    while(--n >= 1){
        if(a[n] < a[n-1])
            return false;
    }
    return true;
}

void ExchangeBogoSort(long int array[], int length){
    int random1,random2;
	long int aux;
    while(!is_sorted4(array, length)){
        random1 = rand() % length;
        random2 = rand() % length;
        if(random1 < random2){ // Check the positions
            if(array[random1] > array[random2]){ // Check if it's sorted
                aux = array[random1];
                array[random1] = array[random2];
                array[random2] = aux;
            }
        }
        else{
            if(array[random1] < array[random2]){ // Check if it's sorted
                aux = array[random1];
                array[random1] = array[random2];
                array[random2] = aux;
            }
        }
    }
}

/*
int main(){
    srand(time(NULL));
    long int array[] = {180,979,34,25,484,70,341,755,293,365},i;
    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);

    printf("\n\n");

    ExchangeBogoSort(array,10);

    for(i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    return 0;
}
*/