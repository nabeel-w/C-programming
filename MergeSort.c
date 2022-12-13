#include<stdio.h>
void print(int arr[],int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void merge(int arr[],int l,int m,int r)
{
    int n1=m-l+1,n2=r-m,i,j,k;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=arr[l+i];
    for(j=0;j<n2;j++)
        R[j]=arr[m+1+j];
    i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
            arr[k]=L[i++];
        else
            arr[k]=R[j++];
        k++;
    }
    while(i<n1)
        arr[k++]=L[i++];
    while(j<n2)
        arr[k++]=R[j++];
}
void sort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        sort(arr,l,m);
        sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main(void)
{
    int arr[] = { 5, 1, 4, 2, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted Array: ");
    print(arr,n);
    sort(arr,0,n-1);
    printf("Sorted Array: ");
    print(arr,n);
}