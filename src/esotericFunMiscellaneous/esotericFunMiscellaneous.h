#ifndef _ESOTERIC_FUN_MISCELLANEOUS_H_
#define _ESOTERIC_FUN_MISCELLANEOUS_H_

#if defined unix || defined __unix || defined __unix__ || defined __APPLE__ || defined __MACH__ || defined __linux__
#include <pthread.h>
#include <semaphore.h>
#endif

#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
#include <windows.h>
#endif

#include <stdbool.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "../utils/utils.h"

// Auxiliar functions that check if the array is sorted

void badSort(long int *array, int length);

void bogoBogoSort(long int *array, int length);

void bogoSort(long int *array, int n);

void bubbleBogoSort(long int *array, int length);

void cocktailBogoSort(long int *array, int length);
// Auxiliar functions that check if the subarrays is sorted

bool isMaxSorted(long int *array, int min, int max);
bool isMinSorted(long int *array, int min, int max);

void exchangeBogoSort(long int *array, int length);

void lessBogoSort(long int *array, int length);

void pancakeSort(long int *array, int length);
// Auxiliar function that "flips" the array
void flip(long int *array, long int *i);

void sillySort(long int *array, int start, int end);

void slowSort(long int *array, int start, int end);

void sleepSort(long int *array, int length);

void spaghettiSort(long int *array, int length);

void stoogeSort(long int *array, int i, int j);

#endif