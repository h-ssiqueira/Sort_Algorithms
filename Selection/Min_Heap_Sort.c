#include <stdio.h>
#include <stdlib.h>

// Worst case performance O(n log n)
// Best case performance O(n log n)
// Average performance O(n log n) 

void heapmin(int array[], int n, int i){ //n is the size of heap
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2, aux;
  
    if(left < n && array[left] < array[smallest]) //Left child is smaller than node
        smallest = left; 
  
    if(right < n && array[right] < array[smallest]) //Right child is smaller than node
        smallest = right; 
  
    if(smallest != i){ //smaller is not the actual node
        aux = array[i];
        array[i] = array[smallest];
        array[smallest] = aux;

        heap(array, n, smallest); //Acess the subtree
    } 
} 
  
void MinHeapSort(int array[], int length){ 
    for(int i = length / 2 - 1; i >= 0; i--) 
        heap(array, length, i); //Creating the heap

    for(int i = length-1, aux; i >= 0; i--){ //Remove each element from heap
        aux = array[i];
        array[i] = array[0];
        array[0] = aux;
  
        heap(array, i, 0); //Reduced heap
    } 
}

int main(){
    int array[] = {117,612,443,21,894,908,802,687,693,845},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    MinHeapSort(array,10);
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    return 0;
}