#include <stdio.h>
#include <stdlib.h>
#include "Hybrids.h"
#define RUN 32 // Run must be in range (32-64), better 32 or 64 (potency of 2)

// Merge Sort + Insertion Sort = Tim Sort
// Worst case performance O(n log n)
// Best case performance O(n)
// Average case performance O(n log n)


void InsertionSortT(long int *array, int left, int right){
    long int aux, *i, *j;
    for(i = array + left + 1; i <= array + right; i++){
        aux = *i;
        j = i - 1;
        while(j >= left + array && *j > aux){
            *(j+1) = *j;
            j--;
        }
        *(j+1) = aux;
    }
}

void MergeT(long int *array, int l, int m, int r){ // Original array in two parts (left-mid + mid+1-right)
    int size1 = m - l + 1, size2 = r - m, i, j, k = l;
	j ^= j;
	long int *left = malloc(size1*sizeof(long int)), *right = malloc(size2*sizeof(long int));
    for(i ^= i; i < size1; i++)
        *(left + i) = *(array + l + i);
    for(i ^= i; i < size2; i++)
        *(right + i) = *(array + m + 1 + i);

    i ^= i;

    while(i < size1 && j < size2){ // Merge two subarrays into one
        if(*(left + i) <= *(right + j)){
            *(array + k) = *(left + i);
            i++;
        }
        else{
            *(array + k) = *(right + j);
            j++;
        }
        k++;
    }

    while(i < size1){ // Copy left elements of array if remaining any
        *(array + k) = *(left + i);
        k++;
        i++;
    }

    while(j < size2){ // Copy right elements of array if remaining any
        *(array + k) = *(right + j);
        k++;
        j++;
    }
	free(left);
	free(right);
}

void TimSort(long int *array, int length){
    int mid = length - 1, right, size, left, i;
    for(i ^= i; i < length; i += RUN){ // Sort subarrays of size RUN or mid
        right = i + RUN - 1;
        right > mid ? InsertionSortT(array, i, mid) : InsertionSortT(array, i, right);
    }

    for(size = RUN; size < length; size *= 2){ // Start merging from size of run and doubling up the value
        for(left ^= left; left < length; left += 2 * size){
            mid = length - 1;
            right = left + 2 * size - 1;
            if(mid < right) // Find ending position of merged array to merge with another
                right = mid;
            mid = left + size - 1;
            MergeT(array, left, mid, right);
        }
    }
}

/*
int main(){
    //long int array[] = {801,299,118,440,734,80,780,715,799,851};
	long int *i;
	long int array[] = {928,219,228,437,270,551,588,503,160,351,557,729,701,363,311,615,462,890,249,145,923,780,674,394,72,485,133,476,599,949,605,235,287,777,400,856,962,365,760,395,50,755,69,567,338,3,949,695,38,470,118,879,54,87,147,480,77,727,812,733,354,852,100,321,987};

    for(i = array; i < array + 65; i++)
        printf("%ld ",*i);

    printf("\n\n");
    TimSort(array,10);
    for(i = array; i < array + 65; i++)
        printf("%ld ",*i);

    return 0;
}
// https://iq.opengenus.org/tim-sort/
*/