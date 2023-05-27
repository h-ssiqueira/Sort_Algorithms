#include "exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n)
// Average case performance O(n**2)

void optimizedCocktailShakerSort(long int *array, int length){
    int start,end = length - 1;
	long int aux, *i;
	bool swap = false;
	start ^= start;
    while(!swap && start < end){
        swap = true;
        for(i = array+start; i < array+end; i++){
            if(*i > *(i+1)){
                aux = *i;
                *i = *(i+1);
                *(i+1) = aux;
                swap = false;
            }
        }
        end--;
        for(i = array+end; i > array+start; i--){
            if(*i < *(i-1)){
                aux = *i;
                *i = *(i-1);
                *(i-1) = aux;
                swap = false;
            }
        }
        start++;
    }
}
