#include <stdio.h>
#include <stdlib.h>

void QuickSort(int array[]){   
    /*mid = len(ar)/2;
    pivot = ar[mid] 
  
    smaller,greater = [],[] 
   
    for(indx, val in enumerate(ar))
        if(indx != mid)
            if(val < pivot)
                smaller.append(val) 
            else if (val > pivot)
                greater.append(val) 
            else
                if(indx < mid)
                    smaller.append(val) 
                else
                    greater.append(val) 
    return quickSort(smaller)+[pivot]+quickSort(greater) 
    */
}
/*

static void OptimizedQuickSort(ref int[] Arr, int Left, int Right)
{
    int Pivot;
    Pivot = Q_Sort(ref Arr, Left, Right);
    if(Left < Pivot - 1)
    {
        OptimizedQuickSort(ref Arr, Left, Pivot - 1);
    }
    if(Right > Pivot + 1)
    {
        OptimizedQuickSort(ref Arr, Pivot + 1, Right);
    }
}  

static int Q_Sort(ref int[] Arr, int Left, int Right)
{
    int Pivot;
    Pivot = Arr[Left];
    while(Left < Right)
    {
        while((Arr[Right] >= Pivot) && (Left < Right))
        {
            Right--;
        }
        if(Left != Right)
        {
            Arr[Left] = Arr[Right];
            Left++;
        }
        while((Arr[Left] <= Pivot) && (Left < Right))
        {
            Left++;
        }
        if(Left != Right)
        {
            Arr[Right] = Arr[Left];
            Right--;
        }
    }   
    Arr[Left] = Pivot;
    return Left;
}  

*/
int main(){
    int array[] = {979,82,937,764,309,761,824,540,786,732},i;
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);
    
    printf("\n\n");
    
    Quick_Sort(array,0,9);
    
    for(i = 0; i < 10; i++)
        printf("%d ",array[i]);

    return 0;
}
