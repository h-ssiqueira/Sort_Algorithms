#ifndef _NON_COMPARISON_DISTRIBUTION_H_
#define _NON_COMPARISON_DISTRIBUTION_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void bucketSort(long int *array, int length);
// Auxiliary function for bucket sort
void insertionSortBinary(int length, long int **matrix);

void countingSort(long int *array, int length);

void beadSort(long int *array, int length);

void pigeonholeSort(long int *array, int length);

void radixLSDSort(long int *array, int length, int radix);
// Auxiliary function for counting each digit of each number of array
void countingByDigit(long int *array, int radix, int exp, long int min, int length);

#endif