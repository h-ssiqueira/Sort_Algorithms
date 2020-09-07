#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define leng 10
#define RUN 32
#define buckets 10

void print(int array[]){
    printf("\n");
    for(int i = 0; i < leng; i++)
        printf("%d ",array[i]);
}

void Swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

bool is_sorted(int array[], int n){
    while(--n >= 1){
        if(array[n] < array[n-1])
            return false;
    }
    return true;
}
    
void bogo_sort(int array[], int n){
    int random;
    while(!is_sorted(array,n)){
        for(int i = 0; i < n; i++){ //tries to sort randomly
            random = rand() % n;
            Swap(&array[i], &array[random]);
        }
        print(array);
    }
}

void flip(int array[], int i){ 
    int start = 0; 
    while(start < i){ 
        Swap(&array[i], &array[start]);
        start++; 
        i--;
    }
}
  
int PancakeSort(int array[], int length){
    int aux,i = length,j;
    for(; i > 1; i--){ 
        aux = 0;
        for(j = 0; j < i; j++){ // Find the position of the greater element of the array
            if(array[j] > array[aux])
                aux = j;
        }
        if(aux != i-1){ // Move he greater element to the end of the array
            flip(array, aux); // Move the number to beginning
            print(array);
            flip(array, i-1); // Reverse the array
            print(array);
        } 
    }
}

void SlowSort(int array[],int start,int end){
    if(start >= end) return;
    int middle = (start + end) / 2;

    SlowSort(array,start,middle); // start - middle parts
    SlowSort(array,middle + 1,end); // middle - end parts
    if(array[end] < array[middle]){
        Swap(&array[middle], &array[end]);
        print(array);
    }
    SlowSort(array,start,end-1); // Sort elements decreasing the array
}

int SpaghettiSort(int array[], int length){
    int i, j, k = 0, aux[length], min = array[0], max = array[0];
    for(i = 0; i < length; i++){ // Find the max and min values in the array
        if(array[i] > max) 
            max = array[i];
        if(array[i] < min) 
            min = array[i];
    }
    for(i = min; i <= max; i++){
        for(j = 0; j < length; j++){
            if(array[j] == i){ // Find the followed elements after min value to wirte in the aux array
                aux[k] = array[j];
                k++;
            }
        }
        print(aux);
    }
    for(i = 0; i < length; i++) // Return the elements in the main array
        array[i] = aux[i];
}

void StoogeSort(int array[], int i, int j){
    int aux;
    if(array[i] > array[j]) // Swap initially the fist and last elements
        Swap(&array[i], &array[j]);
    if(j - i > 1){ 
        aux = (j - i + 1) / 3;
        StoogeSort(array, i, j - aux); // Swap recursively the first 2/3 elements of the array
        StoogeSort(array, i + aux, j); // Swap recursively the last 2/3 elements of the array
        StoogeSort(array, i, j - aux); // Swap recursively again the first 2/3 elements of the array
    }
    else
        print(array);
}

// Struct of the tree
typedef struct node{ 
    int value; 
    struct node *left, *right; 
}Node; 

// Function that releases the tree
Node* Release(Node *T){
	if(T->right != NULL) // Check if there's a node on right
		Release(T->right);
	if(T->left != NULL) // Check if there's a node on left
		Release(T->left);
	free(T); // Reaches a leaf and releases the node
	return NULL;
}
  
// Function that stores the elements of the sorted tree in the array
void Store(Node *root, int array[], int **i){ 
    if(root != NULL){ 
        if(root->left != NULL)
            Store(root->left, array, &(*i)); 
        array[(**i)] = root->value; 
        (**i)++;
        print(array);
        if(root->right != NULL)
            Store(root->right, array, &(*i)); 
    }
} 
  
// Function that creates new nodes for the tree
void Insert(Node **node, int value){ 
    if(!(*node)){
        (*node) = (Node*)malloc(sizeof(Node));
        if(!(*node)) return;
        (*node)->value = value;
        (*node)->left = (*node)->right = NULL;
    }
    else{
        if(value < (*node)->value)
            Insert(&(*node)->left,value);
        else// if(n > (*node)->value)
            Insert(&(*node)->right,value);
    }
}
  
void TreeSort(int array[], int length){ 
    Node *root = NULL; 
    int i,*p;
    
    for(i = 0; i < length; i++) 
        Insert(&root, array[i]); 
    i = 0;
    p = &i; 
    Store(root, array, &p); // Store the values in the array
    root = Release(root);
} 

