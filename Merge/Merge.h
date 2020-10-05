#ifndef MERGE_H_
#define MERGE_H_

// Bottom-Up Merge Sort
void Bottomup_Merge_Sort(int array[], int length);
// Auxiliar funciont to merge two subarrays
void Merge_Bottomup(int array[], int start, int middle, int end);

// In Place Merge Sort
void Merge_Sort_In_Place(int array[], int start, int end);
// Auxiliar function to merge two subarrays
void MergeInPlace(int array[], int start, int middle, int end);

// Merge Sort
void Merge_Sort(int array[], int start, int end);
// Auxiliar function to merge two subarrays
void Merge(int array[], int start, int middle, int end);

#endif