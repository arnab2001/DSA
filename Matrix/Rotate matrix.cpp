/*  LC.48- Rotate Image
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.

Example:       Input:  [[1, 2, 3], 
                        [4, 5, 6], 
                        [7, 8, 9]]
                Output: [[7, 4, 1], 
                        [8, 5, 6], 
                        [9, 6, 3]]   
*/
#include<iostream>
using namespace std;

// Approach 1: Cycle swapping method    TC:O(n*n)  SC:O(1)
void rotate_method1(int arr[n][n])
{
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[n - 1 - j][i];
            arr[n - 1 - j][i] = arr[n - 1 - i][n - 1 - j];
            arr[n - 1 - i][n - 1 - j] = arr[j][n - 1 - i];
            arr[j][n - 1 - i] = temp;
        }
    }
}

// Approach 2: Transpose method      TC:O(n*n)  SC:O(1)
void rotate_method2(int arr[n][n])
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++)
            swap(arr[i][j], arr[j][i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n / 2; j++)
            swap(arr[i][j], arr[i][n - j - 1]);
    }
}

int main()
{
    int n;
    cin n;
    int matrix[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    rotate_method1(matrix);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << matrix[i][j];
    }
    return 0;
}