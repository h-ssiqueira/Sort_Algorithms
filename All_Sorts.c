#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define leng 10
#define RUN 32
#define buckets 10

void print(int array[]){
    printf("\n");
    for(int i = 0; i < leng; i++)
        printf("%d ",array[i]);
}

bool is_sorted(int a[], int n){
    while(--n >= 1){
        if(a[n] < a[n-1]) 
            return false;
    }
    return true;
}
    
void shuffle(int a[], int n){
    int aux, random;
    
    for(int i = 0; i < n; i++){ //tries to sort randomly
        aux = a[i];
        random = rand() % n;
        a[i] = a[random];
        a[random] = aux;
        print(a);
    }
}
    
void bogo_sort(int a[], int n){
    while(!is_sorted(a,n)) 
        shuffle(a,n);
}

void flip(int array[], int i){ 
    int start = 0; 
    while(start < i){ 
        array[start] = array[i] ^ array[start];
        array[i] = array[i] ^ array[start];
        array[start] = array[i] ^ array[start];
        start++; 
        i--; 
        print(array);
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
            flip(array, i-1); // Reverse the array
        } 
    }
}

void SlowSort(int array[],int start,int end){
    if(start >= end) return;
    int middle = (start + end) / 2;
    SlowSort(array,start,middle); // start - middle parts
    SlowSort(array,middle + 1,end); // middle - end parts
    if(array[end] < array[middle]){
        array[end] = array[end] ^ array[middle];
        array[middle] = array[end] ^ array[middle];
        array[end] = array[end] ^ array[middle];
        print(array);
    }
    SlowSort(array,start,end-1);
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
                print(aux);
            }
        }
    }
    for(i = 0; i < length; i++) // Return the elements in the main array
        array[i] = aux[i];
}

