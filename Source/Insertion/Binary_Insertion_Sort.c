#include <stdio.h>
#include <stdlib.h>
#include "Insertion.h"

// O(n log n)

int BinarySearch(long int *array, int num, int start, int end){
    if(end <= start)
        return ((num > *(array + start)) ? (start + 1) : start);

    int mid = (start + end) / 2;

    if(num == *(array + mid))
        return (mid + 1);

    if(num > *(array + mid))
        return BinarySearch(array, num, mid + 1, end);
    return BinarySearch(array, num, start, mid - 1);
}

void InsertionSort(long int *array, int length){
    long int aux;
	int i, j, pos;
    for(i = 1; i < length; i++){
        j = (i - 1);
        aux = *(array + i);

        pos = BinarySearch(array, aux, 0, j); // Find the position where the element should be inserted

        while(pos <= j){ // Move all elements until reaches the position
            *(array + j + 1) = *(array + j);
            j--;
        }
        *(array + j + 1) = aux;
    }
}

/*
int main(){
    long int array[] = {693,378,660,247,77,223,132,685,873,862},*i;

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    printf("\n\n");

    InsertionSort(array,sizeof(array)/sizeof(long int));

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    return 0;
}
*/