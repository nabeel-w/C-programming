#include<stdio.h>
int fib(int n)
{
    if(n<=1)
        return n;
    else
    {
        return fib(n-1)+fib(n-2);
    }
}
int main(void)
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",fib(i));
    }
}