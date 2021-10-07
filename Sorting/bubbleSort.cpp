// C++ program for bubble sort
#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// Function to sort an array using bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code 
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 18, 1, -16, 5, -2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	bubbleSort(arr, n);
	printArray(arr, n);

	return 0;
}

//This code is contributed by Sreemoyee Sadhukhan
