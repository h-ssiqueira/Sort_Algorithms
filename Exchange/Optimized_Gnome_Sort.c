#include <stdio.h>
#include <stdlib.h>

// *Worst case performance O(n**2)
// *Best case performance O(n)
// *Average case performance O(n**2)

void Optimized_Gnome_Sort(int array[],int i){
    int j = i, aux;
    while(j > 0 && array[j-1] > array [j]){
        /*
        array[j] = array[j] ^ array[j-1];
        array[j-1] = array[j] ^ array[j-1];
        array[j] = array[j] ^ array[j-1];
        */
        aux = array[j];
        array[j] = array[j-1];
        array[j-1] = aux;
        j--;
    }
}

int main(){
    int array[] = {771,143,40,570,616,967,376,266,895,121},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    printf("\n\n");
    
    for(i = 1; i < 10; i++)
        Optimized_Gnome_Sort(array,i);
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    return 0;
}
