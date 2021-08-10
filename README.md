# Sorting Algorithms
![GitHub Repository Size](https://img.shields.io/github/repo-size/h-ssiqueira/Sort_algorithms?label=Repository%20Size&style=for-the-badge)
![Contributions](https://img.shields.io/static/v1.svg?label=Contributions&message=Welcome&color=information&style=for-the-badge)

![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)

![Visual Studio Code](https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white)

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

## Summary
* [Description](#Description)
	* [How to execute](#How-to-execute)
* [Algorithms](#Algorithms)
	* [Esoteric & Fun & Miscellaneous](#Esoteric-&-Fun-&-Miscellaneous)
	* [Exchange](#Exchange)
	* [Hybrids](#Hybrids)
	* [Insertion](#Insertion)
	* [Merge](#Merge)
	* [Networks & Concurrent](#Networks-&-Concurrent)
	* [Non-Comparison & Distribution](#Non-Comparison-&-Distribution)
	* [Selection](#Selection)
* [Complexity Table](#Complexity-Table)
* [Testing](#Testing)
	* [Time to access data in different arrays](#Time-to-access-data-in-different-arrays)
	* [Time to assign zero to a variable](#Time-to-assign-zero-to-a-variable)


## Description
A program to show the execution time and the variaty of sorting algorithms in ```C``` language. There are 46 sorting algorithms avaliable distributed in 8 different categories.

### How to execute
Executing ```make``` in terminal allow to compile the program. Commands avaliable to execute with make (```make <command>```):
Command | Description
:---: | :---:
clean | Clear all objects generated
cr | Compile and run, also clear all objects
rmproper | Clear all objects/executable files
run | Execute main program

On program settings there are avaliable modifications noted in table below:
Configuration | Default
:---: | :---:
Display arrays | YES
Display execution time | YES
Save results in a text file | NO
Sorting case | Random
Random interval | 1024
Length of array | 10

<br>

## Algorithms

### [Esoteric & Fun & Miscellaneous](https://github.com/h-ssiqueira/Sort_Algorithms/tree/master/Source/Esoteric_Fun_Miscellaneous)
1. [Bad Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Bad_Sort.c)
1. [Bogo Bogo Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Bogo_Bogo_Sort.c)
1. [Bogo Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Bogo_Sort.c)
1. [Bubble Bogo Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Bubble_Bogo_Sort.c)
1. [Cocktail Bogo Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Cocktail_Bogo_Sort.c)
1. [Exchange Bogo Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Exchange_Bogo_Sort.c)
1. [Less Bogo Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Less_Bogo_Sort.c)
1. [Pancake Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Pancake_Sort.c)
1. [Silly Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Silly_Sort.c)
1. [Slow Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Slow_Sort.c)
1. [Spaghetti Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Spaghetti_Sort.c)
1. [Stooge Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Stooge_Sort.c)

### [Exchange](https://github.com/h-ssiqueira/Sort_Algorithms/tree/master/Source/Exchange)
1. [Bubble Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Bubble_Sort.c)
1. [Circle Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Circle_Sort.c)
1. [Cocktail Shaker Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Cocktail_Shaker_Sort.c)
1. [Comb Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Comb_Sort.c)
1. [Dual Pivot Quick Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Dual_Pivot_Quick_Sort.c)
1. [Gnome Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Gnome_Sort.c)
1. [Odd-Even Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Odd-Even_Sort.c)
1. [Optimized Bubble Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Optimized_Bubble_Sort.c)
1. [Optimized Cocktail Shaker Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Optimized_Cocktail_Shaker_Sort.c)
1. [Optimized Gnome Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Optimized_Gnome_Sort.c)
1. [Quick Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Quick_Sort.c)
1. [Quick Sort 3-way](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Quick_Sort_3-way.c)
1. [Stable Quick Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Stable_Quick_Sort.c)

### [Hybrids](https://github.com/h-ssiqueira/Sort_Algorithms/tree/master/Source/Hybrids)
1. [Tim Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Hybrids/Tim_Sort.c)

### [Insertion](https://github.com/h-ssiqueira/Sort_Algorithms/tree/master/Source/Insertion)
1. [Binary Insertion Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Insertion/Binary_Insertion_Sort.c)
1. [Cycle Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Insertion/Cycle_Sort.c)
1. [Insertion Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Insertion/Insertion_Sort.c)
1. [Patience Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Insertion/Patience_Sort.c)
1. [Shell Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Insertion/Shell_Sort.c)
1. [Tree Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Insertion/Tree_Sort.c)

### [Merge](https://github.com/h-ssiqueira/Sort_Algorithms/tree/master/Source/Merge)
1. [Bottom-up Merge Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Merge/Bottom-Up_Merge_Sort.c)
1. [In-Place Merge Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Merge/In-Place_Merge_Sort.c)
1. [Merge Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Merge/Source/Merge_Sort.c)

### [Networks & Concurrent](https://github.com/h-ssiqueira/Sort_Algorithms/tree/master/Source/Networks_Concurrent)
1. [Bitonic Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Networks_Concurrent/Bitonic_Sort.c)
1. [Pairwise Network Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Networks_Concurrent/Pairwise_Network_Sort.c)

### [Non-Comparison & Distribution](https://github.com/h-ssiqueira/Sort_Algorithms/tree/master/Source/Non-Comparison_Distribution)
1. [Bucket Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Non-Comparison_Distribution/Bucket_Sort.c)
1. [Counting Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Non-Comparison_Distribution/Counting_Sort.c)
1. [Gravity (Bead) Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Non-Comparison_Distribution/Gravity_(Bead)_Sort.c)
1. [Pigeonhole Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Non-Comparison_Distribution/Pigeonhole_Sort.c)
1. [Radix LSD Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Non-Comparison_Distribution/Radix_LSD.c)

### [Selection](https://github.com/h-ssiqueira/Sort_Algorithms/tree/master/Source/Selection)
1. [Double Selection Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Selection/Double_Selection_Sort.c)
1. [Max Heap Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Selection/Max_Heap_Sort.c)
1. [Min Heap Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Selection/Min_Heap_Sort.c)
1. [Selection Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Selection/Selection_Sort.c)

<br>

## Complexity Table

Algorithm | Worst case | Best case | Average | Space complexity | In-place | Stable | Notes
:---: | :---: | :---: | :---: | :---: | :---: | :---: | :---:
[Bad Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Bad_Sort.c) | O(N³) | O(N³) | O(N³) | O(1) | **:heavy_check_mark:** | **:x:** |
[Bogo Bogo Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Bogo_Bogo_Sort.c) |  |  |  | O(1) | **:heavy_check_mark:** | **:x:** | The worst case can ve unbounded due to random manipulation
[Bogo Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Bogo_Sort.c) | O((N+1)!) | O(N) | O((N+1)!) | O(1) | **:heavy_check_mark:** | **:x:** | The worst case can be unbounded due to random manipulation
[Bubble Bogo Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Bubble_Bogo_Sort.c) |  |  |  | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** | The worst case can be unbounded due to random manipulation
[Cocktail Bogo Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Cocktail_Bogo_Sort.c) |  |  |  | O(1) | **:heavy_check_mark:** | **:x:** | The worst case can be unbounded due to random manipulation
[Exchange Bogo Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Exchange_Bogo_Sort.c) |  |  |  | O(1) | **:heavy_check_mark:** | **:x:** | The worst case can be unbounded due to random manipulation
[Less Bogo Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Less_Bogo_Sort.c) |  |  |  | O(1) | **:heavy_check_mark:** | **:x:** | The worst case can be unbounded due to random manipulation
[Pancake Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Pancake_Sort.c) | O(N²) | O(N²) | O(N²) | O(1) | **:heavy_check_mark:** | **:x:** |
[Silly Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Silly_Sort.c) |  |  |  | O(1) | **:heavy_check_mark:** | **:x:** |
[Slow Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Slow_Sort.c) |  |  |  | O(1) | **:heavy_check_mark:** | **:x:** |
[Spaghetti Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Spaghetti_Sort.c) | O(N) |  |  | O(N) | **:x:** | **:heavy_check_mark:** |
[Stooge Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Esoteric_Fun_Miscellaneous/Stooge_Sort.c) | ![O(N^(log 3 / log 1.5))](http://www.sciweavers.org/tex2img.php?eq=O%28N%5E%7B%20%5Cfrac%7Blog%203%7D%7Blog%201.5%7D%7D%20%29&bc=White&fc=Black&im=png&fs=12&ff=arev&edit=0) | ![O(N^(log 3 / log 1.5))](http://www.sciweavers.org/tex2img.php?eq=O%28N%5E%7B%20%5Cfrac%7Blog%203%7D%7Blog%201.5%7D%7D%20%29&bc=White&fc=Black&im=png&fs=12&ff=arev&edit=0) | ![O(N^(log 3 / log 1.5))](http://www.sciweavers.org/tex2img.php?eq=O%28N%5E%7B%20%5Cfrac%7Blog%203%7D%7Blog%201.5%7D%7D%20%29&bc=White&fc=Black&im=png&fs=12&ff=arev&edit=0) | O(N) | **:x:** | **:x:** |
[Bubble Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Bubble_Sort.c) | O(N²) | O(N) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Circle Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Circle_Sort.c) | O(N log N log N) | O(N log N) | O(N log N) | O(1) | **:heavy_check_mark:** | **:x:** |
[Cocktail Shaker Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Cocktail_Shaker_Sort.c) | O(N²) | O(N²) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Comb Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Comb_Sort.c) | O(N²) | O(N log N) | ![O(N² / 2^p)](http://www.sciweavers.org/tex2img.php?eq=O%28%5Cfrac%7BN%5E%7B2%7D%7D%7B2%5E%7Bp%7D%7D%29&bc=White&fc=Black&im=png&fs=12&ff=arev&edit=0) | O(1) | **:heavy_check_mark:** | **:x:** | **p** is the number of increments
[Dual Pivot Quick Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Dual_Pivot_Quick_Sort.c) | O(N²) | O(N log N) | O(N log N) | O(log N) | **:heavy_check_mark:** | **:x:** |
[Gnome Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Gnome_Sort.c) | O(N²) | O(N) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Odd-Even Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Odd-Even_Sort.c) | O(N²) | O(N) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Optimized Bubble Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Optimized_Bubble_Sort.c) | O(N²) | O(N) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Optimized Cocktail Shaker Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Cocktail_Shaker_Sort.c) | O(N²) | O(N) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Optimized Gnome Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Optimized_Gnome_Sort.c) | O(N²) | O(N) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Quick Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Quick_Sort.c) | O(N²) | O(N log N) | O(N log N) | O(log N) | **:heavy_check_mark:** | **:x:** |
[Quick Sort 3-way](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Quick_Sort_3-way.c) | O(N²) | O(N) | O(N log N) | O(log N) or O(N) | **:heavy_check_mark:** | **:x:** |
[Stable Quick Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Exchange/Stable_Quick_Sort.c) | O(N²) | O(N log N) | O(N log N) | O(N) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Tim Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Hybrids/Tim_Sort.c) | O(N log N) | O(N) | O(N log N) | O(N) | **:x:** | **:heavy_check_mark:** |
[Binary Insertion Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Insertion/Binary_Insertion_Sort.c) | O(N log N) | O(N) | O(N log N) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Cycle Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Insertion/Cycle_Sort.c) | O(N²) | O(N²) | O(N²) | O(1) | **:heavy_check_mark:** | **:x:** |
[Insertion Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Insertion/Insertion_Sort.c) | O(N²) | O(N) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Patience Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Insertion/Patience_Sort.c) | O(N log N) | O(N) | O(N log N) | O(N) | **:x:** | **:heavy_check_mark:** |
[Shell Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Insertion/Shell_Sort.c) | ![O(N<sup>3/2</sup>)](http://www.sciweavers.org/tex2img.php?eq=O%28N%5E%7B%5Cfrac%7B3%7D%7B2%7D%7D%29&bc=White&fc=Black&im=png&fs=12&ff=arev&edit=0) or O(N log² N) | O(N log N) | --- | O(1) | **:heavy_check_mark:** | **:x:** |
[Tree Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Insertion/Tree_Sort.c) | O(N²) | O(N log N) | O(N log N) | O(N) | **:x:** | **:heavy_check_mark:** | In worst case, O(N²) when using Binary Search Tree and O(N log N) when using Self-Balanced Binary Search Tree
[Bottom-up Merge Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Merge/Bottom-Up_Merge_Sort.c) | O(N log N) | O(N log N) | O(N log N) | O(N) | **:x:** | **:heavy_check_mark:** |
[In-Place Merge Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Merge/In-Place_Merge_Sort.c) | O(N²) | O(N²) | O(N²) | O(log N) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Merge Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Merge/Source/Merge_Sort.c) | O(N log N) | O(N log N) | O(N log N) | O(N) | **:x:** | **:heavy_check_mark:** |
[Bitonic Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Networks_Concurrent/Bitonic_Sort.c) | O(log² N) | O(log² N) | O(log² N) | O(N log² N) | **:heavy_check_mark:** | **:x:** |
[Pairwise Network Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Networks_Concurrent/Pairwise_Network_Sort.c) | ![(log N)(log N+1)/2](http://www.sciweavers.org/tex2img.php?eq=O%28%5Cfrac%7B%28log%20N%29%28log%20N%2B1%29%7D%7B2%7D%29&bc=White&fc=Black&im=png&fs=12&ff=arev&edit=0) | --- | --- | ![N(log N)(log N-1)/4 + N-1](http://www.sciweavers.org/tex2img.php?eq=O%28%5Cfrac%7BN%28log%20N%29%28log%20N-1%29%7D%7B4%7D%20%2B%20N-1%29&bc=White&fc=Black&im=png&fs=12&ff=arev&edit=0) | **:heavy_check_mark:** | **:x:** | Worst case is using parallel time and space complexity non-parallel time
[Bucket Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Non-Comparison_Distribution/Bucket_Sort.c) | O(N²) | O(N+k) | O(N+k) | O(N+k) | **:x:** | **:heavy_check_mark:** | **k** is the number of buckets
[Counting Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Non-Comparison_Distribution/Counting_Sort.c) | O(N+k) | O(N+k) | O(N+k) | O(N+k) | **:x:** | **:heavy_check_mark:** | **k** is the range of input data
[Gravity (Bead) Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Non-Comparison_Distribution/Gravity_(Bead)_Sort.c) | O(S) | O(1) or ![O(sqrt(N))](http://www.sciweavers.org/tex2img.php?eq=O%28%5Csqrt%7BN%7D%29&bc=White&fc=Black&im=png&fs=12&ff=arev&edit=0) | O(N) | O(N²) | **:x:** | **:heavy_check_mark:** | **S** is the sum of array elements, O(1) cannot be implemented in practice
[Pigeonhole Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Non-Comparison_Distribution/Pigeonhole_Sort.c) | O(N+n) | O(N+n) | O(N+n) | O(N+n) | **:x:** | **:heavy_check_mark:** | **N** is the number of elements and **n** is the range of input data
[Radix LSD Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Non-Comparison_Distribution/Radix_LSD.c) | O(NW) | O(NW) | O(NW) | O(N) | **:x:** | **:heavy_check_mark:** | **W** is the maxumum element width (bits)
[Double Selection Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Selection/Double_Selection_Sort.c) | O(N²) | O(N²) | O(N²) | O(1) | **:heavy_check_mark:** | **:x:** | ![\frac{N^2-N}{2}](http://www.sciweavers.org/tex2img.php?eq=%5Cfrac%7BN%5E2-N%7D%7B2%7D&bc=White&fc=Black&im=png&fs=12&ff=arev&edit=0) Comparisons
[Max Heap Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Selection/Max_Heap_Sort.c) | O(N log N) | O(N log N) | O(N log N) | O(1) | **:heavy_check_mark:** | **:x:** |
[Min Heap Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Selection/Min_Heap_Sort.c) | O(N log N) | O(N log N) | O(N log N) | O(1) | **:heavy_check_mark:** | **:x:** |
[Selection Sort](https://github.com/h-ssiqueira/Sort_Algorithms/blob/master/Source/Selection/Selection_Sort.c) | O(N²) | O(N²) | O(N²) | O(1) | **:heavy_check_mark:** | **:x:** | ![\frac{N^2-N}{4}](http://www.sciweavers.org/tex2img.php?eq=%5Cfrac%7BN%5E2-N%7D%7B4%7D&bc=White&fc=Black&im=png&fs=12&ff=arev&edit=0) Comparisons

## Testing
During the development of this program were made performance/time tests with the C programming language denoted below:

### [Time to access data in different arrays](/tests/timetest.c)
There were eight cases of accesses which the program analyzed:
* Declaration of array:
	* Static (S)
	* Dynamic (D)
* Type of access:
	* Read (R)
	* Write (W)
* Method of access:
	* Integer index (I)
	* Pointer (P)

### [Time to assign zero to a variable](/tests/setzerotest.c)
Setting zero to a variable using assignment operator and XOR logical operator.

<hr>

Licensed by [MIT License](LICENSE)
