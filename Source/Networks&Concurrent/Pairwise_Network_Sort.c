#include <stdio.h>
#include <stdlib.h>
#include "Networks_Concurrent.h"

// Worst case performance O((log n)(1 + log n) / 2)

void Pairwise_Sort(long int array[], int start, int end, int piv){
	if(start != end - piv){
		int i, j, k;
		for(i = start + piv; i < end; i += (2 * piv)){ // Starts comparing the multiples of two
			if(array[i - piv] > array[i]){
				array[i] = array[i] ^ array[i-piv];
				array[i-piv] = array[i] ^ array[i-piv];
				array[i] = array[i] ^ array[i-piv];
			}
		}
		if((end - start) / piv % 2 == 0){ // Doing the same but using the power of 2, starting in different indexes
			Pairwise_Sort(array, start, end, piv * 2);
			Pairwise_Sort(array, start + piv, end + piv, piv * 2);
		}
		else{
			Pairwise_Sort(array, start, end + piv, piv * 2);
			Pairwise_Sort(array, start + piv, end, piv * 2);
		}
		for(j = 1; j < (end - start) / piv; j = (j * 2) + 1)
			continue;
		for(i = start + piv; i + piv < end; i += 2 * piv){ // Compares with the other elements in the array
			for(k = j; k > 1;){
				k /= 2;
				if(k * piv + i < end){
					if(array[i] > array[k * piv + i]){
						array[i] = array[i] ^ array[k * piv + i];
						array[k * piv + i] = array[i] ^ array[k * piv + i];
						array[i] = array[i] ^ array[k * piv + i];
					}
				}
			}
		}
	}
}

/*
int main(){
	long int array[] = {79,732,622,75,982,87,825,352,402,584};
    
    for(int i = 0; i < 10; i++)
        printf("%ld ",array[i]);
    
    printf("\n\n");
    
    Pairwise_Sort(array,0,10,1);
    
    for(int i = 0; i < 10; i++)
        printf("%ld ",array[i]);

	return 0;
}
*/