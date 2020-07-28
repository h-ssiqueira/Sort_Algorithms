#include <stdio.h>
#include <stdlib.h>

// 2n log n comparisons and 0,8 n log n swaps

void DualPivotQuickSort(int array[], int start, int end){
    if(start < end){
        if(array[end] < array[start]){
            array[end] = array[end] ^ array[start];
            array[start] = array[end] ^ array[start];
            array[end] = array[end] ^ array[start];
        }
            
        int last = array[end], first = array[start], p1 = start + 1, p2 = end - 1, aux = p1, swap;
        while(aux <= p2){
            if(array[aux] < first){
                swap = array[aux];
                array[aux] = array[p1];
                array[p1] = swap;
                p1++;
            } 
            else if(array[aux] >= last){
                while(array[p2] > last && aux < p2) 
                    p2--;
                swap = array[aux];
                array[aux] = array[p2];
                array[p2] = swap;
                p2--;
                if(array[aux] < first){
                    swap = array[aux];
                    array[aux] = array[p1];
                    array[p1] = swap;
                    p1++;
                }
            }
            aux++;
        }
        p1--;
        p2++;

        swap = array[p1];
        array[p1] = array[start];
        array[start] = swap;
        
        swap = array[end];
        array[end] = array[p2];
        array[p2] = swap;

        DualPivotQuickSort(array, start, p1 - 1);
        DualPivotQuickSort(array, p1 + 1, p2 - 1);
        DualPivotQuickSort(array, p2 + 1, end);
    }
}

int main(){
    int array[] = {429,941,467,402,149,763,543,554,560,993},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    
    DualPivotQuickSort(array,0,10-1);
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    return 0;
}
