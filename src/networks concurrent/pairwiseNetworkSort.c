#include "networksConcurrent.h"

// Worst case performance O((log n)(1 + log n) / 2)

void pairwiseSort(long int *array, int start, int end, int piv){
	if(start != end - piv){
		int i, j, k;
		for(i = start + piv; i < end; i += (2 * piv)){ // Starts comparing the multiples of two
			if(array[i - piv] > *(array + i)){
				*(array + i) = *(array + i) ^ *(array + i - piv);
				*(array + i - piv) = *(array + i) ^ *(array + i - piv);
				*(array + i) = *(array + i) ^ *(array + i - piv);
			}
		}
		if((end - start) / piv % 2 == 0){ // Doing the same but using the power of 2, starting in different indexes
			pairwiseSort(array, start, end, piv * 2);
			pairwiseSort(array, start + piv, end + piv, piv * 2);
		}
		else{
			pairwiseSort(array, start, end + piv, piv * 2);
			pairwiseSort(array, start + piv, end, piv * 2);
		}
		for(j = 1; j < (end - start) / piv; j = (j * 2) + 1)
			continue;
		for(i = start + piv; i + piv < end; i += 2 * piv){ // Compares with the other elements in the array
			for(k = j; k > 1;){
				k /= 2;
				if(k * piv + i < end){
					if(*(array + i) > *(array + k * piv + i)){
						*(array + i) = *(array + i) ^ *(array + k * piv + i);
						*(array + k * piv + i) = *(array + i) ^ *(array + k * piv + i);
						*(array + i) = *(array + i) ^ *(array + k * piv + i);
					}
				}
			}
		}
	}
}
