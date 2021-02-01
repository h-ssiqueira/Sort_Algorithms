#ifndef NON_COMPARISON_DISTRIBUTION_H_
#define NON_COMPARISON_DISTRIBUTION_H_

// Bucket Sort
void BucketSort(long int array[], int length);
// Auxiliary function for bucket sort
void Insertion_SortB(int length, long int matrix[][length]);

// Counting Sort
void Counting_Sort(long int array[], int length);

// Bead Sort
void BeadSort(long int array[], int length);

// Pigeonhole Sort
void Pigeonhole_Sort(long int array[], int length);

// Radix LSD
void Radix_LSD(long int array[], int length, int radix);
// Auxiliary function for counting each digit of each number of array
void CountingByDigit(long int array[], int radix, int exp, long int min, int length);

#endif