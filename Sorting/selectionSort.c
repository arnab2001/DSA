// Implementation of Selection Sort
#include<stdio.h>

void input(int A[],int n)

{

int i;

printf("Enter %d number of elements: ",n); for(i=0;i<n;i++)
scanf("%d",&A[i]);

}

void display(int A[],int n)

{

int i; for(i=0;i<n;i++)
printf("%d ",A[i]);

}

void swap(int j,int iMin,int A[])

{

int temp; temp=A[j]; A[j]=A[iMin]; A[iMin]=temp;
}

void selectionSort(int a[], int n)

{

int i, j, iMin;

for (j = 0; j < n-1; j++)

{
 
iMin = j;

for (i = j+1; i < n; i++)

{

if (a[i] < a[iMin])

iMin = i;

}

if (iMin != j)

swap(j, iMin,a);

}

}

void main()

{

int A[20],n;

printf("\nEnter the size of the array:"); scanf("%d",&n);
input(A,n);

printf("\nArray before sorting:"); display(A,n);
selectionSort(A,n); printf("\nArray after sorting:"); display(A,n);
}

/* Output:


Enter the size of the array:5

Enter 5 number of elements: 5 7 1 9 4

Array before sorting:5 7 1 9 4

Array after sorting:1 4 5 7 9 */
