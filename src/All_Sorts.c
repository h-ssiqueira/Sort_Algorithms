// Default libraries
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Directory libraries (created)
#include "Esoteric_Fun_Miscellaneous/Esoteric_Fun_Miscellaneous.h"
#include "Exchange/Exchange.h"
#include "Hybrids/Hybrids.h"
#include "Insertion/Insertion.h"
#include "Merge/Merge.h"
#include "Networks_Concurrent/Networks_Concurrent.h"
#include "Non-Comparison_Distribution/Non-Comparison_Distribution.h"
#include "Selection/Selection.h"
#include "QRcode.h"

#if defined unix || defined __unix || defined __unix__ || defined __APPLE__ || defined __MACH__ || defined __linux__
	#define clear system("clear")
#endif
#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
	#define clear system("cls")
#endif

// Limit of length of array
// Limit 512MB of data // 2147483648 //Limit of signed int (16GB total)
#define limsize 67108864

// Get time after executing the sorting algorithm
void afterExec(long int *array, int length, bool display, bool time, unsigned long sec, unsigned long micro, bool sorted){
	FILE *txt = fopen("data.txt","a+");
	if(txt != NULL){
		if(display){
			fprintf(txt,"\n\tArray%ssorted:\n", sorted ? " " : " not ");
			for(long int *i = array; i < array + length; i++)
				fprintf(txt,"%ld ", *i);
			fprintf(txt,"\n");
		}
		if(time)
			fprintf(txt,"\n\tExecution time: %lu seconds %lu microsseconds.\n", sec, micro);
	}
	else
		printf("\n\tError: Cannot open the file.");
	if(txt != NULL)
		fclose(txt);
}

// Get time before executing the sorting algorithm
void beforeExec(long int *array, int length, bool display, char *sort, int range, int choice){
	FILE *txt = fopen("data.txt","a+");
	if(txt != NULL){
		fprintf(txt,"\n\t%s algorithm with length of %u elements and range of 0 to %d %s.",sort, length,choice == 2 ? range : length, choice == 1 ? "ascending" : choice == 2 ? "randomly" : choice == 3 ? "descending" : "identical");
		if(display){
			fprintf(txt,"\n\tArray before sort:\n");
			for(long int *i = array; i < array + length; i++)
				fprintf(txt,"%ld ", *i);
			fprintf(txt,"\n");
		}
	}
	else
		printf("\n\tError: Cannot open the file.");
	if(txt != NULL)
		fclose(txt);
}

// Calculate execution time
void calculatetime(clock_t tic, clock_t toc, unsigned long *sec, unsigned long *micro){
	*sec = (unsigned long)(toc - tic) / CLOCKS_PER_SEC;
	*micro = (unsigned long)(toc - tic) % 1000000;
	printf("\n\tExecution time: %lu seconds %lu microsseconds.\n", *sec, *micro);
}

// Clear screen
void clearScreen(){
	if(clear == -1)
		printf("\nCouldn't clear the screen\n");
}

// Create the array
void create(long int **array, int length){
	*array = (long int*)malloc(length * sizeof(long int));
	if(!(*array)){
		printf("\n\tError: array couldn't be allocated.");
		exit(1);
	}
}

// Generate numbers for the array
void generate(long int *array, int length, short int choice, int randomRange){
	long int *i, j;
	switch(choice){
		case 1:
			for(i = array, j ^= j; i < array + length; i++, j++)
				*i = j;
			break;
		case 3:
			for(i = array, j ^= j; i < array + length; i++, j++)
				*i = length - j;
			break;
		case 4:
			for(i = array; i < array + length; i++)
				*i = 1;
			break;
		default:
			for(i = array; i < array + length; i++)
				*i = rand() % randomRange;
	}
}

// Print the array
void print(long int *array, int length){
    printf("\n");
    for(long int *i = array; i < array+length; i++)
        printf("%ld ",*i);
}

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

/* Check if the array is sorted
*  array, length of array, increasing (true) or decreasing (false)
*/
bool sorted(long int *array, int length, bool increasing){
	if(increasing){
		for(long int *i = array; i < array + length - 1; i++)
			if(*i > *(i+1))
				return false;
		return true;
	}
	else{
		for(long int *i = array; i < array + length - 1; i++)
			if(*i < *(i+1))
				return false;
		return true;
	}
}

