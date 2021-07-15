#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

/*
	S -> Static
	D -> Dynamic

	W -> Write
	R -> Read

	I -> Integer
	P -> Pointer
*/

int main(){
    struct timeval start, end;
    const int size = 1048576; // 1 MB
    int i, arr[size], *array = malloc(size * sizeof(int)), *j, s = 0;
    const int *lastD = array + size, *lastS = arr + size;

    gettimeofday(&start, NULL);
    for(j = arr; j < lastS; j++)
        *j = 1;
    gettimeofday(&end, NULL);
    printf("Setting 1: SWP %ld seconds %ld microsseconds\n\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

    gettimeofday(&start, NULL);
    for(j = array; j < lastD; j++)
        *j = 0;
    gettimeofday(&end, NULL);
    printf("Setting zero =0: DWP %ld seconds %ld microsseconds\n\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

    gettimeofday(&start, NULL);
    for(j = arr; j < lastS; j++)
        *j = 1;
    gettimeofday(&end, NULL);
    printf("Setting 1: SWP %ld seconds %ld microsseconds\n\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

    gettimeofday(&start, NULL);
    for(j = array; j < lastD; j++)
        *j ^= *j;
    gettimeofday(&end, NULL);
    printf("Setting zero XOR: DWP %ld seconds %ld microsseconds\n\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

    free(array);
    return 0;
}