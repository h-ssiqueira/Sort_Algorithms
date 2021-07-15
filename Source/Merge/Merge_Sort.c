#include <stdio.h>
#include <stdlib.h>
#include "Merge.h"

// Worst case performance O(n log n)
// Best case performance O(n log n), O(n) natural variant
// Average case performance O(n log n)
// Worst case comparisons between (n lg n − n + 1) and (n lg n + n + O(lg n))

void Merge(long int *array, int start, int middle, int end){
    int i;
	long int *aux = (long int*)malloc((end - start + 1) * sizeof(long int)), *count1 = array + start, *count2 = array + middle + 1;

    for(i ^= i; count1 <= middle + array && count2 <= array + end; i++){
        if(*count1 < *count2){
            *(aux + i) = *count1;
            count1++;
        }
        else{
            *(aux + i) = *count2;
            count2++;
        }
    }
    while(count1 <= middle + array){
        *(aux + i) = *count1;
        i++;
        count1++;
    }
    while(count2 <= end + array){
        *(aux + i) = *count2;
        i++;
        count2++;
    }
    for(i = start; i <= end; i++)
        *(array + i) = *(aux + i - start);
    free(aux);
}

void Merge_Sort(long int *array, int start, int end){
    if(start < end){
        int middle = (start + end) / 2;

        Merge_Sort(array, start, middle); // first - middle parts
        Merge_Sort(array, middle + 1, end); // middle - end parts
        if(array[middle] < array[middle+1]) // Check if both parts are already sorted, if so, merge is useless
            return;
        Merge(array, start, middle, end); // sort
    }
}

/*
int main(){
    long int array[] = {55,654,321,8,52,31,54,66,221,100}, *i;

    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);

    printf("\n\n");
    Merge_Sort(array,0,10-1); //0 and length - 1

    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);

    return 0;
}
*/