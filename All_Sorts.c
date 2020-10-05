#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Esoteric&Fun&Miscellaneous/Esoteric_Fun_Miscellaneous.h"
#include "Exchange/Exchange.h"
#include "Hybrids/Hybrids.h"
#include "Insertion/Insertion.h"
#include "Merge/Merge.h"
#include "Networks&Concurrent/Networks_Concurrent.h"
#include "Non-Comparison&Distribution/Non-Comparison_Distribution.h"
#include "Selection/Selection.h"
#define lim 4294967296 //Limit of unsigned int
#define powerof2 16

void print(int array[], unsigned int length){
    printf("\n");
    for(int i = 0; i < length; i++)
        printf("%d ",array[i]);
}

void generate(int array[], unsigned int length, int choice){
	switch(choice){
		case 1:
			for(int i = 0; i < length; i++)
				array[i] = i;
			break;
		case 2:
			for(int i = 0; i < length; i++)
				array[i] = rand() % 1000;
			break;
		case 3:
			for(int i = 0; i < length; i++)
				array[i] = length - i;
			break;
	}
}

int main(){
    srand(time(NULL));
    int option_sort, option_category, array[length], arrayPOF2[powerof2],i,choice = 2;
	bool txtfile = false;
	unsigned int length;

	generate(array,length,choice);

    while(true){
        do{
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
            scanf("%d",&option_category);
            if(option_category < 0 || option_category > 8)
                printf("\n\tError: Choose the value in the range displayed.\n");
        }while(option_category < 0 || option_category > 8);
        if(option_category == 0)
            break;
        switch(option_category){
            case 1:
                do{
                    printf("\n\tChoose the sort to be aplied on Esoteric & Fun & Miscellaneous:");
					printf("\n 0 - Menu.");
                    printf("\n 1 - Bad_Sort.");
                    printf("\n 2 - Bogo_Bogo_Sort.");
                    printf("\n 3 - Bogo_Sort.");
					printf("\n 4 - Bubble_Bogo_Sort.");
					printf("\n 5 - Exchange_Bogo_Sort.");
					printf("\n 6 - Less_Bogo_Sort.");
                    printf("\n 7 - Pancake_Sort.");
                    printf("\n 8 - Silly_Sort.");
                    printf("\n 9 - Slow_Sort.");
                    printf("\n10 - Spaghetti_Sort.");
                    printf("\n11 - Stooge_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 0 || option_sort > 11)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 11);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore Bad Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        BadSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 2:
                        printf("\n\tBefore Bogo Bogo Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        BogoBogoSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 3:
                        printf("\n\tBefore Bogo Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        bogo_sort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
					case 4:
                        printf("\n\tBefore Bubble Bogo Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        BubbleBogoSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
					case 5:
                        printf("\n\tBefore Exchange Bogo Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        ExchangeBogoSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
					case 6:
                        printf("\n\tBefore Less Bogo Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        LessBogoSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 7:
                        printf("\n\tBefore Pancake Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        PancakeSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 8:
                        printf("\n\tBefore Silly Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        SillySort(array,0,length-1);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 9:
                        printf("\n\tBefore Slow Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        SlowSort(array,0,length-1);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 10:
                        printf("\n\tBefore Spaghetti Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        SpaghettiSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 11:
                        printf("\n\tBefore Stooge Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        StoogeSort(array,0,length-1);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                }
                break;
            case 2:
                do{
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
                    printf("\n 9 - Optimized_Gnome_Sort.");
                    printf("\n10 - Quick_Sort.");
					printf("\n11 - Quick_Sort_3-way.");
                    printf("\n12 - Stable_Quick_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 0 || option_sort > 12)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 12);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore Bubble Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        Bubble_sort(array,length-1);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 2:
                        printf("\n\tBefore Circle Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        CircleSort(array, length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 3:
                        printf("\n\tBefore Cocktail Shaker Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        CocktailShakerSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 4:
                        printf("\n\tBefore Comb Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        CombSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 5:
                        printf("\n\tBefore Dual Pivot Quick Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        DualPivotQuickSort(array,0,length-1);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 6:
                        printf("\n\tBefore Gnome Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        Gnome_Sort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 7:
                        printf("\n\tBefore Odd-Even Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        Odd_Even_Sort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 8:
                        printf("\n\tBefore Optimized Bubble Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        BubbleSortOptmized(array,length-1);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 9:
                        printf("\n\tBefore Optimized Gnome Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        for(i = 1; i < length; i++)
                            Optimized_Gnome_Sort(array,i);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 10:
                        printf("\n\tBefore Quick Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        Quick_Sort(array,0,length-1);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
					case 11:
                        printf("\n\tBefore 3-way Quick Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        QuickSort3way(array,0,length-1);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 12:
                        printf("\n\tBefore Stable Quick Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        StableQuickSort(array,0,length-1);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                }
                break;
            case 3:
                do{
                    printf("\n\tChoose the sort to be aplied on Hybrids:");
					printf("\n0 - Menu.");
                    printf("\n1 - Tim_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 0 || option_sort > 1);
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 1);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore Tim Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        TimSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                }
                break;
            case 4:
                do{
                    printf("\n\tChoose the sort to be aplied on Insertion:");
					printf("\n0 - Menu.");
                    printf("\n1 - Binary_Insertion_Sort.");
                    printf("\n2 - Cycle_Sort.");
                    printf("\n3 - Insertion_Sort.");
                    printf("\n4 - Shell_Sort.");
                    printf("\n5 - Tree_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 0 || option_sort > 5)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 5);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore Binary Insertion Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        Insertion_Sort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 2:
                        printf("\n\tBefore Cycle Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        CycleSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 3:
                        printf("\n\tBefore Insertion Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        InsertionSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 4:
                        printf("\n\tBefore Shell Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        ShellSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 5:
                        printf("\n\tBefore Tree Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        TreeSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                }
                break;
            case 5:
                do{
                    printf("\n\tChoose the sort to be aplied on Merge:");
					printf("\n0 - Menu.");
                    printf("\n1 - Bottomup_Merge_Sort.");
                    printf("\n2 - In-Place_Merge_Sort.");
                    printf("\n3 - Merge_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 0 || option_sort > 3)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 3);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore Bottom-up Merge Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        Bottomup_Merge_Sort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 2:
                        printf("\n\tBefore In Place Merge Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        MergeSort(array,0,length-1);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 3:
                        printf("\n\tBefore Merge Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        Merge_Sort(array,0,length-1);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                }
                break;
            case 6:
                do{
                    printf("\n\tChoose the sort to be aplied on Networks & Concurrent:");
					printf("\n0 - Menu.");
                    printf("\n1 - Bitonic_Sort.");
					printf("\n2 - Pairwise_Network_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 0 || option_sort > 2)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 2);
                switch(option_sort){
					case 1:
						i = 1;
						while(i > length)
							i *= 2;
						if(i != length){
							for(i = 0; i < powerof2; i++)
            					arrayPOF2[i] = rand() % 1000 + 1;
							printf("\n\tNote: Bitonic sort just accepts power sizes of 2.\n\tCurrent size: %d.\n\tNew size: %d.\n", length,powerof2);
							printf("\n\tBefore Bitonic Sort: ");
							print(arrayPOF2,powerof2);
							printf("\n\tSorting...");
                        	BitonicSort(arrayPOF2,0,powerof2,1);
                        	printf("\n\tArray sorted:");
                        	print(arrayPOF2,powerof2);
						}
						else{
                        	printf("\n\tBefore Bitonic Sort:");
                        	print(array,length);
							printf("\n\tSorting...");
                        	BitonicSort(array,0,length,1);
                        	printf("\n\tArray sorted:");
                        	print(array,length);
						}
                        break;
                    case 2:
                        printf("\n\tBefore Pairwise Network Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        Pairwise_Sort(array,0,length,1);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                }
                break;
            case 7:
                do{
                    printf("\n\tChoose the sort to be aplied on Non-Comparison & Distribution:");
					printf("\n0 - Menu.");
                    printf("\n1 - Bucket_Sort.");
                    printf("\n2 - Counting_Sort.");
                    printf("\n3 - Gravity_(Bead)_Sort.");
                    printf("\n4 - Pigeonhole_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 0 || option_sort > 4)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 4);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore Bucket Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        BucketSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 2:
                        printf("\n\tBefore Counting Sort:");
                        print(array,lengt);
                        printf("\n\tSortihng...");
                        Counting_Sort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 3:
                        printf("\n\tBefore Gravity (Bead) Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        BeadSort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 4:
                        printf("\n\tBefore Pigeonhole Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        Pigeonhole_Sort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                }
                break;
            case 8:
                do{
                    printf("\n\tChoose the sort to be aplied on Selection:");
					printf("\n0 - Menu.");
                    printf("\n1 - Double_Selection_Sort.");
                    printf("\n2 - Max_Heap_Sort.");
                    printf("\n3 - Min_Heap_Sort.");
                    printf("\n4 - Selection_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 0 || option_sort > 4)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 0 || option_sort > 4);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore Double Selection Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        Double_Selection_Sort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 2:
                        printf("\n\tBefore Max Heap Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        Max_Heap_Sort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 3:
                        printf("\n\tBefore Min Heap Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        Min_Heap_Sort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                    case 4:
                        printf("\n\tBefore Selection Sort:");
                        print(array,length);
                        printf("\n\tSorting...");
                        Selection_Sort(array,length);
                        printf("\n\tArray sorted:");
                        print(array,length);
                        break;
                }
                break;
			case 9:
				while(true){
					do{
						printf("\n\tConfigurations:");
						printf("\n0 - Menu.");
						printf("\n1 - Change sorting case.");
						printf("\n2 - Change length of array.");
						printf("\n3 - Save results in a text file - %s", txtfile ? "YES." : "NO.");
						printf("\n4 - Selection_Sort.");
						printf("\n-> ");
						scanf("%d",&option_sort);
						if(option_sort < 0 || option_sort > 4)
							printf("\n\tError: Choose the value in the range displayed.\n\n\t");
					}while(option_sort < 0 || option_sort > 4);
					if(option_sort == 0)
						break;
					switch(option_sort){
						case 1:
							do{
								printf("\n\tInsert the case for sorting:");
								printf("\n1 - Best case.");
								printf("\n2 - Average case.");
								printf("\n3 - Worst case.");
								printf("\n-> ");
								scanf("%d",&choice);
								if(choice < 1 || choice > 3)
									printf("\n\n\tError: Insert a value in the correct range!\n");
							}while(choice < 1 || choice > 3);
						break;
						case 2:
							do{
								printf("\n\tInsert the new length of the array:\n-> ");
								scanf("%u", &length);
							}while(length < 0 || length > lim);
							break;
						case 3:
							!txtfile;
							break;
						case 4:
							break;
					}
				}
				break;
        }
        printf("\n\n");
    }
    return 0;
}