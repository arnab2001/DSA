#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    int i=0, j=M-1;
	    while (i<N && j>=0){
	        if (mat[i][j]==X){
	            return 1;
	        }
	        else if (mat[i][j]>X){
	            j--;
	        }
	        else {
	            i++;
	        }
	    }
	    return 0;
	}
};

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}  