#include <stdio.h>
#include <stdlib.h>

// O(n log n)

int BinarySearch(int array[], int num, int start, int end){ 
    if(end <= start) 
        return (num > array[start]) ? (start + 1) : start; 
  
    int mid = (start + end) / 2; 
  
    if(num == array[mid]) 
        return mid + 1; 
  
    if(num > array[mid]) 
        return BinarySearch(array, num, mid + 1, end); 
    return BinarySearch(array, num, start, mid - 1); 
} 
  
void InsertionSort(int array[], int length){ 
    int i, j, pos, aux; 
  
    for(i = 1; i < length; i++){ 
        j = i - 1; 
        aux = array[i]; 
  
        pos = BinarySearch(array, aux, 0, j); // Find the position where the element should be inserted
  
        while(pos <= j){ // Move all elements until reaches the position
            array[j+1] = array[j]; 
            j--; 
        } 
        array[j+1] = aux; 
    } 
} 

int main(){
    int array[] = {693,378,660,247,77,223,132,685,873,862},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    
    InsertionSort(array,10);
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    return 0;
}
