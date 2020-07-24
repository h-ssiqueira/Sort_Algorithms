#include<stdio.h>
#include<stdlib.h>

// Worst case performance O(n**2) comparisons and O(n) swaps
// Best case performance O(n**2) comparisons and O(n) swaps
// Average performance O(n**2) comparisons and O(n) swaps

//(n**2 - n)/4 comparisons


void Double_Selection_Sort(int array[], int length){
    int changeMin, changeMax;
    
    for(int i = 0, j = length-1; i < j; i++, j--){
        changeMin = i; //starts in the first
        changeMax = j; //starts in the last
        for(int k = i+1; k <= j; k++){
            if(array[k] < array[changeMin]) //search for the min element
                changeMin = k;
            else if(array[k] > array[changeMax]) //search for the max element
                changeMax = k;
        }
        if(i != changeMin){ //swap the positions for fit the min element
            array[i] = array[i] ^ array[changeMin];
            array[changeMin] = array[i] ^ array[changeMin];
            array[i] = array[i] ^ array[changeMin];
        }
        if(j != changeMax){ //swap the positions for fit the max element
            array[j] = array[j] ^ array[changeMax];
            array[changeMax] = array[j] ^ array[changeMax];
            array[j] = array[j] ^ array[changeMax];
        }
    }
}

int main(){
    int ar[] = {5,98,-1,0,11,321,654,555,44,2};
    
    for(int i = 0; i < 10; i++)
        printf("%d ",ar[i]);
    
    printf("\n\n");
    Double_Selection_Sort(ar,10);
    
    for(int i = 0; i < 10; i++)
        printf("%d ",ar[i]);
    
    return 0;
}