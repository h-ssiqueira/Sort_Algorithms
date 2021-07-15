#include <stdio.h>
#include <stdlib.h>
#include "Merge.h"

// Complexity O(n log n)

void MergeInPlace(long int *array, int start, int middle, int end){
	long int value, *middle2 = array + middle + 1, *i;

    if(*(array + middle) <= *middle2) //if already sorted
        return;

    while(start <= middle && middle2 <= end + array){ //merge both halves
        if(*(array + start) <= *middle2) //if the element is in place
            start++;
        else{
            value = *middle2;
            i = middle2;
            // Shift all the elements between element 1
            // element 2, right by 1.
            while(i != array + start){ //move all elements until the beginning
                *i = *(i - 1);
                i--;
            }
            *(array + start) = value;
            start++;
            middle++;
            middle2++;
        }
    }
}

void Merge_Sort_In_Place(long int *array, int start, int end){
    if(start < end){
        int middle = (end + start) / 2;

        Merge_Sort_In_Place(array, start, middle); //first halves
        Merge_Sort_In_Place(array, middle + 1, end); //second halves
        if(*(array + middle) < *(array + middle + 1)) // Check if both parts are already sorted, if so, merge is useless
            return;
        MergeInPlace(array, start, middle, end);
    }
}

/*
int main(){
    long int array[] = {465,54,222,84,23,14,67,321,74,1},*i;

    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);

    printf("\n\n");

    Merge_Sort_In_Place(array,0,10-1); //0 and length - 1

    for(i = array; i < array + 10; i++)
        printf("%ld ",*i);

    return 0;
}
*/