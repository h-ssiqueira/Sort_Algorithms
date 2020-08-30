#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Worst case performance O((n + 1)!)
// Best case performance O(n)
// Average case performance O((n + 1)!)

bool is_sorted(int a[], int n){
    while(--n >= 1){
        if(a[n] < a[n-1]) 
            return false;
    }
    return true;
}

void BogoBogoSort(int array[],int length){
    int size = 2,aux,random;
    bool notsorted = true;
        
    while(notsorted){
        if(is_sorted(array, size))
            size == length ? notsorted = false : size++;
        else
            size = 2;
        if(notsorted){
            for(int i = 0; i < size; i++){ //tries to sort randomly
                aux = array[i];
                random = rand() % size;
                array[i] = array[random];
                array[random] = aux;
            }
        }
    }
}

int main(){
    srand(time(NULL));
    int array[] = {299,581,698,6,451,285,366,253,531,686},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    BogoBogoSort(array,10);
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    return 0;
}