int main(){
    srand(time(NULL));
	clock_t tic, toc;
	long int *array, *arrayPOF2;
    int length = 10, i, powerOf2 = 16, randomRange = 1024;
	short int optionSort, optionCategory, choice = 2;
	unsigned long sec, micro;
	bool txtFile = false, displayArray = true, executionTime = true, arraySorted = false;

	create(&array,length);

	clearScreen();

    while(true){
		generate(array,length,choice,randomRange);
        optionCategory = menu("\tWhich category of sort would you like to see?\n0 - Exit.\n1 - Esoteric & Fun & Miscellaneous.\n2 - Exchange.\n3 - Hybrids.\n4 - Insertion.\n5 - Merge.\n6 - Networks & Concurrent.\n7 - Non-Comparison & Distribution.\n8 - Selection.\n9 - Configurations.\n-> ",9);
		clearScreen();
        if(optionCategory == 0)
            break;
        switch(optionCategory){
            case 1:
				optionSort = menu("\tChoose the sort to be aplied on Esoteric & Fun & Miscellaneous:\n 0 - Menu.\n 1 - Bad_Sort.\n 2 - Bogo_Bogo_Sort.\n 3 - Bogo_Sort.\n 4 - Bubble_Bogo_Sort.\n 5 - Cocktail_Bogo_Sort.\n 6 - Exchange_Bogo_Sort.\n 7 - Less_Bogo_Sort.\n 8 - Pancake_Sort.\n 9 - Silly_Sort.\n10 - Slow_Sort.\n11 - Spaghetti_Sort.\n12 - Stooge_Sort.\n-> ",12);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
						if(txtFile)
							beforeExec(array,length,displayArray,"Bad Sort",randomRange,choice);
                        printf("\tBefore Bad Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        BadSort(array,length);
						toc = clock();
                        break;
                    case 2:
						if(txtFile)
							beforeExec(array,length,displayArray,"Bogo Bogo Sort",randomRange,choice);
                        printf("\tBefore Bogo Bogo Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        BogoBogoSort(array,length);
						toc = clock();
                        break;
                    case 3:
						if(txtFile)
							beforeExec(array,length,displayArray,"Bogo Sort",randomRange,choice);
                        printf("\tBefore Bogo Sort.");
                        if(displayArray)
							print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        bogo_sort(array,length);
						toc = clock();
                        break;
					case 4:
						if(txtFile)
							beforeExec(array,length,displayArray,"Bubble Bogo Sort",randomRange,choice);
                        printf("\tBefore Bubble Bogo Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        BubbleBogoSort(array,length);
						toc = clock();
                        break;
					case 5:
						if(txtFile)
							beforeExec(array,length,displayArray,"Cocktail Bogo Sort",randomRange,choice);
                        printf("\tBefore Cocktail Bogo Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        CocktailBogoSort(array,length);
						toc = clock();
                        break;
					case 6:
						if(txtFile)
							beforeExec(array,length,displayArray,"Exchange Bogo Sort",randomRange,choice);
                        printf("\tBefore Exchange Bogo Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        ExchangeBogoSort(array,length);
						toc = clock();
                        break;
					case 7:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Less Bogo Sort",randomRange,choice);
						printf("\tBefore Less Bogo Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        LessBogoSort(array,length);
						toc = clock();
                        break;
                    case 8:
						if(txtFile)
							beforeExec(array,length,displayArray,"Pancake Sort",randomRange,choice);
                        printf("\tBefore Pancake Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        PancakeSort(array,length);
						toc = clock();
                        break;
                    case 9:
						if(txtFile)
							beforeExec(array,length,displayArray,"Silly Sort",randomRange,choice);
                        printf("\tBefore Silly Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        SillySort(array,0,length-1);
						toc = clock();
                        break;
                    case 10:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Slow Sort",randomRange,choice);
						printf("\tBefore Slow Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Slow_Sort(array,0,length-1);
						toc = clock();
                        break;
                    case 11:
						if(txtFile)
							beforeExec(array,length,displayArray,"Spaghetti Sort",randomRange,choice);
                        printf("\tBefore Spaghetti Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        SpaghettiSort(array,length);
						toc = clock();
                        break;
                    case 12:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Stooge Sort",randomRange,choice);
						printf("\tBefore Stooge Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        StoogeSort(array,0,length-1);
						toc = clock();
                        break;
                }
				arraySorted = sorted(array,length,true);
				arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayArray)
                    print(array,length);
				if(executionTime)
					calculatetime(tic,toc,&sec,&micro);
				if(txtFile && (displayArray || executionTime))
					afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
                break;
            case 2:
                optionSort = menu("\tChoose the sort to be aplied on Exchange:\n 0 - Menu.\n 1 - Bubble_Sort.\n 2 - Circle_Sort.\n 3 - Cocktail_Shaker_Sort.\n 4 - Comb_Sort.\n 5 - Dual_Pivot_Quick_Sort.\n 6 - Gnome_Sort.\n 7 - Odd-Even_Sort.\n 8 - Optimized_Bubble_Sort.\n 9 - Optimized_Cocktail_Shaker_Sort.\n10 - Optimized_Gnome_Sort.\n11 - Quick_Sort.\n12 - Quick_Sort_3-way.\n13 - Stable_Quick_Sort.\n-> ",13);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Bubble Sort",randomRange,choice);
						printf("\tBefore Bubble Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Bubble_sort(array,length-1);
						toc = clock();
                        break;
                    case 2:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Circle Sort",randomRange,choice);
						printf("\tBefore Circle Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        CircleSort(array, length);
						toc = clock();
                        break;
                    case 3:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Cocktail Shaker Sort",randomRange,choice);
						printf("\tBefore Cocktail Shaker Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        CocktailShakerSort(array,length);
						toc = clock();
                        break;
                    case 4:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Comb Sort",randomRange,choice);
						printf("\tBefore Comb Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        CombSort(array,length);
						toc = clock();
                        break;
                    case 5:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Dual Pivot Quick Sort",randomRange,choice);
						printf("\tBefore Dual Pivot Quick Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        DualPivotQuickSort(array,0,length-1);
						toc = clock();
                        break;
                    case 6:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Gnome Sort",randomRange,choice);
						printf("\tBefore Gnome Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Gnome_Sort(array,length);
						toc = clock();
                        break;
                    case 7:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Odd-Even Sort",randomRange,choice);
						printf("\tBefore Odd-Even Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Odd_Even_Sort(array,length);
						toc = clock();
                        break;
                    case 8:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Optimized Bubble Sort",randomRange,choice);
						printf("\tBefore Optimized Bubble Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        BubbleSortOptmized(array,length-1);
						toc = clock();
                        break;
					case 9:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Optimized Cocktail Shaker Sort",randomRange,choice);
						printf("\tBefore Optimized Cocktail Shaker Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        OPTCocktailShakerSort(array,length);
						toc = clock();
                        break;
                    case 10:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Optimized Gnome Sort",randomRange,choice);
						printf("\tBefore Optimized Gnome Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Optimized_Gnome_Sort(array,length);
						toc = clock();
                        break;
                    case 11:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Quick Sort",randomRange,choice);
						printf("\tBefore Quick Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Quick_Sort(array,0,length-1);
						toc = clock();
                        break;
					case 12:
                        if(txtFile)
							beforeExec(array,length,displayArray,"3-way Quick Sort",randomRange,choice);
						printf("\tBefore 3-way Quick Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        QuickSort3way(array,0,length-1);
						toc = clock();
                        break;
                    case 13:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Stable Quick Sort",randomRange,choice);
						printf("\tBefore Stable Quick Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        StableQuickSort(array,0,length-1);
						toc = clock();
                        break;
                }
				arraySorted = sorted(array,length,true);
				arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayArray)
                    print(array,length);
				if(executionTime)
					calculatetime(tic,toc,&sec,&micro);
				if(txtFile && (displayArray || executionTime))
					afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
                break;
            case 3:
                optionSort = menu("\tChoose the sort to be aplied on Hybrids:\n0 - Menu.\n1 - Tim_Sort.\n-> ",1);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Tim Sort",randomRange,choice);
						printf("\tBefore Tim Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        TimSort(array,length);
						toc = clock();
                        break;
                }
				arraySorted = sorted(array,length,true);
				arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayArray)
                    print(array,length);
				if(executionTime)
					calculatetime(tic,toc,&sec,&micro);
				if(txtFile && (displayArray || executionTime))
					afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
                break;
            case 4:
                optionSort = menu("\tChoose the sort to be aplied on Insertion:\n0 - Menu.\n1 - AVLTree_Sort.\n2 - Binary_Insertion_Sort.\n3 - Cycle_Sort.\n4 - Insertion_Sort.\n5 - Patience_Sort.\n6 - Shell_Sort.\n7 - Tree_Sort.\n-> ",7);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
					case 1:
						if(txtFile)
							beforeExec(array,length,displayArray,"AVL Tree Sort",randomRange,choice);
						printf("\n\tBefore AVL Tree Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        AVLTree_Sort(array,length);
						toc = clock();
                        break;
                    case 2:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Binary Insertion Sort",randomRange,choice);
						printf("\tBefore Binary Insertion Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Insertion_Sort(array,length);
						toc = clock();
                        break;
                    case 3:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Cycle Sort",randomRange,choice);
						printf("\tBefore Cycle Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        CycleSort(array,length);
						toc = clock();
                        break;
                    case 4:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Insertion Sort",randomRange,choice);
						printf("\tBefore Insertion Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Insertion_Sort(array,length);
						toc = clock();
                        break;
					case 5:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Patience Sort",randomRange,choice);
						printf("\tBefore Patience Sort.");
                        if(displayArray)
							print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        PatienceSort(array,length);
						toc = clock();
                        break;
                    case 6:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Shell Sort",randomRange,choice);
						printf("\tBefore Shell Sort.");
                        if(displayArray)
							print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        ShellSort(array,length);
						toc = clock();
                        break;
                    case 7:
						if(txtFile)
							beforeExec(array,length,displayArray,"Tree Sort",randomRange,choice);
                        printf("\tBefore Tree Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        TreeSort(array,length);
						toc = clock();
                        break;
                }
				arraySorted = sorted(array,length,true);
				arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayArray)
                    print(array,length);
				if(executionTime)
					calculatetime(tic,toc,&sec,&micro);
				if(txtFile && (displayArray || executionTime))
					afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
                break;
            case 5:
                optionSort = menu("\tChoose the sort to be aplied on Merge:\n0 - Menu.\n1 - Bottomup_Merge_Sort.\n2 - In-Place_Merge_Sort.\n3 - Merge_Sort.\n-> ",3);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Bottom-up Merge Sort",randomRange,choice);
						printf("\tBefore Bottom-up Merge Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Bottomup_Merge_Sort(array,length);
						toc = clock();
                        break;
                    case 2:
                        if(txtFile)
							beforeExec(array,length,displayArray,"In Place Merge Sort",randomRange,choice);
						printf("\tBefore In Place Merge Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Merge_Sort_In_Place(array,0,length-1);
						toc = clock();
                        break;
                    case 3:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Merge Sort",randomRange,choice);
						printf("\tBefore Merge Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Merge_Sort(array,0,length-1);
						toc = clock();
                        break;
                }
				arraySorted = sorted(array,length,true);
				arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayArray)
                    print(array,length);
				if(executionTime)
					calculatetime(tic,toc,&sec,&micro);
				if(txtFile && (displayArray || executionTime))
					afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
                break;
            case 6:
                optionSort = menu("\tChoose the sort to be aplied on Networks & Concurrent:\n0 - Menu.\n1 - Bitonic_Sort.\n2 - Pairwise_Network_Sort.\n-> ",2);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
					case 1:
						i = 1;
						while(i < length)
							i <<= 1;
						if(i != length){
							create(&arrayPOF2,powerOf2);
							generate(arrayPOF2,powerOf2,choice,randomRange);
							if(txtFile)
								beforeExec(arrayPOF2,powerOf2,displayArray,"Bitonic Sort",randomRange,choice);
							printf("\n\tNote: Bitonic sort just accepts lengths of power of 2.\n\tCurrent size: %d.\n\tNew size applied on this algorithm: %d.\n", length,powerOf2);
							printf("\tBefore Bitonic Sort.");
							if(displayArray)
								print(arrayPOF2,powerOf2);
							printf("\n\tSorting...");
							tic = clock();
                        	BitonicSort(arrayPOF2,0,powerOf2,1);
							toc = clock();
                        	arraySorted = sorted(arrayPOF2,powerOf2,true);
							arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
							if(displayArray)
                        		print(arrayPOF2,powerOf2);
							if(executionTime)
								calculatetime(tic,toc,&sec,&micro);
							if(txtFile && (displayArray || executionTime))
								afterExec(arrayPOF2,powerOf2,displayArray,executionTime,sec,micro,arraySorted);
							free(arrayPOF2);
						}
						else{
							if(txtFile)
								beforeExec(array,length,displayArray,"Bitonic Sort",randomRange,choice);
                        	printf("\tBefore Bitonic Sort.");
							if(displayArray)
                        		print(array,length);
							printf("\n\tSorting...");
							tic = clock();
                        	BitonicSort(array,0,length,1);
							toc = clock();
                        	arraySorted = sorted(array,length,true);
							arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
							if(displayArray)
                        		print(array,length);
							if(executionTime)
								calculatetime(tic,toc,&sec,&micro);
							if(txtFile && (displayArray || executionTime))
								afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
						}
                        break;
                    case 2:
						if(txtFile)
							beforeExec(array,length,displayArray,"Pairwise Network Sort",randomRange,choice);
                        printf("\tBefore Pairwise Network Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Pairwise_Sort(array,0,length,1);
						toc = clock();
						arraySorted = sorted(array,length,true);
						arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
						if(displayArray)
                    		print(array,length);
						if(executionTime)
							calculatetime(tic,toc,&sec,&micro);
						if(txtFile && (displayArray || executionTime))
							afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
                        break;
                }
                break;
            case 7:
                optionSort = menu("\tChoose the sort to be aplied on Non-Comparison & Distribution:\n0 - Menu.\n1 - Bucket_Sort.\n2 - Counting_Sort.\n3 - Gravity_(Bead)_Sort.\n4 - Pigeonhole_Sort.\n5 - Radix_LSD Sort.\n-> ",5);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Bucket Sort",randomRange,choice);
						printf("\tBefore Bucket Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        BucketSort(array,length);
						toc = clock();
                        break;
                    case 2:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Counting Sort",randomRange,choice);
						printf("\tBefore Counting Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Counting_Sort(array,length);
						toc = clock();
                        break;
                    case 3:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Gravity (Bead) Sort",randomRange,choice);
						printf("\tBefore Gravity (Bead) Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        BeadSort(array,length);
						toc = clock();
                        break;
                    case 4:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Pigeonhole Sort",randomRange,choice);
						printf("\tBefore Pigeonhole Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Pigeonhole_Sort(array,length);
						toc = clock();
                        break;
					case 5:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Radix LSD Sort",randomRange,choice);
						printf("\tBefore Radix LSD Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Radix_LSD(array,length,10);
						toc = clock();
                        break;
                }
				arraySorted = sorted(array,length,true);
				arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayArray)
                    print(array,length);
				if(executionTime)
					calculatetime(tic,toc,&sec,&micro);
				if(txtFile && (displayArray || executionTime))
					afterExec(array,length,displayArray,executionTime,sec,micro,arraySorted);
                break;
            case 8:
                optionSort = menu("\tChoose the sort to be aplied on Selection:\n0 - Menu.\n1 - Double_Selection_Sort.\n2 - Max_Heap_Sort.\n3 - Min_Heap_Sort.\n4 - Selection_Sort.\n-> ",4);
				clearScreen();
				if(!optionSort)
					break;
                switch(optionSort){
                    case 1:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Double Selection Sort",randomRange,choice);
						printf("\tBefore Double Selection Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Double_Selection_Sort(array,length);
						toc = clock();
                        break;
                    case 2:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Max Heap Sort",randomRange,choice);
						printf("\tBefore Max Heap Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        MaxHeapSort(array,length);
						toc = clock();
                        break;
                    case 3:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Min Heap Sort",randomRange,choice);
						printf("\tBefore Min Heap Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        MinHeapSort(array,length);
						toc = clock();
						arraySorted = sorted(array,length,false);
						arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
                        break;
                    case 4:
                        if(txtFile)
							beforeExec(array,length,displayArray,"Selection Sort",randomRange,choice);
						printf("\tBefore Selection Sort.");
						if(displayArray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Selection_Sort(array,length);
						toc = clock();
                        break;
                }
				if(optionSort != 3)
					arraySorted = sorted(array,length,true);
					arraySorted ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayArray)
                	print(array,length);
				if(executionTime)
					calculatetime(tic,toc,&sec,&micro);
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
							create(&array,length);
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
	QR_code();
	free(array);
    return 0;
}
