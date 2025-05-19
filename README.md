# Sorting Algorithms
![GitHub Repository Size](https://img.shields.io/github/repo-size/h-ssiqueira/Sort_algorithms?label=Repository%20Size&style=flat-square)
![Sorts available](https://img.shields.io/badge/Total_sorts-48-blue?style=flat-square)

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/a6ca7bbf238b4f148cc05878a568554a)](https://app.codacy.com/gh/h-ssiqueira/Sort_Algorithms/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade&style=for-the-badge)

![Contributions](https://img.shields.io/static/v1.svg?label=Contributions&message=Welcome&color=information&style=for-the-badge)

![Docker](https://img.shields.io/badge/Docker-2496ED?style=for-the-badge&logo=docker&logoColor=white)
![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)
![MAC](https://img.shields.io/badge/MAC-000000?style=for-the-badge&logo=macos&logoColor=white)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)

![Visual Studio Code](https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white)

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

## Summary
* [Description](#Description)
	* [How to execute](#How-to-execute)
	 	* [Linux & MAC](#Linux-&-MAC)
		* [Windows](#Windows)
* [Screens](#Screens)
	* [Menu](#Menu)
	* [Submenu](#Submenu)
	* [Settings](#Settings)
	* [Execution](#Execution)
	* [Exit](#Exit)
* [Algorithms](#Algorithms)
* [Complexity Table](#Complexity-Table)


## Description
A program to show the execution time and the variaty of sorting algorithms in ```C``` language. There are 48 sorting algorithms avaliable distributed in 8 different categories.
___
### How to execute
On program settings there are avaliable modifications noted in table below:

Configuration | Default
:---: | :---:
Sorting case | Random
Random interval | 32
Length of array | 10
Save results in a text file | NO
Display arrays | YES
Display execution time | YES

Note: you need to have the [GCC compiler](https://gcc.gnu.org/) or docker environment installed in your machine to execute the instructions below to run the program.
___
#### Generated Image From Packages
- Pull the image:
```shell
docker pull ghcr.io/h-ssiqueira/sort_algorithms:latest
```
- Run the image into a container:
```shell
docker run -it --rm \
  -v /data.txt:/usr/src/app/data.txt \
  ghcr.io/h-ssiqueira/sort_algorithms:latest
```
#### Docker
- Build the image:
```shell
docker build -t sort_algorithms .
```
- Execute the image:
```shell
docker run -it --rm \
  -v /data.txt:/usr/src/app/data.txt \
  sort_algorithms
```
___
#### Linux & MAC
Open a terminal and go to project's directory. Execute ```make``` in terminal allow to compile the program. Commands avaliable to execute with make (```make ${command}```):

Command | Description
:---: | :---:
clean | Clear all objects generated
cr | Compile and run
rmproper | Clear all object files
run | Execute main program
___
#### Windows
On Command Prompt or PowerShell and go to project's directory and execute ```execute.bat```.

___

## Screens
### Menu
![Menu](/imgs/menu.png)
### Submenu
![Submenu](/imgs/submenu.png)
### Settings
![Settings](/imgs/settings.png)
### Execution
![Execution](/imgs/execution.png)
### Exit
![Exit](/imgs/exit.png)

___

## Algorithms

Category | Sort
:---: | :---:
[Esoteric & Fun & Miscellaneous](src/esotericFunMiscellaneous) | [Bad Sort](src/esotericFunMiscellaneous/badSort.c)<br>[Bogo Bogo Sort](src/esotericFunMiscellaneous/bogoBogoSort.c)<br>[Bogo Sort](src/esotericFunMiscellaneous/bogoSort.c)<br>[Bubble Bogo Sort](src/esotericFunMiscellaneous/bubbleBogoSort.c)<br>[Cocktail Bogo Sort](src/esotericFunMiscellaneous/cocktailBogoSort.c)<br>[Exchange Bogo Sort](src/esotericFunMiscellaneous/exchangeBogoSort.c)<br>[Less Bogo Sort](src/esotericFunMiscellaneous/lessBogoSort.c)<br>[Pancake Sort](src/esotericFunMiscellaneous/pancakeSort.c)<br>[Silly Sort](src/esotericFunMiscellaneous/sillySort.c)<br>[Sleep Sort](src/esotericFunMiscellaneous/sleepSort.c)<br>[Slow Sort](src/esotericFunMiscellaneous/slowSort.c)<br>[Spaghetti Sort](src/esotericFunMiscellaneous/spaghettiSort.c)<br>[Stooge Sort](src/esotericFunMiscellaneous/stoogeSort.c)
[Exchange](src/exchange) | [Bubble Sort](src/exchange/bubbleSort.c)<br>[Circle Sort](src/exchange/circleSort.c)<br>[Cocktail Shaker Sort](src/exchange/cocktailShakerSort.c)<br>[Comb Sort](src/exchange/combSort.c)<br>[Dual Pivot Quick Sort](src/exchange/dualPivotQuickSort.c)<br>[Gnome Sort](src/exchange/gnomeSort.c)<br>[Odd-Even Sort](src/exchange/oddEvenSort.c)<br>[Optimized Bubble Sort](src/exchange/optimizedBubbleSort.c)<br>[Optimized Cocktail Shaker Sort](src/exchange/optimizedCocktailShakerSort.c)<br>[Optimized Gnome Sort](src/exchange/optimizedGnomeSort.c)<br>[Quick Sort](src/exchange/quickSort.c)<br>[Quick Sort 3-way](src/exchange/quickSort3Way.c)<br>[Stable Quick Sort](src/exchange/stableQuickSort.c)
[Hybrids](src/hybrids) | [Tim Sort](src/hybrids/timSort.c)
[Insertion](src/insertion) | [AVL Tree Sort](src/insertion/AVLTreeSort.c)<br>[Binary Insertion Sort](src/insertion/binaryInsertionSort.c)<br>[Cycle Sort](src/insertion/cycleSort.c)<br>[Insertion Sort](src/insertion/insertionSort.c)<br>[Patience Sort](src/insertion/patienceSort.c)<br>[Shell Sort](src/insertion/shellSort.c)<br>[Tree Sort](src/insertion/treeSort.c)
[Merge](src/merge) | [Bottom-up Merge Sort](src/merge/bottomupMergeSort.c)<br>[In-Place Merge Sort](src/merge/inPlaceMergeSort.c)<br>[Merge Sort](src/merge/mergeSort.c)
[Networks & Concurrent](src/networksConcurrent) | [Bitonic Sort](src/networksConcurrent/bitonicSort.c)<br>[Pairwise Network Sort](src/networksConcurrent/pairwiseNetworkSort.c)
[Non-Comparison & Distribution](src/noncomparisonDistribution) | [Bucket Sort](src/noncomparisonDistribution/bucketSort.c)<br>[Counting Sort](src/noncomparisonDistribution/countingSort.c)<br>[Gravity (Bead) Sort](src/noncomparisonDistribution/gravityBeadSort.c)<br>[Pigeonhole Sort](src/noncomparisonDistribution/pigeonholeSort.c)<br>[Radix LSD Sort](src/noncomparisonDistribution/radixLSDSort.c)
[Selection](src/selection) | [Double Selection Sort](src/selection/doubleSelectionSort.c)<br>[Max Heap Sort](src/selection/maxHeapSort.c)<br>[Min Heap Sort](src/selection/minHeapSort.c)<br>[Selection Sort](src/selection/selectionSort.c)

___

## Complexity Table

Algorithm | Worst case | Best case | Average | Space complexity | In-place | Stable | Notes
:---: | :---: | :---: | :---: | :---: | :---: | :---: | :---:
[Bad Sort](src/esotericFunMiscellaneous/badSort.c) | O(N³) | O(N³) | O(N³) | O(1) | **:heavy_check_mark:** | **:x:** |
[Bogo Bogo Sort](src/esotericFunMiscellaneous/bogoBogoSort.c) | O(infinity) | O(N²) | O((N+1)!) | O(1) | **:heavy_check_mark:** | **:x:** | The worst case can be unbounded due to random manipulation
[Bogo Sort](src/esotericFunMiscellaneous/bogoSort.c) | O(infinity) | O(N) | O((N+1)!) | O(1) | **:heavy_check_mark:** | **:x:** | The worst case can be unbounded due to random manipulation
[Bubble Bogo Sort](src/esotericFunMiscellaneous/bubbleBogoSort.c) | O(infinity) | O(N) | O((N+1)!) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** | The worst case can be unbounded due to random manipulation
[Cocktail Bogo Sort](src/esotericFunMiscellaneous/cocktailBogoSort.c) | O(infinity) | O(N) | O((N+1)!) | O(1) | **:heavy_check_mark:** | **:x:** | The worst case can be unbounded due to random manipulation
[Exchange Bogo Sort](src/esotericFunMiscellaneous/exchangeBogoSort.c) | O(infinity) | O(N) | O((N+1)!) | O(1) | **:heavy_check_mark:** | **:x:** | The worst case can be unbounded due to random manipulation
[Less Bogo Sort](src/esotericFunMiscellaneous/lessBogoSort.c) | O(infinity) | O(N²) | O((N+1)!) | O(1) | **:heavy_check_mark:** | **:x:** | The worst case can be unbounded due to random manipulation
[Pancake Sort](src/esotericFunMiscellaneous/pancakeSort.c) | O(N²) | O(N²) | O(N²) | O(1) | **:heavy_check_mark:** | **:x:** |
[Silly Sort](src/esotericFunMiscellaneous/sillySort.c) | O(N²) | O(N²) | O(N²) | O(1) | **:heavy_check_mark:** | **:x:** |
[Sleep Sort](src/esotericFunMiscellaneous/sleepSort.c) | O(INT_MAX) | O(max(input) + N) | O(max(input) + N) | O(N) | **:x:** | **:heavy_check_mark:** | Take use of CPU scheduler to sort
[Slow Sort](src/esotericFunMiscellaneous/slowSort.c) | O(N\*N!) | O(N) | O((N+1)!) | O(1) | **:heavy_check_mark:** | **:x:** |
[Spaghetti Sort](src/esotericFunMiscellaneous/spaghettiSort.c) | O(N) | O(N) | O(N) | O(N) | **:x:** | **:heavy_check_mark:** |
[Stooge Sort](src/esotericFunMiscellaneous/stoogeSort.c) | ![O(N^(log 3 / log 1.5))](imgs/stooge.png) | ![O(N^(log 3 / log 1.5))](imgs/stooge.png) | ![O(N^(log 3 / log 1.5))](imgs/stooge.png) | O(N) | **:x:** | **:x:** |
[Bubble Sort](src/exchange/bubbleSort.c) | O(N²) | O(N) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Circle Sort](src/exchange/circleSort.c) | O(N log N log N) | O(N log N) | O(N log N) | O(1) | **:heavy_check_mark:** | **:x:** |
[Cocktail Shaker Sort](src/exchange/cocktailShakerSort.c) | O(N²) | O(N²) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Comb Sort](src/exchange/combSort.c) | O(N²) | O(N log N) | ![O(N² / 2^p)](imgs/comb.png) | O(1) | **:heavy_check_mark:** | **:x:** | **P** is the number of increments
[Dual Pivot Quick Sort](src/exchange/dualPivotQuickSort.c) | O(N²) | O(N log N) | O(N log N) | O(log N) | **:heavy_check_mark:** | **:x:** |
[Gnome Sort](src/exchange/gnomeSort.c) | O(N²) | O(N) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Odd-Even Sort](src/exchange/oddEvenSort.c) | O(N²) | O(N) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Optimized Bubble Sort](src/exchange/optimizedBubbleSort.c) | O(N²) | O(N) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Optimized Cocktail Shaker Sort](src/exchange/cocktailShakerSort.c) | O(N²) | O(N) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Optimized Gnome Sort](src/exchange/optimizedGnomeSort.c) | O(N²) | O(N) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Quick Sort](src/exchange/quickSort.c) | O(N²) | O(N log N) | O(N log N) | O(log N) | **:heavy_check_mark:** | **:x:** |
[Quick Sort 3-way](src/exchange/quickSort3Way.c) | O(N²) | O(N) | O(N log N) | O(log N) or O(N) | **:heavy_check_mark:** | **:x:** |
[Stable Quick Sort](src/exchange/stableQuickSort.c) | O(N²) | O(N log N) | O(N log N) | O(N) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Tim Sort](src/hybrids/timSort.c) | O(N log N) | O(N) | O(N log N) | O(N) | **:x:** | **:heavy_check_mark:** |
[AVL Tree Sort](src/insertion/AVLTreeSort.c) | O(N log N) | O(N) | O(N log N) | O(N) | **:x:** | **:heavy_check_mark:** | In worst case, O(N²) when using Binary Search Tree and O(N log N) when using Self-Balanced Binary Search Tree
[Binary Insertion Sort](src/insertion/binaryInsertionSort.c) | O(N log N) | O(N) | O(N log N) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Cycle Sort](src/insertion/cycleSort.c) | O(N²) | O(N²) | O(N²) | O(1) | **:heavy_check_mark:** | **:x:** |
[Insertion Sort](src/insertion/insertionSort.c) | O(N²) | O(N) | O(N²) | O(1) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Patience Sort](src/insertion/patienceSort.c) | O(N log N) | O(N) | O(N log N) | O(N) | **:x:** | **:heavy_check_mark:** |
[Shell Sort](src/insertion/shellSort.c) | ![O(N<sup>3/2</sup>)](imgs/shell.png) or O(N log² N) | O(N log N) | O(N^1.25) to O(N²) | O(1) | **:heavy_check_mark:** | **:x:** |
[Tree Sort](src/insertion/treeSort.c) | O(N²) | O(N log N) | O(N log N) | O(N) | **:x:** | **:heavy_check_mark:** | In worst case, O(N²) when using Binary Search Tree and O(N log N) when using Self-Balanced Binary Search Tree
[Bottom-up Merge Sort](src/merge/bottomupMergeSort.c) | O(N log N) | O(N log N) | O(N log N) | O(N) | **:x:** | **:heavy_check_mark:** |
[In-Place Merge Sort](src/merge/inPlaceMergeSort.c) | O(N²) | O(N²) | O(N²) | O(log N) | **:heavy_check_mark:** | **:heavy_check_mark:** |
[Merge Sort](src/merge/mergeSort.c) | O(N log N) | O(N log N) | O(N log N) | O(N) | **:x:** | **:heavy_check_mark:** |
[Bitonic Sort](src/networksConcurrent/bitonicSort.c) | O(log² N) | O(log² N) | O(log² N) | O(N log² N) | **:heavy_check_mark:** | **:x:** |
[Pairwise Network Sort](src/networksConcurrent/pairwiseNetworkSort.c) | ![(log N)(log N+1)/2](imgs/pairwiseworst.png) or O(N log N) | O(N log N) | O(N log N) | ![N(log N)(log N-1)/4 + N-1](imgs/pairwiseaverage.png) | **:heavy_check_mark:** | **:x:** | Worst case is using parallel time and space complexity non-parallel time
[Bucket Sort](src/noncomparisonDistribution/bucketSort.c) | O(N²) | O(N+k) | O(N+k) | O(N+k) | **:x:** | **:heavy_check_mark:** | **k** is the number of buckets
[Counting Sort](src/noncomparisonDistribution/countingSort.c) | O(N+k) | O(N+k) | O(N+k) | O(N+k) | **:x:** | **:heavy_check_mark:** | **k** is the range of input data
[Gravity (Bead) Sort](src/noncomparisonDistribution/gravityBeadSort.c) | O(S) | O(1) or ![O(sqrt(N))](imgs/gravity.png) | O(N) | O(N²) | **:x:** | **:heavy_check_mark:** | **S** is the sum of array elements, O(1) cannot be implemented in practice
[Pigeonhole Sort](src/noncomparisonDistribution/pigeonholeSort.c) | O(N+n) | O(N+n) | O(N+n) | O(N+n) | **:x:** | **:heavy_check_mark:** | **N** is the number of elements and **n** is the range of input data
[Radix LSD Sort](src/noncomparisonDistribution/radixLSDSort.c) | O(NW) | O(NW) | O(NW) | O(N) | **:x:** | **:heavy_check_mark:** | **W** is the maxumum element width (bits)
[Double Selection Sort](src/selection/doubleSelectionSort.c) | O(N²) | O(N²) | O(N²) | O(1) | **:heavy_check_mark:** | **:x:** | ![\frac{N^2-N}{2}](imgs/doubleselection.png) Comparisons
[Max Heap Sort](src/selection/maxHeapSort.c) | O(N log N) | O(N log N) | O(N log N) | O(1) | **:heavy_check_mark:** | **:x:** |
[Min Heap Sort](src/selection/minHeapSort.c) | O(N log N) | O(N log N) | O(N log N) | O(1) | **:heavy_check_mark:** | **:x:** |
[Selection Sort](src/selection/selectionSort.c) | O(N²) | O(N²) | O(N²) | O(1) | **:heavy_check_mark:** | **:x:** | ![\frac{N^2-N}{4}](imgs/selection.png) Comparisons