void ShellSort(int array[], int length){
    int aux, h = 1, i, j;
    
    while(h < length) // Set the value of h until reach the value of length or more
        h = 3 * h + 1;
    for(;h > 0; h /= 3){ // h starts decreasing the array
        for(i = h; i < length; i++){ // i will take the value of h, incrementing one by one
            aux = array[i];
            for(j = i; j > h-1 && array[j - h] > aux; j -= h) // and j decreasing until the value of i
                array[j] = array[j - h]; // Implementing the insertion sort
            array[j] = aux;
        }
        print(array);
    }
}

void InsertionSort(int array[],int length){
    for(int i = 1, j, aux; i < length; i++){//i is always one step ahead j
        aux = array[i]; //collect the value of a position
        j = i - 1; //and the index of previous value
        while(j >= 0 && aux < array[j]){ //compares with the previous array until find the lower element
            array[j+1] = array[j];//shift all values one index ahead
            j--;
        }
        array[j+1] = aux;//set the value on right position next to 'start' of array comparing with the index of i
        print(array);
    }
}

void CycleSort(int array[],int length){
    int aux, pos, swap;
    for(int i = 0; i < length - 2; i++){ 
        aux = array[i];
        pos = i; 
        for(int j = i + 1; j < length; j++) // Find the right position
            if(array[j] < aux) 
                pos++; 
        if(pos == i) // If the element is in correct position
            continue; 
        while(aux == array[pos]) // For duplicate elements
            pos++; 
        if(pos != i) // Setting the element in correct position
            Swap(&array[pos], &aux);
        while(pos != i){ // Rotating the cycle
            pos = i; 
            for(int k = i + 1; k < length; k++) // Find the right position
                if(array[k] < aux) 
                    pos++; 
            while(aux == array[pos]) // For duplicate elements
                pos++; 
            if(aux != array[pos]) // Setting the element in correct position
                Swap(&array[pos], &aux);
        } 
        print(array);
    } 
}

int BinarySearch(int array[], int num, int start, int end){ 
    if(end <= start) 
        return (num > array[start]) ? (start + 1) : start; 
    int mid = (start + end) / 2; 
    if(num == array[mid]) 
        return mid + 1; 
    if(num > array[mid]) 
        return BinarySearch(array, num, mid + 1, end); 
    return BinarySearch(array, num, start, mid - 1); 
} 
  
void Insertion_Sort(int array[], int length){ 
    int i, j, pos, aux; 
  
    for(i = 1; i < length; i++){ 
        j = i - 1; 
        aux = array[i]; 
        pos = BinarySearch(array, aux, 0, j); // Find the position where the element should be inserted
        while(pos <= j){ // Move all elements until reaches the position
            array[j+1] = array[j]; 
            j--; 
        } 
        array[j+1] = aux; 
        print(array);
    } 
} 

void Selection_Sort(int array[], int length){
    int change;
    
    for(int i = 0; i < length-1; i++){ //last element won't have other to compair
        change = i;
        for(int j = i+1; j < length; j++)
            if(array[change] > array[j]) //if the element is lower, collect the position
                change = j;
        if(i != change) // if it has been modified, swap positions (using xor)
            Swap(&array[i], &array[change]);
        print(array);
    }
}

void Double_Selection_Sort(int array[], int length){
    int changeMin, changeMax;
    
    for(int i = 0, j = length-1; i < j; i++, j--){
        changeMin = i; //starts in the first
        changeMax = j; //starts in the last
        for(int k = i+1; k <= j; k++){
            if(array[k] < array[changeMin]) //search for the min element
                changeMin = k;
            else if(array[k] > array[changeMax]) //search for the max element
                changeMax = k;
        }
        if(i != changeMin){ //swap the positions for fit the min element
            Swap(&array[i], &array[changeMin]);
        }
        if(j != changeMax) //swap the positions for fit the max element
            Swap(&array[j], &array[changeMax]);
        print(array);
    }
}

