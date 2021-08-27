// Default libraries
#include <limits.h>
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
void afterExec(long int *array, int length, bool display, bool time, unsigned long sec, unsigned long micro);

// Get time before executing the sorting algorithm
void beforeExec(long int *array, int length, bool display, char *sort);

// Calculate execution time
void calculatetime(clock_t tic, clock_t toc, unsigned long *sec, unsigned long *micro);

// Clear screen
void clear_screen();

// Create the array
void create(long int **array, int length);

// Generate numbers for the array
void generate(long int *array, int length, short int choice, int randominterval);

// Print the array
void print(long int *array, int length);

// Print and collect the option from user
short menu(char *text, int len);

/* Check if the array is sorted
*  array, length of array, increasing (true) or decreasing (false)
*/
bool sorted(long int *array, int length, bool increasing);

int main(){
    srand(time(NULL));
	clock_t tic, toc;
	long int *array, *arrayPOF2;
    int length = 10, i, powerof2 = 16, randominterval = 1024;
	short int option_sort, option_category, choice = 2;
	unsigned long sec, micro;
	bool txtfile = false, displayarray = true, exectime = true, input;

	create(&array,length);

	clear_screen();

    while(true){
		generate(array,length,choice,randominterval);
        option_category = menu("\n\tWhich category of sort would you like to see?\n0 - Exit.\n1 - Esoteric & Fun & Miscellaneous.\n2 - Exchange.\n3 - Hybrids.\n4 - Insertion.\n5 - Merge.\n6 - Networks & Concurrent.\n7 - Non-Comparison & Distribution.\n8 - Selection.\n9 - Configurations.\n-> ",9);
		clear_screen();
        if(option_category == 0)
            break;
        switch(option_category){
            case 1:
				option_sort = menu("\n\tChoose the sort to be aplied on Esoteric & Fun & Miscellaneous:\n 0 - Menu.\n 1 - Bad_Sort.\n 2 - Bogo_Bogo_Sort.\n 3 - Bogo_Sort.\n 4 - Bubble_Bogo_Sort.\n 5 - Cocktail_Bogo_Sort.\n 6 - Exchange_Bogo_Sort.\n 7 - Less_Bogo_Sort.\n 8 - Pancake_Sort.\n 9 - Silly_Sort.\n10 - Slow_Sort.\n11 - Spaghetti_Sort.\n12 - Stooge_Sort.\n-> ",12);
				clear_screen();
				if(!option_sort)
					break;
                switch(option_sort){
                    case 1:
						if(txtfile)
							beforeExec(array,length,displayarray,"Bad Sort");
                        printf("\n\tBefore Bad Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        BadSort(array,length);
						toc = clock();
                        break;
                    case 2:
						if(txtfile)
							beforeExec(array,length,displayarray,"Bogo Bogo Sort");
                        printf("\n\tBefore Bogo Bogo Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        BogoBogoSort(array,length);
						toc = clock();
                        break;
                    case 3:
						if(txtfile)
							beforeExec(array,length,displayarray,"Bogo Sort");
                        printf("\n\tBefore Bogo Sort.");
                        if(displayarray)
							print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        bogo_sort(array,length);
						toc = clock();
                        break;
					case 4:
						if(txtfile)
							beforeExec(array,length,displayarray,"Bubble Bogo Sort");
                        printf("\n\tBefore Bubble Bogo Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        BubbleBogoSort(array,length);
						toc = clock();
                        break;
					case 5:
						if(txtfile)
							beforeExec(array,length,displayarray,"Cocktail Bogo Sort");
                        printf("\n\tBefore Cocktail Bogo Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        CocktailBogoSort(array,length);
						toc = clock();
                        break;
					case 6:
						if(txtfile)
							beforeExec(array,length,displayarray,"Exchange Bogo Sort");
                        printf("\n\tBefore Exchange Bogo Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        ExchangeBogoSort(array,length);
						toc = clock();
                        break;
					case 7:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Less Bogo Sort");
						printf("\n\tBefore Less Bogo Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        LessBogoSort(array,length);
						toc = clock();
                        break;
                    case 8:
						if(txtfile)
							beforeExec(array,length,displayarray,"Pancake Sort");
                        printf("\n\tBefore Pancake Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        PancakeSort(array,length);
						toc = clock();
                        break;
                    case 9:
						if(txtfile)
							beforeExec(array,length,displayarray,"Silly Sort");
                        printf("\n\tBefore Silly Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        SillySort(array,0,length-1);
						toc = clock();
                        break;
                    case 10:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Slow Sort");
						printf("\n\tBefore Slow Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Slow_Sort(array,0,length-1);
						toc = clock();
                        break;
                    case 11:
						if(txtfile)
							beforeExec(array,length,displayarray,"Spaghetti Sort");
                        printf("\n\tBefore Spaghetti Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        SpaghettiSort(array,length);
						toc = clock();
                        break;
                    case 12:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Stooge Sort");
						printf("\n\tBefore Stooge Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        StoogeSort(array,0,length-1);
						toc = clock();
                        break;
                }
				sorted(array,length,true) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayarray)
                    print(array,length);
				if(exectime)
					calculatetime(tic,toc,&sec,&micro);
				if(txtfile && (displayarray || exectime))
					afterExec(array,length,displayarray,exectime,sec,micro);
                break;
            case 2:
                option_sort = menu("\n\tChoose the sort to be aplied on Exchange:\n 0 - Menu.\n 1 - Bubble_Sort.\n 2 - Circle_Sort.\n 3 - Cocktail_Shaker_Sort.\n 4 - Comb_Sort.\n 5 - Dual_Pivot_Quick_Sort.\n 6 - Gnome_Sort.\n 7 - Odd-Even_Sort.\n 8 - Optimized_Bubble_Sort.\n 9 - Optimized_Cocktail_Shaker_Sort.\n10 - Optimized_Gnome_Sort.\n11 - Quick_Sort.\n12 - Quick_Sort_3-way.\n13 - Stable_Quick_Sort.\n-> ",13);
				clear_screen();
				if(!option_sort)
					break;
                switch(option_sort){
                    case 1:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Bubble Sort");
						printf("\n\tBefore Bubble Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Bubble_sort(array,length-1);
						toc = clock();
                        break;
                    case 2:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Circle Sort");
						printf("\n\tBefore Circle Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        CircleSort(array, length);
						toc = clock();
                        break;
                    case 3:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Cocktail Shaker Sort");
						printf("\n\tBefore Cocktail Shaker Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        CocktailShakerSort(array,length);
						toc = clock();
                        break;
                    case 4:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Comb Sort");
						printf("\n\tBefore Comb Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        CombSort(array,length);
						toc = clock();
                        break;
                    case 5:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Dual Pivot Quick Sort");
						printf("\n\tBefore Dual Pivot Quick Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        DualPivotQuickSort(array,0,length-1);
						toc = clock();
                        break;
                    case 6:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Gnome Sort");
						printf("\n\tBefore Gnome Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Gnome_Sort(array,length);
						toc = clock();
                        break;
                    case 7:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Odd-Even Sort");
						printf("\n\tBefore Odd-Even Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Odd_Even_Sort(array,length);
						toc = clock();
                        break;
                    case 8:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Optimized Bubble Sort");
						printf("\n\tBefore Optimized Bubble Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        BubbleSortOptmized(array,length-1);
						toc = clock();
                        break;
					case 9:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Optimized Cocktail Shaker Sort");
						printf("\n\tBefore Optimized Cocktail Shaker Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        OPTCocktailShakerSort(array,length);
						toc = clock();
                        break;
                    case 10:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Optimized Gnome Sort");
						printf("\n\tBefore Optimized Gnome Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Optimized_Gnome_Sort(array,length);
						toc = clock();
                        break;
                    case 11:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Quick Sort");
						printf("\n\tBefore Quick Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Quick_Sort(array,0,length-1);
						toc = clock();
                        break;
					case 12:
                        if(txtfile)
							beforeExec(array,length,displayarray,"3-way Quick Sort");
						printf("\n\tBefore 3-way Quick Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        QuickSort3way(array,0,length-1);
						toc = clock();
                        break;
                    case 13:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Stable Quick Sort");
						printf("\n\tBefore Stable Quick Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        StableQuickSort(array,0,length-1);
						toc = clock();
                        break;
                }
				sorted(array,length,true) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayarray)
                    print(array,length);
				if(exectime)
					calculatetime(tic,toc,&sec,&micro);
				if(txtfile && (displayarray || exectime))
					afterExec(array,length,displayarray,exectime,sec,micro);
                break;
            case 3:
                option_sort = menu("\n\tChoose the sort to be aplied on Hybrids:\n0 - Menu.\n1 - Tim_Sort.\n-> ",1);
				clear_screen();
				if(!option_sort)
					break;
                switch(option_sort){
                    case 1:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Tim Sort");
						printf("\n\tBefore Tim Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        TimSort(array,length);
						toc = clock();
                        break;
                }
				sorted(array,length,true) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayarray)
                    print(array,length);
				if(exectime)
					calculatetime(tic,toc,&sec,&micro);
				if(txtfile && (displayarray || exectime))
					afterExec(array,length,displayarray,exectime,sec,micro);
                break;
            case 4:
                option_sort = menu("\n\tChoose the sort to be aplied on Insertion:\n0 - Menu.\n1 - Binary_Insertion_Sort.\n2 - Cycle_Sort.\n3 - Insertion_Sort.\n4 - Patience_Sort.\n5 - Shell_Sort.\n6 - Tree_Sort.\n-> ",6);
				clear_screen();
				if(!option_sort)
					break;
                switch(option_sort){
                    case 1:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Binary Insertion Sort");
						printf("\n\tBefore Binary Insertion Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Insertion_Sort(array,length);
						toc = clock();
                        break;
                    case 2:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Cycle Sort");
						printf("\n\tBefore Cycle Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        CycleSort(array,length);
						toc = clock();
                        break;
                    case 3:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Insertion Sort");
						printf("\n\tBefore Insertion Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Insertion_Sort(array,length);
						toc = clock();
                        break;
					case 4:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Patience Sort");
						printf("\n\tBefore Patience Sort.");
                        if(displayarray)
							print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        PatienceSort(array,length);
						toc = clock();
                        break;
                    case 5:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Shell Sort");
						printf("\n\tBefore Shell Sort.");
                        if(displayarray)
							print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        ShellSort(array,length);
						toc = clock();
                        break;
                    case 6:
						if(txtfile)
							beforeExec(array,length,displayarray,"Tree Sort");
                        printf("\n\tBefore Tree Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        TreeSort(array,length);
						toc = clock();
                        break;
                }
				sorted(array,length,true) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayarray)
                    print(array,length);
				if(exectime)
					calculatetime(tic,toc,&sec,&micro);
				if(txtfile && (displayarray || exectime))
					afterExec(array,length,displayarray,exectime,sec,micro);
                break;
            case 5:
                option_sort = menu("\n\tChoose the sort to be aplied on Merge:\n0 - Menu.\n1 - Bottomup_Merge_Sort.\n2 - In-Place_Merge_Sort.\n3 - Merge_Sort.\n-> ",3);
				clear_screen();
				if(!option_sort)
					break;
                switch(option_sort){
                    case 1:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Bottom-up Merge Sort");
						printf("\n\tBefore Bottom-up Merge Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Bottomup_Merge_Sort(array,length);
						toc = clock();
                        break;
                    case 2:
                        if(txtfile)
							beforeExec(array,length,displayarray,"In Place Merge Sort");
						printf("\n\tBefore In Place Merge Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Merge_Sort_In_Place(array,0,length-1);
						toc = clock();
                        break;
                    case 3:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Merge Sort");
						printf("\n\tBefore Merge Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Merge_Sort(array,0,length-1);
						toc = clock();
                        break;
                }
				sorted(array,length,true) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayarray)
                    print(array,length);
				if(exectime)
					calculatetime(tic,toc,&sec,&micro);
				if(txtfile && (displayarray || exectime))
					afterExec(array,length,displayarray,exectime,sec,micro);
                break;
            case 6:
                option_sort = menu("\n\tChoose the sort to be aplied on Networks & Concurrent:\n0 - Menu.\n1 - Bitonic_Sort.\n2 - Pairwise_Network_Sort.\n-> ",2);
				clear_screen();
				if(!option_sort)
					break;
                switch(option_sort){
					case 1:
						i = 1;
						while(i < length)
							i <<= 1;
						if(i != length){
							create(&arrayPOF2,powerof2);
							generate(arrayPOF2,powerof2,choice,randominterval);
							if(txtfile)
								beforeExec(arrayPOF2,powerof2,displayarray,"Bitonic Sort");
							printf("\n\tNote: Bitonic sort just accepts lengths of power of 2.\n\tCurrent size: %d.\n\tNew size applied on this algorithm: %d.\n", length,powerof2);
							printf("\n\tBefore Bitonic Sort.");
							if(displayarray)
								print(arrayPOF2,powerof2);
							printf("\n\tSorting...");
							tic = clock();
                        	BitonicSort(arrayPOF2,0,powerof2,1);
							toc = clock();
                        	sorted(arrayPOF2,powerof2,true) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
							if(displayarray)
                        		print(arrayPOF2,powerof2);
							if(exectime)
								calculatetime(tic,toc,&sec,&micro);
							if(txtfile && (displayarray || exectime))
								afterExec(arrayPOF2,powerof2,displayarray,exectime,sec,micro);
							free(arrayPOF2);
						}
						else{
							if(txtfile)
								beforeExec(array,length,displayarray,"Bitonic Sort");
                        	printf("\n\tBefore Bitonic Sort.");
							if(displayarray)
                        		print(array,length);
							printf("\n\tSorting...");
							tic = clock();
                        	BitonicSort(array,0,length,1);
							toc = clock();
                        	sorted(array,length,true) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
							if(displayarray)
                        		print(array,length);
							if(exectime)
								calculatetime(tic,toc,&sec,&micro);
							if(txtfile && (displayarray || exectime))
								afterExec(array,length,displayarray,exectime,sec,micro);
						}
                        break;
                    case 2:
						if(txtfile)
							beforeExec(array,length,displayarray,"Pairwise Network Sort");
                        printf("\n\tBefore Pairwise Network Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Pairwise_Sort(array,0,length,1);
						toc = clock();
						sorted(array,length,true) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
						if(displayarray)
                    		print(array,length);
						if(exectime)
							calculatetime(tic,toc,&sec,&micro);
						if(txtfile && (displayarray || exectime))
							afterExec(array,length,displayarray,exectime,sec,micro);
                        break;
                }
                break;
            case 7:
                option_sort = menu("\n\tChoose the sort to be aplied on Non-Comparison & Distribution:\n0 - Menu.\n1 - Bucket_Sort.\n2 - Counting_Sort.\n3 - Gravity_(Bead)_Sort.\n4 - Pigeonhole_Sort.\n5 - Radix_LSD Sort.\n-> ",5);
				clear_screen();
				if(!option_sort)
					break;
                switch(option_sort){
                    case 1:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Bucket Sort");
						printf("\n\tBefore Bucket Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        BucketSort(array,length);
						toc = clock();
                        break;
                    case 2:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Counting Sort");
						printf("\n\tBefore Counting Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSortihng...");
						tic = clock();
                        Counting_Sort(array,length);
						toc = clock();
                        break;
                    case 3:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Gravity (Bead) Sort");
						printf("\n\tBefore Gravity (Bead) Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        BeadSort(array,length);
						toc = clock();
                        break;
                    case 4:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Pigeonhole Sort");
						printf("\n\tBefore Pigeonhole Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Pigeonhole_Sort(array,length);
						toc = clock();
                        break;
					case 5:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Radix LSD Sort");
						printf("\n\tBefore Radix LSD Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Radix_LSD(array,length,10);
						toc = clock();
                        break;
                }
				sorted(array,length,true) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayarray)
                    print(array,length);
				if(exectime)
					calculatetime(tic,toc,&sec,&micro);
				if(txtfile && (displayarray || exectime))
					afterExec(array,length,displayarray,exectime,sec,micro);
                break;
            case 8:
                option_sort = menu("\n\tChoose the sort to be aplied on Selection:\n0 - Menu.\n1 - Double_Selection_Sort.\n2 - Max_Heap_Sort.\n3 - Min_Heap_Sort.\n4 - Selection_Sort.\n-> ",4);
				clear_screen();
				if(!option_sort)
					break;
                switch(option_sort){
                    case 1:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Double Selection Sort");
						printf("\n\tBefore Double Selection Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Double_Selection_Sort(array,length);
						toc = clock();
                        break;
                    case 2:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Max Heap Sort");
						printf("\n\tBefore Max Heap Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        MaxHeapSort(array,length);
						toc = clock();
                        break;
                    case 3:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Min Heap Sort");
						printf("\n\tBefore Min Heap Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        MinHeapSort(array,length);
						toc = clock();
						sorted(array,length,false) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
                        break;
                    case 4:
                        if(txtfile)
							beforeExec(array,length,displayarray,"Selection Sort");
						printf("\n\tBefore Selection Sort.");
						if(displayarray)
                        	print(array,length);
                        printf("\n\tSorting...");
						tic = clock();
                        Selection_Sort(array,length);
						toc = clock();
                        break;
                }
				if(option_sort != 3)
					sorted(array,length,true) ? printf("\n\tArray sorted.") : printf("\n\tArray not sorted.");
				if(displayarray)
                	print(array,length);
				if(exectime)
					calculatetime(tic,toc,&sec,&micro);
				if(txtfile && (displayarray || exectime))
					afterExec(array,length,displayarray,exectime,sec,micro);
                break;
			case 9:
				while(true){
					while(true){
						printf("\n\tConfigurations:\n0 - Menu.\n1 - Change sorting case - %s\n2 - Change random interval - %d\n3 - Change length of array - %d.\n4 - Save results in a text file - %s\n5 - Display arrays - %s\n6 - Display execution time - %s\n-> ",choice > 1 ? (choice == 3 ? "Ascending." : "Random.") : "Descending.",randominterval,length,txtfile ? "YES." : "NO.",displayarray ? "YES." : "NO.",exectime ? "YES." : "NO.");
						if(scanf("%hd",&option_sort) != 1){
							clear_screen();
							printf("\n\tValue inserted is not a number. Try again.\n"),getchar();
						}
						else if(option_sort < 0 || option_sort > 6){
							clear_screen();
							printf("\n\tError: Choose the value in the range displayed.\n\n\t");
						}
						else
							break;
					}
					clear_screen();
					if(option_sort == 0)
						break;
					switch(option_sort){
						case 1:
							choice = menu("\n\tInsert the sorting case:\n1 - Ascending.\n2 - Random.\n3 - Descending.\n-> ",3);
							break;
						case 2:
							while(true){
								printf("\n\tInsert the random interval limit: ");
								if(scanf("%d", &randominterval) != 1){
									clear_screen();
									printf("\n\tValue inserted is not a number. Try again.\n"),	getchar();
								}
								else
									break;
							}
							if(randominterval < 3)
								randominterval = 3;
							else if(randominterval > INT_MAX)
								randominterval = INT_MAX;
							break;
						case 3:
							while(true){
								printf("\n\tInsert the new length of the array:\n-> ");
								if(scanf("%u", &length) != 1){
									clear_screen();
									printf("\n\tValue inserted is not a number. Try again.\n"), getchar();
								}
								else if(length < 2 || length > limsize){
									clear_screen();
									printf("\n\tValue inserted is out of range. Try again.\n");
								}
								else
									break;
							}
							i = 1;
							while(i < length)
								i <<= 1;
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
	QR_code();
	free(array);
    return 0;
}

void afterExec(long int *array, int length, bool display, bool time, unsigned long sec, unsigned long micro){
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

void beforeExec(long int *array, int length, bool display, char *sort){
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

void calculatetime(clock_t tic, clock_t toc, unsigned long *sec, unsigned long *micro){
	*sec = (unsigned long)(toc - tic) / CLOCKS_PER_SEC;
	*micro = (unsigned long)(toc - tic) % 1000000;
	printf("\n\tExecution time: %lu seconds %lu microsseconds.", *sec, *micro);
}

void clear_screen(){
	if(clear == -1)
		printf("\nCouldn't clear the screen\n");
}

void create(long int **array, int length){
	*array = (long int*)malloc(length * sizeof(long int));
	if(!(*array)){
		printf("\n\tError: array couldn't be allocated.");
		exit(1);
	}
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

void print(long int *array, int length){
    printf("\n");
    for(long int *i = array; i < array+length; i++)
        printf("%ld ",*i);
}

short menu(char *text, int len){
	short op;
	while(true){
		printf("%s", text);
		if(scanf("%hd", &op) != 1){
			clear_screen();
			printf("\n\tValue inserted is not a number. Try again.\n"),getchar();
		}
		else if(op < 0 || op > len){
			clear_screen();
			printf("\n\tError: Choose the value in the range displayed.\n\n\t");
		}
		else
			break;
	}
	return op;
}


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
