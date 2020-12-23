all: sort

#sort: Source/All_Sorts.o Source/Esoteric_Fun_Miscellaneous/*.o Source/Exchange/*.o Source/Hybrids/*.o Source/Insertion/*.o Source/Merge/*.o Source/Networks_Concurrent/*.o Source/Non-Comparison_Distribution/*.o Source/Selection/*.o
#	gcc -o sort Source/Esoteric_Fun_Miscellaneous/*.o Source/Exchange/*.o Source/Hybrids/*.o Source/Insertion/*.o Source/Merge/*.o Source/Networks_Concurrent/*.o Source/Non-Comparison_Distribution/*.o Source/Selection/*.o Source/All_Sorts.o -lm

sort: Source/Esoteric_Fun_Miscellaneous/Bad_Sort.o Source/Esoteric_Fun_Miscellaneous/Bogo_Bogo_Sort.o Source/Esoteric_Fun_Miscellaneous/Bogo_Sort.o Source/Esoteric_Fun_Miscellaneous/Bubble_Bogo_Sort.o Source/Esoteric_Fun_Miscellaneous/Cocktail_Bogo_Sort.o Source/Esoteric_Fun_Miscellaneous/Exchange_Bogo_Sort.o Source/Esoteric_Fun_Miscellaneous/Less_Bogo_Sort.o Source/Esoteric_Fun_Miscellaneous/Pancake_Sort.o Source/Esoteric_Fun_Miscellaneous/Silly_Sort.o Source/Esoteric_Fun_Miscellaneous/Slow_Sort.o Source/Esoteric_Fun_Miscellaneous/Spaghetti_Sort.o Source/Esoteric_Fun_Miscellaneous/Stooge_Sort.o Source/Exchange/Bubble_Sort.o Source/Exchange/Circle_Sort.o Source/Exchange/Cocktail_Shaker_Sort.o Source/Exchange/Comb_Sort.o Source/Exchange/Dual_Pivot_Quick_Sort.o Source/Exchange/Gnome_Sort.o Source/Exchange/Odd-Even_Sort.o Source/Exchange/Optimized_Bubble_Sort.o Source/Exchange/Optimized_Cocktail_Shaker_Sort.o Source/Exchange/Optimized_Gnome_Sort.o Source/Exchange/Quick_Sort_3-way.o Source/Exchange/Quick_Sort.o Source/Exchange/Stable_Quick_Sort.o Source/Hybrids/Tim_Sort.o Source/Insertion/Binary_Insertion_Sort.o Source/Insertion/Cycle_Sort.o Source/Insertion/Insertion_Sort.o Source/Insertion/Patience_Sort.o Source/Insertion/Shell_Sort.o Source/Insertion/Tree_Sort.o Source/Merge/Bottom-up_Merge_Sort.o Source/Merge/In-Place_Merge_Sort.o Source/Merge/Merge_Sort.o Source/Networks_Concurrent/Bitonic_Sort.o Source/Networks_Concurrent/Pairwise_Network_Sort.o Source/Non-Comparison_Distribution/Bucket_Sort.o Source/Non-Comparison_Distribution/Counting_Sort.o Source/Non-Comparison_Distribution/Gravity_Bead_Sort.o Source/Non-Comparison_Distribution/Pigeonhole_Sort.o Source/Selection/Double_Selection_Sort.o Source/Selection/Max_Heap_Sort.o Source/Selection/Min_Heap_Sort.o Source/Selection/Selection_Sort.o Source/All_Sorts.o
	gcc -o sort Bad_Sort.o Bogo_Bogo_Sort.o Bogo_Sort.o Bubble_Bogo_Sort.o Cocktail_Bogo_Sort.o Exchange_Bogo_Sort.o Less_Bogo_Sort.o Pancake_Sort.o Silly_Sort.o Slow_Sort.o Spaghetti_Sort.o Stooge_Sort.o Bubble_Sort.o Circle_Sort.o Cocktail_Shaker_Sort.o Comb_Sort.o Dual_Pivot_Quick_Sort.o Gnome_Sort.o Odd-Even_Sort.o Optimized_Bubble_Sort.o Optimized_Cocktail_Shaker_Sort.o Optimized_Gnome_Sort.o Quick_Sort_3-way.o Quick_Sort.o Stable_Quick_Sort.o Tim_Sort.o Binary_Insertion_Sort.o Cycle_Sort.o Insertion_Sort.o Patience_Sort.o Shell_Sort.o Tree_Sort.o Bottom-up_Merge_Sort.o In-Place_Merge_Sort.o Merge_Sort.o Bitonic_Sort.o Pairwise_Network_Sort.o Bucket_Sort.o Counting_Sort.o Gravity_Bead_Sort.o Pigeonhole_Sort.o Double_Selection_Sort.o Max_Heap_Sort.o Min_Heap_Sort.o Selection_Sort.o All_Sorts.o