void Merge(int array[], int start, int middle, int end){
    int count1 = start, count2 = middle + 1, i, *aux = (int*)malloc((end - start + 1) * sizeof(int));

    for(i = 0; count1 <= middle && count2 <= end; i++){
        if(array[count1] < array[count2]){
            aux[i] = array[count1];
            count1++;
        } 
        else{
            aux[i] = array[count2];
            count2++;
        }
    }
    while(count1 <= middle){  
        aux[i] = array[count1];
        i++;
        count1++;
    }
    while(count2 <= end){   
        aux[i] = array[count2];
        i++;
        count2++;
    }
    for(i = start; i <= end; i++)    
        array[i] = aux[i - start];
    print(array);
    free(aux);
}

void Merge_Sort(int array[], int start, int end){
    if(start < end){
        int middle = (start + end) / 2;
        Merge_Sort(array, start, middle); // first - middle parts
        Merge_Sort(array, middle + 1, end); // middle - end parts
        if(array[middle] < array[middle+1]){ // Check if both parts are already sorted, if so, merge is useless
            print(array);
            return;
        }
        Merge(array, start, middle, end); // sort
    }
}

void Bottomup_Merge_Sort(int array[], int length){        
    for(int i = 1; i < length; i += i){ // Start sorting the elements 1-1, 2-2... powers of 2
        for(int j = 0; j < length - i; j += i + i){
            j + i + i - 1 < length-1 ? Merge(array, j, j + i - 1, j + i + i - 1) : Merge(array, j, j + i - 1, length -1); // merge
        }
        print(array);
    }
}

void merge(int array[], int start, int middle, int end){ 
    int middle2 = middle + 1, value, i; 
  
    if(array[middle] <= array[middle2]) //if already sorted
        return;
    while(start <= middle && middle2 <= end){ //merge both halves
        if(array[start] <= array[middle2]) //if the element is in place
            start++;
        else{
            value = array[middle2];
            i = middle2;
            // Shift all the elements between element 1 
            // element 2, right by 1. 
            while(i != start){ //move all elements until the beginning
                array[i] = array[i - 1];
                i--;
            }
            array[start] = value;
            start++;
            middle++;
            middle2++;
        }
        print(array);
    }
}

void MergeSort(int array[], int start, int end){
    if(start < end){
        int middle = (end + start) / 2;
        MergeSort(array, start, middle); //first halves
        MergeSort(array, middle + 1, end); //second halves
        if(array[middle] < array[middle+1]){ // Check if both parts are already sorted, if so, merge is useless
            print(array);
            return;
        }
        merge(array, start, middle, end);
        print(array);
    }
}

void InsertionSortT(int array[], int left, int right){ 
    int aux, j;
    for(int i = left + 1; i <= right; i++){ 
        aux = array[i]; 
        j = i - 1; 
        while (j >= left && array[j] > aux){ 
            array[j+1] = array[j]; 
            j--; 
        } 
        array[j+1] = aux;
        print(array);
    } 
} 

void TimSort(int array[], int length){ 
    int mid, right;
    for(int i = 0; i < length; i += RUN){ // Sort subarrays of size RUN or mid
        right = i + RUN - 1;
        mid = length - 1;
        right > mid ? InsertionSortT(array, i, mid) : InsertionSortT(array, i, right); ; 
    }
  
    for(int size = RUN; size < length; size = 2 * size){ // Start mergin from size of run and doubling up the value
        for(int left = 0; left < length; left += 2 * size){ 
            mid = length - 1;
            right = left + 2 * size - 1; 
            if(mid < right) // Find ending position of merged array to merge with another
                right = mid;
            mid = left + size - 1; 
            Merge(array, left, mid, right); 
        }
    }
}

void Pigeonhole_Sort(int array[], int length){
    int max = array[0],min = array[0],range, i, j = 0;
    
    for(i = 0; i < length; i++){ //collect max and min values of array
        if(array[i] > max)
            max = array[i];
        if(array[i] < min)
            min = array[i];
    }
    range = max - min + 1;
    int holes[range]; //creates an array of ranges
    for(i = 0; i < range; i++) //clear the holes
        holes[i] = 0;
    for(i = 0; i < length; i++)
        holes[array[i] - min]++; //put the amount of times the value repeat in hole array in order
    for(i = 0; i < range; i++)
        while(holes[i]-- > 0)
            array[j++] = i + min; //insert the values to main array
}

