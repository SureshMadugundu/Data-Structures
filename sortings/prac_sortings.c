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
void bubble_sort(int array[], int size)
{
    for(int i = 0 ; i < size -1 ; i++)
    {
        for(int j = i + 1 ; j < size ; j++)
        {
            if(array[i] > array[j])
            {
                swap(&array[i],&array[j]);
            }
        }
    }
    print_array(array,size);
}
void insertion_sort(int array[], int size)
{
    for(int i = 1 ; i < size ; i++)
    {
        int temp = array[i];
        int j = i - 1;
        while( j >= 0 && array[j] > temp)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
    print_array(array,size);
}
void selection_sort(int array[],int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        int min = i;
        for(int j = i + 1; j < size ; j++)
        {
            if(array[j] < array[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            swap(&array[i], &array[min]);
        }
    }
    print_array(array,size);
}
int partition(int array[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[low];
    while(i < j)
    {
        while(array[i] <= pivot)
        {
            i++;
        }
        while(array[j] > pivot)
        {
            j--;
        }
        if(i < j)
        {
            swap(&array[i],&array[j]);
        }
    }
    swap(&array[low],&array[j]);
    return j;
}
void quick_sort(int array[], int low, int high)
{
    if(low < high)
    {
        int partition_index = partition(array,low,high);
        quick_sort(array,low,partition_index-1);
        quick_sort(array,partition_index+1,high);
    }
    
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
    //quick_sort(array,0,size-1);
    merge_sort(array,0,size-1);
    print_array(array,size);

   
}