#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Non-Comparison_Distribution.h"

// Worst case performance O(n + k), k -> range of the non-negative key values
// Best case performance O(n + k)
// Average performance O(n + k)

void Counting_Sort(long int array[], int length){
    long int output[length], max = array[0], min = array[0];
	int i;
    
    for(i = 0; i < length; i++){
        if(array[i] > max) max = array[i];
        if(array[i] < min) min = array[i];
    }
    
    int range = max - min + 1;
	long int count[range];
    
    memset(count,0,sizeof(count)); // Set 0 for all positions in array
    
    for(i = 0; i < length; i++)// Count how many times the value repeat
        count[array[i]-min]++;
    for(i = 1; i < range; i++) // Count the amount of previous incidences
        count[i] += count[i-1];
    for(i = length-1; i >= 0; i--){ 
		output[count[array[i] - min] - 1] = array[i];// Putting the value on the corrected position && already sorted to an auxiliary array
		count[array[i] - min]--;
	}
    for(i = 0; i < length; i++) // Transfering to original array
        array[i] = output[i];
}

/*
int main(){
    int array[] = {305,224,575,587,589,891,810,158,872,805},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    Counting_Sort(array,10);
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    return 0;
}
*/