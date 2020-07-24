#include <stdio.h>
#include <stdlib.h>

// Worst case performance О(n**2) comparisons 
// Best case performance O(n**2) comparisons 
// Average performance О(n**2) comparisons

void CycleSort(int array[],int length){
    int aux, pos;
    for(int i = 0; i < length - 2; i++){ 
        aux = array[i]; 

        pos = i; 
        for(int j = i + 1; j < length; j++) // Find the right position
            if(array[j] < aux) 
                pos++; 
  
        if(pos == i) // If the element is in correct position
            continue; 
  
        while(aux == array[pos]) // For duplicate elements
            pos++; 
  
        if(pos != i){ // Setting the element in correct position
            aux = aux ^ array[pos];
            array[pos] = aux ^ array[pos];
            aux = aux ^ array[pos];
        }
  
        while(pos != i){ // Rotating the cycle
            pos = i; 
  
            for(int k = i + 1; k < length; k++) // Find the right position
                if(array[k] < aux) 
                    pos++; 
  
            while(aux == array[pos]) // For duplicate elements
                pos++; 
  
            if(aux != array[pos]){ // Setting the element in correct position
                aux = aux ^ array[pos];
                array[pos] = aux ^ array[pos];
                aux = aux ^ array[pos];
            }
        } 
    } 
}

int main(){
    int array[] = {807,449,650,900,745,539,390,112,447,973}, i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    printf("\n\n");
    
    CycleSort(array,10);
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    return 0;
}