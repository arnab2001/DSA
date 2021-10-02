/* C++ program to calculate the largest rectangle area.
*
* Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of the ith histogram’s bar. Width of each bar is 1. */

#include <iostream>

using namespace std;

int largestRectangleArea(int* heights, int heightsSize) {
    int i, j, bars, area;
    bool calculated;
    int maxA = 0;
    
    for (i = 0; i < heightsSize; i++) {        
        bars = 1;
        calculated = false;
        
        j = i - 1;
        while (j >= 0) {
            if (heights[j] == heights[i]) {
                calculated = true;
                break;
            } 
            else if (heights[j] > heights[i]) {
                bars++;
                j--;
            }
            else {
                break;
            }
        }
        
        if (calculated == true) {
            continue;
        }
        
        j = i + 1;
        while (j < heightsSize) {
            if (heights[j++] >= heights[i]) { 
                bars++;
            }
            else {
                break;
            }
        }
        
        area = heights[i] * bars;
        
        if (area > maxA) { 
            maxA = area;
        }
    }
    
    return maxA;
}

int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << largestRectangleArea(arr, size) << endl;    
    return 0;
}
