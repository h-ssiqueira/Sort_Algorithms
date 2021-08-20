#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#define n 63

/*
*    Testing pow function, << and *= 2
*/

int main(){
    struct timeval start, end;
    long bypow, bybit, bymult;
    bypow = bybit = bymult = 1;

    gettimeofday(&start, NULL);
    pow(bypow,n);
    gettimeofday(&end, NULL);
    printf("Setting 1: by pow %ld seconds %ld microsseconds\n\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

    gettimeofday(&start, NULL);
    bybit <<= n;
    gettimeofday(&end, NULL);
    printf("Setting 2: by shift %ld seconds %ld microsseconds\n\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

    gettimeofday(&start, NULL);
    for(int i = 1; i < n; i++)
        bymult *= 2;
    gettimeofday(&end, NULL);
    printf("Setting 3: by mult %ld seconds %ld microsseconds\n\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

}