#include <stdio.h>
#include <stdlib.h>
#include "Hybrids.h"
#define RUN 32 // Run must be in range (32-64), better 32 or 64 (potency of 2)

// Merge Sort + Insertion Sort = Tim Sort
// Worst case performance O(n log n)
// Best case performance O(n)
// Average case performance O(n log n)


void InsertionSortT(long int *array, int start, int end){
    long int aux, *i, *j;
    for(i = array + start + 1; i <= array + end; i++){
        aux = *i;
        j = i - 1;
        while(j >= start + array && *j > aux){
            *(j+1) = *j;
            j--;
        }
        *(j+1) = aux;
    }
}

void MergeT(long int *array, int start, int middle, int end){ // Original array in two parts (start-middle + middle+1-end)
    long int *size1, *size2, *left = malloc((middle - start + 1)*sizeof(long int)), *right = malloc((end - middle)*sizeof(long int)), *k = start + array, *i, *j;
	size2 = right + end - middle;
	size1 = left + middle - start + 1;
    for(i = left, j = array + start; i < size1; i++, j++)
        *i = *j;
    for(i = right, j = array + middle + 1; i < size2; i++, j++)
        *i = *j;

    i = left;
	j = right;

    while(i < size1 && j < size2){ // Merge two subarrays into one
        if(*i <= *j){
            *k = *i;
            i++;
        }
        else{
            *k = *j;
            j++;
        }
        k++;
    }

    while(i < size1){ // Copy left elements of array if remaining any
        *k = *i;
        k++;
        i++;
    }

    while(j < size2){ // Copy right elements of array if remaining any
        *k = *j;
        k++;
        j++;
    }
	free(left);
	free(right);
}

void TimSort(long int *array, int length){
    int mid, right, size, left, i;
    for(i ^= i; i < length; i += RUN) // Sort subarrays of size RUN or mid
        InsertionSortT(array, i, length - 1 < i + RUN - 1 ? length - 1 : i + RUN - 1);

    for(size = RUN; size < length; size *= 2){ // Start merging from size of run and doubling up the value
        for(left ^= left; left < length; left += 2 * size){
            right = left + 2 * size - 1 < length - 1 ? left + 2 * size - 1 : length - 1;
            mid = left + size - 1;
			if(mid < right)
            	MergeT(array, left, mid, right);
        }
    }
}

/*
int main(){
    //long int array[] = {801,299,118,440,734,80,780,715,799,851};
	long int *i;
	long int array[] = {928,219,228,437,270,551,588,503,160,351,557,729,701,363,311,615,462,890,249,145,923,780,674,394,72,485,133,476,599,949,605,235,287,777,400,856,962,365,760,395,50,755,69,567,338,3,949,695,38,470,118,879,54,87,147,480,77,727,812,733,354,852,100,321,987};

    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    printf("\n\n");
    TimSort(array,sizeof(array)/sizeof(long int));
    for(i = array; i < array + sizeof(array)/sizeof(long int); i++)
        printf("%ld ",*i);

    return 0;
}
*/