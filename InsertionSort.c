#include<stdio.h>
void print(int arr[],int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void insertion(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int key=arr[i],j;
        for(j=i-1;j>=0&&arr[j]>key;j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
}
int main(void)
{
    int arr[] = { 5, 1, 4, 2, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted Array: ");
    print(arr,n);
    insertion(arr,n);
    printf("Sorted Array: ");
    print(arr,n);
}