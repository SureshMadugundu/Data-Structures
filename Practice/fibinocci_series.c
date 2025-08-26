#include<stdio.h>
int fibinocci(int number)
{
    if(number <= 1) return number;
    return fibinocci(number-1) + fibinocci(number-2);
}
int main()
{
    int number;
    scanf("%d",&number);
    printf("Fibinocci series : %d",fibinocci(number));
    return 0;
}