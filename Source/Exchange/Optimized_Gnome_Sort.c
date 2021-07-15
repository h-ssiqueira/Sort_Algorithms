#include <stdio.h>
#include <stdlib.h>
#include "Exchange.h"

// *Worst case performance O(n**2)
// *Best case performance O(n)
// *Average case performance O(n**2)

void Optimized_Gnome_Sort(long int *array, int length){
    long int aux, *j, *i;
	for(i = array; i < array+length; i++){
		j = i;
		while(j > array && *(j-1) > *j){
			/*
			*j = *j ^ *(j-1);
			*(j-1) = *j ^ *(j-1);
			*j = *j ^ *(j-1);
			*/
			aux = *j;
			*j = *(j-1);
			*(j-1) = aux;
			j--;
		}
	}
}

/*
int main(){
    long int *array = {771,143,40,570,616,967,376,266,895,121},*i;

    for(i = array; i < array+10; i++)
        printf("%ld ",*i);
    printf("\n\n");

    Optimized_Gnome_Sort(array,10);

    for(i = array; i < array+10; i++)
        printf("%ld ",*i);
    return 0;
}
*/