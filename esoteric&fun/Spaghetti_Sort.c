#include <stdio.h>
#include <stdlib.h>

// Average case performance O(n)
  
int SpaghettiSort(int array[], int length){
    int i, j, k = 0, aux[length], min = array[0], max = array[0];
    for(i = 0; i < length; i++){ // Find the max and min values in the array
        if(array[i] > max) 
            max = array[i];
        if(array[i] < min) 
            min = array[i];
    }
    for(i = min; i <= max; i++){
        for(j = 0; j < length; j++){
            if(array[j] == i){ // Find the followed elements after min value to wirte in the aux array
                aux[k] = array[j];
                k++;
            }
        }
    }
    for(i = 0; i < length; i++) // Return the elements in the main array
        array[i] = aux[i];
}
 

int main(){
    int array[] = {323,669,285,167,862,674,733,331,475,445},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    SpaghettiSort(array,10);
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    return 0;
}
