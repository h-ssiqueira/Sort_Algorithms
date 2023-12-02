// Default libraries
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Directory libraries (created)
#include "esotericFunMiscellaneous/esotericFunMiscellaneous.h"
#include "exchange/exchange.h"
#include "hybrids/hybrids.h"
#include "insertion/insertion.h"
#include "merge/merge.h"
#include "networksConcurrent/networksConcurrent.h"
#include "noncomparisonDistribution/noncomparisonDistribution.h"
#include "selection/selection.h"
#include "utils/utils.h"

// Limit of length of array
// Limit 512MB of data // 2147483648 //Limit of signed int (16GB total)
#define limsize 67108864

bool txtFile = false, displayArray = true, executionTime = true, arraySorted = false;

void printError(char *error, bool clearBuffer){
    clearScreen();
    printf("%s", error);
    if(clearBuffer)
        getchar();
}

// Print and collect the option from user
short menu(char *text, int len){
	short op;
	while(true){
		printf("%s", text);
		if(scanf("%hd", &op) != 1)
            printError(E003, true);
		else if(op < 0 || op > len)
			printError(E004, false);
		else
			break;
	}
	return op;
}

// Print informations before sorting array
void informationsPreSort(long int *array, int length, char *algorithm, int randomRange, short int choice){
	if(txtFile)
		fileBeforeExec(array,length,displayArray,algorithm,randomRange,choice);
	printf("\tBefore %s.", algorithm);
	if(displayArray)
		printArray(array,length);
	printf("\n\tSorting...");
}

// Print informations after sorting array
void informationsPosSort(long int *array, int length, clock_t tic, clock_t toc, bool ascending){
	unsigned long sec, micro;
	arraySorted = isSorted(array,length,ascending);
	if(displayArray)
		printArray(array,length);
	if(executionTime)
		calculateTime(tic,toc,&sec,&micro);
	if(txtFile && (displayArray || executionTime))
		fileAfterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
}

