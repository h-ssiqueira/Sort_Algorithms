#include "exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n log n)
// Average case performance O(n log n)

void quickSort(long int *array, int start, int end){
    int middle = *(array+((start + end) / 2)), i = start, j = end;
	long int aux;

    while(i <= j){
        while(*(array+i) < middle && i < end)
            i++;
        while(*(array+j) > middle && j > start)
            j--;
        if(i <= j){
            aux = *(array+i);
            *(array+i) = *(array+j);
            *(array+j) = aux;
            i++;
            j--;
        }
    }
    if(start < j)
        quickSort(array,start,j);
    if(i < end)
        quickSort(array,i,end);
}
