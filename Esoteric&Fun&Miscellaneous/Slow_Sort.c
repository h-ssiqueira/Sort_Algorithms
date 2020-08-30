#include <stdio.h>
#include <stdlib.h>

// Multiply and surrender strategy
// O(n)
// Mix of merge sort and bubble sort

void Slow_Sort(int array[],int start,int end){
    if(start >= end) return;
    int middle = (start + end) / 2;

    Slow_Sort(array,start,middle); // start - middle parts
    Slow_Sort(array,middle + 1,end); // middle - end parts
    if(array[end] < array[middle]){
        array[end] = array[end] ^ array[middle];
        array[middle] = array[end] ^ array[middle];
        array[end] = array[end] ^ array[middle];
    }
    Slow_Sort(array,start,end-1); // Sort elements decreasing the array
}

int main(){
    int array[] = {85,354,1,123,45,897,231,984,35,89},i;
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    
    Slow_Sort(array,0,10-1);//length - 1
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    return 0;
}
