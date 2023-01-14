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
    int i, arr[size], *array = malloc(size * sizeof(int)), *j, s = 0;
    const int *lastD = array + size, *lastS = arr + size;

    tic = clock();
    for(i = 0; i < size; i++)
        arr[i] = 0;
    toc = clock();
    printf("SWI %ld seconds %ld microsseconds\n", (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);

    tic = clock();
    for(j = arr; j < lastS; j++)
        *j = 0;
    toc = clock();
    printf("SWP %ld seconds %ld microsseconds\n\n", (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);

    tic = clock();
    for(i = 0; i < size; i++)
        array[i] = 1;
    toc = clock();
    printf("DWI %ld seconds %ld microsseconds\n", (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);

    tic = clock();
    for(j = array; j < lastD; j++)
        *j = 1;
    toc = clock();
    printf("DWP %ld seconds %ld microsseconds\n\n", (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);

    tic = clock();
    for(i = 0; i < size; i++)
        s += arr[i];
    toc = clock();
    printf("SRI %ld seconds %ld microsseconds\n", (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);

    tic = clock();
    for(j = arr; j < lastS; j++)
        s += *j;
    toc = clock();
    printf("SRP %ld seconds %ld microsseconds\n\n", (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);

    tic = clock();
    for(i = 0; i < size; i++)
        s += array[i];
    toc = clock();
    printf("DRI %ld seconds %ld microsseconds\n", (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);

    tic = clock();
    for(j = array; j < lastD; j++)
        s += *j;
    toc = clock();
    printf("DRP %ld seconds %ld microsseconds\n", (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);

    free(array);
    return 0;
}

/*
SWI 0 seconds 4106 microsseconds
SWP 0 seconds 2291 microsseconds <-

DWI 0 seconds 4685 microsseconds
DWP 0 seconds 2241 microsseconds <- <-

SRI 0 seconds 2892 microsseconds
SRP 0 seconds 2664 microsseconds <- <-

DRI 0 seconds 3140 microsseconds
DRP 0 seconds 2849 microsseconds <-
*/