void BeadSort(int array[], int length){
	int i, j, max, sum;
	char *beads;
 
	for(i = 1, max = array[0]; i < length; i++){
		if(array[i] > max) 
            max = array[i];
    }
	beads = (char*)calloc(1, max * length);
	for(i = 0; i < length; i++){ // Set the beads
		for(j = 0; j < array[i]; j++)
			beads[i * max + j] = 1;
    }
	for(j = 0; j < max; j++){ // Count how many beads has each position
		for(sum = i = 0; i < length; i++){
			sum += beads[i * max + j];
			beads[i * max + j] = 0;
		}
		for(i = length - sum; i < length; i++) // Set bottom sum beads
            beads[i * max + j] = 1;
	}
	for(i = 0; i < length; i++){
		for(j = 0; j < max && beads[i * max + j]; j++)
            continue;
		array[i] = j;
	}
	free(beads);
}

void Counting_Sort(int array[],int length){
    int output[length], i, max = array[0], min = array[0];
    
    for(i = 0; i < length; i++){
        if(array[i] > max) max = array[i];
        if(array[i] < min) min = array[i];
    }
    int range = max - min + 1,count[range];
    memset(count,0,sizeof(count)); // Set 0 for all positions in array
    for(i = 0; i < length; i++)// Count how many times the value repeat
        count[array[i]-min]++;
    for(i = 1; i < range; i++) // Count the amount of previous incidences
        count[i] += count[i-1];
    for(i = length-1; i >= 0; i--){ 
		output[count[array[i] - min] - 1] = array[i];// Putting the value on the corrected position && already sorted to an auxiliary array
		count[array[i] - min]--;
	}
    for(i = 0; i < length; i++) // Transfering to original array
        array[i] = output[i];
}

void Double_Selection_SortMatrix(int length, int matrix[][length]){
    int changeMin, changeMax;

    for(int h = 0; h < buckets; h++){
        for(int i = 0, j = length-1; i < j; i++, j--){
            changeMin = i; //starts in the first
            changeMax = j; //starts in the last
            for(int k = i+1; k <= j; k++){
                if(matrix[h][k] < matrix[h][changeMin]) //search for the min element
                    changeMin = k;
                else if(matrix[h][k] > matrix[h][changeMax]) //search for the max element
                    changeMax = k;
            }
            if(i != changeMin) //swap the positions for fit the min element
                Swap(&matrix[h][i], &matrix[h][changeMin]);
            if(j != changeMax) //swap the positions for fit the max element
                Swap(&matrix[h][i], &matrix[h][changeMax]);
        }
    }
}

