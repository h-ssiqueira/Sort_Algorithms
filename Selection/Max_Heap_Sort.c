#include <stdio.h>
#include <stdlib.h>

// Worst case performance O(n log n)
// Best case performance O(n log n)
// Average performance O(n log n) 

void heapmax(int array[], int n, int i){ //n is the size of heap
    int largest = i, left = 2 * i + 1, right = 2 * i + 2, aux;
  
    if(left < n && array[left] > array[largest]) //Left child is larger than node
        largest = left; 
  
    if(right < n && array[right] > array[largest]) //Right child is larger than node
        largest = right; 
  
    if(largest != i){ //Larger is not the actual node
        aux = array[i];
        array[i] = array[largest];
        array[largest] = aux;

        heap(array, n, largest); //Acess the subtree
    } 
} 
  
void MaxHeapSort(int array[], int length){ 
    for(int i = length / 2 - 1; i >= 0; i--) 
        heap(array, length, i); //Creating the heap

    for(int i = length-1, aux; i > 0; i--){ //Remove each element from heap
        aux = array[i];
        array[i] = array[0];
        array[0] = aux;
  
        heap(array, i, 0); //Reduced heap
    } 
}

int main(){
    int array[] = {423,816,549,499,789,769,463,516,846,473},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    MaxHeapSort(array,10);
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    return 0;
}