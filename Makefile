CC = gcc
CFLAGS = -lm -c -Ofast -lm

all: sort

#---------------------------------------------------------------------------------------------------------------
sort: bin Bad_Sort.o Bogo_Bogo_Sort.o Bogo_Sort.o Bubble_Bogo_Sort.o Cocktail_Bogo_Sort.o Exchange_Bogo_Sort.o Less_Bogo_Sort.o Pancake_Sort.o Silly_Sort.o Slow_Sort.o Spaghetti_Sort.o Stooge_Sort.o Bubble_Sort.o Circle_Sort.o Cocktail_Shaker_Sort.o Comb_Sort.o Dual_Pivot_Quick_Sort.o Gnome_Sort.o Odd-Even_Sort.o Optimized_Bubble_Sort.o Optimized_Cocktail_Shaker_Sort.o Optimized_Gnome_Sort.o Quick_Sort_3-way.o Quick_Sort.o Stable_Quick_Sort.o Tim_Sort.o Binary_Insertion_Sort.o Cycle_Sort.o Insertion_Sort.o Patience_Sort.o Shell_Sort.o Tree_Sort.o Bottom-up_Merge_Sort.o In-Place_Merge_Sort.o Merge_Sort.o Bitonic_Sort.o Pairwise_Network_Sort.o Bucket_Sort.o Counting_Sort.o Gravity_Bead_Sort.o Pigeonhole_Sort.o Radix_LSD.o Double_Selection_Sort.o Max_Heap_Sort.o Min_Heap_Sort.o Selection_Sort.o QRcode.o All_Sorts.o
	${CC} -o sort bin/Bad_Sort.o bin/Bogo_Bogo_Sort.o bin/Bogo_Sort.o bin/Bubble_Bogo_Sort.o bin/Cocktail_Bogo_Sort.o bin/Exchange_Bogo_Sort.o bin/Less_Bogo_Sort.o bin/Pancake_Sort.o bin/Silly_Sort.o bin/Slow_Sort.o bin/Spaghetti_Sort.o bin/Stooge_Sort.o bin/Bubble_Sort.o bin/Circle_Sort.o bin/Cocktail_Shaker_Sort.o bin/Comb_Sort.o bin/Dual_Pivot_Quick_Sort.o bin/Gnome_Sort.o bin/Odd-Even_Sort.o bin/Optimized_Bubble_Sort.o bin/Optimized_Cocktail_Shaker_Sort.o bin/Optimized_Gnome_Sort.o bin/Quick_Sort_3-way.o bin/Quick_Sort.o bin/Stable_Quick_Sort.o bin/Tim_Sort.o bin/Binary_Insertion_Sort.o bin/Cycle_Sort.o bin/Insertion_Sort.o bin/Patience_Sort.o bin/Shell_Sort.o bin/Tree_Sort.o bin/Bottom-up_Merge_Sort.o bin/In-Place_Merge_Sort.o bin/Merge_Sort.o bin/Bitonic_Sort.o bin/Pairwise_Network_Sort.o bin/Bucket_Sort.o bin/Counting_Sort.o bin/Gravity_Bead_Sort.o bin/Pigeonhole_Sort.o bin/Radix_LSD.o bin/Double_Selection_Sort.o bin/Max_Heap_Sort.o bin/Min_Heap_Sort.o bin/Selection_Sort.o bin/QRcode.o bin/All_Sorts.o

#---------------------------------------------------------------------------------------------------------------
# Create the folder for binaries
bin:
	mkdir -p bin

#---------------------------------------------------------------------------------------------------------------
# src/Esoteric_Fun_Miscellaneous/
Bad_Sort.o : src/Esoteric_Fun_Miscellaneous/Bad_Sort.c
	${CC} ${CFLAGS} src/Esoteric_Fun_Miscellaneous/Bad_Sort.c -o bin/Bad_Sort.o

Bogo_Bogo_Sort.o : src/Esoteric_Fun_Miscellaneous/Bogo_Bogo_Sort.c
	${CC} ${CFLAGS} src/Esoteric_Fun_Miscellaneous/Bogo_Bogo_Sort.c -o bin/Bogo_Bogo_Sort.o

Bogo_Sort.o : src/Esoteric_Fun_Miscellaneous/Bogo_Sort.c
	${CC} ${CFLAGS} src/Esoteric_Fun_Miscellaneous/Bogo_Sort.c -o bin/Bogo_Sort.o

Bubble_Bogo_Sort.o : src/Esoteric_Fun_Miscellaneous/Bubble_Bogo_Sort.c
	${CC} ${CFLAGS} src/Esoteric_Fun_Miscellaneous/Bubble_Bogo_Sort.c -o bin/Bubble_Bogo_Sort.o

Cocktail_Bogo_Sort.o : src/Esoteric_Fun_Miscellaneous/Cocktail_Bogo_Sort.c
	${CC} ${CFLAGS} src/Esoteric_Fun_Miscellaneous/Cocktail_Bogo_Sort.c -o bin/Cocktail_Bogo_Sort.o

