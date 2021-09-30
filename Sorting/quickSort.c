//Implementation of Quick Sort

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
void swap(int *ptr1,int *ptr2)
{
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}
int partition(int A[],int p,int r)
{
    int x=A[r];
    int i=p-1;
    for(int j=p;j<r;j++)
    {
        if(A[j]<=x)
        {
            i++;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[r]);
    return i+1;
}
void QuickSort(int A[],int p,int r)
{
    if(p<r)
    {
        int q=partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
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
    QuickSort(A,0,n-1);
    printf("\nArray after sorting:");
    display(A,n);
}

/* Output:

Enter	the size of the array:10
Enter 10 number of elements: 5 7 20 3 11 6 15 4 10 12

Array	before sorting:5 7 20 3 11 6 15 4 10 12
Array	after sorting:3 4 5 6 7 10 11 12 15 20
*/
