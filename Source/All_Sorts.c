// Default libraries
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
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

// Limit of length of array
// Limit 512MB of data // 2147483648 //Limit of signed int (16GB total)
#define limsize 67108864

// Create the array
void create(long int **array, int length);

// Print the array
void print(long int *array, int length);

// Generate numbers for the array
void generate(long int *array, int length, short int choice, int randominterval);

// Calculate execution time
void calculatetime(struct timeval start, struct timeval end, unsigned long *sec, unsigned long *micro);

// Get time before executing the sorting algorithm
void BeforeExec(long int *array, int length, bool display, char *sort);

// Get time after executing the sorting algorithm
void AfterExec(long int *array, int length, bool display, bool time, unsigned long sec, unsigned long micro);

// Sorted increasing
bool sorted(long int *array, int length);
// Sorted decreasing
bool sortedD(long int *array, int length);

int main(){
    srand(time(NULL));
	struct timeval start, end;
	long int *array, *arrayPOF2;
    int length = 10, i, powerof2 = 16, randominterval = 1024;
	short int option_sort, option_category, choice = 2;
	unsigned long sec, micro;
	bool txtfile = false, displayarray = true, exectime = true;

	create(&array,length);

    while(true){
		generate(array,length,choice,randominterval);
        do{
			optionc:
            printf("\n\tWhich category of sort would you like to see?");
            printf("\n0 - Exit.");
            printf("\n1 - Esoteric & Fun & Miscellaneous.");
            printf("\n2 - Exchange.");
            printf("\n3 - Hybrids.");
            printf("\n4 - Insertion.");
            printf("\n5 - Merge.");
            printf("\n6 - Networks & Concurrent.");
            printf("\n7 - Non-Comparison & Distribution.");
            printf("\n8 - Selection.");
			printf("\n9 - Configurations.");
            printf("\n-> ");
            while(scanf("%hd",&option_category) != 1){
				printf("\n\tValue inserted is not a number. Try again.\n");
				getchar();
				goto optionc;
			}
            if(option_category < 0 || option_category > 9)
                printf("\n\tError: Choose the value in the range displayed.\n");
        }while(option_category < 0 || option_category > 9);
        if(option_category == 0)
            break;
        switch(option_category){
            case 1:
                do{
					esotericfunmisc:
                    printf("\n\tChoose the sort to be aplied on Esoteric & Fun & Miscellaneous:");
					printf("\n 0 - Menu.");
                    printf("\n 1 - Bad_Sort.");
                    printf("\n 2 - Bogo_Bogo_Sort.");
                    printf("\n 3 - Bogo_Sort.");
					printf("\n 4 - Bubble_Bogo_Sort.");
					printf("\n 5 - Cocktail_Bogo_Sort.");
					printf("\n 6 - Exchange_Bogo_Sort.");
					printf("\n 7 - Less_Bogo_Sort.");
                    printf("\n 8 - Pancake_Sort.");
                    printf("\n 9 - Silly_Sort.");
                    printf("\n10 - Slow_Sort.");
                    printf("\n11 - Spaghetti_Sort.");
                    printf("\n12 - Stooge_Sort.");
                    printf("\n-> ");
                    while(scanf("%hd",&option_sort) != 1){
						printf("\n\tValue inserted is not a number. Try again.\n");
						getchar();
						goto esotericfunmisc;
					}
                    if(option_sort < 0 || option_sort > 12)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 12);
                switch(option_sort){
                    case 1:
						if(txtfile)
							BeforeExec(array,length,displayarray,"Bad Sort");
                        printf("\n\tBefore Bad Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        BadSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 2:
						if(txtfile)
							BeforeExec(array,length,displayarray,"Bogo Bogo Sort");
                        printf("\n\tBefore Bogo Bogo Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        BogoBogoSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 3:
						if(txtfile)
							BeforeExec(array,length,displayarray,"Bogo Sort");
                        printf("\n\tBefore Bogo Sort.");
                        if(displayarray)
							print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        bogo_sort(array,length);
						gettimeofday(&end,NULL);
                        break;
					case 4:
						if(txtfile)
							BeforeExec(array,length,displayarray,"Bubble Bogo Sort");
                        printf("\n\tBefore Bubble Bogo Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        BubbleBogoSort(array,length);
						gettimeofday(&end,NULL);
                        break;
					case 5:
						if(txtfile)
							BeforeExec(array,length,displayarray,"Cocktail Bogo Sort");
                        printf("\n\tBefore Cocktail Bogo Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        CocktailBogoSort(array,length);
						gettimeofday(&end,NULL);
                        break;
					case 6:
						if(txtfile)
							BeforeExec(array,length,displayarray,"Exchange Bogo Sort");
                        printf("\n\tBefore Exchange Bogo Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        ExchangeBogoSort(array,length);
						gettimeofday(&end,NULL);
                        break;
					case 7:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Less Bogo Sort");
						printf("\n\tBefore Less Bogo Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        LessBogoSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 8:
						if(txtfile)
							BeforeExec(array,length,displayarray,"Pancake Sort");
                        printf("\n\tBefore Pancake Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        PancakeSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 9:
						if(txtfile)
							BeforeExec(array,length,displayarray,"Silly Sort");
                        printf("\n\tBefore Silly Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        SillySort(array,0,length-1);
						gettimeofday(&end,NULL);
                        break;
                    case 10:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Slow Sort");
						printf("\n\tBefore Slow Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Slow_Sort(array,0,length-1);
						gettimeofday(&end,NULL);
                        break;
                    case 11:
						if(txtfile)
							BeforeExec(array,length,displayarray,"Spaghetti Sort");
                        printf("\n\tBefore Spaghetti Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        SpaghettiSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 12:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Stooge Sort");
						printf("\n\tBefore Stooge Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        StoogeSort(array,0,length-1);
						gettimeofday(&end,NULL);
                        break;
                }
				sorted(array,length) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayarray)
                    print(array,length);
				if(exectime)
					calculatetime(start,end,&sec,&micro);
				if(txtfile && (displayarray || exectime))
					AfterExec(array,length,displayarray,exectime,sec,micro);
                break;
            case 2:
                do{
					exchange:
                    printf("\n\tChoose the sort to be aplied on Exchange:");
					printf("\n 0 - Menu.");
                    printf("\n 1 - Bubble_Sort.");
                    printf("\n 2 - Circle_Sort.");
                    printf("\n 3 - Cocktail_Shaker_Sort.");
                    printf("\n 4 - Comb_Sort.");
                    printf("\n 5 - Dual_Pivot_Quick_Sort.");
                    printf("\n 6 - Gnome_Sort.");
                    printf("\n 7 - Odd-Even_Sort.");
                    printf("\n 8 - Optimized_Bubble_Sort.");
					printf("\n 9 - Optimized_Cocktail_Shaker_Sort.");
                    printf("\n10 - Optimized_Gnome_Sort.");
                    printf("\n11 - Quick_Sort.");
					printf("\n12 - Quick_Sort_3-way.");
                    printf("\n13 - Stable_Quick_Sort.");
                    printf("\n-> ");
                    while(scanf("%hd",&option_sort) != 1){
						printf("\n\tValue inserted is not a number. Try again.\n");
						getchar();
						goto exchange;
					}
                    if(option_sort < 0 || option_sort > 13)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 13);
                switch(option_sort){
                    case 1:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Bubble Sort");
						printf("\n\tBefore Bubble Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Bubble_sort(array,length-1);
						gettimeofday(&end,NULL);
                        break;
                    case 2:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Circle Sort");
						printf("\n\tBefore Circle Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        CircleSort(array, length);
						gettimeofday(&end,NULL);
                        break;
                    case 3:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Cocktail Shaker Sort");
						printf("\n\tBefore Cocktail Shaker Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        CocktailShakerSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 4:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Comb Sort");
						printf("\n\tBefore Comb Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        CombSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 5:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Dual Pivot Quick Sort");
						printf("\n\tBefore Dual Pivot Quick Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        DualPivotQuickSort(array,0,length-1);
						gettimeofday(&end,NULL);
                        break;
                    case 6:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Gnome Sort");
						printf("\n\tBefore Gnome Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Gnome_Sort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 7:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Odd-Even Sort");
						printf("\n\tBefore Odd-Even Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Odd_Even_Sort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 8:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Optimized Bubble Sort");
						printf("\n\tBefore Optimized Bubble Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        BubbleSortOptmized(array,length-1);
						gettimeofday(&end,NULL);
                        break;
					case 9:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Optimized Cocktail Shaker Sort");
						printf("\n\tBefore Optimized Cocktail Shaker Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        OPTCocktailShakerSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 10:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Optimized Gnome Sort");
						printf("\n\tBefore Optimized Gnome Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Optimized_Gnome_Sort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 11:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Quick Sort");
						printf("\n\tBefore Quick Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Quick_Sort(array,0,length-1);
						gettimeofday(&end,NULL);
                        break;
					case 12:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"3-way Quick Sort");
						printf("\n\tBefore 3-way Quick Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        QuickSort3way(array,0,length-1);
						gettimeofday(&end,NULL);
                        break;
                    case 13:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Stable Quick Sort");
						printf("\n\tBefore Stable Quick Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        StableQuickSort(array,0,length-1);
						gettimeofday(&end,NULL);
                        break;
                }
				sorted(array,length) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayarray)
                    print(array,length);
				if(exectime)
					calculatetime(start,end,&sec,&micro);
				if(txtfile && (displayarray || exectime))
					AfterExec(array,length,displayarray,exectime,sec,micro);
                break;
            case 3:
                do{
					hybrids:
                    printf("\n\tChoose the sort to be aplied on Hybrids:");
					printf("\n0 - Menu.");
                    printf("\n1 - Tim_Sort.");
                    printf("\n-> ");
                    while(scanf("%hd",&option_sort) != 1){
						printf("\n\tValue inserted is not a number. Try again.\n");
						getchar();
						goto hybrids;
					}
                    if(option_sort < 0 || option_sort > 1)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 1);
                switch(option_sort){
                    case 1:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Tim Sort");
						printf("\n\tBefore Tim Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        TimSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                }
				sorted(array,length) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayarray)
                    print(array,length);
				if(exectime)
					calculatetime(start,end,&sec,&micro);
				if(txtfile && (displayarray || exectime))
					AfterExec(array,length,displayarray,exectime,sec,micro);
                break;
            case 4:
                do{
					insertion:
                    printf("\n\tChoose the sort to be aplied on Insertion:");
					printf("\n0 - Menu.");
                    printf("\n1 - Binary_Insertion_Sort.");
                    printf("\n2 - Cycle_Sort.");
                    printf("\n3 - Insertion_Sort.");
					printf("\n4 - Patience_Sort.");
                    printf("\n5 - Shell_Sort.");
                    printf("\n6 - Tree_Sort.");
                    printf("\n-> ");
                    while(scanf("%hd",&option_sort) != 1){
						printf("\n\tValue inserted is not a number. Try again.\n");
						getchar();
						goto insertion;
					}
                    if(option_sort < 0 || option_sort > 6)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 6);
                switch(option_sort){
                    case 1:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Binary Insertion Sort");
						printf("\n\tBefore Binary Insertion Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Insertion_Sort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 2:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Cycle Sort");
						printf("\n\tBefore Cycle Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        CycleSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 3:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Insertion Sort");
						printf("\n\tBefore Insertion Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Insertion_Sort(array,length);
						gettimeofday(&end,NULL);
                        break;
					case 4:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Patience Sort");
						printf("\n\tBefore Patience Sort.");
                        if(displayarray)
							print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        PatienceSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 5:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Shell Sort");
						printf("\n\tBefore Shell Sort.");
                        if(displayarray)
							print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        ShellSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 6:
						if(txtfile)
							BeforeExec(array,length,displayarray,"Tree Sort");
                        printf("\n\tBefore Tree Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        TreeSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                }
				sorted(array,length) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayarray)
                    print(array,length);
				if(exectime)
					calculatetime(start,end,&sec,&micro);
				if(txtfile && (displayarray || exectime))
					AfterExec(array,length,displayarray,exectime,sec,micro);
                break;
            case 5:
                do{
					merge:
                    printf("\n\tChoose the sort to be aplied on Merge:");
					printf("\n0 - Menu.");
                    printf("\n1 - Bottomup_Merge_Sort.");
                    printf("\n2 - In-Place_Merge_Sort.");
                    printf("\n3 - Merge_Sort.");
                    printf("\n-> ");
                    while(scanf("%hd",&option_sort) != 1){
						printf("\n\tValue inserted is not a number. Try again.\n");
						getchar();
						goto merge;
					}
                    if(option_sort < 0 || option_sort > 3)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 3);
                switch(option_sort){
                    case 1:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Bottom-up Merge Sort");
						printf("\n\tBefore Bottom-up Merge Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Bottomup_Merge_Sort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 2:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"In Place Merge Sort");
						printf("\n\tBefore In Place Merge Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Merge_Sort_In_Place(array,0,length-1);
						gettimeofday(&end,NULL);
                        break;
                    case 3:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Merge Sort");
						printf("\n\tBefore Merge Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Merge_Sort(array,0,length-1);
						gettimeofday(&end,NULL);
                        break;
                }
				sorted(array,length) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayarray)
                    print(array,length);
				if(exectime)
					calculatetime(start,end,&sec,&micro);
				if(txtfile && (displayarray || exectime))
					AfterExec(array,length,displayarray,exectime,sec,micro);
                break;
            case 6:
                do{
					networksconcurrent:
                    printf("\n\tChoose the sort to be aplied on Networks & Concurrent:");
					printf("\n0 - Menu.");
                    printf("\n1 - Bitonic_Sort.");
					printf("\n2 - Pairwise_Network_Sort.");
                    printf("\n-> ");
                    while(scanf("%hd",&option_sort) != 1){
						printf("\n\tValue inserted is not a number. Try again.\n");
						getchar();
						goto networksconcurrent;
					}
                    if(option_sort < 0 || option_sort > 2)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 2);
                switch(option_sort){
					case 1:
						i = 1;
						while(i < length)
							i *= 2;
						if(i != length){
							create(&arrayPOF2,powerof2);
							generate(arrayPOF2,powerof2,choice,randominterval);
							if(txtfile)
								BeforeExec(arrayPOF2,powerof2,displayarray,"Bitonic Sort");
							printf("\n\tNote: Bitonic sort just accepts lengths of power of 2.\n\tCurrent size: %d.\n\tNew size applied on this algorithm: %d.\n", length,powerof2);
							printf("\n\tBefore Bitonic Sort.");
							if(displayarray)
								print(arrayPOF2,powerof2);
							printf("\n\tSorting...");
							gettimeofday(&start,NULL);
                        	BitonicSort(arrayPOF2,0,powerof2,1);
							gettimeofday(&end,NULL);
                        	sorted(arrayPOF2,powerof2) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
							if(displayarray)
                        		print(arrayPOF2,powerof2);
							if(exectime)
								calculatetime(start,end,&sec,&micro);
							if(txtfile && (displayarray || exectime))
								AfterExec(arrayPOF2,powerof2,displayarray,exectime,sec,micro);
							free(arrayPOF2);
						}
						else{
							if(txtfile)
								BeforeExec(array,length,displayarray,"Bitonic Sort");
                        	printf("\n\tBefore Bitonic Sort.");
							if(displayarray)
                        		print(array,length);
							printf("\n\tSorting...");
							gettimeofday(&start,NULL);
                        	BitonicSort(array,0,length,1);
							gettimeofday(&end,NULL);
                        	sorted(array,length) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
							if(displayarray)
                        		print(array,length);
							if(exectime)
								calculatetime(start,end,&sec,&micro);
							if(txtfile && (displayarray || exectime))
								AfterExec(array,length,displayarray,exectime,sec,micro);
						}
                        break;
                    case 2:
						if(txtfile)
							BeforeExec(array,length,displayarray,"Pairwise Network Sort");
                        printf("\n\tBefore Pairwise Network Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Pairwise_Sort(array,0,length,1);
						gettimeofday(&end,NULL);
						sorted(array,length) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
						if(displayarray)
                    		print(array,length);
						if(exectime)
							calculatetime(start,end,&sec,&micro);
						if(txtfile && (displayarray || exectime))
							AfterExec(array,length,displayarray,exectime,sec,micro);
                        break;
                }
                break;
            case 7:
                do{
					noncomparisondist:
                    printf("\n\tChoose the sort to be aplied on Non-Comparison & Distribution:");
					printf("\n0 - Menu.");
                    printf("\n1 - Bucket_Sort.");
                    printf("\n2 - Counting_Sort.");
                    printf("\n3 - Gravity_(Bead)_Sort.");
                    printf("\n4 - Pigeonhole_Sort.");
					printf("\n5 - Radix_LSD Sort.");
                    printf("\n-> ");
                    while(scanf("%hd",&option_sort) != 1){
						printf("\n\tValue inserted is not a number. Try again.\n");
						getchar();
						goto noncomparisondist;
					}
                    if(option_sort < 0 || option_sort > 5)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 5);
                switch(option_sort){
                    case 1:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Bucket Sort");
						printf("\n\tBefore Bucket Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        BucketSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 2:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Counting Sort");
						printf("\n\tBefore Counting Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSortihng...");
						gettimeofday(&start,NULL);
                        Counting_Sort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 3:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Gravity (Bead) Sort");
						printf("\n\tBefore Gravity (Bead) Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        BeadSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 4:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Pigeonhole Sort");
						printf("\n\tBefore Pigeonhole Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Pigeonhole_Sort(array,length);
						gettimeofday(&end,NULL);
                        break;
					case 5:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Radix LSD Sort");
						printf("\n\tBefore Radix LSD Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Radix_LSD(array,length,10);
						gettimeofday(&end,NULL);
                        break;
                }
				sorted(array,length) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayarray)
                    print(array,length);
				if(exectime)
					calculatetime(start,end,&sec,&micro);
				if(txtfile && (displayarray || exectime))
					AfterExec(array,length,displayarray,exectime,sec,micro);
                break;
            case 8:
                do{
					selection:
                    printf("\n\tChoose the sort to be aplied on Selection:");
					printf("\n0 - Menu.");
                    printf("\n1 - Double_Selection_Sort.");
                    printf("\n2 - Max_Heap_Sort.");
                    printf("\n3 - Min_Heap_Sort.");
                    printf("\n4 - Selection_Sort.");
                    printf("\n-> ");
                    while(scanf("%hd",&option_sort) != 1){
						printf("\n\tValue inserted is not a number. Try again.\n");
						getchar();
						goto selection;
					}
                    if(option_sort < 0 || option_sort > 4)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 4);
                switch(option_sort){
                    case 1:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Double Selection Sort");
						printf("\n\tBefore Double Selection Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Double_Selection_Sort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 2:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Max Heap Sort");
						printf("\n\tBefore Max Heap Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        MaxHeapSort(array,length);
						gettimeofday(&end,NULL);
                        break;
                    case 3:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Min Heap Sort");
						printf("\n\tBefore Min Heap Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        MinHeapSort(array,length);
						gettimeofday(&end,NULL);
						sortedD(array,length) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
                        break;
                    case 4:
                        if(txtfile)
							BeforeExec(array,length,displayarray,"Selection Sort");
						printf("\n\tBefore Selection Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						gettimeofday(&start,NULL);
                        Selection_Sort(array,length);
						gettimeofday(&end,NULL);
                        break;
                }
				if(option_sort != 3)
					sorted(array,length) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayarray)
                	print(array,length);
				if(exectime)
					calculatetime(start,end,&sec,&micro);
				if(txtfile && (displayarray || exectime))
					AfterExec(array,length,displayarray,exectime,sec,micro);
                break;
			case 9:
				while(true){
					do{
						config:
						printf("\n\tConfigurations:");
						printf("\n0 - Menu.");
						printf("\n1 - Change sorting case - %s", choice > 1 ? (choice == 3 ? "Ascending." : "Random.") : "Descending.");
						printf("\n2 - Change random interval - %d", randominterval);
						printf("\n3 - Change length of array - %d.", length);
						printf("\n4 - Save results in a text file - %s", txtfile ? "YES." : "NO.");
						printf("\n5 - Display arrays - %s", displayarray ? "YES." : "NO.");
						printf("\n6 - Display execution time - %s", exectime ? "YES." : "NO.");
						printf("\n-> ");
						while(scanf("%hd",&option_sort) != 1){
							printf("\n\tValue inserted is not a number. Try again.\n");
							getchar();
							goto config;
						}
						if(option_sort < 0 || option_sort > 5)
							printf("\n\tError: Choose the value in the range displayed.\n\n\t");
					}while(option_sort < 0 || option_sort > 5);
					if(option_sort == 0)
						break;
					switch(option_sort){
						case 1:
							do{
								sortingcase:
								printf("\n\tInsert the sorting case:");
								printf("\n1 - Ascending.");
								printf("\n2 - Random.");
								printf("\n3 - Descending.");
								printf("\n-> ");
								while(scanf("%hd",&choice) != 1){
									printf("\n\tValue inserted is not a number. Try again.\n");
									getchar();
									goto sortingcase;
								}
								if(choice < 1 || choice > 3)
									printf("\n\n\tError: Insert a value in the correct range!\n");
							}while(choice < 1 || choice > 3);
							break;
						case 2:
							randominter:
							printf("\n\tInsert the random interval limit: ");
							while(scanf("%d", &randominterval)){
								printf("\n\tValue inserted is not a number. Try again.\n");
								getchar();
								goto randominter;
							}
							if(randominterval < 3)
								randominterval = 3;
							else if(randominterval > INT_MAX)
								randominterval = INT_MAX;
							break;
						case 3:
							do{
								len:
								printf("\n\tInsert the new length of the array:\n-> ");
								while(scanf("%u", &length) != 1){
									printf("\n\tValue inserted is not a number. Try again.\n");
									getchar();
									goto len;
								}
							}while(length < 2 || length > limsize);
							i = 1;
							while(i < length)
								i *= 2;
							if(length == i)
								powerof2 = length;
							free(array);
							create(&array,length);
							break;
						case 4:
							txtfile = !txtfile;
							break;
						case 5:
							displayarray = !displayarray;
							break;
						case 6:
							exectime = !exectime;
							break;
					}
				}
				break;
        }
        printf("\n\n");
    }
	qr_code();
	printf("Thank you for using this program. Visit the QR code above to see more projects.\n");
	free(array);
    return 0;
}

void create(long int **array, int length){
	*array = (long int*)malloc(length * sizeof(long int));
	if(!(*array))
		printf("\n\tError: array couldn't be allocated.");
}

void print(long int *array, int length){
    printf("\n");
    for(long int *i = array; i < array+length; i++)
        printf("%ld ",*i);
}

void generate(long int *array, int length, short int choice, int randominterval){
	long int *i, j;
	switch(choice){
		case 1:
			for(i = array, j ^= j; i < array + length; i++, j++)
				*i = j;
			break;
		case 2:
			for(i = array; i < array + length; i++)
				*i = rand() % randominterval;
			break;
		case 3:
			for(i = array, j ^= j; i < array + length; i++, j++)
				*i = length - j;
			break;
	}
}

void calculatetime(struct timeval start, struct timeval end, unsigned long *sec, unsigned long *micro){
	*sec = end.tv_sec - start.tv_sec;
	*micro = end.tv_usec - start.tv_usec;
	printf("\n\tExecution time: %lu seconds %lu microsseconds.", *sec, *micro);
}

void BeforeExec(long int *array, int length, bool display, char *sort){
	FILE *txt = fopen("data.txt","a+");
	if(txt != NULL){
		fprintf(txt,"\n\t%s algorithm with length of %u elements.",sort, length);
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

void AfterExec(long int *array, int length, bool display, bool time, unsigned long sec, unsigned long micro){
	FILE *txt = fopen("data.txt","a+");
	if(txt != NULL){
		if(display){
			fprintf(txt,"\n\tArray sorted:\n");
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

bool sorted(long int *array, int length){
	for(long int *i = array; i < array + length - 1; i++)
		if(*i > *(i+1))
			return false;
	return true;
}

bool sortedD(long int *array, int length){
	for(long int *i = array; i < array + length - 1; i++)
		if(*i < *(i+1))
			return false;
	return true;
}