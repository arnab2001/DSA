// Implementation of Insertion Sort
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

void insertionSort(int arr[],int n)

{

int i,j;

for(int i=1;i<n;i++)

{

int key=arr[i]; int j= i-1;
while(j>=0 && arr[j]>key)

{

arr[j+1]=arr[j]; j=j-1;
}

arr[j+1]=key;

}

}

void main()

{

int A[20],n;

printf("\nEnter the size of the array:");
 
scanf("%d",&n); input(A,n);
printf("\nArray before sorting:"); display(A,n);
insertionSort(A,n); printf("\nArray after sorting:"); display(A,n);
}

/* Output:
Enter the size of the array:5

Enter 5 number of elements: 6 4 8 5 7

Array before sorting:6 4 8 5 7

Array after sorting:4 5 6 7 8 */
