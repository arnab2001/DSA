// C++ program to merge two sorted arrays
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void merge(int nums1[], int nums2[], int m, int n) {
    //Creating an array of size m+n to store a merged array
    int nums3[m+n];
    // copy nums1[] elements to nums3[]
    for(int i=0;i<m;i++)
        nums3[i]=nums1[i];
    //apply insertion sort algorithm to insert nums2[] element in nums3[]
    for(int i=0;i<n;i++){
        int temp=nums2[i];
        int j=m-1;
        for(;j>=0;j--){
            //move elments one position ahead that are greater than current value
            if(nums3[j]>temp){
                nums3[j+1]=nums3[j];
            }
            else
                break;
        }
        m=m+1;
        //put Current element at its correct position.
        nums3[j+1]=temp;
    }
    // printing the resultant array
    cout << "Array after merging" <<endl;
    for(int i=0;i<m;i++)
        cout<<nums3[i]<<" ";
}
int main(){
	// The driver code
	int nums1[] = {1, 3, 5, 7};
        int nums2[] = {2, 4, 6, 8};
	int m = sizeof(nums1) / sizeof(nums1[0]);
        int n = sizeof(nums2) / sizeof(nums2[0]);
	// calling our function
	merge(nums1, nums2, m, n);
	return 0;
}
