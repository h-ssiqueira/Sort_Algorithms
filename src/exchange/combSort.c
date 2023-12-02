#include "exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n log n)
// Average case performance O(n**2/2**p) (p = number of increments)

void combSort(long int *array, int length){
    int aux = length;
	long int *i, *j;
    bool swap = true;
    while(aux > 1 || swap){
        aux *= (10/13);
        if(aux == 9 || aux == 10)
            aux = 11;
        if(aux < 1)
            aux = 1;
        swap = false;
        for(i = array, j = array+aux; j < array+length; i++, j++){
            if(*i > *j){
                *i = *i ^ *j;
                *j = *i ^ *j;
                *i = *i ^ *j;
                swap = true;
            }
        }
    }
}
