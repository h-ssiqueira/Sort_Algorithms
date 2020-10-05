#include <stdio.h>
#include <stdlib.h>
#include "Non-Comparison_Distribution.h"

// Worst case performance O(N + n) N -> range of key values, n -> input size

void Pigeonhole_Sort(int array[], unsigned int length){
    int max = array[0],min = array[0];
	unsigned int range, i, j = 0;
    
    for(i = 0; i < length; i++){ //collect max and min values of array
        if(array[i] > max)
            max = array[i];
        if(array[i] < min)
            min = array[i];
    }
    range = max - min + 1;
    
    int holes[range]; //creates an array of ranges
    for(i = 0; i < range; i++) //clear the holes
        holes[i] = 0;
    for(i = 0; i < length; i++)
        holes[array[i] - min]++; //put the amount of times the value repeat in hole array in order
    for(i = 0; i < range; i++)
        while(holes[i]-- > 0)
            array[j++] = i + min; //insert the values to main array
}

/*
int main(){
    int test[] = {2,20,1,7,3,5,2,-11,2,1},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",test[i]);
    
    printf("\n\n");
    
    Pigeonhole_Sort(test,10);
    
    for(i = 0; i < 10; i++)
        printf("%d ",test[i]);
    
    return 0;
}
*/