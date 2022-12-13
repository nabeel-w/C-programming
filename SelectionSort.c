#include<stdio.h>
void print(int arr[],int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void selection(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int x=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[x])
                x=j;
            
        }
        if(x!=i)
            {
                int tmp=arr[x];
                arr[x]=arr[i];
                arr[i]=tmp;
            }
    }
}
int main(void)
{
    int arr[] = { 5, 1, 4, 2, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted Array: ");
    print(arr,n);
    selection(arr,n);
    printf("Sorted Array: ");
    print(arr,n);
}
