#include <bits/stdc++.h>

using namespace std;


void printMatrix(vector<vector<int>> &mat){
    for (auto i:mat){
        for (auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
}


// we know that we're filling from left to right, so there's no need to check for a Queen anywhere on the right side or 
// in the same column (up or down), so we need to check only 3 directions
// isSafe() function with O(1) time complexity using hashing, Space: O(3n)
bool isSafe(int row, int column, vector<vector<int>> &mat, int n, vector<int> &rowHash, vector<int> &leftUpperDiagonalHash, vector<int> &leftLowerDiagonalHash){
    if (rowHash[row]==1 || leftUpperDiagonalHash[n-1 + row-column]==1 || leftLowerDiagonalHash[row+column]==1)  // checking for clash in the hashes
        return false;
    return true;  // if there's no Queens clashing, return true for the current (row, column)
}


//  we're recursing column wise, and running a for loop for rows for each column in the recursion
bool NQueen(int column, vector<vector<int>> &mat, int n, vector<int> &rowHash, vector<int> &leftUpperDiagonalHash, vector<int> &leftLowerDiagonalHash){
    if (column == n){  // we have successfully put all the Queens, now print the matrix and return true to end the call
        printMatrix(mat);
        return true;
    }
    
    for (int row = 0; row < n; row++){  // now checking each row for that column
        if (isSafe(row, column, mat, n, rowHash, leftUpperDiagonalHash, leftLowerDiagonalHash) == true){  // check if the Queen can successfully be placed on that row for the current column
            mat[row][column] = 1;  // place the queen on that row for the current column
            rowHash[row] = 1;  // since we placed the Queen in that row, we're tracking that change in out row hash
            leftUpperDiagonalHash[n-1 + row-column] = 1; // tracking the change in the left lower diagonal hash
            leftLowerDiagonalHash[row + column] = 1; // tracking the change in the left upper diagonal hash
            
            if (NQueen(column+1, mat, n, rowHash, leftUpperDiagonalHash, leftLowerDiagonalHash) == true)  // checking for next column, by moving to there, by going to the next recursion
                return true;  // if the Queen has been successfully placed for that column, return true
                
            mat[row][column] = 0;  // this (row, column) has been checked for the current recursion, clear it for the next recursion
            rowHash[row] = 0;  // this (row, column) has been checked for the current recursion, clear the entry in the hash for the next recursion
            leftUpperDiagonalHash[n-1 + row-column] = 0;  // this (row, column) has been checked for the current recursion, clear the entry in the hash for the next recursion
            leftLowerDiagonalHash[row + column] = 0;  // this (row, column) has been checked for the current recursion, clear the entry int the hash for the next recursion
        }
    }
    
    return false;  // couldn't place the Queen anywhere for the current column
}


int main(){
    int n = 4;
    
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<int> rowHash(n, 0);
    vector<int> leftUpperDiagonalHash(2*n-1, 0);
    vector<int> leftLowerDiagonalHash(2*n-1, 0);
    
    if (NQueen(0, mat, n, rowHash, leftUpperDiagonalHash, leftLowerDiagonalHash) == false)
        cout<<"No solutions"<<endl;
        
    return 0;
}
