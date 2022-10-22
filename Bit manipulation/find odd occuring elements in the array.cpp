// Find the elements whoch are odd occuring in the array
#include<iostream>
using namespace std;
int findOdd(int arr1[], int n1)
{
    int result = 0;
    
    for(int i = 0; i < n1; i++)
    {
        result = result ^ arr1[i];
    }
    
    return result;
}
    
int main() {
	
	int arr1[]= {1, 5, 4, 6, 6, 5, 2, 2, 3}, n1 = 9;
	
    cout<<findOdd(arr1, n1);
    return 0;
    
}