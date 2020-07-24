#include <stdio.h>
#include <stdlib.h>

// Worst case performance O(n**2)
// Best case performance O(n)
// Average case performance O(n**2)

void CocktailShakerSort(int array[], int length){
    int start = 0,end = length - 1,swap = 0,i;
    while(swap == 0 && start < end){
        swap = 1;
        for(i = start; i < end; i++){
            if(array[i] > array[i+1]){
                array[i] = array[i] ^ array[i+1];
                array[i+1] = array[i] ^ array[i+1];
                array[i] = array[i] ^ array[i+1];
                swap = 0;
            }
        }
        end--;
        for(i = end; i > start; i--){
            if(array[i] < array[i-1]){
                array[i] = array[i] ^ array[i-1];
                array[i-1] = array[i] ^ array[i-1];
                array[i] = array[i] ^ array[i-1];
                swap = 0;
            }
        }
        start++;
    }
}

int main(){
    int array[] = {508,135,423,546,98,809,857,946,225,81},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    printf("\n\n");
    CocktailShakerSort(array,10);
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    return 0;
}
