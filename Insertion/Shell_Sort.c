#include <stdio.h>
#include <stdlib.h>

// Worst case performance O(n**3/2)
// Best case performance O(n log n)

void ShellSort(int array[], int length){
    int aux, h = 1, i, j;
    
    while(h < length) // Set the value of h until reach the value of length or more
        h = 3 * h + 1;
    for(;h > 0; h /= 3){ // h starts decreasing the array
        for(i = h; i < length; i++){ // i will take the value of h, incrementing one by one
            aux = array[i];
            for(j = i; j > h-1 && array[j - h] > aux; j -= h) // and j decreasing until the value of i
                array[j] = array[j - h]; // Implementing the insertion sort
            array[j] = aux;
        }
    }
}


int main(){
    int array[] = {119,536,252,970,681,861,222,369,587,468},i;

    for(i = 0; i < 10; i++) 
        printf("%d ", array[i]);
    
    printf("\n\n");
    
    ShellSort(array,10);
    
    for(i = 0; i < 10; i++) 
        printf("%d ", array[i]);
    return 0;
}
