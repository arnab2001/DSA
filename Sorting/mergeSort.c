// Merge Sort Program
#include<stdio.h>
void input(int A[],int n)
{
    int i;
    printf("Enter %d number of elements: ",n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
}
void display(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
}
void merge(int A[],int p,int q,int r)
{
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1],R[n2+1];
    for(i=0;i<n1;i++)
    {
        L[i]=A[p+i];
    }
    L[n1]= 99999;
    for(j=0;j<n2;j++)
    {
        R[j]=A[q+j+1];
    }
    R[n2]= 99999;
    i=0;
    j=0;
    for(k=p;k<=r;k++)
    {
        if(L[i]<= R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
}
void MergeSort(int A[],int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}
void main()
{
    int A[20],n;
    printf("\nEnter the size of the array:");
    scanf("%d",&n);
    input(A,n);
    printf("\nArray before sorting:");
    display(A,n);
    MergeSort(A,0,n-1);
    printf("\nArray after sorting:");
    display(A,n);
}
/*
Output:
Enter the size of the array:8

Enter 8 number of elements: 32 11 65 83 39 54 77 87

Array before sorting:32 11 65 83 39 54 77 87

Array after sorting:11 32 39 54 65 77 83 87

*/
