// Default libraries
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Directory libraries (created)
#include "esoteric fun miscellaneous/esotericFunMiscellaneous.h"
#include "exchange/exchange.h"
#include "hybrids/hybrids.h"
#include "insertion/insertion.h"
#include "merge/merge.h"
#include "networks concurrent/networksConcurrent.h"
#include "noncomparison distribution/noncomparisonDistribution.h"
#include "selection/selection.h"
#include "utils/utils.h"

// Limit of length of array
// Limit 512MB of data // 2147483648 //Limit of signed int (16GB total)
#define limsize 67108864


// Print and collect the option from user
short menu(char *text, int len){
	short op;
	while(true){
		printf("%s", text);
		if(scanf("%hd", &op) != 1){
			clearScreen();
			printf("\n\tValue inserted is not a number. Try again.\n"),getchar();
		}
		else if(op < 0 || op > len){
			clearScreen();
			printf("\n\tError: Choose the value in the range displayed.\n\n");
		}
		else
			break;
	}
	return op;
}

int main(){
    srand(time(NULL));
	clock_t tic, toc;
	long int *array, *arrayPOF2;
    int length = 10, i, powerOf2 = 16, randomRange = 1024;
	short int optionSort, optionCategory, choice = 2;
	unsigned long sec, micro;
	bool txtFile = false, displayArray = true, executionTime = true, arraySorted = false;

	createArray(&array,length);

	clearScreen();

    while(true){
		generateArray(array,length,choice,randomRange);
        optionCategory = menu("\tWhich category of sort would you like to see?\n0 - Exit.\n1 - Esoteric & Fun & Miscellaneous.\n2 - Exchange.\n3 - Hybrids.\n4 - Insertion.\n5 - Merge.\n6 - Networks & Concurrent.\n7 - Non-Comparison & Distribution.\n8 - Selection.\n9 - Configurations.\n-> ",9);
		clearScreen();
        if(optionCategory == 0)
            break;
        switch(optionCategory){
            case 1:
				optionSort = menu("\tChoose the sort to be aplied on Esoteric & Fun & Miscellaneous:\n 0 - Menu.\n 1 - Bad Sort.\n 2 - Bogo Bogo Sort.\n 3 - Bogo Sort.\n 4 - Bubble Bogo Sort.\n 5 - Cocktail Bogo Sort.\n 6 - Exchange Bogo Sort.\n 7 - Less Bogo Sort.\n 8 - Pancake Sort.\n 9 - Silly Sort.\n10 - Slow Sort.\n11 - Spaghetti Sort.\n12 - Stooge Sort.\n-> ",12);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
						if(txtFile)
							beforeExec(array,length,displayArray,"Bad Sort",randomRange,choice);
                        printf("\tBefore Bad Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        badSort(array,length);
						toc = clock();
                        break;
                    case 2:
						if(txtFile)
							beforeExec(array,length,displayArray,"Bogo Bogo Sort",randomRange,choice);
                        printf("\tBefore Bogo Bogo Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        bogoBogoSort(array,length);
						toc = clock();
                        break;
                    case 3:
						if(txtFile)
							beforeExec(array,length,displayArray,"Bogo Sort",randomRange,choice);
                        printf("\tBefore Bogo Sort.");
                        if(displayArray)
							printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        bogoSort(array,length);
						toc = clock();
                        break;
					case 4:
						if(txtFile)
							beforeExec(array,length,displayArray,"Bubble Bogo Sort",randomRange,choice);
                        printf("\tBefore Bubble Bogo Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        bubbleBogoSort(array,length);
						toc = clock();
                        break;
					case 5:
						if(txtFile)
							beforeExec(array,length,displayArray,"Cocktail Bogo Sort",randomRange,choice);
                        printf("\tBefore Cocktail Bogo Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        cocktailBogoSort(array,length);
						toc = clock();
                        break;
					case 6:
						if(txtFile)
							beforeExec(array,length,displayArray,"Exchange Bogo Sort",randomRange,choice);
                        printf("\tBefore Exchange Bogo Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        exchangeBogoSort(array,length);
						toc = clock();
                        break;
					case 7:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Less Bogo Sort",randomRange,choice);
						printf("\tBefore Less Bogo Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        lessBogoSort(array,length);
						toc = clock();
                        break;
                    case 8:
						if(txtFile)
							beforeExec(array,length,displayArray,"Pancake Sort",randomRange,choice);
                        printf("\tBefore Pancake Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        pancakeSort(array,length);
						toc = clock();
                        break;
                    case 9:
						if(txtFile)
							beforeExec(array,length,displayArray,"Silly Sort",randomRange,choice);
                        printf("\tBefore Silly Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        sillySort(array,0,length-1);
						toc = clock();
                        break;
                    case 10:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Slow Sort",randomRange,choice);
						printf("\tBefore Slow Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        slowSort(array,0,length-1);
						toc = clock();
                        break;
                    case 11:
						if(txtFile)
							beforeExec(array,length,displayArray,"Spaghetti Sort",randomRange,choice);
                        printf("\tBefore Spaghetti Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        spaghettiSort(array,length);
						toc = clock();
                        break;
                    case 12:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Stooge Sort",randomRange,choice);
						printf("\tBefore Stooge Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        stoogeSort(array,0,length-1);
						toc = clock();
                        break;
                }
				arraySorted = isSorted(array,length,true);
				arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayArray)
                    printArray(array,length);
				if(executionTime)
					calculateTime(tic,toc,&sec,&micro);
				if(txtFile && (displayArray || executionTime))
					afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
                break;
            case 2:
                optionSort = menu("\tChoose the sort to be aplied on Exchange:\n 0 - Menu.\n 1 - Bubble Sort.\n 2 - Circle Sort.\n 3 - Cocktail Shaker Sort.\n 4 - Comb Sort.\n 5 - Dual Pivot Quick Sort.\n 6 - Gnome Sort.\n 7 - Odd-Even Sort.\n 8 - Optimized Bubble Sort.\n 9 - Optimized Cocktail Shaker Sort.\n10 - Optimized Gnome Sort.\n11 - Quick Sort.\n12 - Quick Sort 3-way.\n13 - Stable Quick Sort.\n-> ",13);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Bubble Sort",randomRange,choice);
						printf("\tBefore Bubble Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        bubbleSort(array,length-1);
						toc = clock();
                        break;
                    case 2:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Circle Sort",randomRange,choice);
						printf("\tBefore Circle Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        circleSort(array, length);
						toc = clock();
                        break;
                    case 3:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Cocktail Shaker Sort",randomRange,choice);
						printf("\tBefore Cocktail Shaker Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        cocktailShakerSort(array,length);
						toc = clock();
                        break;
                    case 4:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Comb Sort",randomRange,choice);
						printf("\tBefore Comb Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        combSort(array,length);
						toc = clock();
                        break;
                    case 5:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Dual Pivot Quick Sort",randomRange,choice);
						printf("\tBefore Dual Pivot Quick Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        dualPivotQuickSort(array,0,length-1);
						toc = clock();
                        break;
                    case 6:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Gnome Sort",randomRange,choice);
						printf("\tBefore Gnome Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        gnomeSort(array,length);
						toc = clock();
                        break;
                    case 7:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Odd-Even Sort",randomRange,choice);
						printf("\tBefore Odd-Even Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        oddEvenSort(array,length);
						toc = clock();
                        break;
                    case 8:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Optimized Bubble Sort",randomRange,choice);
						printf("\tBefore Optimized Bubble Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        bubbleSortOptmized(array,length-1);
						toc = clock();
                        break;
					case 9:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Optimized Cocktail Shaker Sort",randomRange,choice);
						printf("\tBefore Optimized Cocktail Shaker Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        optimizedCocktailShakerSort(array,length);
						toc = clock();
                        break;
                    case 10:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Optimized Gnome Sort",randomRange,choice);
						printf("\tBefore Optimized Gnome Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        optimizedGnomeSort(array,length);
						toc = clock();
                        break;
                    case 11:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Quick Sort",randomRange,choice);
						printf("\tBefore Quick Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        quickSort(array,0,length-1);
						toc = clock();
                        break;
					case 12:
                        if(txtFile)
							beforeExec(array,length,displayArray,"3-way Quick Sort",randomRange,choice);
						printf("\tBefore 3-way Quick Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        quickSort3Way(array,0,length-1);
						toc = clock();
                        break;
                    case 13:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Stable Quick Sort",randomRange,choice);
						printf("\tBefore Stable Quick Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        stableQuickSort(array,0,length-1);
						toc = clock();
                        break;
                }
				arraySorted = isSorted(array,length,true);
				arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayArray)
                    printArray(array,length);
				if(executionTime)
					calculateTime(tic,toc,&sec,&micro);
				if(txtFile && (displayArray || executionTime))
					afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
                break;
            case 3:
                optionSort = menu("\tChoose the sort to be aplied on Hybrids:\n0 - Menu.\n1 - Tim Sort.\n-> ",1);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Tim Sort",randomRange,choice);
						printf("\tBefore Tim Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        timSort(array,length);
						toc = clock();
                        break;
                }
				arraySorted = isSorted(array,length,true);
				arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayArray)
                    printArray(array,length);
				if(executionTime)
					calculateTime(tic,toc,&sec,&micro);
				if(txtFile && (displayArray || executionTime))
					afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
                break;
            case 4:
                optionSort = menu("\tChoose the sort to be aplied on Insertion:\n0 - Menu.\n1 - AVLTree Sort.\n2 - Binary Insertion Sort.\n3 - Cycle Sort.\n4 - Insertion Sort.\n5 - Patience Sort.\n6 - Shell Sort.\n7 - Tree Sort.\n-> ",7);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
					case 1:
						if(txtFile)
							beforeExec(array,length,displayArray,"AVL Tree Sort",randomRange,choice);
						printf("\n\tBefore AVL Tree Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        AVLTreeSort(array,length);
						toc = clock();
                        break;
                    case 2:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Binary Insertion Sort",randomRange,choice);
						printf("\tBefore Binary Insertion Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        binaryInsertionSort(array,length);
						toc = clock();
                        break;
                    case 3:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Cycle Sort",randomRange,choice);
						printf("\tBefore Cycle Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        cycleSort(array,length);
						toc = clock();
                        break;
                    case 4:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Insertion Sort",randomRange,choice);
						printf("\tBefore Insertion Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        insertionSort(array,length);
						toc = clock();
                        break;
					case 5:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Patience Sort",randomRange,choice);
						printf("\tBefore Patience Sort.");
                        if(displayArray)
							printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        patienceSort(array,length);
						toc = clock();
                        break;
                    case 6:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Shell Sort",randomRange,choice);
						printf("\tBefore Shell Sort.");
                        if(displayArray)
							printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        shellSort(array,length);
						toc = clock();
                        break;
                    case 7:
						if(txtFile)
							beforeExec(array,length,displayArray,"Tree Sort",randomRange,choice);
                        printf("\tBefore Tree Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        treeSort(array,length);
						toc = clock();
                        break;
                }
				arraySorted = isSorted(array,length,true);
				arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayArray)
                    printArray(array,length);
				if(executionTime)
					calculateTime(tic,toc,&sec,&micro);
				if(txtFile && (displayArray || executionTime))
					afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
                break;
            case 5:
                optionSort = menu("\tChoose the sort to be aplied on Merge:\n0 - Menu.\n1 - Bottomup Merge Sort.\n2 - In-Place Merge Sort.\n3 - Merge Sort.\n-> ",3);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Bottom-up Merge Sort",randomRange,choice);
						printf("\tBefore Bottom-up Merge Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        bottomupMergeSort(array,length);
						toc = clock();
                        break;
                    case 2:
                        if(txtFile)
							beforeExec(array,length,displayArray,"In Place Merge Sort",randomRange,choice);
						printf("\tBefore In Place Merge Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        mergeSortInPlace(array,0,length-1);
						toc = clock();
                        break;
                    case 3:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Merge Sort",randomRange,choice);
						printf("\tBefore Merge Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        mergeSort(array,0,length-1);
						toc = clock();
                        break;
                }
				arraySorted = isSorted(array,length,true);
				arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayArray)
                    printArray(array,length);
				if(executionTime)
					calculateTime(tic,toc,&sec,&micro);
				if(txtFile && (displayArray || executionTime))
					afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
                break;
            case 6:
                optionSort = menu("\tChoose the sort to be aplied on Networks & Concurrent:\n0 - Menu.\n1 - Bitonic Sort.\n2 - Pairwise Network Sort.\n-> ",2);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
					case 1:
						i = 1;
						while(i < length)
							i <<= 1;
						if(i != length){
							createArray(&arrayPOF2,powerOf2);
							generateArray(arrayPOF2,powerOf2,choice,randomRange);
							if(txtFile)
								beforeExec(arrayPOF2,powerOf2,displayArray,"Bitonic Sort",randomRange,choice);
							printf("\n\tNote: Bitonic sort just accepts lengths of power of 2.\n\tCurrent size: %d.\n\tNew size applied on this algorithm: %d.\n", length,powerOf2);
							printf("\tBefore Bitonic Sort.");
							if(displayArray)
								printArray(arrayPOF2,powerOf2);
							printf("\n\tSorting...");
							tic = clock();
                        	bitonicSort(arrayPOF2,0,powerOf2,1);
							toc = clock();
                        	arraySorted = isSorted(arrayPOF2,powerOf2,true);
							arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
							if(displayArray)
                        		printArray(arrayPOF2,powerOf2);
							if(executionTime)
								calculateTime(tic,toc,&sec,&micro);
							if(txtFile && (displayArray || executionTime))
								afterExec(arrayPOF2,powerOf2,displayArray,executionTime,sec,micro,arraySorted);
							free(arrayPOF2);
						}
						else{
							if(txtFile)
								beforeExec(array,length,displayArray,"Bitonic Sort",randomRange,choice);
                        	printf("\tBefore Bitonic Sort.");
							if(displayArray)
                        		printArray(array,length);
							printf("\n\tSorting...");
							tic = clock();
                        	bitonicSort(array,0,length,1);
							toc = clock();
                        	arraySorted = isSorted(array,length,true);
							arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
							if(displayArray)
                        		printArray(array,length);
							if(executionTime)
								calculateTime(tic,toc,&sec,&micro);
							if(txtFile && (displayArray || executionTime))
								afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
						}
                        break;
                    case 2:
						if(txtFile)
							beforeExec(array,length,displayArray,"Pairwise Network Sort",randomRange,choice);
                        printf("\tBefore Pairwise Network Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        pairwiseSort(array,0,length,1);
						toc = clock();
						arraySorted = isSorted(array,length,true);
						arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
						if(displayArray)
                    		printArray(array,length);
						if(executionTime)
							calculateTime(tic,toc,&sec,&micro);
						if(txtFile && (displayArray || executionTime))
							afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
                        break;
                }
                break;
            case 7:
                optionSort = menu("\tChoose the sort to be aplied on Non-Comparison & Distribution:\n0 - Menu.\n1 - Bucket Sort.\n2 - Counting Sort.\n3 - Gravity (Bead) Sort.\n4 - Pigeonhole Sort.\n5 - Radix LSD Sort.\n-> ",5);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Bucket Sort",randomRange,choice);
						printf("\tBefore Bucket Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        bucketSort(array,length);
						toc = clock();
                        break;
                    case 2:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Counting Sort",randomRange,choice);
						printf("\tBefore Counting Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        countingSort(array,length);
						toc = clock();
                        break;
                    case 3:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Gravity (Bead) Sort",randomRange,choice);
						printf("\tBefore Gravity (Bead) Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        beadSort(array,length);
						toc = clock();
                        break;
                    case 4:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Pigeonhole Sort",randomRange,choice);
						printf("\tBefore Pigeonhole Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        pigeonholeSort(array,length);
						toc = clock();
                        break;
					case 5:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Radix LSD Sort",randomRange,choice);
						printf("\tBefore Radix LSD Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        radixLSD(array,length,10);
						toc = clock();
                        break;
                }
				arraySorted = isSorted(array,length,true);
				arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayArray)
                    printArray(array,length);
				if(executionTime)
					calculateTime(tic,toc,&sec,&micro);
				if(txtFile && (displayArray || executionTime))
					afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
                break;
            case 8:
                optionSort = menu("\tChoose the sort to be aplied on Selection:\n0 - Menu.\n1 - Double Selection Sort.\n2 - Max Heap Sort.\n3 - Min Heap Sort.\n4 - Selection Sort.\n-> ",4);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Double Selection Sort",randomRange,choice);
						printf("\tBefore Double Selection Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        doubleSelectionSort(array,length);
						toc = clock();
                        break;
                    case 2:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Max Heap Sort",randomRange,choice);
						printf("\tBefore Max Heap Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        maxHeapSort(array,length);
						toc = clock();
                        break;
                    case 3:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Min Heap Sort",randomRange,choice);
						printf("\tBefore Min Heap Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        minHeapSort(array,length);
						toc = clock();
						arraySorted = isSorted(array,length,false);
						arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
                        break;
                    case 4:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Selection Sort",randomRange,choice);
						printf("\tBefore Selection Sort.");
						if(displayArray)
                        	printArray(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        selectionSort(array,length);
						toc = clock();
                        break;
                }
				if(optionSort != 3)
					arraySorted = isSorted(array,length,true);
					arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayArray)
                	printArray(array,length);
				if(executionTime)
					calculateTime(tic,toc,&sec,&micro);
				if(txtFile && (displayArray || executionTime))
					afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
                break;
			case 9:
				while(true){
					while(true){
						printf("\tConfigurations:\n0 - Menu.\n1 - Change sorting case - %s\n2 - Change random interval - %d.\n3 - Change length of array - %d.\n4 - Save results in a text file - %s\n5 - Display arrays - %s\n6 - Display execution time - %s\n-> ",choice > 1 ? (choice > 2 ? (choice == 3 ? "Descending." : "Identical.") : "Random.") : "Ascending.",randomRange,length,txtFile ? "YES." : "NO.",displayArray ? "YES." : "NO.",executionTime ? "YES." : "NO.");
						if(scanf("%hd",&optionSort) != 1){
							clearScreen();
							printf("\n\tValue inserted is not a number. Try again.\n\n"),getchar();
						}
						else if(optionSort < 0 || optionSort > 6){
							clearScreen();
							printf("\n\tError: Choose the value in the range displayed.\n\n");
						}
						else
							break;
					}
					clearScreen();
					if(optionSort == 0)
						break;
					switch(optionSort){
						case 1:
							choice = menu("\tInsert the sorting case:\n1 - Ascending.\n2 - Random.\n3 - Descending.\n4 - Identical elements.\n-> ",4);
							clearScreen();
							break;
						case 2:
							while(true){
								printf("Insert the random interval limit: ");
								if(scanf("%d", &randomRange) != 1){
									clearScreen();
									printf("Value inserted is not a number. Try again.\n"),	getchar();
								}
								else{
									clearScreen();
									break;
								}
							}
							if(randomRange < 3)
								randomRange = 3;
							else if(randomRange > __INT_MAX__)
								randomRange = __INT_MAX__;
							break;
						case 3:
							while(true){
								printf("Insert the new length of the array: ");
								if(scanf("%u", &length) != 1){
									clearScreen();
									printf("Value inserted is not a number. Try again.\n"), getchar();
								}
								else if(length < 2 || length > limsize){
									clearScreen();
									printf("Value inserted is out of range. Try again.\n");
								}
								else
									break;
							}
							i = 1;
							while(i < length)
								i <<= 1;
							if(length == i)
								powerOf2 = length;
							free(array);
							createArray(&array,length);
							break;
						case 4:
							txtFile = !txtFile;
							break;
						case 5:
							displayArray = !displayArray;
							break;
						case 6:
							executionTime = !executionTime;
							break;
					}
				}
				break;
        }
    }
	QRCode();
	free(array);
    return 0;
}
