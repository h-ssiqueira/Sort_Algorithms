#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Non-Comparison_Distribution.h"
#define buckets 10

// Worst case performance O(n**2)
// Best case performance O(n + k) k is the number of buckets
// Average performance O(n + k)

void Double_Selection_SortB(unsigned int length, int matrix[][length]){
    unsigned int changeMin, changeMax;
	int aux;
    for(unsigned int h = 0; h < buckets; h++){
        for(unsigned int i = 0, j = length-1; i < j; i++, j--){
            changeMin = i; //starts in the first
            changeMax = j; //starts in the last
            for(unsigned int k = i+1; k <= j; k++){
                if(matrix[h][k] < matrix[h][changeMin]) //search for the min element
                    changeMin = k;
                else if(matrix[h][k] > matrix[h][changeMax]) //search for the max element
                    changeMax = k;
            }
            if(i != changeMin){ //swap the positions for fit the min element
                /*
                matrix[h][i] = matrix[h][i] ^ matrix[h][changeMin];
                matrix[h][changeMin] = matrix[h][i] ^ matrix[h][changeMin];
                matrix[h][i] = matrix[h][i] ^ matrix[h][changeMin];
                */
                aux = matrix[h][i];
                matrix[h][i] = matrix[h][changeMin];
                matrix[h][changeMin] = aux;
            }
            if(j != changeMax){ //swap the positions for fit the max element
                /*
                matrix[h][j] = matrix[h][j] ^ matrix[h][changeMax];
                matrix[h][changeMax] = matrix[h][j] ^ matrix[h][changeMax];
                matrix[h][j] = matrix[h][j] ^ matrix[h][changeMax];
                */
                aux = matrix[h][i];
                matrix[h][i] = matrix[h][changeMax];
                matrix[h][changeMax] = aux;
            }
        }
    }
}

void BucketSort(int array[], unsigned int length){
    unsigned int i, j, k, range = 1;
	int b[buckets][length];
    for(i = 0; i < buckets; i++){
        for(j = 0; j < length; j++){
            b[i][j] = b[i][j] ^ b[i][j];
        }
    }
    
    for(i = 1, j = array[0]; i < length; i++){ // Determine the range of buckets by getting the max value 
        if(j < array[i])
            j = array[i];
    }
    while(j >= 1){ // count how many digits the number has
        j /= 10;
        range *= 10; // number of digits (quantity of zeros) to determine the range
    }
    
    for(i = 0; i < length; i++){ // sort the values to each bucket
        j = range / 10;
        k = 0;
        while(j <= range){
            if(array[i] < j){
                b[k][i] = array[i];
                break;
            }
            k++;
            j += (range / 10);
        }
    }
    
    Double_Selection_SortB(length,b); // After set the values to each bucket, sort each one using other algorithm
    
    for(i = 0, k = 0; i < buckets; i++){ // Merge all buckets to the original array
        for(j = 0; j < length; j++){
            if(b[i][j] != 0){
                array[k] = b[i][j];
                k++;
            }
        }
    }
}

/*
int main(){
    int array[] = {49,436,448,704,516,297,468,764,735,564};
    
    for(int i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    BucketSort(array,10);
    
    for(int i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    return 0;
}
*/