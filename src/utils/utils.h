#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "errorMessages.h"

// QRCode utils

// New line resetting color
void endl();

// New empty white line
void emptyLine();

// Prints QRcode of repository author's GitHub profile link
void QRCode();

// Screen utils

void clearScreen();

// Array utils

void printArray(long int *array, int length);

bool isSorted(long int *array, int length, bool increasing);

void fileAfterExec(long int *array, int length, bool display, bool time, unsigned long sec, unsigned long micro, bool sorted);

void fileBeforeExec(long int *array, int length, bool display, char *sort, int range, int choice);

void calculateTime(clock_t tic, clock_t toc, unsigned long *sec, unsigned long *micro);

void createArray(long int **array, int length);

void generateArray(long int *array, int length, short int choice, int randomRange);

bool isSortedRandomly(long int *a, int n);

#endif