void StoogeSort(int array[], int i, int j){
    int aux;
    if(array[i] > array[j]){ // Swap initially the fist and last elements
        aux = array[i];
        array[i] = array[j];
        array[j] = aux;
        print(array);
    }
    if(j - i > 1){ 
        aux = (j - i + 1) / 3;
        StoogeSort(array, i, j - aux); // Swap recursively the first 2/3 elements of the array
        StoogeSort(array, i + aux, j); // Swap recursively the last 2/3 elements of the array
        StoogeSort(array, i, j - aux); // Swap recursively again the first 2/3 elements of the array
    }
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
    
    while(h < length) 
        h = 3 * h + 1;
    for(;h > 0; h /= 3){
        for(i = h; i < length; i++){
            aux = array[i];
            for(j = i; j > h-1 && array[j - h] > aux; j -= h)
                array[j] = array[j - h];
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
  
        if(pos != i){ // Setting the element in correct position
            /*
            aux = aux ^ array[pos];
            array[pos] = aux ^ array[pos];
            aux = aux ^ array[pos];
            */
            swap = aux;
            aux = array[pos];
            array[pos] = swap;
        }
  
        while(pos != i){ // Rotating the cycle
            pos = i; 
  
            for(int k = i + 1; k < length; k++) // Find the right position
                if(array[k] < aux) 
                    pos++; 
  
            while(aux == array[pos]) // For duplicate elements
                pos++; 
  
            if(aux != array[pos]){ // Setting the element in correct position
                /*
                aux = aux ^ array[pos];
                array[pos] = aux ^ array[pos];
                aux = aux ^ array[pos];
                */
                swap = aux;
                aux = array[pos];
                array[pos] = swap;
            }
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
    int change, aux;
    
    for(int i = 0; i < length-1; i++){ //last element won't have other to compair
        change = i;
        for(int j = i+1; j < length; j++)
            if(array[change] > array[j]) //if the element is lower, collect the position
                change = j;
        if(i != change){// if it has been modified, swap positions (using xor)
            /*
            array[i] = array[i] ^ array[change];
            array[change] = array[i] ^ array[change];
            array[i] = array[i] ^ array[change];
            */
            aux = array[i];
            array[i] = array[change];
            array[change] = aux;
        }
        print(array);
    }
}

void Double_Selection_Sort(int array[], int length){
    int changeMin, changeMax, aux;
    
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
            /*
            array[i] = array[i] ^ array[changeMin];
            array[changeMin] = array[i] ^ array[changeMin];
            array[i] = array[i] ^ array[changeMin];
            */
            aux = array[i];
            array[i] = array[changeMin];
            array[changeMin] = aux;
        }
        if(j != changeMax){ //swap the positions for fit the max element
            /*
            array[j] = array[j] ^ array[changeMax];
            array[changeMax] = array[j] ^ array[changeMax];
            array[j] = array[j] ^ array[changeMax];
            */
            aux = array[i];
            array[i] = array[changeMax];
            array[changeMax] = aux;
        }
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
        Merge(array, start, middle, end); // sort
    }
}

void merge(int array[], int start, int middle, int end){ 
    int middle2 = middle + 1, value, i; 
  
    if (array[middle] <= array[middle2]) //if already sorted
        return;
  
    while(start <= middle && middle2 <= end){ //merge both halfs
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

        MergeSort(array, start, middle); //first halfs
        MergeSort(array, middle + 1, end); //second halfs
        merge(array, start, middle, end);
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
    int output[length], k, i, max = array[0], min = array[0];
    
    for(i = 0; i < length; i++){
        if(array[i] > max) max = array[i];
        if(array[i] < min) min = array[i];
    }
    
    int range = max - min + 1,count[range];
    
    for(i = 0; i < length; i++)//set zero for 
        output[i] = 0;
    for(i = 0; i < range; i++)//both arrays
        count[i] = 0;
    for(i = 0; i < length; i++)//sort by how many times the value repeats
        count[array[i]-min]++;
    for(i = 1; i <= length; i++) //count the amount of previous incidences
        count[i] += count[i-1];
    for(i = length-1; i >= 0; i--){ 
        k = count[array[i] - min];//getting the right position
		output[k - 1] = array[i];//putting the value on the corrected position && already sorted to an auxiliary array
		count[array[i] - min]--;
	}
    for(i = 0; i < length; i++) //transfering to original array
        array[i] = output[i];
}

void Double_Selection_SortMatrix(int length, int matrix[][length]){
    int changeMin, changeMax, aux;
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
            if(i != changeMin){ //swap the positions for fit the min element
                /*
                matrix[h][i] = matrix[h][i] ^ matrix[h][changeMin];
                matrix[h][changeMin] = matrix[h][i] ^ matrix[h][changeMin];
                matrix[h][i] = matrix[h][i] ^ matrix[h][changeMin];
                */
                aux = matrix[h][i];
                matrix[h][i] = matrix[h][changeMin];
                matrix[h][changeMin] = aux;
            }
            if(j != changeMax){ //swap the positions for fit the max element
                /*
                matrix[h][j] = matrix[h][j] ^ matrix[h][changeMax];
                matrix[h][changeMax] = matrix[h][j] ^ matrix[h][changeMax];
                matrix[h][j] = matrix[h][j] ^ matrix[h][changeMax];
                */
                aux = matrix[h][i];
                matrix[h][i] = matrix[h][changeMax];
                matrix[h][changeMax] = aux;
            }
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
    int aux;
    aux = array[start];
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
    int aux;
    aux = Sort(array, start, end);
    if(start < aux - 1)
        StableQuickSort(array, start, aux - 1);
    if(end > aux + 1)
        StableQuickSort(array, aux + 1, end);
    print(array);
}  

void Quick_Sort(int array[], int start, int end){
    int middle = array[(start + end) / 2], i = start, j = end,aux;
    
    while(i <= j){
        while(array[i] < middle && i < end)
            i++;
        while(array[j] > middle && j > start)
            j--;
        if(i <= j){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            /*
            array[i] = array[i] ^ array[j];
            array[j] = array[i] ^ array[j];  //XOR swapping doesn't work when the values are the same
            array[i] = array[i] ^ array[j];  //Because the truth table for equal values result in 0
            */
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
    int j = i, aux;
    while(j > 0 && array[j-1] > array [j]){
        /*
        array[j] = array[j] ^ array[j-1];
        array[j-1] = array[j] ^ array[j-1];
        array[j] = array[j] ^ array[j-1];
        */
        aux = array[j];
        array[j] = array[j-1];
        array[j-1] = aux;
        j--;
        print(array);
    }
}

void BubbleSortOptmized(int array[], int length){
    bool swap;
    int i,j,aux;
    for(j = 0; j < length; j++){
        swap = false;
        for(i = 0; i < length - j; i++){ // Sort all array and starts decreasing
            if(array[i+1] < array[i]){
                /*
                array[i] = array[i] ^ array[i+1];
                array[i+1] = array[i] ^ array[i+1];
                array[i] = array[i] ^ array[i+1];
                */
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                swap = true;
            }
        }
        print(array);
        if(!swap) // No swapping happened: it's already sorted
            break;
    }
}

void Odd_Even_Sort(int array[],int length){
    int i, j, aux;
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for(i = 1, j = 2; i < length - 1; i += 2, j += 2){
            if(array[i] > array[i+1]){
                /*
                array[i] = array[i] ^ array[j];
                array[j] = array[i] ^ array[j];
                array[i] = array[i] ^ array[j];
                */
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
                sorted = false;
            }
        }
        for(i = 0, j = 1; i < length - 1; i += 2, j += 2){
            if(array[i] > array[i + 1]){
                /*
                array[i] = array[i] ^ array[j];
                array[j] = array[i] ^ array[j];
                array[i] = array[i] ^ array[j];
                */
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
                sorted = false;
            }
        }
        print(array);
    }
}

void Gnome_Sort(int array[], int length){
    int i = 1, aux;
    
    while(i < length){
        if(array[i] >= array[i-1])
            i++;
        else{
            /*
            array[i] = array[i] ^ array[i-1];
            array[i-1] = array[i] ^ array[i-1];
            array[i] = array[i] ^ array[i-1];
            */
            aux = array[i];
            array[i] = array[i-1];
            array[i-1] = aux;
            if(i != 1)
                i--;
        }
        print(array);
    }
}

void DualPivotQuickSort(int array[], int start, int end){
    if(start < end){
        if(array[end] < array[start]){
            array[end] = array[end] ^ array[start];
            array[start] = array[end] ^ array[start];
            array[end] = array[end] ^ array[start];
        }
            
        int last = array[end], first = array[start], p1 = start + 1, p2 = end - 1, aux = p1, swap;
        while(aux <= p2){
            if(array[aux] < first){
                swap = array[aux];
                array[aux] = array[p1];
                array[p1] = swap;
                p1++;
            } 
            else if(array[aux] >= last){
                while(array[p2] > last && aux < p2) 
                    p2--;
                swap = array[aux];
                array[aux] = array[p2];
                array[p2] = swap;
                p2--;
                if(array[aux] < first){
                    swap = array[aux];
                    array[aux] = array[p1];
                    array[p1] = swap;
                    p1++;
                }
            }
            aux++;
        }
        p1--;
        p2++;

        swap = array[p1];
        array[p1] = array[start];
        array[start] = swap;
        
        swap = array[end];
        array[end] = array[p2];
        array[p2] = swap;

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
                array[i] = array[i] ^ array[j];
                array[j] = array[i] ^ array[j];
                array[i] = array[i] ^ array[j];
                swap = 1;
            }
        }
        print(array);
    }
}

void CocktailShakerSort(int array[], int length){
    int start = 0,end = length - 1,swap = 0,i,aux;
    while(swap == 0 && start < end){
        swap = 1;
        for(i = start; i < end; i++){
            if(array[i] > array[i+1]){
                /*
                array[i] = array[i] ^ array[i+1];
                array[i+1] = array[i] ^ array[i+1];
                array[i] = array[i] ^ array[i+1];
                */
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                swap = 0;
            }
        }
        end--;
        for(i = end; i > start; i--){
            if(array[i] < array[i-1]){
                /*
                array[i] = array[i] ^ array[i-1];
                array[i-1] = array[i] ^ array[i-1];
                array[i] = array[i] ^ array[i-1];
                */
                aux = array[i];
                array[i] = array[i-1];
                array[i-1] = aux;
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
    while(length > 1){
        for(int i = 0; i < length; i++){
            if(array[i] > array[i+1]){
                array[i] = array[i] ^ array[i+1]; 
                array[i+1] = array[i] ^ array[i+1];
                array[i] = array[i] ^ array[i+1];
            }
        }
        length--;
        print(array);
    }
}

void heapmax(int array[], int n, int i){ //n is the size of heap
    int largest = i, left = 2 * i + 1, right = 2 * i + 2, aux;
  
    if(left < n && array[left] > array[largest]) //Left child is larger than node
        largest = left; 
  
    if(right < n && array[right] > array[largest]) //Right child is larger than node
        largest = right; 
  
    if(largest != i){ //Larger is not the actual node
        aux = array[i];
        array[i] = array[largest];
        array[largest] = aux;
        print(array);
        heap(array, n, largest); //Acess the subtree
    } 
} 
  
void MaxHeapSort(int array[], int length){ 
    for(int i = length / 2 - 1; i >= 0; i--) 
        heap(array, length, i); //Creating the heap

    for(int i = length-1, aux; i > 0; i--){ //Remove each element from heap
        aux = array[i];
        array[i] = array[0];
        array[0] = aux;
        print(array);
        heap(array, i, 0); //Reduced heap
    } 
}

void heapmin(int array[], int n, int i){ //n is the size of heap
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2, aux;
  
    if(left < n && array[left] < array[smallest]) //Left child is smaller than node
        smallest = left; 
  
    if(right < n && array[right] < array[smallest]) //Right child is smaller than node
        smallest = right; 
  
    if(smallest != i){ //smaller is not the actual node
        aux = array[i];
        array[i] = array[smallest];
        array[smallest] = aux;
        print(array);
        heap(array, n, smallest); //Acess the subtree
    } 
} 
  
void MinHeapSort(int array[], int length){ 
    for(int i = length / 2 - 1; i >= 0; i--) 
        heap(array, length, i); //Creating the heap

    for(int i = length-1, aux; i >= 0; i--){ //Remove each element from heap
        aux = array[i];
        array[i] = array[0];
        array[0] = aux;
        print(array);
        heap(array, i, 0); //Reduced heap
    } 
}


int main(){
    srand(time(NULL));
    int option_sort, option_category, array[leng],i;

    for(i = 0; i < leng; i++){
        array[i] = rand() % 1000 + 1;
    }

    while(true){
        do{
            printf("\n\tWhich category of sort would you like to see?");          
            printf("\n0 - Exit.");
            printf("\n1 - Selection.");
            printf("\n2 - Non-Comparison & Distribution.");
            printf("\n3 - Networks & Concurrent.");
            printf("\n4 - Merge.");
            printf("\n5 - Insertion.");
            printf("\n6 - Hybrids.");
            printf("\n7 - Exchange.");
            printf("\n8 - Esoteric & Fun & Miscellaneous.");
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
                    printf("Selection:");
                    printf("\n1 - Selection_Sort.");
                    printf("\n2 - Double_Selection_Sort.");
                    printf("\n3 - Max_Heap_Sort.");
                    printf("\n4 - Min_Heap_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 1 || option_sort > 2)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 1 || option_sort > 2);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Selection_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 2:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Double_Selection_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 3:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Max_Heap_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 4:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Min_Heap_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                }
                break;
            case 2:
                do{
                    printf("Non-Comparison & Distribution:");
                    printf("\n1 - Pigeonhole_Sort.");
                    printf("\n2 - Gravity_(Bead)_Sort.");
                    printf("\n3 - Counting_Sort.");
                    printf("\n4 - Bucket_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 1 || option_sort > 4)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 1 || option_sort > 4);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Pigeonhole_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 2:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        BeadSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 3:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Counting_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 4:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        BucketSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                }
                break;
            case 3:
                printf("Networks & Concurrent:");
                break;
            case 4:
                do{
                    printf("Merge:");
                    printf("\n1 - Merge_Sort.");
                    printf("\n2 - In-Place_Merge_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 1 || option_sort > 2)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 1 || option_sort > 2);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Merge_Sort(array,0,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 2:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        MergeSort(array,0,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                }
                break;
            case 5:
                do{
                    printf("Insertion:");
                    printf("\n1 - Tree_Sort.");
                    printf("\n2 - Shell_Sort.");
                    printf("\n3 - Insertion_Sort.");
                    printf("\n4 - Cycle_Sort.");
                    printf("\n5 - Binary_Insertion_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 1 || option_sort > 5)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 1 || option_sort > 5);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        TreeSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 2:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        ShellSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 3:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        InsertionSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 4:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        CycleSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 5:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Insertion_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                }
                break;
            case 6:
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
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        TimSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                }
                break;
            case 7:
                do{
                    printf("Exchange:");
                    printf("\n1 - Stable_Quick_Sort.");
                    printf("\n2 - Quick_Sort.");
                    printf("\n3 - Optimized_Gnome_Sort.");
                    printf("\n4 - Optimized_Bubble_Sort.");
                    printf("\n5 - Odd-Even_Sort.");
                    printf("\n6 - Gnome_Sort.");
                    printf("\n7 - Dual_Pivot_Quick_Sort.");
                    printf("\n8 - Comb_Sort.");
                    printf("\n9 - Cocktail_Shaker_Sort.");
                    printf("\n10 - Circle_Sort.");
                    printf("\n11 - Bubble_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 1 || option_sort > 11)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 1 || option_sort > 11);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        StableQuickSort(array,0,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 2:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Quick_Sort(array,0,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 3:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        for(i = 1; i < leng; i++)
                            Optimized_Gnome_Sort(array,i);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 4:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        BubbleSortOptmized(array,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 5:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Odd_Even_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 6:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Gnome_Sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 7:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        DualPivotQuickSort(array,0,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 8:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        CombSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 9:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        CocktailShakerSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 10:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        CircleSort(array, leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 11:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        Bubble_sort(array,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                }
                break;
            case 8:
                do{
                    printf("Esoteric & Fun & Miscellaneous:");                   
                    printf("\n1 - Stooge_Sort.");
                    printf("\n2 - Spaghetti_Sort.");
                    printf("\n3 - Slow_Sort.");
                    printf("\n4 - Pancake_Sort.");
                    printf("\n5 - Bogo_Sort.");
                    printf("\n-> ");
                    scanf("%d",&option_sort);
                    if(option_sort < 1 || option_sort > 5)
                        printf("\n\tError: Choose the value in the range displayed.\n\n\t");
                }while(option_sort < 1 || option_sort > 5);
                switch(option_sort){
                    case 1:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        bogo_sort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 2:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        PancakeSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 3:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        SlowSort(array,0,leng-1);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 4:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        SpaghettiSort(array,leng);
                        printf("\n\tArray sorted:");
                        print(array);
                        break;
                    case 5:
                        printf("\n\tBefore sort:");
                        print(array);
                        printf("\n\tSorting...");
                        StoogeSort(array,0,leng-1);
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