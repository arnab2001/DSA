//Implementation of Bubble Sort
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

void swap(int a,int arr[])

{

int temp; temp=arr[a]; arr[a]=arr[a+1]; arr[a+1]=temp;
}

void bubbleSort(int arr[], int n)

{

int i,j;

for (i=0;i<n-1;i++)

{

for (j=0;j<n-i-1;j++)

{
 
if(arr[j]>arr[j+1]) swap(j,arr);
}

}

}

void main()

{

int A[20],n;

printf("\nEnter the size of the array:"); scanf("%d",&n);
input(A,n);

printf("\nArray before sorting:"); display(A,n);
bubbleSort(A,n);

printf("\nArray after sorting:"); display(A,n);
}

/* Output:

Enter the size of the array:5

Enter 5 number of elements: 9 3 7 1 4



Array before sorting:9 3 7 1 4

Array after sorting:1 3 4 7 9 */
