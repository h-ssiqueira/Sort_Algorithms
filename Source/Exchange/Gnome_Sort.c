#include <stdio.h>
#include <stdlib.h>
#include "Exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n)
// Average case performance O(n**2)

void Gnome_Sort(long int *array, int length){
    long int aux, *i = array+1;

    while(i < array+length){
        if(*i >= *(i-1))
            i++;
        else{
            /*
            *i = *i ^ *(i-1);
            *(i-1) = *i ^ *(i-1);
            *i = *i ^ *(i-1);
            */
            aux = *i;
            *i = *(i-1);
            *(i-1) = aux;
            if(i != array+1)
                i--;
        }
    }
}

/*
int main(){
    long int *array = {9,5,3,7,6,4,8,1,2,10},*i;

    for(i = array; i < array+10; i++)
        printf("%ld ",*i);
    printf("\n\n");

    Gnome_Sort(array,10);

    for(i = array; i < array+10; i++)
        printf("%ld ",*i);
    return 0;
}
*/