# Source/Esoteric_Fun_Miscellaneous/
Source/Esoteric_Fun_Miscellaneous/Bad_Sort.o : Source/Esoteric_Fun_Miscellaneous/Bad_Sort.c
	gcc -c Source/Esoteric_Fun_Miscellaneous/Bad_Sort.c

Source/Esoteric_Fun_Miscellaneous/Bogo_Bogo_Sort.o : Source/Esoteric_Fun_Miscellaneous/Bogo_Bogo_Sort.c
	gcc -c Source/Esoteric_Fun_Miscellaneous/Bogo_Bogo_Sort.c

Source/Esoteric_Fun_Miscellaneous/Bogo_Sort.o : Source/Esoteric_Fun_Miscellaneous/Bogo_Sort.c
	gcc -c Source/Esoteric_Fun_Miscellaneous/Bogo_Sort.c

Source/Esoteric_Fun_Miscellaneous/Bubble_Bogo_Sort.o : Source/Esoteric_Fun_Miscellaneous/Bubble_Bogo_Sort.c
	gcc -c Source/Esoteric_Fun_Miscellaneous/Bubble_Bogo_Sort.c

Source/Esoteric_Fun_Miscellaneous/Cocktail_Bogo_Sort.o : Source/Esoteric_Fun_Miscellaneous/Cocktail_Bogo_Sort.c
	gcc -c Source/Esoteric_Fun_Miscellaneous/Cocktail_Bogo_Sort.c

Source/Esoteric_Fun_Miscellaneous/Exchange_Bogo_Sort.o : Source/Esoteric_Fun_Miscellaneous/Exchange_Bogo_Sort.c
	gcc -c Source/Esoteric_Fun_Miscellaneous/Exchange_Bogo_Sort.c

Source/Esoteric_Fun_Miscellaneous/Less_Bogo_Sort.o : Source/Esoteric_Fun_Miscellaneous/Less_Bogo_Sort.c
	gcc -c Source/Esoteric_Fun_Miscellaneous/Less_Bogo_Sort.c

Source/Esoteric_Fun_Miscellaneous/Pancake_Sort.o : Source/Esoteric_Fun_Miscellaneous/Pancake_Sort.c
	gcc -c Source/Esoteric_Fun_Miscellaneous/Pancake_Sort.c

Source/Esoteric_Fun_Miscellaneous/Silly_Sort.o : Source/Esoteric_Fun_Miscellaneous/Silly_Sort.c
	gcc -c Source/Esoteric_Fun_Miscellaneous/Silly_Sort.c

Source/Esoteric_Fun_Miscellaneous/Slow_Sort.o : Source/Esoteric_Fun_Miscellaneous/Slow_Sort.c
	gcc -c Source/Esoteric_Fun_Miscellaneous/Slow_Sort.c

Source/Esoteric_Fun_Miscellaneous/Spaghetti_Sort.o : Source/Esoteric_Fun_Miscellaneous/Spaghetti_Sort.c
	gcc -c Source/Esoteric_Fun_Miscellaneous/Spaghetti_Sort.c

Source/Esoteric_Fun_Miscellaneous/Stooge_Sort.o : Source/Esoteric_Fun_Miscellaneous/Stooge_Sort.c
	gcc -c Source/Esoteric_Fun_Miscellaneous/Stooge_Sort.c

# Source/Exchange/
Source/Exchange/Bubble_Sort.o : Source/Exchange/Bubble_Sort.c
	gcc -c Source/Exchange/Bubble_Sort.c

Source/Exchange/Circle_Sort.o : Source/Exchange/Circle_Sort.c
	gcc -c Source/Exchange/Circle_Sort.c

Source/Exchange/Cocktail_Shaker_Sort.o : Source/Exchange/Cocktail_Shaker_Sort.c
	gcc -c Source/Exchange/Cocktail_Shaker_Sort.c

Source/Exchange/Comb_Sort.o : Source/Exchange/Comb_Sort.c
	gcc -c Source/Exchange/Comb_Sort.c

Source/Exchange/Dual_Pivot_Quick_Sort.o : Source/Exchange/Dual_Pivot_Quick_Sort.c
	gcc -c Source/Exchange/Dual_Pivot_Quick_Sort.c

Source/Exchange/Gnome_Sort.o : Source/Exchange/Gnome_Sort.c
	gcc -c Source/Exchange/Gnome_Sort.c

Source/Exchange/Odd-Even_Sort.o : Source/Exchange/Odd-Even_Sort.c
	gcc -c Source/Exchange/Odd-Even_Sort.c

Source/Exchange/Optimized_Bubble_Sort.o : Source/Exchange/Optimized_Bubble_Sort.c
	gcc -c Source/Exchange/Optimized_Bubble_Sort.c

Source/Exchange/Optimized_Cocktail_Shaker_Sort.o : Source/Exchange/Optimized_Cocktail_Shaker_Sort.c
	gcc -c Source/Exchange/Optimized_Cocktail_Shaker_Sort.c

