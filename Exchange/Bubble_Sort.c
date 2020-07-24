#include <stdio.h>
#include <stdlib.h>

// Worst case performance O(n**2) comparisons and O(n**2) swaps
// Best case performance O(n) and O(1) swaps
// Average case performance O(n**2) comparisons and O(n**2) swaps

void Bubble_sort(int array[],int length){
    while(length > 1){
        for(int i = 0; i < length; i++){
            if(array[i] > array[i+1]){
                array[i] = array[i] ^ array[i+1]; 
                array[i+1] = array[i] ^ array[i+1];
                array[i] = array[i] ^ array[i+1];
            }
        }
        length--;
    }
}

int main(){
    int array[] = {5,9,4,22,51,3,10,65,111,49},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    printf("\n\n");
    Bubble_sort(array,9);
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    return 0;
}
