class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> col(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                col[j]=col[j-1]+col[j];
            }
        }
        return col[n-1];
    }
};