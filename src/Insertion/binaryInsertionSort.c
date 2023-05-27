#include "insertion.h"

// O(n log n)

int binarySearch(long int *array, int num, int start, int end){
    if(end <= start)
        return ((num > *(array + start)) ? (start + 1) : start);

    int mid = (start + end) / 2;

    if(num == *(array + mid))
        return (mid + 1);

    if(num > *(array + mid))
        return binarySearch(array, num, mid + 1, end);
    return binarySearch(array, num, start, mid - 1);
}

void binaryInsertionSort(long int *array, int length){
    long int aux;
	int i, j, pos;
    for(i = 1; i < length; i++){
        j = (i - 1);
        aux = *(array + i);

        pos = binarySearch(array, aux, 0, j); // Find the position where the element should be inserted

        while(pos <= j){ // Move all elements until reaches the position
            *(array + j + 1) = *(array + j);
            j--;
        }
        *(array + j + 1) = aux;
    }
}