Exchange_Bogo_Sort.o : src/Esoteric_Fun_Miscellaneous/Exchange_Bogo_Sort.c
	${CC} ${CFLAGS} src/Esoteric_Fun_Miscellaneous/Exchange_Bogo_Sort.c -o bin/Exchange_Bogo_Sort.o

Less_Bogo_Sort.o : src/Esoteric_Fun_Miscellaneous/Less_Bogo_Sort.c
	${CC} ${CFLAGS} src/Esoteric_Fun_Miscellaneous/Less_Bogo_Sort.c -o bin/Less_Bogo_Sort.o

Pancake_Sort.o : src/Esoteric_Fun_Miscellaneous/Pancake_Sort.c
	${CC} ${CFLAGS} src/Esoteric_Fun_Miscellaneous/Pancake_Sort.c -o bin/Pancake_Sort.o

Silly_Sort.o : src/Esoteric_Fun_Miscellaneous/Silly_Sort.c
	${CC} ${CFLAGS} src/Esoteric_Fun_Miscellaneous/Silly_Sort.c -o bin/Silly_Sort.o

Slow_Sort.o : src/Esoteric_Fun_Miscellaneous/Slow_Sort.c
	${CC} ${CFLAGS} src/Esoteric_Fun_Miscellaneous/Slow_Sort.c -o bin/Slow_Sort.o

Spaghetti_Sort.o : src/Esoteric_Fun_Miscellaneous/Spaghetti_Sort.c
	${CC} ${CFLAGS} src/Esoteric_Fun_Miscellaneous/Spaghetti_Sort.c -o bin/Spaghetti_Sort.o

Stooge_Sort.o : src/Esoteric_Fun_Miscellaneous/Stooge_Sort.c
	${CC} ${CFLAGS} src/Esoteric_Fun_Miscellaneous/Stooge_Sort.c -o bin/Stooge_Sort.o

#---------------------------------------------------------------------------------------------------------------
# src/Exchange/
Bubble_Sort.o : src/Exchange/Bubble_Sort.c
	${CC} ${CFLAGS} src/Exchange/Bubble_Sort.c -o bin/Bubble_Sort.o

Circle_Sort.o : src/Exchange/Circle_Sort.c
	${CC} ${CFLAGS} src/Exchange/Circle_Sort.c -o bin/Circle_Sort.o

Cocktail_Shaker_Sort.o : src/Exchange/Cocktail_Shaker_Sort.c
	${CC} ${CFLAGS} src/Exchange/Cocktail_Shaker_Sort.c -o bin/Cocktail_Shaker_Sort.o

Comb_Sort.o : src/Exchange/Comb_Sort.c
	${CC} ${CFLAGS} src/Exchange/Comb_Sort.c -o bin/Comb_Sort.o

Dual_Pivot_Quick_Sort.o : src/Exchange/Dual_Pivot_Quick_Sort.c
	${CC} ${CFLAGS} src/Exchange/Dual_Pivot_Quick_Sort.c -o bin/Dual_Pivot_Quick_Sort.o

Gnome_Sort.o : src/Exchange/Gnome_Sort.c
	${CC} ${CFLAGS} src/Exchange/Gnome_Sort.c -o bin/Gnome_Sort.o

Odd-Even_Sort.o : src/Exchange/Odd-Even_Sort.c
	${CC} ${CFLAGS} src/Exchange/Odd-Even_Sort.c -o bin/Odd-Even_Sort.o

Optimized_Bubble_Sort.o : src/Exchange/Optimized_Bubble_Sort.c
	${CC} ${CFLAGS} src/Exchange/Optimized_Bubble_Sort.c -o bin/Optimized_Bubble_Sort.o

Optimized_Cocktail_Shaker_Sort.o : src/Exchange/Optimized_Cocktail_Shaker_Sort.c
	${CC} ${CFLAGS} src/Exchange/Optimized_Cocktail_Shaker_Sort.c -o bin/Optimized_Cocktail_Shaker_Sort.o

Optimized_Gnome_Sort.o : src/Exchange/Optimized_Gnome_Sort.c
	${CC} ${CFLAGS} src/Exchange/Optimized_Gnome_Sort.c -o bin/Optimized_Gnome_Sort.o

Quick_Sort_3-way.o : src/Exchange/Quick_Sort_3-way.c
	${CC} ${CFLAGS} src/Exchange/Quick_Sort_3-way.c -o bin/Quick_Sort_3-way.o

Quick_Sort.o : src/Exchange/Quick_Sort.c
	${CC} ${CFLAGS} src/Exchange/Quick_Sort.c -o bin/Quick_Sort.o

Stable_Quick_Sort.o : src/Exchange/Stable_Quick_Sort.c
	${CC} ${CFLAGS} src/Exchange/Stable_Quick_Sort.c -o bin/Stable_Quick_Sort.o

# src/Hybrids/
Tim_Sort.o : src/Hybrids/Tim_Sort.c
	${CC} ${CFLAGS} src/Hybrids/Tim_Sort.c -o bin/Tim_Sort.o

#---------------------------------------------------------------------------------------------------------------
# src/Insertion/
Binary_Insertion_Sort.o : src/Insertion/Binary_Insertion_Sort.c
	${CC} ${CFLAGS} src/Insertion/Binary_Insertion_Sort.c -o bin/Binary_Insertion_Sort.o

