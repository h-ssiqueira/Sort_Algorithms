#include <stdio.h>
#include <stdlib.h>

// Worst case performance O(n + k), k -> range of the non-negative key values

void Counting_Sort(int array[],int length){
    int output[length], k, i, max = array[0], min = array[0];
    
    for(i = 0; i < length; i++){
        if(array[i] > max) max = array[i];
        if(array[i] < min) min = array[i];
    }
    
    int range = max - min + 1,count[range];
    
    for(i = 0; i < length; i++)//set zero for 
        output[i] = 0;
    for(i = 0; i < range; i++)//both arrays
        count[i] = 0;
    for(i = 0; i < length; i++)//sort by how many times the value repeats
        count[array[i]-min]++;
    for(i = 1; i <= length; i++) //count the amount of previous incidences
        count[i] += count[i-1];
    for(i = length-1; i >= 0; i--){ 
        k = count[array[i] - min];//getting the right position
		output[k - 1] = array[i];//putting the value on the corrected position && already sorted to an auxiliary array
		count[array[i] - min]--;
	}
    for(i = 0; i < length; i++) //transfering to original array
        array[i] = output[i];
}

int main(){
    int array[] = {4,10,1,8,6,9,5,2,7,3},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    Counting_Sort(array,10);
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    return 0;
}
