// LC-54. Spiral Matrix
// Given an m x n matrix, return all elements of the matrix in spiral order.

/*Example 1:          Input: matrix = [[1,2,3],
                                    [4,5,6],
                                    [7,8,9]]
                    Output: [1,2,3,6,9,8,7,4,5]
Example 2:
                    Input: matrix = [[1,2,3,4],
                                    [5,6,7,8],
                                    [9,10,11,12]]
                    Output: [1,2,3,4,8,12,11,10,9,5,6,7]*/

#include<bits\stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    int top = 0;
    int bottom = row - 1;
    int left = 0;
    int right = col - 1;

    int count = 0;
    int total = row*col;
    
    vector<int> ans; 
    while(count < total){

        for(int i = left ; count<total && i<=right;i++ ){
            ans.push_back(matrix[top][i]);
            count++;
        }
        top++;

        for(int i = top ;count<total && i<=bottom; i++ ){
            ans.push_back(matrix[i][right]);
            count++;
        }
        right--;

        for(int i = right ;count<total && i>=left; i-- ){
            ans.push_back(matrix[bottom][i]);
            count++;
        }
        bottom--;

        for(int i = bottom ;count<total && i>=top ;i-- ){
            ans.push_back(matrix[i][left]);
            count++;
        }
        left++;
    }
    return ans;
    
}



int main(){
    vector<vector<int>> matrix = {  {1,2,3,4},
                                    {5,6,7,8},
                                    {9,10,11,12}};

    vector<int> result = spiralOrder(matrix);

    for(auto elem : result){
        cout <<elem<<" "; //1 2 3 4 8 12 11 10 9 5 6 7
    }
}