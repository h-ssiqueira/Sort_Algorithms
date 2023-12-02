#include "exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n)
// Average case performance O(n**2)

void gnomeSort(long int *array, int length){
    long int aux, *i = array+1;

    while(i < array+length){
        if(*i >= *(i-1))
            i++;
        else{
            aux = *i;
            *i = *(i-1);
            *(i-1) = aux;
            if(i != array+1)
                i--;
        }
    }
}
