#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Esoteric_Fun_Miscellaneous.h"
 
 // Worst case performance O((n + 1)!)
 // Best case performance O(n)
 // Average case performance O((n + 1)!)
 
bool is_sorted2(long int a[], int n){
    while(--n >= 1){
        if(a[n] < a[n-1]) 
            return false;
    }
    return true;
}
    
void bogo_sort(long int a[], int n){
    long int aux;
	int random;
    while(!is_sorted2(a,n)){
        for(int i = 0; i < n; i++){ //tries to sort randomly
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
    long int numbers[] = {1,10,9,7,3,0,50,654,222,-2};
    
    for(int i = 0; i < 10; i++) 
        printf("%ld ", numbers[i]);
    
    printf("\n\n");
    bogo_sort(numbers,10);
    
    for(int i = 0; i < 10; i++) 
        printf("%ld ", numbers[i]);
    return 0;
}
*/