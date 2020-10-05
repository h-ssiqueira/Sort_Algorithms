#ifndef MERGE_H_
#define MERGE_H_

// Bottom-Up Merge Sort
void Bottomup_Merge_Sort(int array[], unsigned int length);
// Auxiliar funciont to merge two subarrays
void Merge_Bottomup(int array[], unsigned int start, unsigned int middle, unsigned int end);

// In Place Merge Sort
void Merge_Sort_In_Place(int array[], unsigned int start, unsigned int end);
// Auxiliar function to merge two subarrays
void MergeInPlace(int array[], unsigned int start, unsigned int middle, unsigned int end);

// Merge Sort
void Merge_Sort(int array[], unsigned int start, unsigned int end);
// Auxiliar function to merge two subarrays
void Merge(int array[], unsigned int start, unsigned int middle, unsigned int end);

#endif