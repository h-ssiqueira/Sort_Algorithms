#include "exchange.h"

// Worst case performance O(n**2)
// Best case performance O(n log n)
// Average case performance O(n log n)

long int sort(long int *array, int start, int end){
    long int aux = *(array+start);

    while(start < end){
        while((*(array+end) >= aux) && (start < end))
            end--;
        if(start != end){
            *(array+start) = *(array+end);
            start++;
        }
        while((*(array+start) <= aux) && (start < end))
            start++;
        if(start != end){
            *(array+end) = *(array+start);
            end--;
        }
    }
    *(array+start) = aux;
    return start;
}

void stableQuickSort(long int *array, int start, int end){
    long int aux = sort(array, start, end);

    if(start < aux - 1)
        stableQuickSort(array, start, aux - 1);
    if(end > aux + 1)
        stableQuickSort(array, aux + 1, end);
}
