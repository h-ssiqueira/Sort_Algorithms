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
    for(i = 0; i < size; i++)
        arr[i] = 0;
    gettimeofday(&end, NULL);
    printf("SWI %ld seconds %ld microsseconds\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

    gettimeofday(&start, NULL);
    for(j = arr; j < lastS; j++)
        *j = 0;
    gettimeofday(&end, NULL);
    printf("SWP %ld seconds %ld microsseconds\n\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

    gettimeofday(&start, NULL);
    for(i = 0; i < size; i++)
        array[i] = 1;
    gettimeofday(&end, NULL);
    printf("DWI %ld seconds %ld microsseconds\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

    gettimeofday(&start, NULL);
    for(j = array; j < lastD; j++)
        *j = 1;
    gettimeofday(&end, NULL);
    printf("DWP %ld seconds %ld microsseconds\n\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

    gettimeofday(&start, NULL);
    for(i = 0; i < size; i++)
        s += arr[i];
    gettimeofday(&end, NULL);
    printf("SRI %ld seconds %ld microsseconds\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

    gettimeofday(&start, NULL);
    for(j = arr; j < lastS; j++)
        s += *j;
    gettimeofday(&end, NULL);
    printf("SRP %ld seconds %ld microsseconds\n\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

    gettimeofday(&start, NULL);
    for(i = 0; i < size; i++)
        s += array[i];
    gettimeofday(&end, NULL);
    printf("DRI %ld seconds %ld microsseconds\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

    gettimeofday(&start, NULL);
    for(j = array; j < lastD; j++)
        s += *j;
    gettimeofday(&end, NULL);
    printf("DRP %ld seconds %ld microsseconds\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);

    free(array);
    return 0;
}