#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Worst case performance O(n**2) comparisons and O(n**2) swaps
// Best case performance O(n) and O(1) swaps
// Average case performance O(n**2) comparisons and O(n**2) swaps

void BubbleSortOptmized(int array[], int length){
    bool swap;
    int i,j;
    for(j = 0; j < length; j++){
        swap = false;
        for(i = 0; i < length - j; i++){ // Sort all array and starts decreasing
            if(array[i+1] < array[i]){
                array[i] = array[i] ^ array[i+1];
                array[i+1] = array[i] ^ array[i+1];
                array[i] = array[i] ^ array[i+1];
                swap = true;
            }
        }
        if(!swap) // No swapping happened: it's already sorted
            break;
    }

}

int main(){
    int array[] = {66,600,410,815,779,233,998,510,734,65},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
        
    printf("\n\n");
    
    BubbleSortOptmized(array,9);
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);

    return 0;
}
