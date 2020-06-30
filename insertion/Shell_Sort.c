#include <stdio.h>
#include <stdlib.h>

// Worst case performance O(n**2) or O(n log**2 n)
// Best case performance O(n log n) or O(n log**2 n)

void ShellSort(int array[], int length){
    int aux, h = 1, i, j;
    
    while(h < length) 
        h = 3 * h + 1;
    for(;h > 0; h /= 3){
        for(i = h; i < length; i++){
            aux = array[i];
            for(j = i; j > h-1 && array[j - h] > aux; j -= h)
                array[j] = array[j - h];
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
