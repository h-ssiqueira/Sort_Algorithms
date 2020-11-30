#include <stdio.h>
#include <stdlib.h>
#include "Merge.h"

// Worst case performance O(n log n)
// Best case performance O(n log n), O(n) natural variant
// Average case performance O(n log n)
// Worst case comparisons between (n lg n − n + 1) and (n lg n + n + O(lg n))

void Merge(long int array[], int start, int middle, int end){
    int count1 = start, count2 = middle + 1, i;
	long int *aux = (long int*)malloc((end - start + 1) * sizeof(long int));

    for(i = 0; count1 <= middle && count2 <= end; i++){
        if(array[count1] < array[count2]){
            aux[i] = array[count1];
            count1++;
        }
        else{
            aux[i] = array[count2];
            count2++;
        }
    }
    while(count1 <= middle){
        aux[i] = array[count1];
        i++;
        count1++;
    }
    while(count2 <= end){
        aux[i] = array[count2];
        i++;
        count2++;
    }
    for(i = start; i <= end; i++)
        array[i] = aux[i - start];
    free(aux);
}

void Merge_Sort(long int array[], int start, int end){
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
    long int ar[] = {55,654,321,8,52,31,54,66,221,100};

    for(int i = 0; i < 10; i++)
        printf("%ld ",ar[i]);

    printf("\n\n");
    Merge_Sort(ar,0,10-1); //0 and length - 1

    for(int i = 0; i < 10; i++)
        printf("%ld ",ar[i]);

    return 0;
}
*/