
#include<stdio.h>
void read_array(int array[], int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        scanf("%d",&array[i]);
    }
}
void print_array(int array[], int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",array[i]);
    }    
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void merge(int array[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int k = 0;

    // temporary array of size (high - low + 1)
    int temp[high - low + 1];

    // merge elements into temp[]
    while (left <= mid && right <= high) 
    {
        if (array[left] <= array[right])
        {
            temp[k++] = array[left++];
        } 
        else
        {
            temp[k++] = array[right++];
        }
    }

    // copy remaining left part
    while (left <= mid)
    {
        temp[k++] = array[left++];
    }

    // copy remaining right part
    while (right <= high)
    {
        temp[k++] = array[right++];
    }

    // copy sorted temp[] back to array[]
    for (int i = 0; i < k; i++)
    {
        array[low + i] = temp[i];
    }
}
void merge_sort(int array[], int low, int high)
{
    if (low >= high) return;   // base case

    int mid = (low + high) / 2;
    merge_sort(array, low, mid);
    merge_sort(array, mid + 1, high);
    merge(array, low, mid, high);
}
int main()
{
    int size;
    scanf("%d",&size);

    int array[size];
    read_array(array,size);
    merge_sort(array,0,size-1);
    print_array(array,size);

   
}
