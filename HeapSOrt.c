
#include<stdio.h>
void print(int arr[],int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void swap(int *a,int* b)
{
    int tmp=*a;
    *a = *b;
    *b=tmp;
}
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[left]>arr[largest])
        largest=left;
    if(right<n&&arr[right]>arr[largest])
        largest=right;
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}
void sort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(int i=n-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr, i, 0);
    }
}
int main(void)
{
    int arr[] = { 5, 1, 4, 2, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted Array: ");
    print(arr,n);
    sort(arr,n);
    printf("Sorted Array: ");
    print(arr,n);
}