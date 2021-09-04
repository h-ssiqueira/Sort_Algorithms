mkdir bin
gcc -lm -c -Ofast src/Esoteric_Fun_Miscellaneous/Bad_Sort.c -o bin/Bad_Sort.o
gcc -lm -c -Ofast src/Esoteric_Fun_Miscellaneous/Bogo_Bogo_Sort.c -o bin/Bogo_Bogo_Sort.o
gcc -lm -c -Ofast src/Esoteric_Fun_Miscellaneous/Bogo_Sort.c -o bin/Bogo_Sort.o
gcc -lm -c -Ofast src/Esoteric_Fun_Miscellaneous/Bubble_Bogo_Sort.c -o bin/Bubble_Bogo_Sort.o
gcc -lm -c -Ofast src/Esoteric_Fun_Miscellaneous/Cocktail_Bogo_Sort.c -o bin/Cocktail_Bogo_Sort.o
gcc -lm -c -Ofast src/Esoteric_Fun_Miscellaneous/Exchange_Bogo_Sort.c -o bin/Exchange_Bogo_Sort.o
gcc -lm -c -Ofast src/Esoteric_Fun_Miscellaneous/Less_Bogo_Sort.c -o bin/Less_Bogo_Sort.o
gcc -lm -c -Ofast src/Esoteric_Fun_Miscellaneous/Pancake_Sort.c -o bin/Pancake_Sort.o
gcc -lm -c -Ofast src/Esoteric_Fun_Miscellaneous/Silly_Sort.c -o bin/Silly_Sort.o
gcc -lm -c -Ofast src/Esoteric_Fun_Miscellaneous/Slow_Sort.c -o bin/Slow_Sort.o
gcc -lm -c -Ofast src/Esoteric_Fun_Miscellaneous/Spaghetti_Sort.c -o bin/Spaghetti_Sort.o
gcc -lm -c -Ofast src/Esoteric_Fun_Miscellaneous/Stooge_Sort.c -o bin/Stooge_Sort.o
gcc -lm -c -Ofast src/Exchange/Bubble_Sort.c -o bin/Bubble_Sort.o
gcc -lm -c -Ofast src/Exchange/Circle_Sort.c -o bin/Circle_Sort.o
gcc -lm -c -Ofast src/Exchange/Cocktail_Shaker_Sort.c -o bin/Cocktail_Shaker_Sort.o
gcc -lm -c -Ofast src/Exchange/Comb_Sort.c -o bin/Comb_Sort.o
gcc -lm -c -Ofast src/Exchange/Dual_Pivot_Quick_Sort.c -o bin/Dual_Pivot_Quick_Sort.o
gcc -lm -c -Ofast src/Exchange/Gnome_Sort.c -o bin/Gnome_Sort.o
gcc -lm -c -Ofast src/Exchange/Odd-Even_Sort.c -o bin/Odd-Even_Sort.o
gcc -lm -c -Ofast src/Exchange/Optimized_Bubble_Sort.c -o bin/Optimized_Bubble_Sort.o
gcc -lm -c -Ofast src/Exchange/Optimized_Cocktail_Shaker_Sort.c -o bin/Optimized_Cocktail_Shaker_Sort.o
gcc -lm -c -Ofast src/Exchange/Optimized_Gnome_Sort.c -o bin/Optimized_Gnome_Sort.o
gcc -lm -c -Ofast src/Exchange/Quick_Sort_3-way.c -o bin/Quick_Sort_3-way.o
gcc -lm -c -Ofast src/Exchange/Quick_Sort.c -o bin/Quick_Sort.o
gcc -lm -c -Ofast src/Exchange/Stable_Quick_Sort.c -o bin/Stable_Quick_Sort.o
gcc -lm -c -Ofast src/Hybrids/Tim_Sort.c -o bin/Tim_Sort.o
gcc -lm -c -Ofast src/Insertion/AVLTree_Sort.c -o bin/AVLTree_Sort.o
gcc -lm -c -Ofast src/Insertion/Binary_Insertion_Sort.c -o bin/Binary_Insertion_Sort.o
gcc -lm -c -Ofast src/Insertion/Cycle_Sort.c -o bin/Cycle_Sort.o
gcc -lm -c -Ofast src/Insertion/Insertion_Sort.c -o bin/Insertion_Sort.o
gcc -lm -c -Ofast src/Insertion/Patience_Sort.c -o bin/Patience_Sort.o
gcc -lm -c -Ofast src/Insertion/Shell_Sort.c -o bin/Shell_Sort.o
gcc -lm -c -Ofast src/Insertion/Tree_Sort.c -o bin/Tree_Sort.o
gcc -lm -c -Ofast src/Merge/Bottom-up_Merge_Sort.c -o bin/Bottom-up_Merge_Sort.o
gcc -lm -c -Ofast src/Merge/In-Place_Merge_Sort.c -o bin/In-Place_Merge_Sort.o
gcc -lm -c -Ofast src/Merge/Merge_Sort.c -o bin/Merge_Sort.o
gcc -lm -c -Ofast src/Networks_Concurrent/Bitonic_Sort.c -o bin/Bitonic_Sort.o
gcc -lm -c -Ofast src/Networks_Concurrent/Pairwise_Network_Sort.c -o bin/Pairwise_Network_Sort.o
gcc -lm -c -Ofast src/Non-Comparison_Distribution/Bucket_Sort.c -o bin/Bucket_Sort.o
gcc -lm -c -Ofast src/Non-Comparison_Distribution/Counting_Sort.c -o bin/Counting_Sort.o
gcc -lm -c -Ofast src/Non-Comparison_Distribution/Gravity_Bead_Sort.c -o bin/Gravity_Bead_Sort.o
gcc -lm -c -Ofast src/Non-Comparison_Distribution/Pigeonhole_Sort.c -o bin/Pigeonhole_Sort.o
gcc -lm -c -Ofast src/Non-Comparison_Distribution/Radix_LSD.c -o bin/Radix_LSD.o
gcc -lm -c -Ofast src/Selection/Double_Selection_Sort.c -o bin/Double_Selection_Sort.o
gcc -lm -c -Ofast src/Selection/Max_Heap_Sort.c -o bin/Max_Heap_Sort.o
gcc -lm -c -Ofast src/Selection/Min_Heap_Sort.c -o bin/Min_Heap_Sort.o
gcc -lm -c -Ofast src/Selection/Selection_Sort.c -o bin/Selection_Sort.o
gcc -lm -c -Ofast src/QRcode.c -o bin/QRcode.o
gcc -lm -c -Ofast src/All_Sorts.c -o bin/All_Sorts.o
gcc -o sort bin/*.o
.\sort