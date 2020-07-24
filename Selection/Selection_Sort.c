#include<stdio.h>
#include<stdlib.h>

// Worst case performance O(n**2) comparisons and O(n) swaps
// Best case performance O(n**2) comparisons and O(n) swaps
// Average performance O(n**2) comparisons and O(n) swaps

//(n**2 - n)/2 comparisons

void Selection_Sort(int array[], int length){
    int change;
    
    for(int i = 0; i < length-1; i++){ //last element won't have other to compair
        change = i;
        for(int j = i+1; j < length; j++)
            if(array[change] > array[j]) //if the element is lower, collect the position
                change = j;
        if(i != change){// if it has been modified, swap positions (using xor)
            array[i] = array[i] ^ array[change];
            array[change] = array[i] ^ array[change];
            array[i] = array[i] ^ array[change];
        }
    }
}

int main(){
    int v[] = {3,67,31,90,1,44,654,89,21,20};
    
    for(int i = 0; i < 10; i++)
        printf("%d ",v[i]);
    
    printf("\n\n");
    
    Selection_Sort(v,10);
    
    for(int i = 0; i < 10; i++)
        printf("%d ",v[i]);
    
    return 0;
}
