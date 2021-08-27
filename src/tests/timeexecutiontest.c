#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

/*
sys/time gettimeofday() (outdated)
time.h and clock()
*/

int main(){
    clock_t tic, toc;
    struct timeval start,end;
    long sum = 0;
    for(int j = 0; j < 10; j++){
        tic = clock();
        for(unsigned int i = 0; i < __INT_MAX__; i++)
            sum++;
        toc = clock();

        gettimeofday(&start,NULL);
        for(unsigned int i = 0; i < __INT_MAX__; i++)
            sum++;
        gettimeofday(&end,NULL);

        printf("gtd %d = %lu s %lu usec\n", j+1, (unsigned long)end.tv_sec-start.tv_sec,(unsigned long)end.tv_usec-start.tv_usec);
        printf("clk %d = %lu s %lu usec\n", j+1, (unsigned long)(toc - tic) / CLOCKS_PER_SEC,(unsigned long)(toc - tic) % 1000000);
    }
    return 0;
}

/*
gtd 1 = 6 s 18446744073708954441 usec (...)
clk 1 = 5 s 177707 usec <-
gtd 2 = 5 s 381038 usec
clk 2 = 5 s 428725 usec
gtd 3 = 5 s 337146 usec
clk 3 = 5 s 326659 usec
gtd 4 = 5 s 328089 usec
clk 4 = 5 s 360812 usec
gtd 5 = 6 s 18446744073708873478 usec (...)
clk 5 = 5 s 322761 usec
gtd 6 = 5 s 308854 usec
clk 6 = 5 s 317467 usec
gtd 7 = 5 s 392836 usec
clk 7 = 5 s 370607 usec
gtd 8 = 6 s 18446744073708923721 usec (...)
clk 8 = 5 s 323091 usec
gtd 9 = 5 s 305663 usec
clk 9 = 5 s 321904 usec
gtd 10 = 5 s 308578 usec
clk 10 = 5 s 302084 usec
*/
