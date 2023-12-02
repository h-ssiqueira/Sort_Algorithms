#include "exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n**2)
// Average case performance O(n**2)

void cocktailShakerSort(long int *array, int length){
    int start, end = length - 1;
	long int aux, *i;
	start ^= start;
    while(start < end){
        for(i = array+start; i < array+end; i++){
            if(*i > *(i+1)){
                aux = *i;
                *i = *(i+1);
                *(i+1) = aux;
            }
        }
        end--;
        for(i = array+end; i > array+start; i--){
            if(*i < *(i-1)){
                aux = *i;
                *i = *(i-1);
                *(i-1) = aux;
            }
        }
        start++;
    }
}
