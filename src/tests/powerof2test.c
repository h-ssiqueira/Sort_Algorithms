#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 63

/*
*    Testing pow function, << and *= 2
*/

int main(){
    clock_t tic, toc;
    long bypow, bybit, bymult;
    bypow = bybit = bymult = 1;

    tic = clock();
    pow(bypow,n);
    toc = clock();
    printf("Setting 1: by pow %ld seconds %ld microsseconds\n\n", (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);

    tic = clock();
    bybit <<= n;
    toc = clock();
    printf("Setting 2: by shift %ld seconds %ld microsseconds\n\n", (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);

    tic = clock();
    for(int i = 1; i < n; i++)
        bymult *= 2;
    toc = clock();
    printf("Setting 3: by mult %ld seconds %ld microsseconds\n\n", (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);

}

/*
Setting 1: by pow 0 seconds 14 microsseconds

Setting 2: by shift 0 seconds 1 microsseconds <-

Setting 3: by mult 0 seconds 2 microsseconds
*/