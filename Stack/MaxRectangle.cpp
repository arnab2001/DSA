
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution{
  public:

    // Finds the maximum area under
    // the histogram represented
    // by histogram
    int larghist(int arr[], int n)
    {
        stack<int> s;
        int res = 0, tp, curr;
        for(int i=0; i<n; i++)
        {
            while(!s.empty() && arr[s.top()] >= arr[i])
            {
                tp = s.top();s.pop();
                curr = arr[tp] * (s.empty() ? i : (i-s.top()-1));
                res = max(res, curr);
            }
            s.push(i);
        }
        while(!s.empty())
        {
            tp = s.top();s.pop();
            curr = arr[tp] * (s.empty() ? n : (n-s.top()-1));
            res = max(res, curr);
        }
        return res;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {

        // Calculate area for first row and initialize it as
        int res = larghist(M[0], m);

        // iterate over row to find maximum rectangular area
        // considering each row as histogram
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(M[i][j] == 1)
                {
                    M[i][j] += M[i-1][j];
                }
            }
            // Update result if area with current row (as last
            // row) of rectangle) is more
            res = max(res, larghist(M[i], m));
        }
        return res;
    }
};



int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
// Time Complexity: O(R x C). 
// Only one traversal of the matrix is required, so the time complexity is O(R X C)
// Space Complexity: O(C). 
// Stack is required to store the columns, so so space complexity is O(C)
// Troyunz