int main(){
    srand(time(NULL));
	clock_t tic, toc;
	long int *array, *arrayPOF2;
    int length = 10, i, powerOf2 = 16, randomRange = 1024;
	short int optionSort, optionCategory, choice = 2;

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
						informationsPreSort(array,length,"Bad Sort",randomRange,choice);
						tic = clock();
                        badSort(array,length);
						toc = clock();
                        break;
                    case 2:
						informationsPreSort(array,length,"Bogo Bogo Sort",randomRange,choice);
						tic = clock();
                        bogoBogoSort(array,length);
						toc = clock();
                        break;
                    case 3:
						informationsPreSort(array,length,"Bogo Sort",randomRange,choice);
						tic = clock();
                        bogoSort(array,length);
						toc = clock();
                        break;
					case 4:
						informationsPreSort(array,length,"Bubble Bogo Sort",randomRange,choice);
						tic = clock();
                        bubbleBogoSort(array,length);
						toc = clock();
                        break;
					case 5:
						informationsPreSort(array,length,"Cocktail Bogo Sort",randomRange,choice);
						tic = clock();
                        cocktailBogoSort(array,length);
						toc = clock();
                        break;
					case 6:
						informationsPreSort(array,length,"Exchange Bogo Sort",randomRange,choice);
						tic = clock();
                        exchangeBogoSort(array,length);
						toc = clock();
                        break;
					case 7:
						informationsPreSort(array,length,"Less Bogo Sort",randomRange,choice);
						tic = clock();
                        lessBogoSort(array,length);
						toc = clock();
                        break;
                    case 8:
						informationsPreSort(array,length,"Pancake Sort",randomRange,choice);
						tic = clock();
                        pancakeSort(array,length);
						toc = clock();
                        break;
                    case 9:
						informationsPreSort(array,length,"Silly Sort",randomRange,choice);
						tic = clock();
                        sillySort(array,0,length-1);
						toc = clock();
                        break;
                    case 10:
                        informationsPreSort(array,length,"Slow Sort",randomRange,choice);
						tic = clock();
                        slowSort(array,0,length-1);
						toc = clock();
                        break;
                    case 11:
						informationsPreSort(array,length,"Spaghetti Sort",randomRange,choice);
						tic = clock();
                        spaghettiSort(array,length);
						toc = clock();
                        break;
                    case 12:
						informationsPreSort(array,length,"Stooge Sort",randomRange,choice);
						tic = clock();
                        stoogeSort(array,0,length-1);
						toc = clock();
                        break;
                }
				informationsPosSort(array,length,tic,toc,true);
                break;
            case 2:
                optionSort = menu("\tChoose the sort to be aplied on Exchange:\n 0 - Menu.\n 1 - Bubble Sort.\n 2 - Circle Sort.\n 3 - Cocktail Shaker Sort.\n 4 - Comb Sort.\n 5 - Dual Pivot Quick Sort.\n 6 - Gnome Sort.\n 7 - Odd-Even Sort.\n 8 - Optimized Bubble Sort.\n 9 - Optimized Cocktail Shaker Sort.\n10 - Optimized Gnome Sort.\n11 - Quick Sort.\n12 - Quick Sort 3-way.\n13 - Stable Quick Sort.\n-> ",13);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
						informationsPreSort(array,length,"Bubble Sort",randomRange,choice);
						tic = clock();
                        bubbleSort(array,length-1);
						toc = clock();
                        break;
                    case 2:
						informationsPreSort(array,length,"Circle Sort",randomRange,choice);
						tic = clock();
                        circleSort(array, length);
						toc = clock();
                        break;
                    case 3:
						informationsPreSort(array,length,"Cocktail Shaker Sort",randomRange,choice);
						tic = clock();
                        cocktailShakerSort(array,length);
						toc = clock();
                        break;
                    case 4:
						informationsPreSort(array,length,"Comb Sort",randomRange,choice);
						tic = clock();
                        combSort(array,length);
						toc = clock();
                        break;
                    case 5:
						informationsPreSort(array,length,"Dual Pivot Quick Sort",randomRange,choice);
						tic = clock();
                        dualPivotQuickSort(array,0,length-1);
						toc = clock();
                        break;
                    case 6:
						informationsPreSort(array,length,"Gnome Sort",randomRange,choice);
						tic = clock();
                        gnomeSort(array,length);
						toc = clock();
                        break;
                    case 7:
						informationsPreSort(array,length,"Odd-Even Sort",randomRange,choice);
						tic = clock();
                        oddEvenSort(array,length);
						toc = clock();
                        break;
                    case 8:
						informationsPreSort(array,length,"Optimized Bubble Sort",randomRange,choice);
						tic = clock();
                        bubbleSortOptmized(array,length-1);
						toc = clock();
                        break;
					case 9:
						informationsPreSort(array,length,"Optimized Cocktail Shaker Sort",randomRange,choice);
						tic = clock();
                        optimizedCocktailShakerSort(array,length);
						toc = clock();
                        break;
                    case 10:
						informationsPreSort(array,length,"Optimized Gnome Sort",randomRange,choice);
						tic = clock();
                        optimizedGnomeSort(array,length);
						toc = clock();
                        break;
                    case 11:
						informationsPreSort(array,length,"Quick Sort",randomRange,choice);
						tic = clock();
                        quickSort(array,0,length-1);
						toc = clock();
                        break;
					case 12:
						informationsPreSort(array,length,"3-way Quick Sort",randomRange,choice);
						tic = clock();
                        quickSort3Way(array,0,length-1);
						toc = clock();
                        break;
                    case 13:
						informationsPreSort(array,length,"Stable Quick Sort",randomRange,choice);
						tic = clock();
                        stableQuickSort(array,0,length-1);
						toc = clock();
                        break;
                }
				informationsPosSort(array,length,tic,toc,true);
                break;
            case 3:
                optionSort = menu("\tChoose the sort to be aplied on Hybrids:\n0 - Menu.\n1 - Tim Sort.\n-> ",1);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
						informationsPreSort(array,length,"Tim Sort",randomRange,choice);
						tic = clock();
                        timSort(array,length);
						toc = clock();
                        break;
                }
				informationsPosSort(array,length,tic,toc,true);
                break;
            case 4:
                optionSort = menu("\tChoose the sort to be aplied on Insertion:\n0 - Menu.\n1 - AVLTree Sort.\n2 - Binary Insertion Sort.\n3 - Cycle Sort.\n4 - Insertion Sort.\n5 - Patience Sort.\n6 - Shell Sort.\n7 - Tree Sort.\n-> ",7);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
					case 1:
						informationsPreSort(array,length,"AVL Tree Sort",randomRange,choice);
						tic = clock();
                        AVLTreeSort(array,length);
						toc = clock();
                        break;
                    case 2:
						informationsPreSort(array,length,"Binary Insertion Sort",randomRange,choice);
						tic = clock();
                        binaryInsertionSort(array,length);
						toc = clock();
                        break;
                    case 3:
						informationsPreSort(array,length,"Cycle Sort",randomRange,choice);
						tic = clock();
                        cycleSort(array,length);
						toc = clock();
                        break;
                    case 4:
						informationsPreSort(array,length,"Insertion Sort",randomRange,choice);
						tic = clock();
                        insertionSort(array,length);
						toc = clock();
                        break;
					case 5:
						informationsPreSort(array,length,"Patience Sort",randomRange,choice);
						tic = clock();
                        patienceSort(array,length);
						toc = clock();
                        break;
                    case 6:
						informationsPreSort(array,length,"Shell Sort",randomRange,choice);
						tic = clock();
                        shellSort(array,length);
						toc = clock();
                        break;
                    case 7:
						informationsPreSort(array,length,"Tree Sort",randomRange,choice);
						tic = clock();
                        treeSort(array,length);
						toc = clock();
                        break;
                }
				informationsPosSort(array,length,tic,toc,true);
                break;
            case 5:
                optionSort = menu("\tChoose the sort to be aplied on Merge:\n0 - Menu.\n1 - Bottomup Merge Sort.\n2 - In-Place Merge Sort.\n3 - Merge Sort.\n-> ",3);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
						informationsPreSort(array,length,"Bottom-up Merge Sort",randomRange,choice);
						tic = clock();
                        bottomupMergeSort(array,length);
						toc = clock();
                        break;
                    case 2:
						informationsPreSort(array,length,"In Place Merge Sort",randomRange,choice);
						tic = clock();
                        mergeSortInPlace(array,0,length-1);
						toc = clock();
                        break;
                    case 3:
						informationsPreSort(array,length,"Merge Sort",randomRange,choice);
						tic = clock();
                        mergeSort(array,0,length-1);
						toc = clock();
                        break;
                }
				informationsPosSort(array,length,tic,toc,true);
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
							printf("\n\tNote: Bitonic sort just accepts lengths of power of 2.\n\tCurrent size: %d.\n\tNew size applied on this algorithm: %d.\n", length,powerOf2);
							informationsPreSort(arrayPOF2,powerOf2,"Bitonic Sort",randomRange,choice);
							tic = clock();
                        	bitonicSort(arrayPOF2,0,powerOf2,1);
							toc = clock();
							informationsPosSort(arrayPOF2,powerOf2,tic,toc,true);
							free(arrayPOF2);
						}
						else{
							informationsPreSort(array,length,"Bitonic Sort",randomRange,choice);
							tic = clock();
                        	bitonicSort(array,0,length,1);
							toc = clock();
							informationsPosSort(array,length,tic,toc,true);
						}
                        break;
                    case 2:
						informationsPreSort(array,length,"Pairwise Network Sort",randomRange,choice);
						tic = clock();
                        pairwiseSort(array,0,length,1);
						toc = clock();
						informationsPosSort(array,length,tic,toc,true);
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
						informationsPreSort(array,length,"Bucket Sort",randomRange,choice);
						tic = clock();
                        bucketSort(array,length);
						toc = clock();
                        break;
                    case 2:
						informationsPreSort(array,length,"Counting Sort",randomRange,choice);
						tic = clock();
                        countingSort(array,length);
						toc = clock();
                        break;
                    case 3:
						informationsPreSort(array,length,"Gravity (Bead) Sort",randomRange,choice);
						tic = clock();
                        beadSort(array,length);
						toc = clock();
                        break;
                    case 4:
						informationsPreSort(array,length,"Pigeonhole Sort",randomRange,choice);
						tic = clock();
                        pigeonholeSort(array,length);
						toc = clock();
                        break;
					case 5:
						informationsPreSort(array,length,"Radix LSD Sort",randomRange,choice);
						tic = clock();
                        radixLSD(array,length,10);
						toc = clock();
                        break;
                }
				informationsPosSort(array,length,tic,toc,true);
                break;
            case 8:
                optionSort = menu("\tChoose the sort to be aplied on Selection:\n0 - Menu.\n1 - Double Selection Sort.\n2 - Max Heap Sort.\n3 - Min Heap Sort.\n4 - Selection Sort.\n-> ",4);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
						informationsPreSort(array,length,"Double Selection Sort",randomRange,choice);
						tic = clock();
                        doubleSelectionSort(array,length);
						toc = clock();
                        break;
                    case 2:
						informationsPreSort(array,length,"Max Heap Sort",randomRange,choice);
						tic = clock();
                        maxHeapSort(array,length);
						toc = clock();
                        break;
                    case 3:
						informationsPreSort(array,length,"Min Heap Sort",randomRange,choice);
						tic = clock();
                        minHeapSort(array,length);
						toc = clock();
						arraySorted = isSorted(array,length,false);
                        break;
                    case 4:
						informationsPreSort(array,length,"Selection Sort",randomRange,choice);
						tic = clock();
                        selectionSort(array,length);
						toc = clock();
                        break;
                }
				informationsPosSort(array,length,tic,toc,optionSort != 3);
                break;
			case 9:
				while(true){
					while(true){
						printf("\tConfigurations:\n0 - Menu.\n1 - Change sorting case - %s\n2 - Change random interval - %d.\n3 - Change length of array - %d.\n4 - Save results in a text file - %s\n5 - Display arrays - %s\n6 - Display execution time - %s\n-> ",choice > 1 ? (choice > 2 ? (choice == 3 ? "Descending." : "Identical.") : "Random.") : "Ascending.",randomRange,length,txtFile ? "YES." : "NO.",displayArray ? "YES." : "NO.",executionTime ? "YES." : "NO.");
						if(scanf("%hd",&optionSort) != 1)
                            printError(E003, true);
						else if(optionSort < 0 || optionSort > 6)
							printError(E004, false);
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
								if(scanf("%d", &randomRange) != 1)
									printError(E003, true);
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
								if(scanf("%u", &length) != 1)
									printError(E003, true);
								else if(length < 2 || length > limsize)
                                    printError(E006, false);
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