Cycle_Sort.o : src/Insertion/Cycle_Sort.c
	${CC} ${CFLAGS} src/Insertion/Cycle_Sort.c -o bin/Cycle_Sort.o

Insertion_Sort.o : src/Insertion/Insertion_Sort.c
	${CC} ${CFLAGS} src/Insertion/Insertion_Sort.c -o bin/Insertion_Sort.o

Patience_Sort.o : src/Insertion/Patience_Sort.c
	${CC} ${CFLAGS} src/Insertion/Patience_Sort.c -o bin/Patience_Sort.o

Shell_Sort.o : src/Insertion/Shell_Sort.c
	${CC} ${CFLAGS} src/Insertion/Shell_Sort.c -o bin/Shell_Sort.o

Tree_Sort.o : src/Insertion/Tree_Sort.c
	${CC} ${CFLAGS} src/Insertion/Tree_Sort.c -o bin/Tree_Sort.o

#---------------------------------------------------------------------------------------------------------------
# src/Merge/
Bottom-up_Merge_Sort.o : src/Merge/Bottom-up_Merge_Sort.c
	${CC} ${CFLAGS} src/Merge/Bottom-up_Merge_Sort.c -o bin/Bottom-up_Merge_Sort.o

In-Place_Merge_Sort.o : src/Merge/In-Place_Merge_Sort.c
	${CC} ${CFLAGS} src/Merge/In-Place_Merge_Sort.c -o bin/In-Place_Merge_Sort.o

Merge_Sort.o : src/Merge/Merge_Sort.c
	${CC} ${CFLAGS} src/Merge/Merge_Sort.c -o bin/Merge_Sort.o

#---------------------------------------------------------------------------------------------------------------
# src/Networks_Concurrent/
Bitonic_Sort.o : src/Networks_Concurrent/Bitonic_Sort.c
	${CC} ${CFLAGS} src/Networks_Concurrent/Bitonic_Sort.c -o bin/Bitonic_Sort.o

Pairwise_Network_Sort.o : src/Networks_Concurrent/Pairwise_Network_Sort.c
	${CC} ${CFLAGS} src/Networks_Concurrent/Pairwise_Network_Sort.c -o bin/Pairwise_Network_Sort.o

#---------------------------------------------------------------------------------------------------------------
# src/Non-Comparison_Distribution/
Bucket_Sort.o : src/Non-Comparison_Distribution/Bucket_Sort.c
	${CC} ${CFLAGS} src/Non-Comparison_Distribution/Bucket_Sort.c -o bin/Bucket_Sort.o

Counting_Sort.o : src/Non-Comparison_Distribution/Counting_Sort.c
	${CC} ${CFLAGS} src/Non-Comparison_Distribution/Counting_Sort.c -o bin/Counting_Sort.o

Gravity_Bead_Sort.o : src/Non-Comparison_Distribution/Gravity_Bead_Sort.c
	${CC} ${CFLAGS} src/Non-Comparison_Distribution/Gravity_Bead_Sort.c -o bin/Gravity_Bead_Sort.o

Pigeonhole_Sort.o : src/Non-Comparison_Distribution/Pigeonhole_Sort.c
	${CC} ${CFLAGS} src/Non-Comparison_Distribution/Pigeonhole_Sort.c -o bin/Pigeonhole_Sort.o

Radix_LSD.o : src/Non-Comparison_Distribution/Radix_LSD.c
	${CC} ${CFLAGS} src/Non-Comparison_Distribution/Radix_LSD.c -o bin/Radix_LSD.o

#---------------------------------------------------------------------------------------------------------------
# src/Selection/
Double_Selection_Sort.o : src/Selection/Double_Selection_Sort.c
	${CC} ${CFLAGS} src/Selection/Double_Selection_Sort.c -o bin/Double_Selection_Sort.o

Max_Heap_Sort.o : src/Selection/Max_Heap_Sort.c
	${CC} ${CFLAGS} src/Selection/Max_Heap_Sort.c -o bin/Max_Heap_Sort.o

Min_Heap_Sort.o : src/Selection/Min_Heap_Sort.c
	${CC} ${CFLAGS} src/Selection/Min_Heap_Sort.c -o bin/Min_Heap_Sort.o

Selection_Sort.o : src/Selection/Selection_Sort.c
	${CC} ${CFLAGS} src/Selection/Selection_Sort.c -o bin/Selection_Sort.o

#---------------------------------------------------------------------------------------------------------------
# src/
QRcode.o : src/QRcode.c
	${CC} ${CFLAGS} src/QRcode.c -o bin/QRcode.o

All_Sorts.o : src/All_Sorts.c
	${CC} ${CFLAGS} src/All_Sorts.c -o bin/All_Sorts.o

#---------------------------------------------------------------------------------------------------------------
# Clear all objects
clean:
	rm -rf *.o
	rm -rf *.out

# Clear all
rmproper: clean
	rm -rf sort

# Compile and run
cr: sort clean
	./sort

# Run executable
run:
	./sort