int BucketSort(int array[], int length){
    int i, j, k, b[buckets][length], range = 1;

    for(i = 0; i < buckets; i++){
        for(j = 0; j < length; j++){
            b[i][j] = b[i][j] ^ b[i][j];
        }
    }
    for(i = 1, j = array[0]; i < length; i++){ // Determine the range of buckets by getting the max value 
        if(j < array[i])
            j = array[i];
    }
    while(j >= 1){ // count how many digits the number has
        j /= 10;
        range *= 10; // number of digits (quantity of zeros) to determine the range
    }
    for(i = 0; i < length; i++){ // sort the values to each bucket
        j = range / 10;
        k = 0;
        while(j <= range){
            if(array[i] < j){
                b[k][i] = array[i];
                break;
            }
            k++;
            j += (range / 10);
        }
    }
    printf("\n");
    for(i = 0; i < buckets; i++){
        for(j = 0; j < length; j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
    Double_Selection_SortMatrix(length,b); // After set the values to each bucket, sort each one using other algorithm
    for(i = 0; i < buckets; i++){
        for(j = 0; j < length; j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
    for(i = 0, k = 0; i < buckets; i++){ // Merge all buckets to the original array
        for(j = 0; j < length; j++){
            if(b[i][j] != 0){
                array[k] = b[i][j];
                k++;
            }
        }
    }
}

int Sort(int array[], int start, int end){
    int aux = array[start];
    
    while(start < end){
        while((array[end] >= aux) && (start < end))
            end--;
        if(start != end){
            array[start] = array[end];
            start++;
        }
        while((array[start] <= aux) && (start < end))
            start++;
        if(start != end){
            array[end] = array[start];
            end--;
        }
    }   
    array[start] = aux;
    return start;
}

void StableQuickSort(int array[], int start, int end){
    int aux = Sort(array, start, end);

    if(start < aux - 1)
        StableQuickSort(array, start, aux - 1);
    if(end > aux + 1)
        StableQuickSort(array, aux + 1, end);
    print(array);
}  

void Quick_Sort(int array[], int start, int end){
    int middle = array[(start + end) / 2], i = start, j = end;
    
    while(i <= j){
        while(array[i] < middle && i < end)
            i++;
        while(array[j] > middle && j > start)
            j--;
        if(i <= j){
            Swap(&array[i], &array[j]);
            i++;
            j--;
        }
    }
    if(start < j)
        Quick_Sort(array,start,j);
    if(i < end)
        Quick_Sort(array,i,end);
    print(array);
}

void Optimized_Gnome_Sort(int array[],int i){
    int j = i;
    while(j > 0 && array[j-1] > array [j]){
        Swap(&array[j-1], &array[j]);
        j--;
        print(array);
    }
}

void BubbleSortOptmized(int array[], int length){
    bool swap;
    int i,j;
    for(j = 0; j < length; j++){
        swap = false;
        for(i = 0; i < length - j; i++){ // Sort all array and starts decreasing
            if(array[i+1] < array[i]){
                Swap(&array[i], &array[i+1]);
                swap = true;
            }
        }
        print(array);
        if(!swap) // No swapping happened: it's already sorted
            break;
    }
}

void Odd_Even_Sort(int array[],int length){
    int i, j;
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for(i = 1, j = 2; i < length - 1; i += 2, j += 2){
            if(array[i] > array[i+1]){
                Swap(&array[i], &array[j]);
                sorted = false;
            }
        }
        for(i = 0, j = 1; i < length - 1; i += 2, j += 2){
            if(array[i] > array[i + 1]){
                Swap(&array[i], &array[j]);
                sorted = false;
            }
        }
        print(array);
    }
}

void Gnome_Sort(int array[], int length){
    int i = 1;
    
    while(i < length){
        if(array[i] >= array[i-1])
            i++;
        else{
            Swap(&array[i], &array[i-1]);
            if(i != 1)
                i--;
        }
        print(array);
    }
}

void DualPivotQuickSort(int array[], int start, int end){
    if(start < end){
        if(array[end] < array[start])
            Swap(&array[start], &array[end]);
        int last = array[end], first = array[start], p1 = start + 1, p2 = end - 1, aux = p1;
        while(aux <= p2){
            if(array[aux] < first){
                Swap(&array[aux], &array[p1]);
                p1++;
            } 
            else if(array[aux] >= last){
                while(array[p2] > last && aux < p2) 
                    p2--;
                Swap(&array[aux], &array[p2]);
                p2--;
                if(array[aux] < first){
                    Swap(&array[aux], &array[p1]);
                    p1++;
                }
            }
            aux++;
        }
        p1--;
        p2++;
        Swap(&array[p1], &array[start]);
        Swap(&array[end], &array[p2]);
        print(array);
        DualPivotQuickSort(array, start, p1 - 1);
        DualPivotQuickSort(array, p1 + 1, p2 - 1);
        DualPivotQuickSort(array, p2 + 1, end);
    }
}

void CombSort(int array[], int length){
    int i,j,aux,swap = 1;

    aux = swap;
    while(aux > 1 || swap == 1){
        aux *= (10/13);
        if(aux == 9 || aux == 10) 
            aux = 11;
        if(aux < 1) 
            aux = 1;
        swap = 0;
        for(i = 0, j = aux; j < length; i++, j++){
            if(array[i] > array[j]){
                Swap(&array[i], &array[j]);
                swap = 1;
            }
        }
        print(array);
    }
}

void CocktailShakerSort(int array[], int length){
    int start = 0,end = length - 1,swap = 0,i;

    while(swap == 0 && start < end){
        swap = 1;
        for(i = start; i < end; i++){
            if(array[i] > array[i+1]){
                Swap(&array[i], &array[i+1]);
                swap = 0;
            }
        }
        end--;
        for(i = end; i > start; i--){
            if(array[i] < array[i-1]){
                Swap(&array[i], &array[i-1]);
                swap = 0;
            }
        }
        start++;
        print(array);
    }
}

int CircleSortAux(int start[], int end[]){
	int *p, *q, t, swap;
 
	if(start == end) 
        return 0;
	for(swap = 0, p = start, q = end; p < q || (p == q && ++q); p++, q--) // (++q for odd center of array)
		if(*p > *q){
			t = *p;
            *p = *q;
            *q = t;
            swap = 1;
        }
	return swap | CircleSortAux(start, q) | CircleSortAux(p, end);
}
 
void CircleSort(int array[], int length){
	while(CircleSortAux(array, array + (length - 1))) 
        print(array);
}

void Bubble_sort(int array[],int length){
    while(length > 1){ // Each loop eleminates the last element in array which is already sorted
        for(int i = 0; i < length; i++){ // length - 1 comparisons for each loop
            if(array[i] > array[i+1]) // Compare each 2 elements of the array 
                Swap(&array[i], &array[i+1]);
        }
        length--;
        print(array);
    }
}

void heapmax(int array[], int n, int i){ //n is the size of heap
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
  
    if(left < n && array[left] > array[largest]) //Left child is larger than node
        largest = left; 
    if(right < n && array[right] > array[largest]) //Right child is larger than node
        largest = right; 
    if(largest != i){ //Larger is not the actual node
        Swap(&array[i], &array[largest]);
        print(array);
        heapmax(array, n, largest); //Acess the subtree
    } 
} 
  
void Max_Heap_Sort(int array[], int length){ 
    for(int i = length / 2 - 1; i >= 0; i--) 
        heapmax(array, length, i); //Creating the heap
    for(int i = length-1; i > 0; i--){ //Remove each element from heap
        Swap(&array[i], &array[0]);
        print(array);
        heapmax(array, i, 0); //Reduced heap
    } 
}

void heapmin(int array[], int n, int i){ //n is the size of heap
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;

    if(left < n && array[left] < array[smallest]) //Left child is smaller than node
        smallest = left; 
    if(right < n && array[right] < array[smallest]) //Right child is smaller than node
        smallest = right; 
    if(smallest != i){ //smaller is not the actual node
        Swap(&array[i], &array[smallest]);
        print(array);
        heapmin(array, n, smallest); //Acess the subtree
    } 
} 
  
void Min_Heap_Sort(int array[], int length){ 
    for(int i = length / 2 - 1; i >= 0; i--) 
        heapmin(array, length, i); //Creating the heap
    for(int i = length-1; i >= 0; i--){ //Remove each element from heap
        Swap(&array[i], &array[0]);
        print(array);
        heapmin(array, i, 0); //Reduced heap
    } 
}

void Pairwise_Sort(int array[], int start, int end, int piv){
	if(start != end - piv){
		int i, j, k;
		for(i = start + piv; i < end; i += (2 * piv)){ // Starts comparing the multiples of two
			if(array[i - piv] > array[i]){
				Swap(&array[i], &array[i-piv]);
			}
		}
        print(array);
		if((end - start) / piv % 2 == 0){ // Doing the same but using the power of 2, starting in different indexes
			Pairwise_Sort(array, start, end, piv * 2);
			Pairwise_Sort(array, start + piv, end + piv, piv * 2);
		}
		else{
			Pairwise_Sort(array, start, end + piv, piv * 2);
			Pairwise_Sort(array, start + piv, end, piv * 2);
		}
		for(j = 1; j < (end - start) / piv; j = (j * 2) + 1)
			continue;
		for(i = start + piv; i + piv < end; i += 2 * piv){ // Compares with the other elements in the array
			for(k = j; k > 1;){
				k /= 2;
				if(k * piv + i < end){
					if(array[i] > array[k * piv + i]){
						Swap(&array[i], &array[k * piv + i]);
					}
				}
			}
		}
        print(array);
	}
}

void SillySort(int array[],int start, int end){ 
    if(start < end){
		int mid = start + ((end - start) / 2); // Calculate the middle of the (sub)array
		
		SillySort(array, start, mid); // Calls recursively until rech pairs of the elements (array[i]->array[i+1])
		SillySort(array, mid + 1, end);
		if(array[start] > array[mid+1]){ // Sort the two elements
            Swap(&array[start], &array[mid+1]);
            print(array);
        }
		SillySort(array, start + 1, end); // Do the same but for start+1
	}
}

void BadSort(int array[], int length){
    int smaller;
    bool check;
    for(int i = 0; i < length; i++){
        smaller = i;         
        for(int j = i; j < length; j++){ // Find the smaller element
            check = true;
            for(int k = j + 1; k < length; k++){
                if(array[j] > array[k]){ // Check if array[j] is the smaller
                    check = false;
                    break;
                }
            }
            if(check){
                smaller = j;
                break;
            }
        }
        Swap(&array[i], &array[smaller]);
        print(array);
    }
}

void BogoBogoSort(int array[],int length){
    int size = 2,random;
    bool notsorted = true;
        
    while(notsorted){
        if(is_sorted(array, size))
            size == length ? notsorted = false : size++;
        else
            size = 2; 
        if(notsorted){
            for(int i = 0; i < size; i++){ //tries to sort randomly
                random = rand() % size;
                Swap(&array[i],&array[random]);
            }
            print(array);
        }
    }
}

void BubbleBogoSort(int array[], int length){
    int random,aux;
    while(!is_sorted(array, length)){
        random = rand() % length-1;    
        if(array[random] > array[random+1]){ // Tries to sort randomly the index and index+1
            aux = array[random];
            array[random] = array[random+1];
            array[random+1] = aux;
        }
    }
}

void ExchangeBogoSort(int array[], int length){
    int random1,random2,aux;
    while(!is_sorted(array, length)){
        random1 = rand() % length;
        random2 = rand() % length;
        if(random1 < random2){ // Check the positions
            if(array[random1] > array[random2]){ // Check if it's sorted
                aux = array[random1];
                array[random1] = array[random2];
                array[random2] = aux;
            }
        }
        else{
            if(array[random1] < array[random2]){ // Check if it's sorted
                aux = array[random1];
                array[random1] = array[random2];
                array[random2] = aux;
            }
        }
    }
}

void LessBogoSort(int array[], int length){
    int index = 0,aux,random;
    while(index != length){
        while(!is_sorted(array, index+1)){ // Tries to sort randomly
            random = rand() % length;
            aux = array[random];
            array[random] = array[index];
            array[index] = aux;
        }
        index++;
    }
}


int main(){
    srand(time(NULL));
    int option_sort, option_category, array[leng],i;

    while(true){
        for(i = 0; i < leng; i++)
            array[i] = rand() % 1000 + 1;
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
            printf("\n-> ");
            scanf("%d",&option_category);
            if(option_category < 0 || option_category > 8)
                printf("\n\tError: Choose the value in the range displayed.\n");
        }while(option_category < 0 || option_category > 8);
        if(option_category == 0)
            break;
        printf("\n\tChoose the sort to be aplied on ");
        switch(option_category){
            case 1:
                do{
                    printf("Esoteric & Fun & Miscellaneous:");
                    printf("\n1 - Bad_Sort.");
                    printf("\n2 - Bogo_Bogo_Sort.");
                    printf("\n3 - Bogo_Sort.");
					printf("\n4 - Bubble_Bogo_Sort.");
					printf("\n5 - Exchange_Bogo_Sort.");
					printf("\n6 - Less_Bogo_Sort.");
                    printf("\n7 - Pancake_Sort.");
                    printf("\n8 - Silly_Sort.");
                    printf("\n9 - Slow_Sort.");
                    printf("\n10 - Spaghetti_Sort.");
                    printf("\n11 - Stooge_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 1 || option_sort > 11)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 1 || option_sort > 11);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore Bad Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        BadSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 2:
                        printf("\n\tBefore Bogo Bogo Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        BogoBogoSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 3:
                        printf("\n\tBefore Bogo Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        bogo_sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
					case 4:
                        printf("\n\tBefore Bubble Bogo Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        BubbleBogoSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
					case 5:
                        printf("\n\tBefore Exchange Bogo Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        ExchangeBogoSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
					case 6:
                        printf("\n\tBefore Less Bogo Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        LessBogoSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 7:
                        printf("\n\tBefore Pancake Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        PancakeSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 8:
                        printf("\n\tBefore Silly Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        SillySort(array,0,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 9:
                        printf("\n\tBefore Slow Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        SlowSort(array,0,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 10:
                        printf("\n\tBefore Spaghetti Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        SpaghettiSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 11:
                        printf("\n\tBefore Stooge Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        StoogeSort(array,0,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                }
                break;
            case 2:
                do{
                    printf("Exchange:");
                    printf("\n1 - Bubble_Sort.");
                    printf("\n2 - Circle_Sort.");
                    printf("\n3 - Cocktail_Shaker_Sort.");
                    printf("\n4 - Comb_Sort.");
                    printf("\n5 - Dual_Pivot_Quick_Sort.");
                    printf("\n6 - Gnome_Sort.");
                    printf("\n7 - Odd-Even_Sort.");
                    printf("\n8 - Optimized_Bubble_Sort.");
                    printf("\n9 - Optimized_Gnome_Sort.");
                    printf("\n10 - Quick_Sort.");
                    printf("\n11 - Stable_Quick_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 1 || option_sort > 11)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 1 || option_sort > 11);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore Bubble Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Bubble_sort(array,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 2:
                        printf("\n\tBefore Circle Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        CircleSort(array, leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 3:
                        printf("\n\tBefore Cocktail Shaker Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        CocktailShakerSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 4:
                        printf("\n\tBefore Comb Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        CombSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 5:
                        printf("\n\tBefore Dual Pivot Quick Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        DualPivotQuickSort(array,0,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 6:
                        printf("\n\tBefore Gnome Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Gnome_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 7:
                        printf("\n\tBefore Odd-Even Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Odd_Even_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 8:
                        printf("\n\tBefore Optimized Bubble Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        BubbleSortOptmized(array,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 9:
                        printf("\n\tBefore Optimized Gnome Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        for(i = 1; i < leng; i++)
                            Optimized_Gnome_Sort(array,i);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 10:
                        printf("\n\tBefore Quick Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Quick_Sort(array,0,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 11:
                        printf("\n\tBefore Stable Quick Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        StableQuickSort(array,0,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                }
                break;
            case 3:
                do{
                    printf("Hybrids:");
                    printf("\n1 - Tim_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort != 1)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort != 1);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore Tim Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        TimSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                }
                break;
            case 4:
                do{
                    printf("Insertion:");
                    printf("\n1 - Binary_Insertion_Sort.");
                    printf("\n2 - Cycle_Sort.");
                    printf("\n3 - Insertion_Sort.");
                    printf("\n4 - Shell_Sort.");
                    printf("\n5 - Tree_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 1 || option_sort > 5)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 1 || option_sort > 5);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore Binary Insertion Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Insertion_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 2:
                        printf("\n\tBefore Cycle Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        CycleSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 3:
                        printf("\n\tBefore Insertion Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        InsertionSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 4:
                        printf("\n\tBefore Shell Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        ShellSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 5:
                        printf("\n\tBefore Tree Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        TreeSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                }
                break;
            case 5:
                do{
                    printf("Merge:");
                    printf("\n1 - Bottomup_Merge_Sort.");
                    printf("\n2 - In-Place_Merge_Sort.");
                    printf("\n3 - Merge_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 1 || option_sort > 3)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 1 || option_sort > 3);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore Bottom-up Merge Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Bottomup_Merge_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 2:
                        printf("\n\tBefore In Place Merge Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        MergeSort(array,0,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 3:
                        printf("\n\tBefore Merge Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Merge_Sort(array,0,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                }
                break;
            case 6:
                do{
                    printf("Networks & Concurrent:");
                    printf("\n1 - Pairwise_Network_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort != 1)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort != 1);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore Pairwise Network Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Pairwise_Sort(array,0,leng,1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                }
                break;
            case 7:
                do{
                    printf("Non-Comparison & Distribution:");
                    printf("\n1 - Bucket_Sort.");
                    printf("\n2 - Counting_Sort.");
                    printf("\n3 - Gravity_(Bead)_Sort.");
                    printf("\n4 - Pigeonhole_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 1 || option_sort > 4)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 1 || option_sort > 4);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore Bucket Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        BucketSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 2:
                        printf("\n\tBefore Counting Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Counting_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 3:
                        printf("\n\tBefore Gravity (Bead) Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        BeadSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 4:
                        printf("\n\tBefore Pigeonhole Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Pigeonhole_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                }
                break;
            case 8:
                do{
                    printf("Selection:");
                    printf("\n1 - Double_Selection_Sort.");
                    printf("\n2 - Max_Heap_Sort.");
                    printf("\n3 - Min_Heap_Sort.");
                    printf("\n4 - Selection_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 1 || option_sort > 4)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 1 || option_sort > 4);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore Double Selection Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Double_Selection_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 2:
                        printf("\n\tBefore Max Heap Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Max_Heap_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 3:
                        printf("\n\tBefore Min Heap Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Min_Heap_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 4:
                        printf("\n\tBefore Selection Sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Selection_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                }
                break;
        }
        printf("\n\n");
    }
    return 0;
}