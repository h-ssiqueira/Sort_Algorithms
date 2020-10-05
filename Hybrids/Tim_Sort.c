#include <stdio.h>
#include <stdlib.h>
#include "Hybrids.h"
#define RUN 32 // Run must be in range (32-64), better 32 or 64 (potency of 2)

// Merge Sort + Insertion Sort = Tim Sort
// Worst case performance O(n log n)
// Best case performance O(n)
// Average case performance O(n log n)
  
void InsertionSortT(int array[], unsigned int left, unsigned int right){ 
    int aux;
	unsigned int i,j;
    for(i = left + 1; i <= right; i++){ 
        aux = array[i]; 
        j = i - 1; 
        while (j >= left && array[j] > aux){ 
            array[j+1] = array[j]; 
            j--; 
        } 
        array[j+1] = aux; 
    } 
} 
  
void MergeT(int array[], unsigned int l, unsigned int m, unsigned int r){ // Original array in two parts (left-mid + mid+1-right)
    unsigned int size1 = m - l + 1, size2 = r - m, i, j = 0, k = l;
	int left[size1], right[size2]; 
    for(i = 0; i < size1; i++) 
        left[i] = array[l + i]; 
    for(i = 0; i < size2; i++) 
        right[i] = array[m + 1 + i]; 
  
    i = 0; 
  
    while(i < size1 && j < size2){ // Merge two subarrays into one
        if(left[i] <= right[j]){ 
            array[k] = left[i]; 
            i++; 
        } 
        else{ 
            array[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while(i < size1){ // Copy left elements of array if remaining any
        array[k] = left[i]; 
        k++; 
        i++; 
    } 
  
    while(j < size2){ // Copy right elements of array if remaining any
        array[k] = right[j]; 
        k++; 
        j++; 
    } 
} 
  
void TimSort(int array[], unsigned int length){ 
    unsigned int mid, right;
    for(int i = 0; i < length; i += RUN){ // Sort subarrays of size RUN or mid
        right = i + RUN - 1;
        mid = length - 1;
        right > mid ? InsertionSortT(array, i, mid) : InsertionSortT(array, i, right); 
    }
  
    for(unsigned int size = RUN; size < length; size = 2 * size){ // Start mergin from size of run and doubling up the value
        for(unsigned int left = 0; left < length; left += 2 * size){ 
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
    int array[] = {801,299,118,440,734,80,780,715,799,851},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    TimSort(array,10);
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    return 0;
}
*/