Source/Exchange/Optimized_Gnome_Sort.o : Source/Exchange/Optimized_Gnome_Sort.c
	gcc -c Source/Exchange/Optimized_Gnome_Sort.c

Source/Exchange/Quick_Sort_3-way.o : Source/Exchange/Quick_Sort_3-way.c
	gcc -c Source/Exchange/Quick_Sort_3-way.c

Source/Exchange/Quick_Sort.o : Source/Exchange/Quick_Sort.c
	gcc -c Source/Exchange/Quick_Sort.c

Source/Exchange/Stable_Quick_Sort.o : Source/Exchange/Stable_Quick_Sort.c
	gcc -c Source/Exchange/Stable_Quick_Sort.c

# Source/Hybrids/
Source/Hybrids/Tim_Sort.o : Source/Hybrids/Tim_Sort.c
	gcc -c Source/Hybrids/Tim_Sort.c

# Source/Insertion/
Source/Insertion/Binary_Insertion_Sort.o : Source/Insertion/Binary_Insertion_Sort.c
	gcc -c Source/Insertion/Binary_Insertion_Sort.c

Source/Insertion/Cycle_Sort.o : Source/Insertion/Cycle_Sort.c
	gcc -c Source/Insertion/Cycle_Sort.c

Source/Insertion/Insertion_Sort.o : Source/Insertion/Insertion_Sort.c
	gcc -c Source/Insertion/Insertion_Sort.c

Source/Insertion/Patience_Sort.o : Source/Insertion/Patience_Sort.c
	gcc -c Source/Insertion/Patience_Sort.c

Source/Insertion/Shell_Sort.o : Source/Insertion/Shell_Sort.c
	gcc -c Source/Insertion/Shell_Sort.c

Source/Insertion/Tree_Sort.o : Source/Insertion/Tree_Sort.c
	gcc -c Source/Insertion/Tree_Sort.c

# Source/Merge/
Source/Merge/Bottom-up_Merge_Sort.o : Source/Merge/Bottom-up_Merge_Sort.c
	gcc -c Source/Merge/Bottom-up_Merge_Sort.c

Source/Merge/In-Place_Merge_Sort.o : Source/Merge/In-Place_Merge_Sort.c
	gcc -c Source/Merge/In-Place_Merge_Sort.c

Source/Merge/Merge_Sort.o : Source/Merge/Merge_Sort.c
	gcc -c Source/Merge/Merge_Sort.c

# Source/Networks_Concurrent/
Source/Networks_Concurrent/Bitonic_Sort.o : Source/Networks_Concurrent/Bitonic_Sort.c
	gcc -c Source/Networks_Concurrent/Bitonic_Sort.c

Source/Networks_Concurrent/Pairwise_Network_Sort.o : Source/Networks_Concurrent/Pairwise_Network_Sort.c
	gcc -c Source/Networks_Concurrent/Pairwise_Network_Sort.c

# Source/Non-Comparison_Distribution/
Source/Non-Comparison_Distribution/Bucket_Sort.o : Source/Non-Comparison_Distribution/Bucket_Sort.c
	gcc -c Source/Non-Comparison_Distribution/Bucket_Sort.c

Source/Non-Comparison_Distribution/Counting_Sort.o : Source/Non-Comparison_Distribution/Counting_Sort.c
	gcc -c Source/Non-Comparison_Distribution/Counting_Sort.c

Source/Non-Comparison_Distribution/Gravity_Bead_Sort.o : Source/Non-Comparison_Distribution/Gravity_Bead_Sort.c
	gcc -c Source/Non-Comparison_Distribution/Gravity_Bead_Sort.c

Source/Non-Comparison_Distribution/Pigeonhole_Sort.o : Source/Non-Comparison_Distribution/Pigeonhole_Sort.c
	gcc -c Source/Non-Comparison_Distribution/Pigeonhole_Sort.c

# Source/Selection/
Source/Selection/Double_Selection_Sort.o : Source/Selection/Double_Selection_Sort.c
	gcc -c Source/Selection/Double_Selection_Sort.c

Source/Selection/Max_Heap_Sort.o : Source/Selection/Max_Heap_Sort.c
	gcc -c Source/Selection/Max_Heap_Sort.c

Source/Selection/Min_Heap_Sort.o : Source/Selection/Min_Heap_Sort.c
	gcc -c Source/Selection/Min_Heap_Sort.c

Source/Selection/Selection_Sort.o : Source/Selection/Selection_Sort.c
	gcc -c Source/Selection/Selection_Sort.c

# Source/
Source/All_Sorts.o : Source/All_Sorts.c
	gcc -c Source/All_Sorts.c

#--------------------------------------------------------------------------
# Clear all objects
clean:
	rm -rf *.o

# Clear all
rmproper: clean
	rm -rf sort

# Compile and run (linux)
crl: sort clean
	./sort

# Run executable (linux)
runl:
	./sort

# Run executable (windows)
runw:
	sort

# Compile and run (windows)
crw: sort clean
	sort