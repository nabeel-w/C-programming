#include<stdio.h>
int main(void)
{
    int a[]={1,2,3,4,5};
    int size=sizeof(a)/sizeof(int);
    int sum[size];
    sum[0]=a[0];
    for (int i = 1; i < size; i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    
    for (int i = 0; i < size; i++)
    {
        printf("%d\t",sum[i]);
    }
    
}