#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Esoteric_Fun_Miscellaneous.h"
 
 // Worst case performance O((n + 1)!)
 // Best case performance O(n)
 // Average case performance O((n + 1)!)
 
bool is_sorted(int a[], unsigned int n){
    while(--n >= 1){
        if(a[n] < a[n-1]) 
            return false;
    }
    return true;
}
    
void bogo_sort(int a[], unsigned int n){
    int aux;
	unsigned int random;
    while(!is_sorted(a,n)){
        for(unsigned int i = 0; i < n; i++){ //tries to sort randomly
            aux = a[i];
            random = rand() % n;
            a[i] = a[random];
            a[random] = aux;
        }
    }
}

/*    
int main(){
    srand(time(NULL));
    int numbers[] = {1,10,9,7,3,0,50,654,222,-2};
    
    for(int i = 0; i < 10; i++) 
        printf("%d ", numbers[i]);
    
    printf("\n\n");
    bogo_sort(numbers,10);
    
    for(int i = 0; i < 10; i++) 
        printf("%d ", numbers[i]);
    return 0;
}
*/