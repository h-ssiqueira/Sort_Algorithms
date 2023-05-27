#include "exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n)

void oddEvenSort(long int *array, int length){
    long int aux, *i, *j;
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for(i = array+1, j = array+2; i < array+length - 1; i += 2, j += 2){
            if(*i > *(i+1)){
                aux = *i;
                *i = *j;
                *j = aux;
                sorted = false;
            }
        }
        for(i = array, j = array+1; i < array+length - 1; i += 2, j += 2){
            if(*i > *(i+1)){
                aux = *i;
                *i = *j;
                *j = aux;
                sorted = false;
            }
        }
    }
}
