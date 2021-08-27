#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	S -> Static
	D -> Dynamic

	W -> Write
	R -> Read

	I -> Integer
	P -> Pointer
*/

int main(){
    clock_t tic, toc;
    const int size = 1048576; // 1 MB
    int arr[size], *array = malloc(size * sizeof(int)), *j;
    const int *lastD = array + size, *lastS = arr + size;

    tic = clock();
    for(j = arr; j < lastS; j++)
        *j = 1;
    toc = clock();
    printf("Setting 1: SWP %ld seconds %ld microsseconds\n\n", (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);

    tic = clock();
    for(j = array; j < lastD; j++)
        *j = 0;
    toc = clock();
    printf("Setting zero =0: DWP %ld seconds %ld microsseconds\n\n", (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);

    tic = clock();
    for(j = arr; j < lastS; j++)
        *j = 1;
    toc = clock();
    printf("Setting 1: SWP %ld seconds %ld microsseconds\n\n", (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);

    tic = clock();
    for(j = array; j < lastD; j++)
        *j ^= *j;
    toc = clock();
    printf("Setting zero XOR: DWP %ld seconds %ld microsseconds\n\n", (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);

    free(array);
    return 0;
}

/*
Setting 1: SWP 0 seconds 3992 microsseconds

Setting zero =0: DWP 0 seconds 3530 microsseconds

Setting 1: SWP 0 seconds 2152 microsseconds

Setting zero XOR: DWP 0 seconds 2167 microsseconds  <-
*/