#include<stdio.h>

int main()
{
    int size;
    scanf("%d",&size);

    int array[size];
    int hash[10] = {0};
    for(int i = 0 ; i < size ; i++)
    {
        scanf("%d",&array[i]);
    }

    for(int i = 0 ; i < size ; i++)
    {
        hash[array[i]] += 1;
    }
    printf("%d",hash[2]);
} 