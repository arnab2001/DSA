//Implementation of Bubble Sort
#include <stdio.h>

void display(int A[], int n)

{

    int i;
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
}


void bubbleSort(int A[],int n){
    int isSort = 0;
    int temp;
    for(int i=0;i<n-1;i++){
        printf("Working On Pass Number : %d\n",i+1);
        isSort = 1;
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSort = 0;
            }
        }
        if(isSort){
            return;
        }
    }
}

int main()

{

    int A[20], n;

    printf("\nEnter the size of the array:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter The eliment at index %d : ",i);
        scanf("%d", &A[i]);
    }
    printf("\nArray before sorting:\n");
    display(A, n);
    bubbleSort(A, n);

    printf("\nArray after sorting:\n");
    display(A, n);

    return 0;
}

/* Output:

Enter the size of the array:5

Enter 5 number of elements: 9 3 7 1 4



Array before sorting:9 3 7 1 4

Array after sorting:1 3 4 7 9 */
