#include<stdio.h>

void swap(int * a , int * b)
{
    int temp = * a;
    * a = * b;
    * b = temp;
}
void print_array(int array[], int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}
void selection_sort(int array[], int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = i+1 ; j < size ; j++)
        {
            if(array[i] > array[j])
            {
                swap(&array[i],&array[j]);
            }
        }
    }
    printf("After Sorting:");
    print_array(array,size);
}
int main()
{
    int size;
    scanf("%d",&size);
    int array[size];

    for(int i = 0 ; i < size ; i++)
    {
        scanf("%d",&array[i]);
    }
    print_array(array,size);
    selection_sort(array,size);
    return 0;
}