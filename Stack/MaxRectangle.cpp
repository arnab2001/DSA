
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution{
  public:
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
        int res = larghist(M[0], m);
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(M[i][j] == 1)
                {
                    M[i][j] += M[i-1][j];
                }
            }
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
