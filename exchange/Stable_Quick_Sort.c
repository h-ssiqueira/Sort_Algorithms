#include <stdio.h>
#include <stdlib.h>

// Worst case performance O(n**2)
// Best case performance O(n log n)
// Average case performance O(n log n)

int Sort(int array[], int start, int end){
    int aux;
    aux = array[start];
    while(start < end){
        while((array[end] >= aux) && (start < end))
            end--;
        if(start != end){
            array[start] = array[end];
            start++;
        }
        while((array[start] <= aux) && (start < end))
            start++;
        if(start != end){
            array[end] = array[start];
            end--;
        }
    }   
    array[start] = aux;
    return start;
}

void StableQuickSort(int array[], int start, int end){
    int aux;
    aux = Sort(array, start, end);
    if(start < aux - 1)
        StableQuickSort(array, start, aux - 1);
    if(end > aux + 1)
        StableQuickSort(array, aux + 1, end);
}  

int main(){
    int array[] = {979,82,937,764,309,761,824,540,786,732},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    
    StableQuickSort(array,0,9);
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);

    return 0;
}
